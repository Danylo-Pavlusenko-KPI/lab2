#pragma once
#include "Country.h"
#include <vector>

class Parser
{
	std::vector<std::string> content;
	int file_count;
	int general_count;
	std::string filename;
	Country* countries;
	int** points;
	bool is_number(const std::string&);
public:
	Parser(std::vector<std::string>, int, std::string filename);
	~Parser();
	void ProcessFile();
	Country* GetCountries();
	int** GetPoints();
	int GetCount();
};

