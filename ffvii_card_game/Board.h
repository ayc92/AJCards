#include "Card.h"
#include <vector>


#ifndef BOARD_H
#define BOARD_H

class Board
{

private:
	//vector organized like this: [r1c1, r1c2, r1c3, r2,c1, r2c2, r2c3, r3c1, r3c2, r3c3]
	std::vector <Card> grid;
	int num_cards, num_p1, num_p2;

public:

	//Constructor/Destructor//
	Board();
	~Board();

	//Getter methods//
	int Get_num_p1 ();
	int Get_num_p2 ();
	int Get_num_cards ();
	std::vector <Card> Get_grid ();

	//Setter methods//
	void Set_num_p1 (int val);
	void Set_num_p2 (int val);
	void Set_num_cards (int val);

	//Other Methods//
	int CalcIndex (int row, int col);
	bool isDone ();
	int PlaceCard (int row, int col, Card card);
	std::string toString ();
	void draw ();
};

#endif

