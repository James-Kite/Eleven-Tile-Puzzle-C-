#include "TileBoard.h"

TileBoard::TileBoard(string input_state, string final_state)
{
	this->state = input_state;
	this->final_state = final_state;
}


TileBoard::~TileBoard()
{
}

string TileBoard::getState()
{
	return this->state;
}

int TileBoard::return_blank()
{
	for (unsigned int i = 0; i != this->state.length(); i++)
	{
		if (this->state.at(i) == '_')
		{
			return i;
		}
	}
}

string TileBoard::return_up()
{
	int blank = this->return_blank();
	string result = "";
	if (blank > 3 && this->state.at(blank - 4) != '+')
	{
		for (unsigned int i = 0; i != this->state.length(); i++)
		{
			if (i == blank - 4)
			{
				result += this->state.at(blank);
			} 
			else if (i == blank)
			{
				result += this->state.at(blank - 4);
			}
			else
			{
				result += this->state.at(i);
			}
		}
		return result;
	}
	else 
	{
		return "";
	}
}

string TileBoard::return_right()
{
	int blank = this->return_blank();
	string result = "";
	if (blank != 3 && blank != 7 && blank != 11 && blank != 15 && this->state.at(blank + 1) != '+')
	{
		for (unsigned int i = 0; i != this->state.length(); i++)
		{
			if (i == blank + 1)
			{
				result += this->state.at(blank);
			}
			else if (i == blank)
			{
				result += this->state.at(blank + 1);
			}
			else
			{
				result += this->state.at(i);
			}
		}
		return result;
	}
	else
	{
		return "";
	}
}

string TileBoard::return_down()
{
	int blank = this->return_blank();
	string result = "";
	if (blank < 12 && this->state.at(blank + 4) != '+')
	{
		for (unsigned int i = 0; i != this->state.length(); i++)
		{
			if (i == blank + 4)
			{
				result += this->state.at(blank);
			}
			else if (i == blank)
			{
				result += this->state.at(blank + 4);
			}
			else
			{
				result += this->state.at(i);
			}
		}
		return result;
	}
	else
	{
		return "";
	}
}

string TileBoard::return_left()
{
	int blank = this->return_blank();
	string result = "";
	if (blank != 0 && blank != 4 && blank != 8 && blank != 12 && this->state.at(blank - 1) != '+')
	{
		for (unsigned int i = 0; i != this->state.length(); i++)
		{
			if (i == blank - 1)
			{
				result += this->state.at(blank);
			}
			else if (i == blank)
			{
				result += this->state.at(blank - 1);
			}
			else
			{
				result += this->state.at(i);
			}
		}
		return result;
	}
	else
	{
		return "";
	}
}

