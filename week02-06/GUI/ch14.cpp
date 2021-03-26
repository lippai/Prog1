/*
g++ ch14.cpp -o ch14
*/
#include "std_lib_facilities.h"

class B1
{
public:
	virtual void vf() const {cout << "B1::vf()" << endl;}
	void f() const {cout << "B1::f()" << endl;}
	virtual void pvf() {cout << "B1::pvf()" << endl;}
};

class D1 : public B1
{
public:
	void vf() const override {cout << "D1::vf()" << endl;}
	void f() const {cout << "D1::f()" << endl;}
	virtual void pvf() {cout << "D1::pvf()" << endl;}
};

class D2 : public D1
{
public:
	virtual void pvf() override {cout << "D2::pvf()" << endl;}
};

class B2
{
public:
	virtual void pvf() {cout << "B1::pvf()" << endl;}
};

class D21 : public B2
{
public:
	string s = "D21::pvf()";
	virtual void pvf() override {cout << s << endl;}
};

class D22 : public B2
{
public:
	int i = 22;
	void pvf() override {cout << i << endl;}
	void f();
};

void call1(B1& x)
{
	
	x.vf();
	x.f();
	x.pvf();
}

void call2(B2& x)
{
	x.pvf();
}

int main()
{
	B1 b1;
	D1 d1;
	
	b1.vf();
	b1.f();
	cout << endl;
	
	call1(d1);
	cout << endl;
	
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	cout << endl;
	
	D21 d21;
	D22 d22;
	call2(d21);
	call2(d22);
}
