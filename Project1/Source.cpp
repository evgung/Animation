#include "Graphics.h"
#include "Fire.h"
#include "Human.h"
#include "Bubble.h"

int main()
{
	srand((unsigned)time(NULL));
	system("mode con cols=160 lines=45");
	
	hWnd = GetConsoleWindow();
	gr::InitGraphics(hWnd);
	int wid = gr::GetWid();
	int heg = gr::GetHeg();

	// Фон
	COLORREF back = RGB(10, 10, 10);
	gr::Set_pen(gr::dc, back, 1);
	gr::Set_brush(gr::dc, back, 1);
	Sleep(30);
	Rectangle(gr::dc, 0, 0, wid, heg);
	
	// Огонь
	Fire fire(back);
	fire.VisBoiler();

	// Человек
	Human human(back, fire);

	int r = rand() % 245 + 10;
	int g = rand() % 245 + 10;
	int b = rand() % 245 + 10;

	human.VisHuman();
	human.VisIngr(r, g, b);

	// Пузырьки
	Bubble bubble(back, fire);

	int x_center = wid / 2;
	int y_center = 140;

	BYTE key;
	while (true)
	{
		if (!_kbhit())
		{
			fire.VisFire();
			Sleep(400);
			fire.EraseFire();
		}
		else
		{
			key = _getch();
			if (key == 32)
			{
				human.AnimHuman(r, g, b);

				r = rand() % 245 + 10;
				g = rand() % 245 + 10;
				b = rand() % 245 + 10;

				human.SetIngrToDefault();
				human.VisIngr(r, g, b);

				bubble.BubbleFly();
				bubble.AnimBubbles(x_center, y_center, 30, 2);

				fire.VisFire();
				Sleep(800);
				fire.EraseFire();

				bubble.BlowOutBubbles();
			}
		}
	}

	return 0;
}