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
	static BOOL bNowDraw = FALSE;//�׸��� ��� ǥ�� ����

	switch (iMessage) {
	case WM_LBUTTONDOWN://���콺 ���� ��ư Ŭ����
		x = LOWORD(lParam);//���콺 x��ǥ
		y = HIWORD(lParam);//���콺 y��ǥ 
		bNowDraw = TRUE;//�׸��� ���
		return 0;
	case WM_MOUSEMOVE://���콺�� ������ ���
		if (bNowDraw == TRUE) {//���� �׸��� ����϶�
			hdc = GetDC(hWnd);
			MoveToEx(hdc, x, y, NULL);//ó�� ������ ����
			x = LOWORD(lParam);//�̵��� x��ǥ
			y = HIWORD(lParam);//�̵��� y��ǥ
			LineTo(hdc, x, y);//���׸���
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP://���콺 ���ʹ�ư���� ����
		bNowDraw = FALSE;//�׸��� ��� ����
		return 0;
	case WM_LBUTTONDBLCLK://����Ŭ�� ��
		InvalidateRect(hWnd, NULL, TRUE);//��ü �����
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
