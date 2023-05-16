#pragma once
#include <string>

struct Country
{
	std::string name;
	int points; //for column
	int general_score;
	Country() : name(""), points(0), general_score(0) {};
	bool operator<(const Country& other) const noexcept
	{
		return points < other.points;
	}
	bool operator>(const Country& other) const noexcept
	{
		return points > other.points;
	}
};
