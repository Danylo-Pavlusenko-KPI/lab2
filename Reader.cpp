#include "Reader.h"

using namespace std;
namespace fs = std::filesystem;

bool Reader::CheckDirectory() {
	try {
		for (const auto& entry : fs::directory_iterator(dir)) {
			if (entry.path().string().rfind(".csv") == entry.path().string().length() - 4) {
				files.push_back(entry.path().string());
				ifstream file(entry.path());
				int n;
				file >> n;
				general_num += n;
				file.close();
			}
		}
	}
	catch (fs::filesystem_error) { return false; }
	return general_num > 0;
}

vector<string> Reader::ReadFile() {
	vector<string> content;
	ifstream file(files[iterator++]);
	while (!file.eof())
	{
		string buffer;
		getline(file, buffer);
		content.push_back(buffer);
	}
	return content;
}

void Reader::WriteIntoFile(std::vector<Country> to_write) {
	const string file_to_write = "results.csv";
	string path = dir + "\\" + file_to_write;
	ofstream file(path);
	for (int i = 0; i < to_write.size(); i++)
		file << to_write[i].name << ',' << to_write[i].general_score << std::endl;
	file.close();
}
