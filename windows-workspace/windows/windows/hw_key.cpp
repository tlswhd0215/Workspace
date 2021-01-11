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
		case VK_RETURN://엔터키 입력시
			x = 50;
			y += 15;//출력위치 조정
			line_num++;//문자열 번호 증가
			break;
		case VK_BACK://백스페이스 입력시
			len = _tcslen(str[line_num]);
			if (line_num > 0 && len == 0) {//만약 그 줄에 문자가 없으면
				line_num--;//문자열 번호 감소
				y -= 15;//출력위치 감소
				len= _tcslen(str[line_num]);
			}
			else {//문자가 있으면 
				str[line_num][len - 1] = 0;//그 문자 지움
				InvalidateRect(hWnd, NULL, TRUE);//모두 지우고 다시 출력해서 변화 확인 (지우기 기능이기 때문에 모두 지우고 다시 써야 확인 가능)
			}
			break;
		default://그외 문자 입력시
			len = _tcslen(str[line_num]);
			str[line_num][len] = wParam;//str에 저장
			str[line_num][len + 1] = 0;
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i <= line_num; i++) {//백스페이스를 사용시 모두 지워지기 때문에 모든 문자열을 출력해줌
			TextOut(hdc, x, y=i*15, str[i], _tcslen(str[i]));//줄의 위치를 바꿔주면서 출력
		}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
