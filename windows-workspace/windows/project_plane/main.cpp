#include <windows.h>
#include <TCHAR.H>
#include "resource.h"
#include <MMSystem.h>
#include <cstdlib>
#include <ctime>
#define status_start 0
#define status_menu 1
#define status_play 2
#define status_end 3

#define enemy_num_max 10
#define player_bullet_max 20
#define enemy_bullet_max 5

void g_main(HWND);
void g_menu(HWND);
void g_play(HWND);
void g_end(HWND);
void f_init(HWND);
void f_keyboard(HWND);
void f_bullet_player(HWND);
void f_bullet_enemy(HWND);
void f_enemy(HWND);
void f_ScoreBoard(HWND);
void f_enemy_move(HWND);
void f_crash(HWND);
void f_reset(HWND);
void s_paint(HWND);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = _T("1945");

typedef struct ObjectSet {
	int x;
	int y;
	bool blife;
	int type;
}Object;

Object player;
Object bullet_player[player_bullet_max];
Object enemy[10];
Object enemy_bullet[10][enemy_bullet_max];
Object crash[11];

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = NULL;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_CAPTION|WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 700,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd; // hWnd 정보도 전역변수에 저장!	

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

HBITMAP hBMDBuf, hBMMain, hBMMenu, hBMStage;
HBITMAP hBMBullet_p, hBMBullet_e, hBMTextMain, hBMArrowMenu;
HBITMAP hBMPlayer;
HBITMAP hBMEnemy[4];
HBITMAP hBMCrash;

int current_menu = 0;
bool select_menu = FALSE;
BOOL bPlayerAlive = TRUE;
int nPlayerSpeed = 8;
int nEnemy = 0;
BOOL bEnd = FALSE;
int nstage = 1348;
int nStageCount = 0;
int status = status_start;
int text_main_toggle = 1;
int player_life = 3;
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_INITDIALOG:
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			SetTimer(hWndMain, 1, 20, NULL);
			select_menu = FALSE;
			EndDialog(hDlg, 0);
			return 0;
		}
	}
	return 0;
}
BOOL CALLBACK DlgProc_e(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_INITDIALOG:
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_MENU:
			SetTimer(hWndMain, 1, 30, NULL);
			KillTimer(hWndMain, 3);
			status = status_menu;
			current_menu = 0;
			select_menu = FALSE;
			hBMDBuf = NULL;
			EndDialog(hDlg, 0);
			return 0;
		case ID_BUTTON_RESET:
			f_reset(hWndMain);
			EndDialog(hDlg, 0);
			return 0;
		}
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_CREATE: {
		SetTimer(hWnd, 1, 30, NULL);
		SetTimer(hWnd, 2, 1000, NULL);
		srand((unsigned int)time(NULL));

		//리소스 로드
		hBMMain = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MAIN));
		hBMTextMain = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MAIN_TEXT));
		hBMMenu = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MENU));
		hBMArrowMenu = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MENU_ARROW));
		hBMStage = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_STAGE1));
		hBMPlayer = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAYER));
		hBMEnemy[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY1));
		hBMEnemy[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY2));
		hBMEnemy[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY3));
		hBMEnemy[3] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY4));
		hBMBullet_p = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_PLAYER1));
		hBMBullet_e = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_ENEMY1));
		hBMCrash = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_EXPLOSION));
		return 0;
	}
	case WM_TIMER: {
		switch (wParam) {
		case 1:
			switch (status) {
			case status_start:
				g_main(hWnd);
				break;
			case status_menu:
				g_menu(hWnd);
				break;
			case status_play:
				g_play(hWnd);
				break;
			case status_end:
				g_end(hWnd);
				break;
			}
			break;
		case 2:
			text_main_toggle = text_main_toggle ? 0 : 1;
			break;
		case 3:	
			f_enemy(hWnd);
			f_crash(hWnd);
			break;
		case 4:
			f_init(hWnd);
			SetTimer(hWnd, 5, 5000, NULL);
			KillTimer(hWnd, 4);
			break;
		case 5:
			player.blife = TRUE;
			player_life--;
			KillTimer(hWnd, 5);
			break;
		}
		return 0;
	}
	case WM_PAINT: {
		s_paint(hWnd);
		return 0;
	}
	
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		DeleteObject(hBMDBuf);
		DeleteObject(hBMMain);
		DeleteObject(hBMMenu);
		DeleteObject(hBMStage);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
void s_paint(HWND hWnd) {
	RECT rt;
	GetClientRect(hWnd, &rt);
	PAINTSTRUCT ps;
	HDC hDC = BeginPaint(hWnd, &ps);
	HDC hMemDC;
	HBITMAP hBMOld;

	hMemDC = CreateCompatibleDC(hDC);
	hBMOld = (HBITMAP)SelectObject(hMemDC, hBMDBuf);
	BitBlt(hDC, 0, 0, rt.right, rt.bottom, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hBMOld);
	DeleteDC(hMemDC);
	EndPaint(hWnd, &ps);
}
void g_main(HWND hWnd) {
	RECT rt;
	GetClientRect(hWnd, &rt);
	HDC hDC = GetDC(hWnd);
	HDC hBufDC, hMainDC;

	HBITMAP hBMOldBuf, hBMOldMain;
	if (hBMDBuf == NULL) {
		hBMDBuf = CreateCompatibleBitmap(hDC, rt.right, rt.bottom);
	}
	hBufDC = CreateCompatibleDC(hDC);
	hBMOldBuf = (HBITMAP)SelectObject(hBufDC, hBMDBuf);

	hMainDC = CreateCompatibleDC(hDC);
	hBMOldMain = (HBITMAP)SelectObject(hMainDC, hBMMain);

	BitBlt(hBufDC, 0, 0, rt.right, rt.bottom, hMainDC, 0, 0, SRCCOPY);

	if (text_main_toggle) {
		hBMOldMain = (HBITMAP)SelectObject(hMainDC, hBMTextMain);
		TransparentBlt(hBufDC, 20, 600, 460, 48, hMainDC, 0, 0, 460, 48, RGB(8,8, 8));
	}
	f_keyboard(hWnd);
	SelectObject(hMainDC, hBMOldMain);
	SelectObject(hBufDC, hBMOldBuf);

	DeleteDC(hMainDC);
	DeleteDC(hBufDC);

	ReleaseDC(hWnd, hDC);
	InvalidateRect(hWnd, NULL, FALSE);
}


void g_menu(HWND hWnd) {
	KillTimer(hWnd, 2);

	RECT rt;
	GetClientRect(hWnd, &rt);
	HDC hDC = GetDC(hWnd);
	HDC hBufDC, hMenuDC;
	int yaxis[5] = { 110,160,220,270,320 };
	int xaxis = 50;
	HBITMAP hBMOldBuf, hBMOldMenu;
	if (hBMDBuf == NULL) {
		hBMDBuf = CreateCompatibleBitmap(hDC, rt.right, rt.bottom);
	}
	hBufDC = CreateCompatibleDC(hDC);
	hBMOldBuf = (HBITMAP)SelectObject(hBufDC, hBMDBuf);

	hMenuDC = CreateCompatibleDC(hDC);
	hBMOldMenu = (HBITMAP)SelectObject(hMenuDC, hBMMenu);

	BitBlt(hBufDC, 0, 0, 500,700, hMenuDC, 0, 0, SRCCOPY);

	f_keyboard(hWnd);
	
	if (select_menu) {
		switch (current_menu) {
		case 0:
			f_init(hWnd);
			player.blife = TRUE;
			status = status_play;
			SetTimer(hWnd, 3, 1000, NULL);
			break;
		case 1:
			KillTimer(hWnd, 1);
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_TUTORIAL), hWnd, DlgProc);
			break;
		case 2:
			KillTimer(hWnd, 1);
			f_ScoreBoard(hWnd);
			break;
		case 3:
			KillTimer(hWnd, 1);
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_SETTING), hWnd, DlgProc);
			break;
		case 4:
			SendMessage(hWnd, WM_DESTROY, NULL, NULL);
			break;
		}
	}
	else {
		hBMOldMenu = (HBITMAP)SelectObject(hMenuDC, hBMArrowMenu);
		TransparentBlt(hBufDC, xaxis, yaxis[current_menu], 50, 30, hMenuDC, 0, 0, 50, 30, RGB(240, 248, 255));
	}
	SelectObject(hMenuDC, hBMOldMenu);
	SelectObject(hBufDC, hBMOldBuf);

	DeleteDC(hMenuDC);
	DeleteDC(hBufDC);

	ReleaseDC(hWnd, hDC);

	InvalidateRect(hWnd, NULL, FALSE);
}

void g_play(HWND hWnd) {
	RECT rt;
	GetClientRect(hWnd, &rt);
	HDC hDC = GetDC(hWnd);
	HDC hBufDC, hStageDC;
	HBITMAP hBMOldBuf, hBMOldStage;

	
	if (hBMDBuf == NULL) {
		hBMDBuf = CreateCompatibleBitmap(hDC, rt.right, rt.bottom);
	}

	hBufDC = CreateCompatibleDC(hDC);
	hBMOldBuf = (HBITMAP)SelectObject(hBufDC, hBMDBuf);

	hStageDC = CreateCompatibleDC(hDC);
	hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMStage);

	BitBlt(hBufDC, 0, 0, rt.right, rt.bottom, hStageDC, 0, nstage, SRCCOPY);

	if (!bEnd) {
		nstage -= 3;
		if (nstage <= 0) {
			nstage = 2048 - rt.bottom;
			nStageCount++;
		}
		if (nStageCount > 10)
		{
			bEnd = TRUE;
			status = status_end;
		}
	}
	if (player_life==0) {
		bEnd = TRUE;
		status = status_end;
		return;
	}
	f_enemy_move(hWnd);
	f_keyboard(hWnd);
	f_bullet_player(hWnd);
	f_bullet_enemy(hWnd);
	for (int i = 0; i < enemy_num_max; i++) {
		if (enemy[i].blife) {
			switch (enemy[i].type) {
			case 0:
			case 1:
			case 2:
				SelectObject(hStageDC, hBMEnemy[enemy[i].type]);
				TransparentBlt(hBufDC, enemy[i].x, enemy[i].y, 40, 35, hStageDC, 0, 0, 40, 35, RGB(240, 248, 255));
				break;
			case 3:
				SelectObject(hStageDC, hBMEnemy[3]);
				TransparentBlt(hBufDC, enemy[i].x, enemy[i].y, 80, 45, hStageDC, 0, 0, 80, 45, RGB(240, 248, 255));
			}
		}
	}

	for (int i = 0; i < enemy_num_max; i++) {
		if (enemy[i].blife) {
			for (int j = 0; j < enemy_bullet_max; j++) {
				if (enemy_bullet[i][j].blife) {
					SelectObject(hStageDC, hBMBullet_e);
					TransparentBlt(hBufDC, enemy_bullet[i][j].x, enemy_bullet[i][j].y, 15, 15, hStageDC, 0, 0, 15, 15, RGB(255, 255, 255));
				}
			}
		}
	}
	SelectObject(hStageDC, hBMCrash);
	for (int i = 0; i < 11; i++) {
		if (!crash[i].blife)
			continue;
		TransparentBlt(hBufDC, crash[i].x, crash[i].y, 60, 60, hStageDC, 0, 0, 60, 60, RGB(255, 255, 255));
	}
	if (bPlayerAlive) {
		for (int i = 0; i < player_bullet_max; i++) {
			if (bullet_player[i].blife) {
				SelectObject(hStageDC, hBMBullet_p);
				TransparentBlt(hBufDC, bullet_player[i].x, bullet_player[i].y, 7, 30, hStageDC, 0, 0, 7, 30, RGB(255, 255, 255));
			}
		}
		SelectObject(hStageDC, hBMPlayer);
		TransparentBlt(hBufDC, player.x, player.y, 60, 53, hStageDC, 0, 0, 60, 53, RGB(240, 248, 255));
	}

	SelectObject(hStageDC, hBMOldStage);
	SelectObject(hBufDC, hBMOldBuf);

	DeleteDC(hStageDC);
	DeleteDC(hBufDC);

	ReleaseDC(hWnd, hDC);

	InvalidateRect(hWnd, NULL, FALSE);
}
void g_end(HWND hWnd) {
	KillTimer(hWnd, 1);
	KillTimer(hWnd, 3);
	DialogBox(g_hInst, MAKEINTRESOURCE(IDD_GAME_END), hWnd, DlgProc_e);
}
void f_init(HWND hWnd) {
	RECT rt;
	GetClientRect(hWnd, &rt);
	bPlayerAlive = TRUE;
	player.x = (rt.right / 2) - 30;
	player.y = rt.bottom - 100;
}
void f_keyboard(HWND hWnd) {
	RECT rt;
	GetClientRect(hWnd, &rt);
	static int nbullet = 0;
	static int count = 0;
	switch (status) {
	case status_start:
		if (GetAsyncKeyState(VK_SPACE)) {
			status = status_menu;
		}
		break;
	case status_menu:
		if (!select_menu)
		{
			if (GetAsyncKeyState(VK_DOWN)&0x0001| (GetAsyncKeyState(VK_RIGHT) & 0x0001))
				current_menu = (current_menu + 1) % 5;
			if (GetAsyncKeyState(VK_UP)&0x0001|(GetAsyncKeyState(VK_LEFT) & 0x0001))
				current_menu = (current_menu + 4) % 5;
			if ((GetAsyncKeyState(VK_SPACE)&0x0001)| (GetAsyncKeyState(VK_RETURN) & 0x0001))
				select_menu = TRUE;
		}
		break;
	case status_play:
		if (bPlayerAlive) {
			if (GetAsyncKeyState(VK_DOWN) & 0x8001)
				player.y = (player.y + nPlayerSpeed) >= (rt.bottom - 53) ? rt.bottom - 53 : (player.y + nPlayerSpeed);
			if (GetAsyncKeyState(VK_UP) & 0x8001)
				player.y = (player.y - nPlayerSpeed) <= rt.top ? rt.top: (player.y - nPlayerSpeed);
			if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
				player.x = (player.x + nPlayerSpeed) >= (rt.right - 60) ? rt.right- 60 : (player.x + nPlayerSpeed);
			if (GetAsyncKeyState(VK_LEFT) & 0x8001)
				player.x = (player.x - nPlayerSpeed) <= rt.left ? rt.left : (player.x - nPlayerSpeed);
			if (GetAsyncKeyState(VK_SPACE) & 0x8001) {
				if (count % 3 == 0) {
					if (bullet_player[nbullet].blife == FALSE) {
						bullet_player[nbullet].blife = TRUE;
						bullet_player[nbullet].x = player.x + 27;
						bullet_player[nbullet].y = player.y;
					}
					if (nbullet++ > player_bullet_max) {
						nbullet = 0;
					}
				}
				count++;
			}
		}
		break;
	case status_end:
		break;
	}
}
void f_bullet_player(HWND hWnd) {
	if (!bPlayerAlive) {
		return;
	}
	for (int i = 0; i < player_bullet_max; i++) {
		bullet_player[i].y -= 30;
		if (bullet_player[i].y < -15)
			bullet_player[i].blife = FALSE;

	}
	for (int i = 0; i < player_bullet_max; i++) {
		if (!bullet_player[i].blife)
			continue;
		for (int j = 0; j < enemy_num_max;j++) {
			if (!enemy[j].blife)
				continue;
			if(enemy[j].type!=3)
			{
				if ((bullet_player[i].y < enemy[j].y +30) && (bullet_player[i].y > enemy[j].y-30 ))
				{
					if ((bullet_player[i].x > enemy[j].x+5) && (bullet_player[i].x+7 < enemy[j].x + 35)) {
						bullet_player[i].blife = FALSE;
						enemy[j].blife = FALSE;
						for (int n = 0; n < enemy_bullet_max; n++) {
							enemy_bullet[j][n].blife = FALSE;
						}
						crash[j].blife = TRUE;
						crash[j].x = enemy[j].x;
						crash[j].y = enemy[j].y;
					}
				}
			}
			else {
				if ((bullet_player[i].y < enemy[j].y + 30) && (bullet_player[i].y > enemy[j].y - 30))
				{
					if ((bullet_player[i].x > enemy[j].x + 15) && (bullet_player[i].x + 7 < enemy[j].x + 65)) {
						bullet_player[i].blife = FALSE;
						enemy[j].blife = FALSE;
						crash[j].blife = TRUE;
						crash[j].x = enemy[j].x;
						crash[j].y = enemy[j].y;
					}
				}
			}
		}
	}
}

void f_bullet_enemy(HWND hWnd) {
	for (int i = 0; i < enemy_num_max; i++) {
		for (int j = 0; j < enemy_bullet_max; j++) {
			if (enemy_bullet[i][j].blife) {
				enemy_bullet[i][j].y += 10;
				if (enemy_bullet[i][j].y > 680) {
					enemy_bullet[i][j].blife = FALSE;
				}
				if (player.blife) {
					if (player.x<enemy_bullet[i][j].x + 15 && player.x + 40>enemy_bullet[i][j].x) {
						if (player.y<enemy_bullet[i][j].y + 15 && player.y + 30>enemy_bullet[i][j].y) {
							enemy_bullet[i][j].blife = FALSE;
							player.blife = FALSE;
							crash[10].blife = TRUE;
							crash[10].x = player.x;
							crash[10].y = player.y;
							bPlayerAlive = FALSE;
							SetTimer(hWnd, 4, 2000, NULL);
						}
					}
				}
			}
		}
	}
}
void f_enemy(HWND hWnd) {
	static int nextEnemy = 0;
	int pos[6][2] = { {0,50},{450,50},{150,0},{300,0},{200,0},{400,0} };
	static int made = 0;
	int p;
	if (made >= 20) {
		made = 0;
	}
	nextEnemy = rand() % 4;
	for (int i = 0; i < enemy_num_max; i++) {
		if (enemy[i].blife) {
			for (int j = 0; j < enemy_bullet_max; j++) {
				if (!enemy_bullet[i][j].blife) {
					enemy_bullet[i][j].blife = TRUE;
					enemy_bullet[i][j].type = enemy[i].type;
					enemy_bullet[i][j].x = enemy[i].x + 20;
					enemy_bullet[i][j].y = enemy[i].y + 30;
					break;
				}
			}
		}
	}
	if (nextEnemy == 3) {
		for (int i = 0; i < enemy_num_max; i++) {
			if (!enemy[i].blife) {
				enemy[i].blife = TRUE;
				enemy[i].type = 3;
				p = rand() % 3;
				if (p == 0) {
					enemy[i].x = pos[nextEnemy][0];
					enemy[i].y = pos[nextEnemy][1];
				}
				else if (p == 1) {
					enemy[i].x = pos[nextEnemy+1][0];
					enemy[i].y = pos[nextEnemy+1][1];
				}
				else {
					enemy[i].x = pos[nextEnemy + 2][0];
					enemy[i].y = pos[nextEnemy + 2][1];
				}
				made += 5;
				return;
			}
		}
	}
	for (int i = 0; i < enemy_num_max; i++) {
		if (!enemy[i].blife) {
			enemy[i].blife = TRUE;
			enemy[i].x = pos[nextEnemy][0];
			enemy[i].y = pos[nextEnemy][1];
			enemy[i].type = nextEnemy;
			made += 4;
			return;
		}
	}
	
}
void f_enemy_move(HWND hWnd) {

	for (int i = 0; i < 20; i++) {
		if (enemy[i].blife) {
			switch (enemy[i].type) {
			case 0:
				if (enemy[i].blife) {
					enemy[i].x += 3;
					enemy[i].y += 6;
				}
				if (enemy[i].x >= 480 || enemy[i].y >= 680)
					enemy[i].blife = FALSE;
				break;
			case 1:
				if (enemy[i].blife) {
					enemy[i].x -= 3;
					enemy[i].y += 4;
				}
				if (enemy[i].x <= 20 || enemy[i].y >= 680)
					enemy[i].blife = FALSE;
				break;
			case 2:
				if (enemy[i].blife) {
					if (enemy[i].y < player.y) {
						if (player.x + 30 - enemy[i].x > -20) {
							enemy[i].x += 4;
						}
						if (player.x + 30 - enemy[i].x < 20)
							enemy[i].x -= 4;
					}
					enemy[i].y += 7;
				}
				if (enemy[i].x <= 20 || enemy[i].y >= 680 || enemy[i].x >= 480)
					enemy[i].blife = FALSE;
				break;
			case 3:
				if (enemy[i].blife) {
					enemy[i].y += 5;
				}
				if (enemy[i].y >= 680)
					enemy[i].blife = FALSE;
				break;
			}
			if (player.blife) {
				if (enemy[i].x + 30 > player.x + 10 && enemy[i].x + 10 < player.x + 30) {
					if (enemy[i].y + 30 > player.y&&enemy[i].y < player.y + 30) {
						enemy[i].blife = FALSE;
						player.blife = FALSE;
						crash[10].blife = TRUE;
						crash[10].x = player.x;
						crash[10].y = player.y;
						bPlayerAlive = FALSE;
						SetTimer(hWnd, 4, 2000, NULL);
					}
				}
			}
		}
	}
}
void f_crash(HWND hWnd) {
	for (int i = 0; i < 11; i++) {
		if (crash[i].blife)
			crash[i].blife = FALSE;
	}
}
void f_ScoreBoard(HWND hWnd) {
	DialogBox(g_hInst, MAKEINTRESOURCE(IDD_SCORE), hWnd, DlgProc);
}
void f_reset(HWND hWnd) {
	HDC hDC;
	hDC = GetDC(hWnd);
	RECT rt;
	GetClientRect(hWnd, &rt);
	bEnd = FALSE;
	nstage = 2048-rt.bottom;
	status = status_play;
	player_life = 3;
	nStageCount = 0;
	player.blife = TRUE;
	hBMDBuf = NULL;
	for (int i = 0; i < player_bullet_max; i++) {
		bullet_player[i].blife = FALSE;
	}
	for (int i = 0; i < enemy_num_max; i++) {
		enemy[i].blife = FALSE;
		for (int j = 0; j < enemy_bullet_max; j++) {
			enemy_bullet[i][j].blife = FALSE;
		}
	}
	f_init(hWnd);
	for (int i = 0; i < 11; i++) {
		crash[i].blife = FALSE;
	}
	SetTimer(hWnd, 1, 30, NULL);
	SetTimer(hWnd, 3, 1000, NULL);

	ReleaseDC(hWnd, hDC);
}