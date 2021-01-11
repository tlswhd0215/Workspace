#include <windows.h>
#include <TCHAR.H>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = _T("Rop Mode");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd; // hWnd 정보도 전역변수에 저장!

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int sx, sy, oldx, oldy;
	static BOOL bNowDraw = FALSE;

	switch (iMessage) {
	case WM_LBUTTONDOWN:		//왼쪽 버튼 눌렀을때
		sx = LOWORD(lParam);	//좌표 저장
		sy = HIWORD(lParam);
		oldx = sx;
		oldy = sy;			
		bNowDraw = TRUE;		//그리기 허용
		return 0;
	case WM_MOUSEMOVE:			//마우스가 움직일때
		if (bNowDraw) {			//그리기가 허용되어 있으면
			hdc = GetDC(hWnd);
			SetROP2(hdc, R2_NOT);//이전에 그린 선을 반전시킴 (흰색으로 보이게 됨)
			MoveToEx(hdc, sx, sy, NULL);//선 그리기
			LineTo(hdc, oldx, oldy);
			oldx = LOWORD(lParam);
			oldy = HIWORD(lParam);
			MoveToEx(hdc, sx, sy, NULL);//다시 그려서 흰색으로 반전시킴
			LineTo(hdc, oldx, oldy);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP:			//좌클릭이 끝나면
		bNowDraw = FALSE;		//그리기 모드 종료
		hdc = GetDC(hWnd);
		MoveToEx(hdc, sx, sy, NULL);//새위치에 선 그리기
		LineTo(hdc, oldx, oldy);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
