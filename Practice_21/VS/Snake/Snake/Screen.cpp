#include "Screen.h"

void Screen::position(int value) {
	*(this->screen + this->snake->getHead().X + this->snake->getHead().Y) = value;
}

Screen::Screen() {
	screen = new int[80 * 25];

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 80; j++) {
			if (i == 0 || i == 24 || j == 0 || j == 79) 
				*(this->screen + j + i * 80) = 1;
			else 
				*(this->screen + j + i * 80) = 0;
		}
	this->snake->createHead();
	this->snake->setHeadX(40);
	this->snake->setHeadY(13 * 80);
	position(this->snake->getHead().initial);
}

void Screen::printScreen() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++){
			if (*(this->screen + j + i * 80) == 0) cout << " ";
			else cout << "#";
		}
		cout << endl;
	}
}

void Screen::borders() {
	if (this->snake->getHead().X == 1 
			|| this->snake->getHead().Y / 80 == 1) 
		this->isIncrease = false;
	else if (this->snake->getHead().X == 78 
			|| this->snake->getHead().Y / 80 == 23 ) 
		this->isIncrease = true;

}

void Screen::move() {
	borders();
	position(0);
	if (this->isVertical) {
		this->snake->setHeadY(((this->isIncrease) ?
			(this->snake->getHead().Y / 80 - 1) : (this->snake->getHead().Y / 80 + 1)) * 80);
	} else {
		this->snake->setHeadX((this->isIncrease) ?
			(this->snake->getHead().X - 1) : (this->snake->getHead().X + 1));
	}
	position(this->snake->getHead().initial);
}

void Screen::moveIntegrator(char i) {
	switch (i){
	case 'w':
		this->isVertical = true;
		this->isIncrease = true;
		break;

	case 'a':
		this->isVertical = false;
		this->isIncrease = true;
		break;

	case 's':
		this->isVertical = true;
		this->isIncrease = false;
		break;

	case 'd':
		this->isVertical = false;
		this->isIncrease = false;
		break;

	default:
		break;
	}
}

//void input(char& i) {
//	cin >> i;
//}

void Screen::game() {
	while (true) {
		system("cls");
		char i = 'w';
		printScreen();
		cout << "Controller: ";
		/*thread controller(input, i);
		controller.detach();*/

		cin >> i;
		moveIntegrator(i);
		move();
		this_thread::sleep_for(chrono::milliseconds(40));
	}
}

Screen::~Screen() {
	delete[] screen;
	delete snake;
}
