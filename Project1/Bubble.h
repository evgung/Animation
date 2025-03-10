#pragma once
#include "Graphics.h"
#include "Fire.h"

#define PI 3.14159265359

class Bubble
{
private:
	COLORREF bubble_col, bubble_border, light, back;
	Fire fire;
	int x1, y1, wid, heg, x0_light, y0_light, r_light;

	void VisBubble(int, int, int);
	void EraseBubble(int, int, int);

public:
	Bubble(COLORREF, Fire);
	void AnimBubbles(int, int, int, int);
	void BubbleFly();
	void BlowOutBubbles();
};

Bubble::Bubble(COLORREF back_, Fire fire_)
{
	wid = gr::GetWid();
	heg = gr::GetHeg();
	fire = fire_;

	back = back_;
	bubble_col = RGB(27, 117, 167);
	bubble_border = RGB(0, 78, 140);
	light = RGB(201, 227, 242);

	x1 = wid / 2;
	y1 = 140;
	x0_light = 0;
	y0_light = 0;
	r_light = 0;
}

void Bubble::VisBubble(int x0, int y0, int r)
{
	gr::Set_pen(gr::dc, bubble_border, 2);
	gr::Set_brush(gr::dc, bubble_col, 1);
	Ellipse(gr::dc, x0 - r, y0 - r, x0 + r, y0 + r);

	gr::Set_pen(gr::dc, light, 1);
	gr::Set_brush(gr::dc, light, 1);
	x0_light = x0 - r / 2.3;
	y0_light = y0 - r / 2.3;
	r_light = r / 4;
	Ellipse(gr::dc, x0_light - r_light, y0_light - r_light, x0_light + r_light, y0_light + r_light);
}

void Bubble::EraseBubble(int x0, int y0, int r)
{
	gr::Set_pen(gr::dc, back, 2);
	gr::Set_brush(gr::dc, back, 1);
	Ellipse(gr::dc, x0 - r, y0 - r, x0 + r, y0 + r);
}

void Bubble::AnimBubbles(int x0, int y0, int r, int n)
{
	fire.VisFire();
	Sleep(50);
	fire.EraseFire();

	if (n == 0)
		VisBubble(x0, y0, r);
	else
	{
		VisBubble(x0, y0, r);
		int x0_, y0_;
		for (int i = 0; i < 8; i++)
		{
			x0_ = x0 + 2 * r * cos(PI * i / 4);
			y0_ = y0 + 2 * r * sin(PI * i / 4);
			AnimBubbles(x0_, y0_, 0.3 * r, n - 1);
		}
	}
}

void Bubble::BubbleFly()
{
	int x0 = wid / 2, y0 = heg / 2, r = 30;
	while (y0 > y1)
	{
		VisBubble(x0, y0, r);
		fire.VisFire();

		Sleep(50);
		EraseBubble(x0, y0, r);
		fire.EraseFire();
		fire.VisBoiler();
		y0 -= 5;
	}
}

void Bubble::BlowOutBubbles()
{
	gr::Set_pen(gr::dc, back, 1);
	gr::Set_brush(gr::dc, back, 1);
	Rectangle(gr::dc, x1 - 100, y1 - 100, x1 + 100, y1 + 100);

	for (int i = 0; i < 15; i++)
	{
		gr::Set_pen(gr::dc, bubble_col, 2);
		Arc(gr::dc, x1 - 200, y1, x1 + 200, y1 + 350, (x1 + 50) + i * 15, (y1 + 30) + i * 2, x1 + i * 15, y1 + i * 2);
		Arc(gr::dc, x1 - 200, y1, x1 + 200, y1 + 350, x1 - i * 15, y1 + i * 2, (x1 - 50) - i * 15, (y1 + 30) + i * 2);
		Arc(gr::dc, x1 - 200, y1 + 50, x1 + 200, y1 + 400, (x1 + 50) + i * 15, (y1 + 80) + i * 2, x1 + i * 15, y1 + i * 2);
		Arc(gr::dc, x1 - 200, y1 + 50, x1 + 200, y1 + 400, x1 - i * 15, y1 + i * 2, (x1 - 50) - i * 15, (y1 + 80) + i * 2);

		fire.VisFire();
		Sleep(50);
		fire.EraseFire();

		gr::Set_pen(gr::dc, back, 2);
		Arc(gr::dc, x1 - 200, y1, x1 + 200, y1 + 350, (x1 + 50) + i * 15, (y1 + 30) + i * 2, x1 + i * 15, y1 + i * 2);
		Arc(gr::dc, x1 - 200, y1, x1 + 200, y1 + 350, x1 - i * 15, y1 + i * 2, (x1 - 50) - i * 15, (y1 + 30) + i * 2);
		Arc(gr::dc, x1 - 200, y1 + 50, x1 + 200, y1 + 400, (x1 + 50) + i * 15, (y1 + 80) + i * 2, x1 + i * 15, y1 + i * 2);
		Arc(gr::dc, x1 - 200, y1 + 50, x1 + 200, y1 + 400, x1 - i * 15, y1 + i * 2, (x1 - 50) - i * 15, (y1 + 80) + i * 2);
	}
}