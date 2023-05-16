#pragma once
#include "Country.h"
#include <vector>

class Dopobachennia
{
	int general_count;
	int current_count;
	int top;
	Country* countries;
	int** points;
	void ProcessColumn(int);
	void SortTable();
	void SortScores();
public:
	Dopobachennia(int);
	~Dopobachennia();
	void AppendTable(Country*, int**, int);
	void ProcessAll();
	std::vector<Country> GetTop();
};

