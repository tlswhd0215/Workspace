// VS_2017 버전 first.cpp

#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("Tetris");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)//윈도우 클래스 속성 설정
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
	hWndMain = hWnd; // hWnd 정보도 전역변수에 저장!   

	HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

void DrawScreen(HDC hdc);	//화면을 출력하는 함수
void MakeNewBrick();		//새로운 블럭을 만드는 함수
int GetAround(int x, int y, int b, int r);	//브릭 주변이 비어있는지 체크하는 함수
BOOL MoveDown();	//브릭을 아래로 내려가게 하는 함수
void TestFull();
void PrintTile(HDC hdc, int x, int y, int c);	//drawbitmap 함수를 이용해 원하는 모양의 타일을 출력하는 함수
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hbit); //비트맵을 출력하는 함수

#define BW 10	//게임판 너비
#define BH 20	//게임판 높이
#define random(n)(rand()%n);	//난수를 생성하는 매크로
#define TS 24
struct Point {
	int x, y;
};

Point Shape[][4][4] = {	//블록의 모양
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

enum { EMPTY, BRICK, WALL = sizeof(Shape) / sizeof(Shape[0]) + 1 };//빈공간과 블럭 벽 지정
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot;
int nbrick;
int score;	//현재 점수
int bricknum;	//사용된 블록의 수
enum tag_Status { GAMEOVER, RUNNING, PAUSE };	//게임 상태
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

	case WM_CREATE:	//생성시 윈도우 구성
		hWndMain = hWnd;
		SetRect(&crt, 0, 0, (BW + 12) * TS, (BH + 2) * TS);
		AdjustWindowRect(&crt, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, TRUE);	//작업 영역과 스타일 지정
		SetWindowPos(hWndMain, NULL, 0, 0, crt.right - crt.left, crt.bottom - crt.top,
			SWP_NOMOVE | SWP_NOZORDER);	//윈도우의 위치를 지정
		GameStatus = GAMEOVER;//게임은 종료상태
		srand(GetTickCount());	//위에서 define된 random의 사용을 위해 시간소요를 srand에 넣어줌
		for (i = 0; i < 11; i++) {
			hBit[i] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1 + i));	//hBit에 비트맵이미지 저장
		}
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDM_GAME_START:	//게임 시작이 눌린 경우
			if (GameStatus != GAMEOVER) {
				break;
			}
			for (x = 0; x < BW + 2; x++) {
				for (y = 0; y < BH + 2; y++) {
					board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY; //벽과 빈 공간들을 만듬
				}
			}
			score = 0;//점수 초기화
			bricknum = 0;//블럭 수 초기화
			GameStatus = RUNNING;//게임상태 변경
			nbrick = random(sizeof(Shape) / sizeof(Shape[0]));	//다음에 내려올 브릭 모양
			MakeNewBrick();//블럭 생성
			Interval = 1000;//간격을 1초로 지정
			SetTimer(hWnd, 1, Interval, NULL);
			break;
		case IDM_GAME_PAUSE:	//일시중지
			if (GameStatus == RUNNING) {	//실행중이면 정지
				GameStatus = PAUSE;
				KillTimer(hWnd, 1);
			}
			else if (GameStatus == PAUSE) {	//이미 중지된 상태면 다시 실행
				GameStatus = RUNNING;
				SetTimer(hWnd, 1, Interval, NULL);
			}
			break;
		case IDM_GAME_EXIT:	//게임종료
			DestroyWindow(hWnd);
			break;
		}
		return 0;

	case WM_TIMER:	//정해진 시간마다 아래로 브릭이 움직이고
		if (MoveDown() == TRUE) {
			MakeNewBrick();	//새로운 브릭 생성
		}
		return 0;

	case WM_KEYDOWN:	//각 방향키가 눌렸을때 주위가 비었는지를 확인하고 브릭을 이동
		if (GameStatus != RUNNING || brick == -1)
			return 0;
		switch (wParam) {
		case VK_LEFT://왼쪽으로 이동
			if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {
				ny--;
				InvalidateRect(hWnd, NULL, FALSE);
			}
			break;
		case VK_RIGHT://오른쪽으로 이동
			if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {
				nx++;
				InvalidateRect(hWnd, NULL, FALSE);
			}
			break;

		case VK_UP://회전
			trot = (rot == 3 ? 0 : rot + 1);
			if (GetAround(nx, ny, brick, trot) == EMPTY) {
				rot = trot;
				InvalidateRect(hWnd, NULL, FALSE);
			}
			break;

		case VK_DOWN://블록이 아래로 빠르게 이동
			if (MoveDown() == TRUE) { ; }
			MakeNewBrick();
			break;
		case VK_SPACE://블록이 아래로 바로 떨어짐
			while (MoveDown() == FALSE) { ; }
			MakeNewBrick();
			break;
		}

		return 0;

	case WM_PAINT:	//DrawScreen 함수를 이용해 화면 출력
		hdc = BeginPaint(hWnd, &ps);
		DrawScreen(hdc);
		EndPaint(hWnd, &ps);
		return 0;


	case WM_DESTROY:	//비트맵과 타이머 제거 후 종료
		KillTimer(hWndMain, 1);
		for (i = 0; i < 11; i++) {
			DeleteObject(hBit[i]);
		}

		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void DrawScreen(HDC hdc) {// 화면을 출력하는 함수
	int x, y, i;
	TCHAR str[128];

	//테두리 그림
	for (x = 0; x < BW + 1; x++) {
		PrintTile(hdc, x, 0, WALL);
		PrintTile(hdc, x, BH + 1, WALL);
	}
	for (y = 0; y < BH + 2; y++) {
		PrintTile(hdc, 0, y, WALL);
		PrintTile(hdc, BW + 1, y, WALL);
	}

	//게임판 그림
	for (x = 1; x < BW + 1; x++) {
		for (y = 1; y < BH + 1; y++) {
			PrintTile(hdc, x, y, board[x][y]);

		}
	}

	//이동중인 벽돌 그림
	if (GameStatus != GAMEOVER && brick != -1) {
		for (i = 0; i < 4; i++) {
			PrintTile(hdc, nx + Shape[brick][rot][i].x, ny + Shape[brick][rot][i].y, brick + 1);
		}
	}

	//다음 벽돌 그림
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

	//정보 출력
	lstrcpy(str, TEXT("Tetrix Ver 1.2"));
	TextOut(hdc, (BW + 4)*TS, 30, str, lstrlen(str));
	wsprintf(str, TEXT("점수 : %d    "), score);
	TextOut(hdc, (BW + 4)*TS, 60, str, lstrlen(str));
	wsprintf(str, TEXT("벽돌 : %d 개"), bricknum);
	TextOut(hdc, (BW + 4)*TS, 80, str, lstrlen(str));
}

void MakeNewBrick() {	//새로운 브릭을 만드는 함수
	bricknum++;//블럭수 추가
	brick = nbrick;
	nbrick = random(sizeof(Shape) / sizeof(Shape[0]));	//다음에 내려올 브릭 모양 설정
	nx = BW / 2;
	ny = 3;
	rot = 0;
	InvalidateRect(hWndMain, NULL, FALSE);
	if (GetAround(nx, ny, brick, rot) != EMPTY) {	//새로 만들어진 브릭 주위가 비어있지 않으면 게임오버
		KillTimer(hWndMain, 1);
		GameStatus = GAMEOVER;
		MessageBox(hWndMain, TEXT("게임이 끝났습니다. 다시시작하려면 게임/시작")
			TEXT("항목(S) 을 선택해 주십시오."), TEXT("알림"), MB_OK);
	}
}

int GetAround(int x, int y, int b, int r) {	//주위가 비어있는 상태인지 체크
	int i, k = EMPTY;

	for (i = 0; i < 4; i++) {
		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	}
	return k;
}

BOOL MoveDown() {	//아래로 떨어지는 함수

	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {
		TestFull();
		return TRUE;
	}
	ny++;
	//즉시 그려서 벽돌이 내려가는 모양을 보여준다
	InvalidateRect(hWndMain, NULL, FALSE);
	UpdateWindow(hWndMain);

	return FALSE;
}
//한 줄이 가득 차면 지워줌
void TestFull() {
	int i, x, y, ty;
	int count = 0;
	static int arScoreInc[] = { 0,1,3,8,20 };

	for (i = 0; i < 4; i++) {
		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = brick + 1;
	}
	brick = -1;//이동중인 블럭이 없는 상태
	for (y = 1; y < BH + 1; y++) {
		for (x = 1; x < BW + 1; x++) {
			if (board[x][y] == EMPTY)break;
		}
		if (x == BW + 1) {	//한줄이 가득 찼을때
			count++;
			for (ty = y; ty > 1; ty--) {
				for (x = 1; x < BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}
			InvalidateRect(hWndMain, NULL, FALSE);
			UpdateWindow(hWndMain);
			Sleep(150);//줄을 지우고 대기
		}
	}
	score += arScoreInc[count];//점수 추가
	if (bricknum % 10 == 0 && Interval > 200) {//블럭이 10개 떨어지면 떨어지는 주기가 올라감
		Interval -= 50;
		SetTimer(hWndMain, 1, Interval, NULL);
	}
}

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit) {//비트맵을 이용해서 실제 블럭을 그림
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

void PrintTile(HDC hdc, int x, int y, int c) {//DrawBitmap에 그릴 위치와 타일 종류를 전달
	DrawBitmap(hdc, x*TS, y*TS, hBit[c]);
}