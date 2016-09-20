#include "TileBoard.h"
#include "ElevenTile.h"

#include <iostream>
#include<fstream>
#include<list>

using namespace std;

int main()
{

	cout << "Starting Eleven Tile solver..." << endl;

	list<string> filenames;

	filenames.push_back("+bb+acb_+ddd+dad2+bb+addd+a_b+dcd.txt");
	filenames.push_back("+db+a_db+cad+ddb2+db+adbd+a_d+bcd.txt");
	filenames.push_back("+_d+adbd+cdd+bab2+db+addd+bad+_bc.txt");
	filenames.push_back("+bc+abdd+_db+dda2+cb+adbd+bdd+_da.txt");
	filenames.push_back("+bd+ad_d+dbd+cab2+bd+_add+cdd+bba.txt");
	filenames.push_back("+cd+abd_+bda+dbd2+cd+adad+bd_+bdb.txt");
	filenames.push_back("+a_+abdc+ddb+dbd2+ba+acd_+dbd+dbd.txt");
	filenames.push_back("+dd+a_dd+bbd+bca2+bd+adad+d_d+bbc.txt");
	filenames.push_back("+dc+aa_b+ddd+bbd2+ca+adbd+_dd+dbb.txt");
	filenames.push_back("+dd+adb_+abd+bcd2+dd+_aad+bdb+cbd.txt");
	filenames.push_back("+db+adb_+cad+ddb2+bd+ad_b+dcd+dba.txt");
	filenames.push_back("+bc+addb+bdd+a_d2+db+ac_b+dad+ddb.txt");
	filenames.push_back("+bd+ad_b+acd+dbd2+bd+_adb+adc+bdd.txt");
	filenames.push_back("+c_+adda+bdd+dbb2+_a+acdd+bdd+dbb.txt");
	filenames.push_back("+bc+abdd+dd_+dab2+bc+addb+dbd+d_a.txt");
	filenames.push_back("+dc+aa_d+bdd+dbb2+cd+ad_b+add+bdb.txt");

	for (string file : filenames) 
	{
		cout << "Solving a new puzzle..." << endl;

		string input = "";
		for (int i = 0; i != 16; i++)
		{
			input += file.at(i);
		}

		string finalState = "";
		for (int i = 17; i != 33; i++)
		{
			finalState += file.at(i);
		}

		ElevenTile puzzle;

		list<string> route = puzzle.iterativeSearch(input, finalState);

		string line1;
		string line2;
		string line3;
		string line4;

		for (string node : route)
		{
			line1 += node.at(0);
			line1 += node.at(1);
			line1 += node.at(2);
			line1 += node.at(3);
			line1 += " ";

			line2 += node.at(4);
			line2 += node.at(5);
			line2 += node.at(6);
			line2 += node.at(7);
			line2 += " ";

			line3 += node.at(8);
			line3 += node.at(9);
			line3 += node.at(10);
			line3 += node.at(11);
			line3 += " ";

			line4 += node.at(12);
			line4 += node.at(13);
			line4 += node.at(14);
			line4 += node.at(15);
			line4 += " ";
		}

		ofstream outputfile;
		outputfile.open(file);
		if (outputfile.is_open())
		{
			outputfile << line1;
			outputfile << line2;
			outputfile << line3;
			outputfile << line4;
			outputfile.close();
		}
		else
		{
			cout << "Unable to open file." << endl;
		}

		cout << " \n Puzzle finished! \n" << endl;

	}

	string val;

	cout << "Type 'end' to end program." << endl;

	while (cin >> val){
		if (val == "end") {
			return 0;
		}
	}

}