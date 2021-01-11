#include <windows.h>
#include <stdio.h>
#include "resource.h"

void OnTimer(HWND hWnd);  // Ÿ�̸� ����
void OnPaint(HWND hWnd);  // ����Ʈ ����

HINSTANCE g_hInst;

typedef struct ObjectTag
{
	int x; // x��ǥ
	int y; // y��ǥ
	int bLife; // ��� �ִ��� üũ
}Object;

#define MAX 1

Object hero; // ���� ����� ������Ʈ
Object bullet[MAX]; // �̻��� ������Ʈ
Object enemy; // ���� ����� ������Ʈ
Object bong; // ���� ����� ������Ʈ

void Init(HWND hWnd); // �ʱ�ȭ �Լ�
void GetKeyInput(HWND hWnd); // Ű���� ó�� �Լ�
void Bullet(HWND hWnd); // �Ѿ�


LRESULT CALLBACK WndProc(HWND hWnd,  // ��� �Լ� ���ν���
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,     // �� ���� �Լ�
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	g_hInst = hInstance;
	char szTitleName[] = "������ �����ڱ���";   // ���� Ÿ��Ʋ ��

	HWND hWnd;
	MSG msg;
	WNDCLASSEX wnd;

	wnd.cbSize = sizeof(wnd);
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ��׶���� �Ͼ��
	wnd.lpszClassName = szTitleName;
	wnd.lpszMenuName = NULL;

	RegisterClassEx(&wnd);

	hWnd = CreateWindow(szTitleName, szTitleName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL); // ���� ���

	ShowWindow(hWnd, nCmdShow);  // �������� �Լ� �ߵ�
	UpdateWindow(hWnd);  //   ������Ʈ ������ �ߵ�   

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);  // ��� �޼���
		DispatchMessage(&msg);  // �޼��� �߼�
	}

	return msg.wParam;
}

HBITMAP hBMBuf, hBMStage, hBMBullet;  // ���� ȭ�� ,��ŸƮ ȭ�� , �̻��� ȭ��
HBITMAP hBMMyShap[3];  // �Ʊ� 3�� ȭ��
HBITMAP hBMEnemy[3];  // ���� 3�� ȭ��
HBITMAP hBMBong[6];  //����ȭ�� 6��

LRESULT CALLBACK WndProc(HWND hWnd,  // ��� �Լ� ȣ��
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE: {  // �������� ũ����Ʈ �Լ� �ߵ� ù ȭ�� ����Ŀ� �޽��� ó��
		SetTimer(hWnd, 1, 1, NULL);  // Ÿ�̸Ӹ� �츰��
		Init(hWnd);  // ���� �ڵ�

		hBMStage = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_STAGE)); // ��ŸƮ ���ȭ��

		hBMMyShap[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MyShap1)); // ���ΰ� ����� ��Ʈ��1
		hBMMyShap[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MyShap2)); // ���ΰ� ����� ��Ʈ��2
		hBMMyShap[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MyShap3)); // ���ΰ� ����� ��Ʈ��3

		hBMBullet = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Bullet)); // �Ʊ��� ��� �̻��� ��Ʈ�� 

		hBMEnemy[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Enemy1)); // ���� ����� ��Ʈ��1
		hBMEnemy[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Enemy2)); // ���� ����� ��Ʈ��2
		hBMEnemy[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Enemy3)); // ���� ����� ��Ʈ��3

		hBMBong[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG1)); // ������ ���� ��Ʈ�� 1
		hBMBong[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG2)); // ������ ���� ��Ʈ�� 2
		hBMBong[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG3)); // ������ ���� ��Ʈ�� 3
		hBMBong[3] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG4)); // ������ ���� ��Ʈ�� 4
		hBMBong[4] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG5)); // ������ ���� ��Ʈ�� 5
		hBMBong[5] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG6)); // ������ ���� ��Ʈ�� 6
		return FALSE; }
	case WM_TIMER: //SetTimer �Լ��� ���� ���ҷ� Ÿ�̸Ӹ� ��ġ���� ��� ������ �ð� ��������
	 // �� �޽����� �ݺ������� ť�� �ٿ�����
		OnTimer(hWnd);   // OnTimer(HWND hWnd)���� �츰��
		return FALSE;
	case WM_PAINT:
		OnPaint(hWnd);   // OnPaint(HWND hWnd)���� �츰��
		return FALSE;
	case WM_DESTROY:    // �޼��� ���� ���� �޼���
		KillTimer(hWnd, 1);  // Ÿ�̸Ӹ� ���δ�
		DeleteObject(hBMStage);  // hBMStage �� ��� ��ŸƮ ȭ���� �����Ѵ�
		DeleteObject(hBMBuf);    // ������ �����Ѵ�
		PostQuitMessage(0);    // ���̻� �޼��� �������� ����
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void OnTimer(HWND hWnd)
{
	Sleep(30);  // Ÿ�̸Ӹ� 30���� ������
	RECT crt;
	GetClientRect(hWnd, &crt);
	HDC hDC = GetDC(hWnd);
	HDC hBufDC, hStageDC;

	HBITMAP hBMOldBuf, hBMOldStage;

	static BOOL bStop = FALSE;
	static int nStage = 6531 - crt.bottom;
	static int nSWMyShap = 0;  // �Ʊ���
	static int nSWEnemy = 0;   // ������
	static int bBong = 0;      // �������

	if (hBMBuf == NULL)
	{
		hBMBuf = CreateCompatibleBitmap(hDC, crt.right, crt.bottom);
	}

	hBufDC = CreateCompatibleDC(hDC);
	hBMOldBuf = (HBITMAP)SelectObject(hBufDC, hBMBuf);

	// ��� ���
	hStageDC = CreateCompatibleDC(hDC);
	hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMStage);

	BitBlt(hBufDC, 0, 0, crt.right, crt.bottom,
		hStageDC, 0, nStage, SRCCOPY);
	//  ���������� ���� �����ϸ�
	if (bStop == FALSE)  // ���� �׸��ǰ� ���߸�
	{
		nStage -= 3;  // 3�� �ӵ��� ���η� ���ڷ� ���Ѷ�(���� ���� �ӵ��� 0�̸� ȭ���� �����)
		if (nStage <= 0)  // ���� �ӵ��� 0���� ������ �Ʒ� ��ɿ� ������
		{
			bStop = TRUE;   // �̰�쿡 ��ž�Ǵ��� �������� ��� �����϶�
		}

	}

	// Ű���� ó��
	GetKeyInput(hWnd);  // Ű���� �ڵ� ����, ���Լ� ������ Ű���� Ű �۵� �ȵ� 

	// �̻���
	Bullet(hWnd);    // �̻��� �ڵ�ν� �̻����� �����̰� ����� �Լ�

	// �� �����
	if (enemy.bLife == TRUE)
	{
		switch (nSWEnemy)
		{
		case 0:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMEnemy[0]);
			TransparentBlt(hBufDC, enemy.x, enemy.y, 32, 31,
				hStageDC, 0, 0, 32, 31, RGB(0, 255, 0));
			nSWEnemy = 1;
			break;
		case 1:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMEnemy[1]);
			TransparentBlt(hBufDC, enemy.x, enemy.y, 32, 31,
				hStageDC, 0, 0, 32, 31, RGB(0, 255, 0));
			nSWEnemy = 2;
			break;
		case 2:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMEnemy[2]);
			TransparentBlt(hBufDC, enemy.x, enemy.y, 32, 31,
				hStageDC, 0, 0, 32, 31, RGB(0, 255, 0));
			nSWEnemy = 0;
			break;
		}
	}

	// �̻���

	hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBullet);

	for (int i = 0; i < MAX; i++)
	{
		TransparentBlt(hBufDC, bullet[i].x, bullet[i].y, 17, 15,
			hStageDC, 0, 0, 17, 15, RGB(0, 0, 0));
	}

	// ����
	if (bong.bLife == TRUE)
	{
		switch (bBong)
		{
		case 0:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[0]);
			TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
				hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
			bBong = 1;
			break;
		case 1:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[1]);
			TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
				hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
			bBong = 2;
			break;
		case 2:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[2]);
			TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
				hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
			bBong = 3;
			break;
		case 3:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[3]);
			TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
				hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
			bBong = 4;
			break;
		case 4:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[4]);
			TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
				hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
			bBong = 5;
			break;
		case 5:
			hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[5]);
			TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
				hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
			bBong = 0;
			bong.bLife = FALSE;
			enemy.bLife = TRUE;
			break;
		}
	}
	// ���� ����� ���
	switch (nSWMyShap)
	{
	case 0:
		hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMMyShap[0]);
		TransparentBlt(hBufDC, hero.x, hero.y, 57, 42, hStageDC, 0, 0, 57, 42, RGB(0, 255, 0));
		nSWMyShap = 1;
		break;
	case 1:
		hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMMyShap[1]);
		TransparentBlt(hBufDC, hero.x, hero.y, 57, 42, hStageDC, 0, 0, 57, 42, RGB(0, 255, 0));
		nSWMyShap = 2;
		break;
	case 2:
		hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMMyShap[2]);
		TransparentBlt(hBufDC, hero.x, hero.y, 57, 42, hStageDC, 0, 0, 57, 42, RGB(0, 255, 0));
		nSWMyShap = 0;
		break;
	}

	SelectObject(hStageDC, hBMOldStage);
	SelectObject(hBufDC, hBMOldBuf);

	DeleteDC(hStageDC);
	DeleteDC(hBufDC);

	ReleaseDC(hWnd, hDC);

	InvalidateRect(hWnd, NULL, FALSE);
}

void OnPaint(HWND hWnd)
{
	RECT crt;
	GetClientRect(hWnd, &crt);
	PAINTSTRUCT ps;
	HDC hDC = BeginPaint(hWnd, &ps);
	HDC hMemDC;
	HBITMAP hOldBit;


	hMemDC = CreateCompatibleDC(hDC);
	hOldBit = (HBITMAP)SelectObject(hMemDC, hBMBuf);
	BitBlt(hDC, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBit);
	DeleteDC(hMemDC);
	EndPaint(hWnd, &ps);

}

void Init(HWND hWnd)
{
	// ���� ����� �ʱ�ȭ
	RECT crt;
	GetClientRect(hWnd, &crt);

	hero.x = (crt.right / 2) - (57 / 2);
	hero.y = crt.bottom - 100;
	hero.bLife = 3;

	// �Ѿ�
	for (int i = 0; i < MAX; i++)
	{
		bullet[i].bLife = FALSE;
		bullet[i].y = -20;
		bullet[i].x = 10;
	}

	// �� �����
	enemy.bLife = TRUE;
	enemy.x = 0;
	enemy.y = 50;

	// ��
	bong.bLife = FALSE;

}

void GetKeyInput(HWND hWnd)  // Ű���� �Է� ó��
{
	RECT ctr;
	GetClientRect(hWnd, &ctr);
	static int i = 0;

	if (GetAsyncKeyState(VK_LEFT))   // ���� Ű����Ű
	{
		hero.x -= 7;  // x������ 7��ŭ�� �ӵ��� �̵��Ѵ�

		if (hero.x <= 0)
			hero.x = 0;
	}

	if (GetAsyncKeyState(VK_RIGHT)) // ������ Ű����Ű
	{
		hero.x += 7;   // x������ 7��ŭ�� �ӵ��� �̵��Ѵ�

		if (hero.x >= ctr.right - 57)
			hero.x = ctr.right - 57;
	}

	if (GetAsyncKeyState(VK_UP))  // ������ Ű����Ű
	{
		hero.y -= 7;   // v������ 7��ŭ�� �ӵ��� �̵��Ѵ�

		if (hero.y <= 0)
			hero.y = 0;
	}

	if (GetAsyncKeyState(VK_DOWN))  //�Ʒ� ���� Ű����Ű
	{
		hero.y += 7;  // y������ 7��ŭ�� �ӵ��� �̵��Ѵ�

		if (hero.y >= ctr.bottom - 42)
			hero.y = ctr.bottom - 42;
	}

	if (GetAsyncKeyState(VK_SPACE))   // �����̽��� Ű���� Ű
	{
		if (bullet[i].bLife == FALSE)    // ���� �̻����� ������ �ǰ� ���� ���Ѵ�
		{
			bullet[i].bLife = TRUE;  // �̻����� �������� �߻�ȴ�
			bullet[i].x = hero.x + 20; // �̻����� x������ �÷��� 20�ؼ� �߻�ȴ�
			bullet[i].y = hero.y;    // �̻����� v������ �߻�ȴ�
		}
		if (i++ > MAX)
			i = 0;
	}


}

void Bullet(HWND hWnd)
{
	static int nSw = 0;
	if (nSw == 0)
	{
		enemy.x += 7;

		if (enemy.x >= 640 - 32)
		{
			nSw = 1;
		}
	}
	if (nSw == 1)
	{
		enemy.x -= 7;

		if (enemy.x <= 0)
		{
			nSw = 0;
		}
	}



	for (int i = 0; i < MAX; i++)
	{
		bullet[i].y -= 30;   // �̻����� �ӵ��� ��ġ�� �Է�

		// �̻����� ȭ�� ������ ������
		if (bullet[i].y < -15)
			bullet[i].bLife = FALSE; // �������� �����۵����� �ʴ´�

		   // �浹üũ
		if ((bullet[i].y < enemy.y + 31) && (bullet[i].y > enemy.y))
			// �̻��� i�� ������� v������ 31�ȿ� ���������� �浹�϶�
		{
			if ((bullet[i].x > enemy.x) && (bullet[i].x < enemy.x + 32))
				// �̻��� i�� ������� x������ 32�ȿ� ���������� �浹�϶�
			{
				bullet[i].bLife = FALSE;   // �̻����� i���̸� ������ �������� �״´�
				enemy.bLife = FALSE;       // �����Ⱑ �״´�.
				bong.bLife = TRUE;         // ����ȭ���� �߻��ϸ� ȭ�鿡 ��Ÿ���� 
				bong.x = enemy.x;          // ����ȭ���� �������� x�࿡�� �߻��϶�
				bong.y = enemy.y;          // ����ȭ���� �������� v�࿡�� �߻��϶�
			}
		}

	}
}