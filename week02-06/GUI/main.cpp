/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 600;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Window text"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{500,400}, 100, 50};

	r.set_fill_color(Color::red);
	r.set_style(Line_style(Line_style::dashdot, 2));

	Text t {Point{600,500}, "Yo, graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{200,100}, "badge.jpg"};

	Circle c {Point{400,200}, 100};

	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();

}
