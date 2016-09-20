#include "ElevenTile.h"

using namespace std;

ElevenTile::ElevenTile()
{
}


ElevenTile::~ElevenTile()
{
}

list<string> ElevenTile::iterativeSearch(string start, string end)
{
	for (unsigned int depth = 1; true; depth++)
	{
		cout << "Depth: " << depth << endl;

		list<string> route = depthFirstSearch(start, end, depth);

		int size = route.size();

		if (size > 0)
		{
			return route;
		}

	}
}

list<string> ElevenTile::depthFirstSearch(string start, string end, unsigned int depth)
{
	if (depth == 0)
	{
		// return an empty list
		list<string> output;
		return output;
	}
	else if (start == end)
	{
		list<string> route;
		route.push_back(end);
		return route;
	}
	else
	{
		TileBoard node(start, end);
		list<string> next_nodes = expand_node(node);
		for (string next : next_nodes)
		{
			list<string> route = depthFirstSearch(next, end, depth - 1);
			int size = route.size();
			if (size > 0)
			{
				route.push_front(start);
				return route;
			}
		}
		// return an empty list
		list<string> output;
		return output;
	}
}

list<string> ElevenTile::expand_node(TileBoard node)
{
	list<string> output;
	string up = node.return_up();
	string right = node.return_right();
	string down = node.return_down();
	string left = node.return_left();
	if (up != "")
	{
		output.push_back(up);
	}
	if (right != "")
	{
		output.push_back(right);
	}
	if (down != "")
	{
		output.push_back(down);
	}
	if (left != "") 
	{
		output.push_back(left);
	}
	return output;
}