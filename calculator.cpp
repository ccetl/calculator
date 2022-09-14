#include <windows.h>
#include <cassert>

#define BUTTON_ONE 10

HWND imput;

int firstinput;

void division() {

}

void plus() {

}

void subtraction() {

}

LRESULT CALLBACK MessageHandler(HWND hWnd, UINT uMSG, WPARAM wParam, LPARAM lParam) {
	switch (uMSG) {
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == BUTTON_ONE)
			firstinput + 1;
		break;
	}
	return DefWindowProc(hWnd, uMSG, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	HWND hWnd;
	WNDCLASS calculator;
	MSG msg;
	HWND h1;
	HWND h2;
	HWND h3;
	HWND h4;
	HWND h5;
	HWND h6;
	HWND h7;
	HWND h8;
	HWND h9;
	HWND durch;
	HWND plus;
	HWND minus;
	HWND mal;
	HWND ist;
	HWND imputshowone;


	calculator = {};
	calculator.style = CS_HREDRAW | CS_VREDRAW;
	calculator.lpfnWndProc = MessageHandler;
	calculator.hInstance = hInstance;
	calculator.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	calculator.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	calculator.lpszClassName = "CalculatorlpszClasc";

	assert(RegisterClass(&calculator));

	hWnd = CreateWindow("CalculatorlpszClasc", "Calculator", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

	h1 = CreateWindow("button", "1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 130, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	h2 = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 130, 130, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	h3 = CreateWindow("button", "3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 130, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);

	h4 = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 190, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	h5 = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 130, 190, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	h6 = CreateWindow("button", "6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 190, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);

	h7 = CreateWindow("button", "7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 250, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	h8 = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 130, 250, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	h9 = CreateWindow("button", "9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 250, 100, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);

	durch = CreateWindow("button", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 130, 150, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	plus = CreateWindow("button", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 70, 245, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	ist = CreateWindow("button", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 265, 70, 245, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	mal = CreateWindow("button", "x", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 190, 150, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);
	minus = CreateWindow("button", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 360, 250, 150, 50, hWnd, (HMENU)BUTTON_ONE, hInstance, NULL);

	imputshowone = CreateWindow("STATIC", "adsad", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 10, 500, 50, hWnd, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	SetForegroundWindow(hWnd);
	UpdateWindow(hWnd);

	while (true) {
		BOOL result = GetMessage(&msg, 0, 0, 0);

		if (result > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			return result;
		}
	}
}