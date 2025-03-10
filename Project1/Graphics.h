#pragma once
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <random>
#include <cmath>
using namespace std;
HWND hWnd;

class Graphics
{
private:
	static HPEN hPen;
	static HBRUSH hBrush;
	static int wid, heg;
public:
	static HDC dc;
	static void Set_pen(HDC, COLORREF, int);
	static void Set_brush(HDC, COLORREF, bool);
	static void Line(HDC, int, int, int, int);
	static int GetWid() { return wid; }
	static int GetHeg() { return heg; }

	static void InitGraphics(HWND);
	~Graphics();
};
HBRUSH Graphics::hBrush = NULL;
HPEN Graphics::hPen = NULL;
HDC Graphics::dc = NULL;
int Graphics::wid = 0;
int Graphics::heg = 0;

void Graphics::InitGraphics(HWND hWnd)
{
	dc = GetDC(hWnd);
	RECT rect;
	GetClientRect(hWnd, &rect);
	wid = rect.right;
	heg = rect.bottom;
	Set_pen(dc, RGB(255, 255, 255), 1);
	Set_brush(dc, RGB(255, 255, 255), true);
}

Graphics::~Graphics()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(hWnd, dc);
	DeleteDC(dc);
}

void Graphics::Set_pen(HDC dc, COLORREF col, int w)
{
	hPen = CreatePen(PS_INSIDEFRAME, w, col);
	SelectObject(dc, hPen);
}

void Graphics::Set_brush(HDC dc, COLORREF col, bool empty)
{
	empty ? hBrush = ::CreateSolidBrush(col) : 
			hBrush = ::CreateSolidBrush(NULL_BRUSH);
	::SelectObject(dc, hBrush);
}

void Graphics::Line(HDC dc, int x1, int y1, int x2, int y2)
{
	MoveToEx(dc, x1, y1, NULL);
	LineTo(dc, x2, y2);
}

typedef Graphics gr;