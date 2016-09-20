#include "TileBoard.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

class ElevenTile {

public:

	ElevenTile();
	~ElevenTile();
	list<string> iterativeSearch(string, string);
	list<string> depthFirstSearch(string, string, unsigned int);
	list<string> expand_node(TileBoard);

};