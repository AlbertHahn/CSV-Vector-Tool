#include "CSV.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <ctime>


Helper::Helper()
{}

Helper::~Helper()
{}

// Timestamp function
std::string Helper::get_date(void)
{
#define MAX_DATE 12

	time_t now;
	char the_date[MAX_DATE];

	the_date[0] = '\0';

	now = time(NULL);

	if (now != -1)
	{
		//strftime(the_date, MAX_DATE, "%d_%m_%Y", gmtime(&now));
	}

	return std::string(the_date);
}

// Function to erase certain string with a specific target
void Helper::erase(std::vector <std::string>& rows, std::string search)
{
	int pos = 0;
	int found = -1;
	// Search after one specific string (search) 
	std::vector <std::string >::iterator it = std::find(rows.begin(), rows.end(), search);
	// If the string was found stop
	if (it != rows.end())
	{
		pos = it - rows.begin();
		std::cerr << "String wurde gefunden, auf der Position " + std::to_string(pos) + ".\n\n";

		do {
			found = rows[pos].find(search, found + 1);

			if (found != -1)
			{
				rows[pos] = rows[pos].substr(0, found) + rows[pos].substr(found + search.length());
			}
			std::cerr << "String wurde geloescht.\n\n";

		} while (found != -1);
	}
	// Error Handlingmessage
	else std::cerr << "Der gesuchte String wurde nicht gefunden.\n\n";
}

// Function to searchfor a specific string in a row
// stores the values of specific string 
int  Helper::Searchfor(std::vector <std::string>& rows, std::string search)
{
	int pos = 0;
	// Search after one specific string (search) 
	std::vector <std::string >::iterator it = std::find(rows.begin(), rows.end(), search);
	// If the string was found stop
	if (it != rows.end())
	{

		// Postioning of the vector at search 
		pos = it - rows.begin();
		std::cerr << "String wurde gefunden, auf der Position " + std::to_string(pos) + ".\n\n";
		return pos;
	}

	// Error Handlingmessage
	else std::cerr << "Der gesuchte String wurde nicht gefunden.\n\n"; return 0;
}

void  Helper::replace(std::vector <std::string>& rows, std::string search)
{
	int pos = 0;
	// Search after one specific string (search) 
	std::vector <std::string >::iterator it = std::find(rows.begin(), rows.end(), search);
	// If the string was found stop
	if (it != rows.end())
	{

		// Postioning of the vector at search 
		pos = it - rows.begin();
		rows[pos] = search;
		std::cerr << "String wurde gefunden, auf der Position " + std::to_string(pos) + ".\n\n";
	}

	// Error Handlingmessage
	else std::cerr << "Der gesuchte String wurde nicht gefunden.\n\n";
}

