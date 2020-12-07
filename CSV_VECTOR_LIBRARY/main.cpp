// *Created by Albert Hahn


#include <iostream>
#include <fstream>
#include <string>
#include "CSV.h"


int main(int argc, char** argv)
{
	std::fstream inputFile;
	std::string row;
	std::vector <std::string > rows;

	CSV* r = new CSV();

	r->StartMenu();
	r->Fileopen(inputFile);
	r->read(inputFile, row, rows);
	r->write(rows);
	r->Closefile(inputFile);

	system("PAUSE");
	return 0;
}