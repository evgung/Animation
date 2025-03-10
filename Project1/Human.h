#pragma once
#include "Graphics.h"
#include "Fire.h"
	
class Human
{
private:
	COLORREF back, human_col, hat_col, hat_border;
	POINT up, down, l_hand, r_hand, l_ingr, r_ingr;
	Fire fire;
	int wid, heg, R;

	void EraseHuman();
	void EraseIngr();

public:
	Human(COLORREF, Fire);
	void VisHuman();
	void VisIngr(int, int, int);
	void SetIngrToDefault();
	void AnimHuman(int, int, int);
};

Human::Human(COLORREF back_, Fire fire_)
{
	wid = gr::GetWid();
	heg = gr::GetHeg();
	fire = fire_;

	back = back_;
	human_col = RGB(197, 208, 230);
	hat_col = RGB(90, 46, 135);
	hat_border = RGB(61, 34, 111);

	R = 40;
	up = { wid / 2 - 240, heg / 2 - 170 };
	down = { wid / 2 - 240, heg / 2 + 20 };
	r_hand = { up.x + 50, up.y + 110 };
	l_hand = { up.x - 50, up.y + 110 };
	l_ingr = { r_hand.x - 15, r_hand.y - 15 };
	r_ingr = { r_hand.x + 15, r_hand.y + 15 };
}

void Human::VisHuman()
{
	gr::Set_pen(gr::dc, human_col, 4);
	gr::Set_brush(gr::dc, back, 1);
	//Sleep(10);

	// Тело
	gr::Line(gr::dc, up.x, up.y, down.x, down.y);

	// Ноги
	gr::Line(gr::dc, down.x, down.y, down.x + 45, down.y + 155);
	gr::Line(gr::dc, down.x + 45, down.y + 155, down.x + 55, down.y + 155);

	gr::Line(gr::dc, down.x, down.y, down.x - 45, down.y + 155);
	gr::Line(gr::dc, down.x - 45, down.y + 155, down.x - 55, down.y + 155);

	// Руки
	gr::Line(gr::dc, up.x, up.y, r_hand.x, r_hand.y);
	gr::Line(gr::dc, up.x, up.y, l_hand.x, l_hand.y);

	// Голова
	Ellipse(gr::dc, up.x - R, up.y - 2 * R, up.x + R, up.y);

	// Лицо
	gr::Line(gr::dc, up.x - 10, up.y - 60, up.x - 10, up.y - 40);
	gr::Line(gr::dc, up.x + 10, up.y - 60, up.x + 10, up.y - 40);
	Arc(gr::dc, up.x - 10, up.y - 30, up.x + 10, up.y - 13, up.x - 10, up.y - 20, up.x + 10, up.y - 20);

	// Шляпа
	gr::Set_pen(gr::dc, hat_border, 3);
	gr::Set_brush(gr::dc, hat_col, 1);
	POINT hat[13] = {
		{up.x - R - 20, up.y - 65},
		{up.x - 20, up.y - 2 * R},
		{up.x - 10, up.y - 2 * R - 30},
		{up.x + 10, up.y - 2 * R - 50},
		{up.x + 40, up.y - 2 * R - 45},
		{up.x + 45, up.y - 2 * R - 20},
		{up.x + 35, up.y - 2 * R - 35},
		{up.x + 18, up.y - 2 * R - 35},
		{up.x + 15, up.y - 2 * R - 25},
		{up.x + 20, up.y - 2 * R},
		{up.x + R + 20, up.y - 65},
		{up.x + 25, up.y - 60},
		{up.x - 25, up.y - 60}
	};
	Polygon(gr::dc, hat, 13);
}

void Human::EraseHuman()
{
	gr::Set_pen(gr::dc, back, 4);
	gr::Set_brush(gr::dc, back, 1);
	//Sleep(10);

	// Тело
	gr::Line(gr::dc, up.x, up.y, down.x, down.y);

	// Руки
	gr::Line(gr::dc, up.x, up.y, r_hand.x, r_hand.y);
	gr::Line(gr::dc, up.x, up.y, l_hand.x, l_hand.y);

	// Голова
	Ellipse(gr::dc, up.x - R, up.y - 2 * R, up.x + R, up.y);

	// Лицо
	gr::Line(gr::dc, up.x - 10, up.y - 60, up.x - 10, up.y - 40);
	gr::Line(gr::dc, up.x + 10, up.y - 60, up.x + 10, up.y - 40);
	Arc(gr::dc, up.x - 10, up.y - 30, up.x + 10, up.y - 13, up.x - 10, up.y - 20, up.x + 10, up.y - 20);

	// Ингредиент
	Ellipse(gr::dc, r_hand.x - 15, r_hand.y - 15, r_hand.x + 15, r_hand.y + 15);

	// Шляпа
	gr::Set_pen(gr::dc, back, 3);
	POINT hat[13] = {
		{up.x - R - 20, up.y - 65},
		{up.x - 20, up.y - 2 * R},
		{up.x - 10, up.y - 2 * R - 30},
		{up.x + 10, up.y - 2 * R - 50},
		{up.x + 40, up.y - 2 * R - 45},
		{up.x + 45, up.y - 2 * R - 20},
		{up.x + 35, up.y - 2 * R - 35},
		{up.x + 18, up.y - 2 * R - 35},
		{up.x + 15, up.y - 2 * R - 25},
		{up.x + 20, up.y - 2 * R},
		{up.x + R + 20, up.y - 65},
		{up.x + 25, up.y - 60},
		{up.x - 25, up.y - 60}
	};
	Polygon(gr::dc, hat, 13);
}

void Human::VisIngr(int r, int g, int b)
{
	// Ингредиент
	gr::Set_pen(gr::dc, RGB(r, g, b), 4);
	gr::Set_brush(gr::dc, RGB(r / 2, g / 2, b / 2), 1);
	//Sleep(10);

	Ellipse(gr::dc, l_ingr.x, l_ingr.y, r_ingr.x, r_ingr.y);
}

void Human::EraseIngr()
{
	gr::Set_pen(gr::dc, back, 4);
	gr::Set_brush(gr::dc, back, 1);
	//Sleep(10);

	Ellipse(gr::dc, l_ingr.x, l_ingr.y, r_ingr.x, r_ingr.y);
}

void Human::SetIngrToDefault()
{
	l_ingr = { r_hand.x - 15, r_hand.y - 15 };
	r_ingr = { r_hand.x + 15, r_hand.y + 15 };
}

void Human::AnimHuman(int r, int g, int b)
{
	// Человек наклоняется
	for (int i = 0; i < 15; i++)
	{
		fire.VisFire();
		Sleep(50);
		fire.EraseFire();
		EraseHuman();

		up.x += 5;
		up.y += 2;
		l_hand.x += 2;
		r_hand.x += 12;
		r_hand.y -= 3;
		VisHuman();

		l_ingr = { r_hand.x - 15, r_hand.y - 15 };
		r_ingr = { r_hand.x + 15, r_hand.y + 15 };
		VisIngr(r, g, b);
	}

	fire.VisFire();
	Sleep(400);
	fire.EraseFire();

	// Ингредиент падает и человек возвращается на место
	while (up.x != wid / 2 - 240 || l_ingr.y < heg / 2 + 1)
	{
		fire.VisFire();
		Sleep(50);
		fire.EraseFire();

		if (up.x != wid / 2 - 240)
		{
			EraseHuman();

			up.x -= 5;
			up.y -= 2;
			l_hand.x -= 2;
			r_hand.x -= 12;
			r_hand.y += 3;
			VisHuman();
		}

		if (l_ingr.y < heg / 2 + 1)
		{
			EraseIngr();
			fire.VisBoiler();

			l_ingr.y += 5;
			r_ingr.y += 5;
			VisIngr(r, g, b);
		}
	}
	fire.VisBoiler();
}