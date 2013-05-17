#include <gl/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <array>
#ifdef APPLE || _APPLE || APPLE || _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifndef CARD_H
#define CARD_H
#define NUM_VALS 4

enum Side {
	LEFT, UP, RIGHT, DOWN,
};

class Card
{

private:
	
	//card name
	std::string card_name;

	//card image
	unsigned char *image;

	//card values in this order: left, up, right, low
	int vals[NUM_VALS];
	
	//possession: 1 = p_1, -1 = p_2
	int possession;

	//position {row, col}
	int pos[2];

public:

	//Constructor/Destructor//
	//Constructor without image argument (unsigned char) is for debugging.
	Card (std::string card_name, int possession, int left, int high, int right, int low);
	Card (std::string card_name, unsigned char *tga, int possession, int left, int high, int right, int low);
	Card();
	~Card();
	//Getters//
	int Get_possession ();
	int Get_left ();
	int Get_up ();
	int Get_right ();
	int Get_down ();
	int Get_row	();
	int Get_col ();
	std::string Get_name ();

	//Setters//
	void Set_pos (int row, int col);

	//Other Methods//
	void ChangePossession ();
	int CompareCard (Card card, Side side);
	void draw (float* vert1, float* vert2, float* vert3, float* vert4);
	std::string toString ();
};

#endif

