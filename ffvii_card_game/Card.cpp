#include "Card.h"
#include <iostream>
#include <sstream>

using namespace std;

string Card::Get_name		() { return card_name; }
int Card::Get_possession	() { return possession; }
int Card::Get_left			() { return vals[0]; }
int Card::Get_up			() { return vals[1]; }
int Card::Get_right			() { return vals[2]; }
int Card::Get_down			() { return vals[3]; }
int Card::Get_row			() { return pos[0]; }
int Card::Get_col			() { return pos[1]; }

//Card representation of NULL is one instantiated like this: Card ("NULL", 0, 0, 0, 0, 0)
Card::Card (string card_name, int possession, int left, int high, int right, int low) {
	this->card_name = card_name;
	this->possession = possession;
	vals[0] = left;
	vals[1] = high;
	vals[2] = right;
	vals[3] = low;
}

Card::Card (string card_name, unsigned char *tga, int possession, int left, int high, int right, int low) {
	this->card_name = card_name;
	image = tga;
	this->possession = possession;
	vals[0] = left;
	vals[1] = high;
	vals[2] = right;
	vals[3] = low;
}

Card::~Card(void) {}

void Card::Set_pos (int row, int col) {
	pos[0] = row;
	pos[1] = col;
}

void Card::ChangePossession () {
	possession = possession * -1;
}

//side = {left, up, right, down}
int Card::CompareCard (Card card, Side side) {
	switch (side) {
		case LEFT:
			return vals[0] > card.Get_right();
		case UP:
			return vals[1] > card.Get_down();
		case RIGHT:
			return vals[2] > card.Get_left();
		case DOWN:
			return vals[3] > card.Get_up();
		default:
			//temporarily return 65. but will need to change return val.
			return 65;
	}
}

void Card::draw (float* vert1, float* vert2, float* vert3, float* vert4) {
	


}

std::string Card::toString () {
	std::stringstream ss;
	ss << card_name << "(";
	for (int i = 0; i < NUM_VALS; i++) {
		ss << vals[i];
		if (i < NUM_VALS - 1) {
			ss << ",";
		}
	}
	ss << ")";
	return ss.str();
}
