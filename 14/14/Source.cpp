#include <set>
#include <map>
#include <regex>
#include <string>
#include <fstream>
#include <iostream>

struct Edition {
	std::string type; // book or article
	int id;
	std::string author;
	std::string name;
	Edition() {};
};

std::istream& operator >> (std::istream& in, Edition& e) {
	if (!std::getline(in, e.type))
		return in;
	std::getline(in, e.author);
	std::getline(in, e.name);
	if (e.type == "book") {
		// read some other fields
	}
	else if (e.type == "article") {
		// read some other fields
	}
	// skip empty line
	// this line is separator
	while (in.get() != '\n');
	return in;
}

std::ostream& operator << (std::ostream& out, const Edition& e) {
	return out << "    Id: " << e.id << "\n"
		<< "  Type: " << e.type << "\n"
		<< "Author: " << e.author << "\n"
		<< "  Name: " << e.name << "\n";
}

bool contains_word(const std::string& str, const std::string& word) {
	std::regex r("\\b" + word + "\\b");
	std::smatch m;
	return std::regex_search(str, m, r);
}

int main() {

	std::ifstream file("data.txt");
	std::set<std::string> authors;
	std::multimap<std::string, Edition> editions;
	const auto sep = std::string(50, '-');
	Edition edition;
	while (file >> edition) {
		editions.emplace(edition.author, edition);
		authors.insert(edition.author);
	}
	int id = 0;
	for (auto& e : editions)
		e.second.id = ++id;

	for (const auto& e : editions)
		std::cout << e.second << sep << "\n";

	std::string prevAuthor;
	std::ofstream file1("authors.txt");
	for (const auto& author : authors)
		file1 << author << "\n";
	std::ofstream file2("editions.txt");
	std::cout << "Enter word: ";
	std::string word;
	std::getline(std::cin, word);
	for (const auto& e : editions) {
		if (contains_word(e.second.name, word))
			file2 << e.second << "\n";
	}
	return 0;
}