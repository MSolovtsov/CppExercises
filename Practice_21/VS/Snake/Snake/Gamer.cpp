#include "Gamer.h"


void Gamer::createHead() {
	Point head;
	head.initial = 1;
	snake.push_back(head);
}

Gamer::Point Gamer::getHead() {
	return this->snake[0];
}

void Gamer::setHeadX(int value) {
	this->snake[0].X = value;
}

void Gamer::setHeadY(int value) {
	this->snake[0].Y = value;
}

Gamer::~Gamer() {
	snake.clear();
}