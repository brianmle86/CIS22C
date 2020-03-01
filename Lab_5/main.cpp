#include <person.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {
	
	string path, line, content;
	cout << "Enter path";

	getline(cin, path);
	ifstream in;
	in.open(path);
	while (in >> line) {
		content += line;
		content += "|";

	}
	cout << content;
	Person test;
	test.readFile(content);

	in.close();
	return 0;
}