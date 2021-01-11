// VS_2017 ���� first.cpp

#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("Tetris");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)//������ Ŭ���� �Ӽ� ����
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = 0;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd; // hWnd ������ ���������� ����!   

	HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

void DrawScreen(HDC hdc);	//ȭ���� ����ϴ� �Լ�
void MakeNewBrick();		//���ο� ���� ����� �Լ�
int GetAround(int x, int y, int b, int r);	//�긯 �ֺ��� ����ִ��� üũ�ϴ� �Լ�
BOOL MoveDown();	//�긯�� �Ʒ��� �������� �ϴ� �Լ�
void TestFull();
void PrintTile(HDC hdc, int x, int y, int c);	//drawbitmap �Լ��� �̿��� ���ϴ� ����� Ÿ���� ����ϴ� �Լ�
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hbit); //��Ʈ���� ����ϴ� �Լ�

#define BW 10	//������ �ʺ�
#define BH 20	//������ ����
#define random(n)(rand()%n);	//������ �����ϴ� ��ũ��
#define TS 24
struct Point {
	int x, y;
};

Point Shape[][4][4] = {	//����� ���
   { {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2}, {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2} },
   { {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1} },
   { {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1}, {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1} },
   { {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1}, {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1} },
   { {0,0,1,0,1,0,-1,-1}, {0,0,0,-1,0,1,-1,1}, {0,0,-1,0,1,0,1,1}, {0,0,0,-1,1,1,-1} },
   { {0,0,1,0,-1,0,1,-1}, {0,0,0,1,0,-1,-1,-1}, {0,0,1,0,-1,0,-1,1}, {0,0,0,-1,0,1,1,1} },
   { {0,0,-1,0,1,0,0,1}, {0,0,0,-1,0,1,1,0}, {0,0,-1,0,1,0,0,-1}, {0,0,-1,0,0,-1,0,1} },
   { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}},
   { {0,0,0,0,0,-1,1,0}, {0,0,0,0,-1,0,0,-1}, {0,0,0,0,0,1,-1,0},{0,0,0,0,0,1,1,0} },
};

enum { EMPTY, BRICK, WALL = sizeof(Shape) / sizeof(Shape[0]) + 1 };//������� �� �� ����
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot;
int nbrick;
int score;	//���� ����
int bricknum;	//���� ����� ��
enum tag_Status { GAMEOVER, RUNNING, PAUSE };	//���� ����
tag_Status GameStatus;
int Interval;
HBITMAP hBit[11];

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	int i;
	RECT crt;
	int trot;
	HDC hdc;
	PAINTSTRUCT ps;
	int x, y;


	switch (iMessage) {

	case WM_CREATE:	//������ ������ ����
		hWndMain = hWnd;
		SetRect(&crt, 0, 0, (BW + 12) * TS, (BH + 2) * TS);
		AdjustWindowRect(&crt, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, TRUE);	//�۾� ������ ��Ÿ�� ����
		SetWindowPos(hWndMain, NULL, 0, 0, crt.right - crt.left, crt.bottom - crt.top,
			SWP_NOMOVE | SWP_NOZORDER);	//�������� ��ġ�� ����
		GameStatus = GAMEOVER;//������ �������
		srand(GetTickCount());	//������ define�� random�� ����� ���� �ð��ҿ並 srand�� �־���
		for (i = 0; i < 11; i++) {
			hBit[i] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1 + i));	//hBit�� ��Ʈ���̹��� ����
		}
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDM_GAME_START:	//���� ������ ���� ���
			if (GameStatus != GAMEOVER) {
				break;
			}
			for (x = 0; x < BW + 2; x++) {
				for (y = 0; y < BH + 2; y++) {
					board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY; //���� �� �������� ����
				}
			}
			score = 0;//���� �ʱ�ȭ
			bricknum = 0;//�� �� �ʱ�ȭ
			GameStatus = RUNNING;//���ӻ��� ����
			nbrick = random(sizeof(Shape) / sizeof(Shape[0]));	//������ ������ �긯 ���
			MakeNewBrick();//�� ����
			Interval = 1000;//������ 1�ʷ� ����
			SetTimer(hWnd, 1, Interval, NULL);
			break;
		case IDM_GAME_PAUSE:	//�Ͻ�����
			if (GameStatus == RUNNING) {	//�������̸� ����
				GameStatus = PAUSE;
				KillTimer(hWnd, 1);
			}
			else if (GameStatus == PAUSE) {	//�̹� ������ ���¸� �ٽ� ����
				GameStatus = RUNNING;
				SetTimer(hWnd, 1, Interval, NULL);
			}
			break;
		case IDM_GAME_EXIT:	//��������
			DestroyWindow(hWnd);
			break;
		}
		return 0;

	case WM_TIMER:	//������ �ð����� �Ʒ��� �긯�� �����̰�
		if (MoveDown() == TRUE) {
			MakeNewBrick();	//���ο� �긯 ����
		}
		return 0;

	case WM_KEYDOWN:	//�� ����Ű�� �������� ������ ��������� Ȯ���ϰ� �긯�� �̵�
		if (GameStatus != RUNNING || brick == -1)
			return 0;
		switch (wParam) {
		case VK_LEFT://�������� �̵�
			if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {
				ny--;
				InvalidateRect(hWnd, NULL, FALSE);
			}
			break;
		case VK_RIGHT://���������� �̵�
			if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {
				nx++;
				InvalidateRect(hWnd, NULL, FALSE);
			}
			break;

		case VK_UP://ȸ��
			trot = (rot == 3 ? 0 : rot + 1);
			if (GetAround(nx, ny, brick, trot) == EMPTY) {
				rot = trot;
				InvalidateRect(hWnd, NULL, FALSE);
			}
			break;

		case VK_DOWN://����� �Ʒ��� ������ �̵�
			if (MoveDown() == TRUE) { ; }
			MakeNewBrick();
			break;
		case VK_SPACE://����� �Ʒ��� �ٷ� ������
			while (MoveDown() == FALSE) { ; }
			MakeNewBrick();
			break;
		}

		return 0;

	case WM_PAINT:	//DrawScreen �Լ��� �̿��� ȭ�� ���
		hdc = BeginPaint(hWnd, &ps);
		DrawScreen(hdc);
		EndPaint(hWnd, &ps);
		return 0;


	case WM_DESTROY:	//��Ʈ�ʰ� Ÿ�̸� ���� �� ����
		KillTimer(hWndMain, 1);
		for (i = 0; i < 11; i++) {
			DeleteObject(hBit[i]);
		}

		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void DrawScreen(HDC hdc) {// ȭ���� ����ϴ� �Լ�
	int x, y, i;
	TCHAR str[128];

	//�׵θ� �׸�
	for (x = 0; x < BW + 1; x++) {
		PrintTile(hdc, x, 0, WALL);
		PrintTile(hdc, x, BH + 1, WALL);
	}
	for (y = 0; y < BH + 2; y++) {
		PrintTile(hdc, 0, y, WALL);
		PrintTile(hdc, BW + 1, y, WALL);
	}

	//������ �׸�
	for (x = 1; x < BW + 1; x++) {
		for (y = 1; y < BH + 1; y++) {
			PrintTile(hdc, x, y, board[x][y]);

		}
	}

	//�̵����� ���� �׸�
	if (GameStatus != GAMEOVER && brick != -1) {
		for (i = 0; i < 4; i++) {
			PrintTile(hdc, nx + Shape[brick][rot][i].x, ny + Shape[brick][rot][i].y, brick + 1);
		}
	}

	//���� ���� �׸�
	for (x = BW + 3; x <= BW + 11; x++) {
		for (y = BH - 5; y <= BH + 1; y++) {
			if (x == BW + 3 || x == BW + 11 || y == BH - 5 || y == BH + 1) {
				PrintTile(hdc, x, y, WALL);
			}
			else {
				PrintTile(hdc, x, y, 0);
			}
		}
	}

	if (GameStatus != GAMEOVER) {
		for (i = 0; i < 4; i++) {
			PrintTile(hdc, BW + 7 + Shape[nbrick][0][i].x, BH - 2 + Shape[nbrick][0][i].y, nbrick + 1);

		}
	}

	//���� ���
	lstrcpy(str, TEXT("Tetrix Ver 1.2"));
	TextOut(hdc, (BW + 4)*TS, 30, str, lstrlen(str));
	wsprintf(str, TEXT("���� : %d    "), score);
	TextOut(hdc, (BW + 4)*TS, 60, str, lstrlen(str));
	wsprintf(str, TEXT("���� : %d ��"), bricknum);
	TextOut(hdc, (BW + 4)*TS, 80, str, lstrlen(str));
}

void MakeNewBrick() {	//���ο� �긯�� ����� �Լ�
	bricknum++;//���� �߰�
	brick = nbrick;
	nbrick = random(sizeof(Shape) / sizeof(Shape[0]));	//������ ������ �긯 ��� ����
	nx = BW / 2;
	ny = 3;
	rot = 0;
	InvalidateRect(hWndMain, NULL, FALSE);
	if (GetAround(nx, ny, brick, rot) != EMPTY) {	//���� ������� �긯 ������ ������� ������ ���ӿ���
		KillTimer(hWndMain, 1);
		GameStatus = GAMEOVER;
		MessageBox(hWndMain, TEXT("������ �������ϴ�. �ٽý����Ϸ��� ����/����")
			TEXT("�׸�(S) �� ������ �ֽʽÿ�."), TEXT("�˸�"), MB_OK);
	}
}

int GetAround(int x, int y, int b, int r) {	//������ ����ִ� �������� üũ
	int i, k = EMPTY;

	for (i = 0; i < 4; i++) {
		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	}
	return k;
}

BOOL MoveDown() {	//�Ʒ��� �������� �Լ�

	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {
		TestFull();
		return TRUE;
	}
	ny++;
	//��� �׷��� ������ �������� ����� �����ش�
	InvalidateRect(hWndMain, NULL, FALSE);
	UpdateWindow(hWndMain);

	return FALSE;
}
//�� ���� ���� ���� ������
void TestFull() {
	int i, x, y, ty;
	int count = 0;
	static int arScoreInc[] = { 0,1,3,8,20 };

	for (i = 0; i < 4; i++) {
		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = brick + 1;
	}
	brick = -1;//�̵����� ���� ���� ����
	for (y = 1; y < BH + 1; y++) {
		for (x = 1; x < BW + 1; x++) {
			if (board[x][y] == EMPTY)break;
		}
		if (x == BW + 1) {	//������ ���� á����
			count++;
			for (ty = y; ty > 1; ty--) {
				for (x = 1; x < BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}
			InvalidateRect(hWndMain, NULL, FALSE);
			UpdateWindow(hWndMain);
			Sleep(150);//���� ����� ���
		}
	}
	score += arScoreInc[count];//���� �߰�
	if (bricknum % 10 == 0 && Interval > 200) {//���� 10�� �������� �������� �ֱⰡ �ö�
		Interval -= 50;
		SetTimer(hWndMain, 1, Interval, NULL);
	}
}

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit) {//��Ʈ���� �̿��ؼ� ���� ���� �׸�
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);

	DeleteDC(MemDC);
}

void PrintTile(HDC hdc, int x, int y, int c) {//DrawBitmap�� �׸� ��ġ�� Ÿ�� ������ ����
	DrawBitmap(hdc, x*TS, y*TS, hBit[c]);
}