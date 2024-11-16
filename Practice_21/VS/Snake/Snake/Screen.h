#pragma once
#include <iostream>
#include <thread>
//#include <function>
#include "Gamer.h"

using namespace std;

class Screen : public Gamer {
private:
	int* screen;

	Gamer* snake = new Gamer();

	bool isVertical = true;
	bool isIncrease = true;

	void printScreen();

	void moveIntegrator(char i);

	void borders();

	void position(int value);

	void move();

public:

	Screen();


	void game();

	~Screen();

};

