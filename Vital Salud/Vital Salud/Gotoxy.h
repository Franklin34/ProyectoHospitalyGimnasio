#ifndef GOTOXY_H
#define GOTOXY_H
#include<iostream>
#include"windows.h"

using namespace std;

class Gotoxy {
private:
	int x;
	int y;
public:
	Gotoxy();
	void display(int, int);
};

#endif // !GOTOXY_H