// VS_2017 버전 first.cpp

#include <windows.h>
#include <TCHAR.H>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = _T("OldObject");
void TestResource(BOOL bUnsel, BOOL bDelete, int num);
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
void TestResource(BOOL bUnsel, BOOL bDelete, int num) {
	HDC hdc;
	HPEN hPen, OldPen;
	int i;
	TCHAR str[256];

	hdc = GetDC(hWndMain);
	for (i = 0; i < num; i++) {
		hPen = CreatePen(PS_SOLID, rand() % 5 + 1, RGB(rand() % 256, rand() % 256, rand() % 256));
		OldPen = (HPEN)SelectObject(hdc, hPen);
		MoveToEx(hdc, rand() % 300, rand() % 200+40, NULL);
		LineTo(hdc, rand() % 300, rand() % 200 + 40);
		if (bUnsel)
			SelectObject(hdc, OldPen);
		if (bDelete)
			DeleteObject(hPen);
		wsprintf(str, _T("%d"), i);
		SetWindowText(hWndMain, str);
	}
	ReleaseDC(hWndMain, hdc);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	LPCTSTR Mes = _T("1:정상적인 경우, 2:선택해제 없이 삭제만 3:삭제하지 않음");
	switch (iMessage) {
	case WM_KEYDOWN:
		switch (wParam) {
		case '1':TestResource(TRUE, TRUE, 10000); break;
		case '2':TestResource(FALSE, TRUE, 10000); break;
		case '3':TestResource(FALSE, FALSE, 10000); break;
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 10, 10, Mes, _tcslen(Mes));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
