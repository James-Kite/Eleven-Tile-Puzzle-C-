// This class defines the tile board, including methods to get the current state of the board, the state if the blank tile was swapped in a certain direction

#ifndef TILEBOARD_H
#define TILEBOARD_H

#include <string>

using namespace std;

class TileBoard
{
public:
	TileBoard(string, string);
	~TileBoard();
	string getState();
	int return_blank();
	string return_up();
	string return_right();
	string return_down();
	string return_left();
private:
	string state;
	string final_state;
};

#endif // TILEBOARD_H