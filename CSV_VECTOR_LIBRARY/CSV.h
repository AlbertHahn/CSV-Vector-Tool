#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>


class CSV
{
private:

	std::string Dateiname;
	std::string tempDateiname;
	std::fstream File;
	std::fstream inputFile;
	char seperator = ',';


public:

	CSV();
	~CSV();
	int Headercounter(std::fstream& in, int& counter);
	void execute_functions(std::fstream& in, std::string& row, std::vector <std::string>& rows);
	void read(std::fstream& in, std::string& row, std::vector <std::string >& rows);
	void write(std::vector <std::string>& rows);

	void StartMenu(void);

	std::fstream& Fileopen(std::fstream& inputFile);
	std::fstream& Closefile(std::fstream& inputFile);


};

class Helper : public CSV
{
public:

	Helper();
	~Helper();

	std::string get_date(void);

	void  replaceAll(std::string& str, const std::string& from, const std::string& to);
	void  erase(std::vector <std::string>& rows, std::string target);
	void  replace(std::vector <std::string>& rows, std::string search);

	int  Searchfor(std::vector <std::string>& rows, std::string search);

};

