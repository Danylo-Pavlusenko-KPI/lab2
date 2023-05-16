#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Country.h"

class Reader
{
	std::string dir;
	std::vector<std::string> files;
	int iterator = 0;
	int general_num = 0;
public:
	Reader(std::string _dir) : dir(_dir) {}
	bool CheckDirectory();
	std::vector<std::string> ReadFile();
	int GetCountriesNum() { return general_num; }
	int GetFilesNum() { return files.size(); }
	std::string GetFileName(int pos) { return files[pos]; }
	void WriteIntoFile(std::vector<Country>);
};


