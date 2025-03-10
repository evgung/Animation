#pragma once
#include "Graphics.h"

class Fire
{
private:
	COLORREF back, fire_col, pil_col, boiler_col, boiler_border, water_col, wood_col, slice_col;
	POINT ton1[3], ton2[4], ton3[6], ton4[7], ton5[6], ton6[3];
	int wid, heg, x1, x2, y1, y2;
	int r, left, top, right, bottom, left_pil, right_pil;

	void SetCoords();

public:
	Fire() {}
	Fire(COLORREF);
	void VisFire();
	void EraseFire();
	void VisBoiler();
};

Fire::Fire(COLORREF back_)
{
	wid = gr::GetWid();
	heg = gr::GetHeg();

	back = back_;
	fire_col = RGB(255, 79, 0);
	pil_col = RGB(128, 64, 48);
	boiler_col = RGB(80, 80, 80);
	boiler_border = RGB(50, 50, 50);
	water_col = RGB(0, 149, 182);
	wood_col = RGB(119, 37, 13);
	slice_col = RGB(249, 197, 147);

	r = 50;
	left = wid / 2 - r;
	top = heg / 2 - r + 250;
	right = wid / 2 + r;
	bottom = heg / 2 + r + 250;

	left_pil = left - 80;
	right_pil = right + 80;
}

void Fire::SetCoords()
{
	ton1[0] = { left, bottom - r };
	ton1[1] = { rand() % 15 + left - 10, rand() % 10 + bottom - r - 50 };
	ton1[2] = { left + 20, bottom - r };

	ton2[0] = { left + 10, top + 20 };
	ton2[1] = { rand() % 10 + left + 10, rand() % 10 + top - 15 };
	ton2[2] = { rand() % 15 + left + 10, rand() % 15 + top - 50 };
	ton2[3] = { left + 30, top + 5 };

	x1 = rand() % 10 + left + 50;
	y1 = rand() % 20 + top - 30;
	ton3[0] = { left + 15, top + 5 };
	ton3[1] = { left + 30, top };
	ton3[2] = { rand() % 7 + left + 35, rand() % 10 + top - 50 };
	ton3[3] = { rand() % 10 + left + 38, rand() % 20 + top - 85 };
	ton3[4] = { x1, y1 };
	ton3[5] = { left + 55, top };

	x2 = rand() % 10 + right - 20;
	y2 = rand() % 20 + top - 5;
	ton4[0] = { left + 50, top + 5 };
	ton4[1] = { x1, y1 };
	ton4[2] = { rand() % 10 + left + 63, rand() % 10 + top - 55 };
	ton4[3] = { rand() % 10 + left + 70, rand() % 10 + top - 80 };
	ton4[4] = { rand() % 10 + left + 75, rand() % 10 + top - 40 };
	ton4[5] = { x2, y2 };
	ton4[6] = { right - 10, top + 30 };

	ton5[0] = { right - 20, top + 20 };
	ton5[1] = { x2, y2 };
	ton5[2] = { rand() % 5 + right - 7, rand() % 5 + top - 10 };
	ton5[3] = { rand() % 10 + right + 3, rand() % 10 + top - 30 };
	ton5[4] = { right - 5, top + 25 };
	ton5[5] = { right - 1, bottom - r + 5 };

	ton6[0] = { right - 5, top + 25 };
	ton6[1] = { rand() % 10 + right + 5, rand() % 10 + top + 9 };
	ton6[2] = { right - 1, bottom - r + 5 };
}

void Fire::VisFire()
{
	gr::Set_pen(gr::dc, fire_col, 1);
	gr::Set_brush(gr::dc, fire_col, 1);

	SetCoords();

	// Огонь
	Polygon(gr::dc, ton1, 3);
	Polygon(gr::dc, ton2, 4);
	Polygon(gr::dc, ton3, 6);
	Polygon(gr::dc, ton4, 7);
	Polygon(gr::dc, ton5, 6);
	Polygon(gr::dc, ton6, 3);
	Ellipse(gr::dc, left, top, right, bottom);

	// Бревна
	gr::Set_pen(gr::dc, wood_col, 15);
	gr::Line(gr::dc, left + 25, bottom - 10, left - 5, bottom + 10);
	gr::Line(gr::dc, left + 40, bottom - 5, left + 25, bottom + 30);
	gr::Line(gr::dc, right - 45, bottom - 5, right - 30, bottom + 30);
	gr::Line(gr::dc, right - 30, bottom - 10, right, bottom + 13);

	gr::Set_pen(gr::dc, wood_col, 0);
	gr::Set_brush(gr::dc, slice_col, 1);
	Ellipse(gr::dc, left - 13, bottom + 2, left + 3, bottom + 18);
	Ellipse(gr::dc, left + 17, bottom + 22, left + 33, bottom + 38);
	Ellipse(gr::dc, right - 38, bottom + 22, right - 22, bottom + 38);
	Ellipse(gr::dc, right - 8, bottom + 5, right + 8, bottom + 21);

	// Огонь
	gr::Set_pen(gr::dc, fire_col, 1);
	gr::Set_brush(gr::dc, fire_col, 1);
	Ellipse(gr::dc, left, top, right, bottom); 
}

void Fire::EraseFire()
{
	gr::Set_pen(gr::dc, back, 1);
	gr::Set_brush(gr::dc, back, 1);
	//Sleep(10);

	Polygon(gr::dc, ton1, 3);
	Polygon(gr::dc, ton2, 4);
	Polygon(gr::dc, ton3, 6);
	Polygon(gr::dc, ton4, 7);
	Polygon(gr::dc, ton5, 6);
	Polygon(gr::dc, ton6, 3);
}

void Fire::VisBoiler()
{
	gr::Set_pen(gr::dc, pil_col, 10);
	gr::Set_brush(gr::dc, pil_col, 1);
	//Sleep(10);

	// Левая стойка
	gr::Line(gr::dc, left_pil, heg - 20, left_pil, heg / 2);
	gr::Line(gr::dc, left_pil, heg / 2, left_pil + 20, heg / 2 - 50);
	gr::Line(gr::dc, left_pil, heg / 2, left_pil - 20, heg / 2 - 50);

	// Правая стойка
	gr::Line(gr::dc, right_pil, heg - 20, right_pil, heg / 2);
	gr::Line(gr::dc, right_pil, heg / 2, right_pil + 20, heg / 2 - 50);
	gr::Line(gr::dc, right_pil, heg / 2, right_pil - 20, heg / 2 - 50);

	// Правая часть перекладины
	gr::Line(gr::dc, wid / 2, heg / 2 - 20, right_pil + 30, heg / 2 - 20);

	// Котёл
	gr::Set_pen(gr::dc, boiler_border, 5);
	gr::Set_brush(gr::dc, boiler_col, 1);
	//Sleep(10);

	Ellipse(gr::dc, wid / 2 - 60, heg / 2, wid / 2 + 60, heg / 2 + 100);

	gr::Set_brush(gr::dc, water_col, 1);
	//Sleep(10);

	Ellipse(gr::dc, wid / 2 - 50, heg / 2, wid / 2 + 50, heg / 2 + 35);

	Arc(gr::dc, wid / 2 - 40, heg / 2 - 35, wid / 2 + 40, heg / 2 + 40, wid / 2 + 40, heg / 2 + 5, wid / 2 - 42, heg / 2 + 5);
	gr::Line(gr::dc, wid / 2 + 37, heg / 2 + 5, wid / 2 + 37, heg / 2 + 25);

	// Левая часть перекладины
	gr::Set_pen(gr::dc, pil_col, 10);
	gr::Set_brush(gr::dc, pil_col, 1);
	//Sleep(10);

	gr::Line(gr::dc, left_pil - 30, heg / 2 - 20, wid / 2, heg / 2 - 20);
}