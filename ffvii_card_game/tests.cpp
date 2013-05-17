#include "tests.h"
#include "Board.h"
#include <iostream>


using namespace std;
void test1 () {
	Board game_board = Board();
	//first make two hands of 5 cards each.
	vector <Card> h1;
	h1.push_back(Card("Mario",	1,	6,	8,	10,	7));
	h1.push_back(Card("Luigi",	1,	8,	10,	5,	4));
	h1.push_back(Card("Yoshi",	1,	10,	7,	7,	4));
	h1.push_back(Card("Toad",	1,	6,	6,	4,	8));
	h1.push_back(Card("Peach",	1,	7,	7,	7,	7));

	vector <Card> h2;
	h2.push_back(Card("Lloyd",	-1,	10,	9,	4,	3));
	h2.push_back(Card("Colette",-1,	7,	5,	9,	8));
	h2.push_back(Card("Asbel",	-1, 6,	9,	9,	6));
	h2.push_back(Card("Senel",	-1, 8,	3,	10,	6));
	h2.push_back(Card("Sheena",	-1,	4,	10,	5,	5));

	if (game_board.PlaceCard(2, 0, h1[0]) == 1) {	//destructive (modifies physical board)
		cout << "PlaceCard success!" << endl;
	} else {
		cout << "Place taken!" << endl;
	}
	h1.erase(h1.begin());
	cout << game_board.toString() << endl;
	cout << "DONE!" << endl;
}

void test2 () {
	cout << sizeof(GLfloat) << endl;
}