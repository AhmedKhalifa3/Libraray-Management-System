#include <iostream>
#include <fstream>
#include "Library.h"





int main() {

	fstream file;
	string file_name = "data.txt";
	file.open(file_name, ios::in | ios::out | ios::app);

	if (!file.is_open()) {
		cerr << "Failed to open the file." << std::endl;
		return 1;
	}


	Library lib;
	lib.getFileBooks(file_name);
	int x;
	x = Menue();



	while (x != 7) {
		if (x == 1) {
			Book* book = create_book();
			lib.addBook(book);
			lib.savebooks("data.txt");
		}
		else if (x == 2) {
			string title, unusedline;
			cout << "\nEnter Book Title: ";
			getline(cin, unusedline);
			getline(cin, title);
			lib.deleteBook(title);
			lib.savebooks("data.txt");
		}
		else if (x == 3) {
			lib.displaybooks();
		}
		else if (x == 4) {
			search_for_book(lib);
		}
		else if (x == 5) {
			string title, unusedline;
			cout << "\nEnter Book Title: ";
			getline(cin, unusedline);
			getline(cin, title);
			lib.borrowBook(title);
			lib.savebooks("data.txt");
		}
		else if (x == 6) {
			string title, unusedline;
			cout << "\nEnter Book Title: ";
			getline(cin, unusedline);
			getline(cin, title);
			lib.returnBook(title);
			lib.savebooks("data.txt");
		}
		x = Menue();
	}
	
	file.close();

	return 0;
}