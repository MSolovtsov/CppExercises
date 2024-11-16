#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Gamer {
private:
	struct Point {
		int initial = 1;
		int X;
		int Y;
	};

	vector<Point> snake;

public:

	void createHead();

	Point getHead();

	void setHeadX(int value);

	void setHeadY(int value);

	~Gamer();


};

