/*
g++ drill1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill1 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h" 
#include "Graph.h" 
#include "GUI.h" 

int main()
{
	int xmax = 600;
	int ymax = 400;
	Point tl(100,100);
	Simple_window win{ tl,xmax,ymax,"Window" };
	
	Axis xa(Axis::x, Point(20,ymax/2), xmax-40, 10, "x axis");
	xa.set_color(Color::blue);
	xa.label.set_color(Color::red);
	
	Axis ya(Axis::y, Point(xmax/2,ymax-20), ymax-40, 10, "y axis");
	ya.set_color(Color::blue);
	ya.label.set_color(Color::red);
	
	Function sine(sin, 0, 50,Point(0, 200), 1000,50,50); 
	sine.set_color(Color::black); 
	
	Polygon poly;
	poly.add(Point(490,140));
	poly.add(Point(540,40));
	poly.add(Point(590,140));
	poly.set_color(Color::blue);
	poly.set_style(Line_style::dashdot);
	
	Rectangle r(Point(100,100), 100, 40); 
	r.set_color(Color::yellow);
	r.set_style(Line_style::dashdotdot);
	
	Text t(Point(0, 40), "Space for text message");
	t.set_font(Font::times_bold);
	t.set_font_size(30); 
	
	Image img(Point(200,100), "tree.jpg");
	
	Circle c(Point(100,200),50);
	
	Mark m(Point(100,200), 'x');
	
	//attach//
	win.attach(img);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine); 
	win.attach(poly);
	win.attach(r);
	win.attach(t);
	win.attach(c);
	win.attach(m);
	//attach//
	
	win.wait_for_button();
}
