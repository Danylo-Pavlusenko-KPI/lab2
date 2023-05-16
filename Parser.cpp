#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <format>

bool Parser::is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

Parser::Parser(std::vector<std::string> _content, int _general_count, std::string _filename) {
	content = _content;
	general_count = _general_count;
	filename = _filename;
	if (!is_number(content[0])) {
		std::string error_message = std::format("Problem with line 1 in file {}\n", filename);
		throw error_message;
	}
	file_count = stoi(content[0]);
	countries = new Country[file_count];
	points = new int* [general_count];
	for (int i = 0; i < general_count; i++) {
		points[i] = new int[general_count];
	}
}

Parser::~Parser() {
	delete[] countries;
	for (int i = 0; i < general_count; i++) {
		delete[] points[i];
	}
	delete[] points;
}



void Parser::ProcessFile() {
	for (int i = 0; i < file_count; i++) {
		std::stringstream line(content[i + 1]);
		std::getline(line, countries[i].name, ',');
		std::string buffer;
		for (int j = 0; j < general_count; j++) {
			std::getline(line, buffer, ',');
			if (!is_number(buffer)) {
				std::string error_message = std::format("Problem with line: {}, column: {} in file {}\n", i + 2, j + 2, filename);
				throw error_message;
			}
			points[i][j] = stoi(buffer);
		}
	}
}


Country* Parser::GetCountries() {
	Country* to_return = new Country[file_count];
	for (int i = 0; i < file_count; i++) {
		to_return[i] = countries[i];
	}
	return to_return;
}

int** Parser::GetPoints() {
	int** to_return = new int* [general_count];
	for (int i = 0; i < general_count; i++) {
		to_return[i] = new int[general_count];
		for (int j = 0; j < general_count; j++) {
			to_return[i][j] = points[i][j];
		}
	}
	return to_return;
}

int Parser::GetCount() {
	return file_count;
}
