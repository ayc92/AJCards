#include "Board.h"
#include "functs.h"
#include <iostream>
#include <sstream>

#define DIMENSION 3

int Board::Get_num_p1 () { return num_p1; }
int Board::Get_num_p2 () { return num_p2; }
int Board::Get_num_cards () { return num_cards; }
std::vector <Card> Board::Get_grid () { return grid; }

void Board::Set_num_p1 (int val) { num_p1 = val; }
void Board::Set_num_p2 (int val) { num_p2 = val; }
void Board::Set_num_cards (int val) { num_cards = val; }

//NULL card has params ("NULL", 0, 0, 0, 0, 0)
Board::Board ()
{
	num_p1 = 0;
	num_p2 = 0;
	num_cards = 0;
	grid.resize(DIMENSION * DIMENSION, Card("NULL", 0, 0, 0, 0, 0));
}

Board::~Board (void) {}

int Board::CalcIndex (int row, int col) {
	return 3 * row + col;
}

bool Board::isDone () {
	if (num_cards == DIMENSION * DIMENSION) {
		return true;
	} else {
		return false;
	}
}

//Place card, and check vals with surrounding cards.
//ERROR card has params ("ERROR", 0, 0, 0, 0, 0).
//If card can be placed, return 1. If not, return 0.
int Board::PlaceCard (int row, int col, Card card) {
	int index = CalcIndex(row, col);
	if (grid.at(index).Get_name() == "NULL") {
		grid[index]			= card;
		Card& left_card		= Card ("RANGE_ERROR", 0, 0, 0, 0, 0); //Get surrounding cards
		Card& up_card		= Card ("RANGE_ERROR", 0, 0, 0, 0, 0);
		Card& right_card	= Card ("RANGE_ERROR", 0, 0, 0, 0, 0);
		Card& down_card		= Card ("RANGE_ERROR", 0, 0, 0, 0, 0);
		if (col == 0) {
			right_card		= grid[CalcIndex(row, 1)];
			if (row == 0) {
				down_card	= grid[CalcIndex(1, 0)];
			} else if (row == 2) {
				up_card		= grid[CalcIndex(1, 0)];
			} else {
				up_card		= grid[CalcIndex(0, 0)];
				down_card	= grid[CalcIndex(2, 0)];
			}
		} else if (col == 2) {
			left_card		= grid[CalcIndex(row, 1)];
			if (row == 0) {
				down_card	= grid[CalcIndex(1, 2)];
			} else if (row == 2) {
				up_card		= grid[CalcIndex(1, 2)];
			} else {
				up_card		= grid[CalcIndex(0, 2)];
				down_card	= grid[CalcIndex(2, 2)];
			}
		} else {	//col == 1
			left_card		= grid[CalcIndex(row, 0)];
			right_card		= grid[CalcIndex(row, 2)];
			if (row == 0) {
				down_card	= grid[CalcIndex(1, 1)];
			} else if (row == 2) {
				up_card		= grid[CalcIndex(1, 1)];
			} else {
				up_card		= grid[CalcIndex(0, 1)];
				down_card	= grid[CalcIndex(2, 1)];
			}
		}
		return 1;
	} else {
		return 0;
	}
}

void Board::draw () {
	//draw background
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f (0.5, 0.5, 0.3);
		glVertex3f(0.0, 6.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(3.0, 6.0, 0.0);
		glVertex3f(3.0, 0.0, 0.0);
	glEnd();

	//draw lines
	glBegin(GL_LINES);
		glColor3f (1.0, 1.0, 1.0);
		glVertex3f(0.0, 2.0, 0.0);	//bottom horizontal line
		glVertex3f(3.0, 2.0, 0.0);
		glVertex3f(0.0, 4.0, 0.0);	//top horizontal line
		glVertex3f(3.0, 4.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);	//left vertical line
		glVertex3f(1.0, 6.0, 0.0);
		glVertex3f(2.0, 0.0, 0.0);	//right vertical line
		glVertex3f(2.0, 6.0, 0.0);
	glEnd();
	
}

std::string Board::toString () {
	std::stringstream ss;
	for (int i = 0; i < grid.size(); i++) {
		ss << grid[i].toString();
		if (i < grid.size() - 1) {
			ss << " || ";
		}
	}
	return ss.str();
}