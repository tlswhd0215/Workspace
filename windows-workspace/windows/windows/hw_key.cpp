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
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
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
	PAINTSTRUCT ps;
	static TCHAR str[30][256];
	static int x = 50;
	static int y = 50;
	static int line_num = 0;
	int len;
	switch (iMessage) {
	case WM_CHAR:
		switch (wParam) {
		case VK_RETURN://����Ű �Է½�
			x = 50;
			y += 15;//�����ġ ����
			line_num++;//���ڿ� ��ȣ ����
			break;
		case VK_BACK://�齺���̽� �Է½�
			len = _tcslen(str[line_num]);
			if (line_num > 0 && len == 0) {//���� �� �ٿ� ���ڰ� ������
				line_num--;//���ڿ� ��ȣ ����
				y -= 15;//�����ġ ����
				len= _tcslen(str[line_num]);
			}
			else {//���ڰ� ������ 
				str[line_num][len - 1] = 0;//�� ���� ����
				InvalidateRect(hWnd, NULL, TRUE);//��� ����� �ٽ� ����ؼ� ��ȭ Ȯ�� (����� ����̱� ������ ��� ����� �ٽ� ��� Ȯ�� ����)
			}
			break;
		default://�׿� ���� �Է½�
			len = _tcslen(str[line_num]);
			str[line_num][len] = wParam;//str�� ����
			str[line_num][len + 1] = 0;
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i <= line_num; i++) {//�齺���̽��� ���� ��� �������� ������ ��� ���ڿ��� �������
			TextOut(hdc, x, y=i*15, str[i], _tcslen(str[i]));//���� ��ġ�� �ٲ��ָ鼭 ���
		}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
