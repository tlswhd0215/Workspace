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
	hWndMain = hWnd; // hWnd ������ ���������� ����!

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
	case WM_LBUTTONDOWN:		//���� ��ư ��������
		sx = LOWORD(lParam);	//��ǥ ����
		sy = HIWORD(lParam);
		oldx = sx;
		oldy = sy;			
		bNowDraw = TRUE;		//�׸��� ���
		return 0;
	case WM_MOUSEMOVE:			//���콺�� �����϶�
		if (bNowDraw) {			//�׸��Ⱑ ���Ǿ� ������
			hdc = GetDC(hWnd);
			SetROP2(hdc, R2_NOT);//������ �׸� ���� ������Ŵ (������� ���̰� ��)
			MoveToEx(hdc, sx, sy, NULL);//�� �׸���
			LineTo(hdc, oldx, oldy);
			oldx = LOWORD(lParam);
			oldy = HIWORD(lParam);
			MoveToEx(hdc, sx, sy, NULL);//�ٽ� �׷��� ������� ������Ŵ
			LineTo(hdc, oldx, oldy);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP:			//��Ŭ���� ������
		bNowDraw = FALSE;		//�׸��� ��� ����
		hdc = GetDC(hWnd);
		MoveToEx(hdc, sx, sy, NULL);//����ġ�� �� �׸���
		LineTo(hdc, oldx, oldy);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
