#include <windows.h>
#include <TCHAR.H>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = _T("First");

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
	WndClass.style = CS_HREDRAW | CS_VREDRAW|CS_DBLCLKS;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;

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
	static int x;
	static int y;
	static BOOL bNowDraw = FALSE;//그리기 허용 표시 변수

	switch (iMessage) {
	case WM_LBUTTONDOWN://마우스 왼쪽 버튼 클릭시
		x = LOWORD(lParam);//마우스 x좌표
		y = HIWORD(lParam);//마우스 y좌표 
		bNowDraw = TRUE;//그리기 허용
		return 0;
	case WM_MOUSEMOVE://마우스가 움직일 경우
		if (bNowDraw == TRUE) {//만약 그리기 모드일때
			hdc = GetDC(hWnd);
			MoveToEx(hdc, x, y, NULL);//처음 시작점 선택
			x = LOWORD(lParam);//이동된 x좌표
			y = HIWORD(lParam);//이동된 y좌표
			LineTo(hdc, x, y);//선그리기
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP://마우스 왼쪽버튼에서 떼면
		bNowDraw = FALSE;//그리기 모드 종료
		return 0;
	case WM_LBUTTONDBLCLK://더블클릭 시
		InvalidateRect(hWnd, NULL, TRUE);//전체 지우기
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
