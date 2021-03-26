/*
g++ ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

int main()
{
	int xmax = 800;
	int ymax = 1000;
	Point p {100,100};
	Simple_window win{p, xmax, ymax, "Window"};
	
	int x_size = win.x_max();
	int y_size = win.y_max();
	int xgrid = 100;
	int ygrid = 100;
	int gridsqrt = 800;
	
	Lines grid;
	for(int x = xgrid; x <= gridsqrt; x = x+xgrid)
		grid.add(Point(x,0),Point(x,gridsqrt));
	for(int y = ygrid; y <= gridsqrt; y = y+ygrid)
		grid.add(Point(0,y),Point(gridsqrt,y));
		
	win.attach(grid);
	
	Vector_ref <Graph_lib::Rectangle> rectangles;
	for (int i = 0; i < 800; i = i + 100)
	{
		rectangles.push_back(new Graph_lib::Rectangle(Point{ i,i }, 100, 100));
		rectangles[i/100].set_fill_color(Color::red);
		win.attach(rectangles[i/100]);
	}
	
	Image nagy1(Point(100,300), "nagy.jpg");
	Image nagy2(Point(300,300), "nagy.jpg");
	Image nagy3(Point(500,300), "nagy.jpg");	
	win.attach(nagy1);
	win.attach(nagy2);
	win.attach(nagy3);

	int x = 0;
	int y = 0;
	
	for(int i = 0; i >= 0 ; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			Image kicsi(Point(x,y), "kicsi.jpg");
			if(i == 0)
			{
				x = x + 100;	
			}
			if(i == 1)
			{
				y = y + 100;
			}
			if(i == 2)
			{
				x = x - 100;
			}
			if(i == 3)
			{
				y = y - 100;
			}
			win.attach(kicsi);
			win.wait_for_button();
		}
		if (x == 0 && y == 0)
		{
			i = -1;
		}
	}	
}
