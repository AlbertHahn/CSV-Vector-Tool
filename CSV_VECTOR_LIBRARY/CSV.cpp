#include "CSV.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <ctime>

// Constructor
CSV::CSV() :inputFile()
{

}
// Destructor
CSV::~CSV()
{

}

int CSV::Headercounter(std::fstream& in, int& counter)
{
	std::stringstream ss;
	std::string header;

	// reading the header
	std::getline(in, header);

	ss.clear();
	ss << header;

	// counting the header
	int Headercounter = std::count(header.begin(), header.end(), seperator);

	return counter = Headercounter;
}

void CSV::execute_functions(std::fstream& in, std::string& row, std::vector <std::string>& rows)
{
	std::string search;
	Helper object;
	int options = 0;
	int counter = 0;
	std::cerr << "Choose options by typing in a number" << std::endl;
	std::cerr << "1. Search string" << std::endl;
	std::cerr << "2. Erase string" << std::endl;
	std::cerr << "3. End programm and parse new CSV" << std::endl;
	std::cin >> options;

	switch (options) {
	case 1:
		std::cerr << "Type in a string to find him in the file" << std::endl;
		std::cin >> search;
		object.Searchfor(rows, search);
		execute_functions(in, row, rows);
		break;
	case 2:
		std::cerr << "Type in a string to find him in the file" << std::endl;
		std::cin >> search;
		object.erase(rows, search);
		execute_functions(in, row, rows);
		break;
	case 3:
		std::cout << "Parse new CSV";
		break;


	}
}

void CSV::read(std::fstream& in, std::string& row, std::vector <std::string>& rows)
{
	std::string temp;
	int counter = 0;
	int rowcount = 0;
	int compareStatus[2] = { 0,0 };

	if (!in)
	{
		std::cerr << "Fehler beim Oeffnen der Datei!" << std::endl;
	}
	else {

		Headercounter(in, counter);
		in.seekg(0);

		while (std::getline(in, row, seperator))
		{
			// Push a empty row in the vector if it's empty
			if (row.empty())
			{
				rows.push_back("");
				++rowcount;
			}
			else
			{
				rows.push_back(row);
				++rowcount;
			}
		}


		rowcount = rowcount / counter;
		rowcount = rowcount + 1;


		execute_functions(in, row, rows);

	}

}

void CSV::write(std::vector <std::string>& rows)
{
	Helper object;
	int counter = rows.size();
	std::string timestamp;
	bool error = 0;

	// Adding manipulated and a timestamp to the name of the file 
	tempDateiname += "_manipulated";
	timestamp = object.get_date();
	tempDateiname += timestamp;
	tempDateiname += ".csv";

	File.open(tempDateiname, std::fstream::in | std::fstream::out | std::fstream::trunc);

	std::fstream in_write(tempDateiname);

	if (!in_write)
	{
		error = 1;
	}
	else
	{
		// Writes all the vectors to the new CSV file
		for (int i = 0; i < counter; i++)in_write << rows[i] << seperator;
	}

	if (error == 1)
	{
		std::cerr << "Fehler beim beschreiben der Datei!" << std::endl;
		in_write.close();
	}
	else
	{
		std::cout << "Der Schreibvorgang war Erfolgreich" << std::endl;
		in_write.close();
	}
}

void CSV::StartMenu(void)
{
	std::cout << "*********************************************************************************************" << std::endl;
	std::cout << "*     Please enter the name of your CSV-File stored in the same folder as this programm     *" << std::endl;
	std::cout << "*           The file must have the ending '.csv' You don't have to type it in               *" << std::endl;
	std::cout << "*	                                        Type in the filename:                       *" << std::endl;
	std::cout << "*********************************************************************************************" << std::endl;
}

std::fstream& CSV::Fileopen(std::fstream& inputFile)
{
	std::cin >> Dateiname;
	tempDateiname = Dateiname;

	inputFile.open(Dateiname += ".csv", std::ios::in);

	if (inputFile.fail())
	{
		//std::cerr << "Error: " << strerror(errno);
		exit(0);
	}

	return inputFile;
}

std::fstream& CSV::Closefile(std::fstream& inputFile)
{
	inputFile.close();

	return inputFile;
}


