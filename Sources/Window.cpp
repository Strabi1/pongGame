
#include "Window.h"


Window::Window()
{	
}

Window::~Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			// Event fired when the window is created
			Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
			// .. and then stored for later lookup
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
			window->onCreate();
		} break;

		case WM_DESTROY:
		{
			// Event fired when the window is destroyed
			Window* window =(Window*) GetWindowLongPtr(hwnd, GWLP_USERDATA);
			window->onDestroy();
			::PostQuitMessage(0);
		} break;

		case WM_SIZE:
		{
			Window* window =(Window*) GetWindowLongPtr(hwnd, GWLP_USERDATA);
			window->onResize(hwnd);

		} break;

		default:
		{
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
		} break;
	}

	return NULL;
}


bool Window::init()
{
	//Setting up WNDCLASSEX object
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	if (!::RegisterClassEx(&wc)) // If the registration of class will fail, the function will return false
		return false;

	//Creation of the window
	m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "Pong game", WS_OVERLAPPEDWINDOW & (~ WS_THICKFRAME), CW_USEDEFAULT, CW_USEDEFAULT, 1366, 768,
		NULL, NULL, NULL, this);

	//if the creation fail return false
	if (!m_hwnd) 
		return false;

	//show up the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);


	hdc = GetDC(m_hwnd);

	//set this flag to true to indicate that the window is initialized and running
	m_is_run = true;


	return true;
}



#include <stdio.h>
bool Window::broadcast(MSG *msg)
{

	if(!msg)
		return false;

	TranslateMessage(msg);
	DispatchMessage(msg);

	// Render
	StretchDIBits(hdc, 0, 0, buffer_width, buffer_height, 0, 0, buffer_width, buffer_height,
			buffer_memory, &buffer_bitmap_info, DIB_RGB_COLORS, SRCCOPY);

	this->onUpdate();

	Sleep(1);

	return true;
}


bool Window::release()
{
	//Destroy the window
	if (!::DestroyWindow(m_hwnd))
		return false;

	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	m_is_run = false;
}

void Window::onResize(HWND hwnd)
{
	RECT rect;
	
	GetClientRect(hwnd, &rect);

	buffer_width = rect.right - rect.left;
	buffer_height = rect.bottom - rect.top;
	int buffer_size = buffer_width * buffer_height * sizeof(unsigned int);

	if(buffer_memory)
	{
		VirtualFree(buffer_memory, 0, MEM_RELEASE);
	}

	buffer_memory = VirtualAlloc(0, buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	buffer_bitmap_info.bmiHeader.biSize = sizeof(buffer_bitmap_info.bmiHeader);
	buffer_bitmap_info.bmiHeader.biWidth = buffer_width;
	buffer_bitmap_info.bmiHeader.biHeight = buffer_height;
	buffer_bitmap_info.bmiHeader.biPlanes = 1;
	buffer_bitmap_info.bmiHeader.biBitCount = 32;
	buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;
	
}

int Window::getWindowWidth()
{
	return buffer_width;
}

int Window::getWindowHeight()
{
	return buffer_height;
}
