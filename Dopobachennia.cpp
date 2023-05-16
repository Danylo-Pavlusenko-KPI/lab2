#include "Dopobachennia.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Dopobachennia::Dopobachennia(int _general_count) {
	current_count = 0;
	general_count = _general_count;
	countries = new Country[general_count];
	points = new int* [general_count];
	for (int i = 0; i < general_count; i++) {
		points[i] = new int[general_count];
	}
	const int DEFAULT_TOP = 10;
	top = general_count < DEFAULT_TOP ? general_count : DEFAULT_TOP;
}

Dopobachennia::~Dopobachennia() {
	delete[] countries;
	for (int i = 0; i < general_count; i++) {
		delete[] points[i];
	}
	delete[] points;
}

void Dopobachennia::AppendTable(Country* new_c, int** new_p, int count) {
	for (int i = 0; i < count; i++) {
		countries[current_count + i] = new_c[i];
		points[current_count + i] = new_p[i];
	}
	current_count += count;
}


void Dopobachennia::ProcessColumn(int col) {
	const int Points[] = { 12, 10, 8, 7, 6, 5, 4, 3, 2, 1 };
	for (int i = 0; i < general_count; i++) {
		countries[i].points = points[i][col];
	}
	SortTable();
	for (int i = 0; i < top; i++) {
		countries[i].general_score += Points[i];
	}
}

void Dopobachennia::ProcessAll() {
	for (int i = 0; i < general_count; i++)
		ProcessColumn(i);
}


void Dopobachennia::SortTable() {
	for (int i = 0; i < general_count - 1; i++) {
		for (int j = 0; j < general_count - i - 1; j++) {
			if (countries[j] < countries[j + 1]) {
				Country temp_c = countries[j];
				int* temp_p = new int[general_count];
				for (int i = 0; i < general_count; i++) temp_p[i] = points[j][i];

				countries[j] = countries[j + 1];
				for (int i = 0; i < general_count; i++) points[j][i] = points[j + 1][i];

				countries[j + 1] = temp_c;
				for (int i = 0; i < general_count; i++) points[j + 1][i] = temp_p[i];
			}
		}
	}
}


void Dopobachennia::SortScores() {
	for (int i = 0; i < general_count - 1; i++) {
		for (int j = 0; j < general_count - i - 1; j++) {
			if (countries[j].general_score < countries[j + 1].general_score) {
				Country temp = countries[j];
				countries[j] = countries[j + 1];
				countries[j + 1] = temp;
			}
		}
	}
}

std::vector<Country> Dopobachennia::GetTop() {
	SortScores();
	std::vector<Country> result;
	for (int i = 0; i < top; i++) result.push_back(countries[i]);
	return result;
}



