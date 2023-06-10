
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Library.h"
using namespace std;
fstream file;

Book::Book(string title, string auther, int id, string bublisher, int year) : title(title), auther(auther), id(id), bublisher(bublisher), year(year), available(true){}

Book::~Book() {}

string Book::get_title() const {
	return title;
}

string Book::get_auther() const {
	return auther;
}

int Book::get_id() const {
	return id;
}

string Book::get_bublisher() const {
	return bublisher;
}

int Book::get_year() const {
	return year;
}

bool Book::isAvailable() const {
	return available;
}

void Book::borowBook() {
	available = false;
}

void Book::returnBook() {
	available = true;
}




//////////////////////////////////

Member::Member(string name, string address, string phone, string email) : name(name), address(address), phone(phone), email(email), membership_status(false) {}
string Member:: get_name() const {
	return name;
}

string Member::get_address() const{
	return address;
}

string Member::get_phone() const{
	return phone;
}

string Member::get_email() const{
	return email;
}

bool Member::isMember() const{
	return membership_status;
}

void Member::becomeMember() {
	membership_status = true;
}

void Member::cancelMemebership() {
	membership_status = false;
}

////////////////////////////////////////////////////


Library::~Library() {
	// Free the dynamically allocated memory for the books
	for (Book* book : books) {
		delete book;
	}
	books.clear();
}

void Library::addBook( Book* book) {
	books.push_back(book);
}

void Library::displaybooks() const {
	cout << "\nDisplaying All Library books\n";
	int counter;
	counter = 1;
	for (const Book* book : books) {
		cout << "\nBook[" << counter << ']' << endl;
		cout << "Title = " << book->get_title() << endl;
		cout << "Auther = " << book->get_auther() << endl;
		cout << "ID = " << book->get_id() << endl;
		cout << "Bublisher = " << book->get_bublisher() << endl;
		cout << "Bublication Date = " << book->get_year() << endl;
		cout << "Available = " << book->isAvailable() << endl;
		counter++;
	}
}

void Library::deleteBook(const string& title) {
	bool exist;
	exist = false;
	for (auto book = books.begin(); book != books.end(); ++book) {
		if((*book)->get_title() == title){
			exist = true;
			cout << "...Deleting...\n";
			delete* book;
			books.erase(book);
			cout << "Book " << title << " has been erased successfully\n";
			return;
		}
	}
	if (!exist) {
		cout << "Book with the title " << title << " does not exist in the library\n";
	}

}

void Library::searchByAuthor(string& author) const {
	cout << "Books by the author " << author << endl;
	bool exist;
	exist = false;
	int counter;
	counter = 0;
	for(const Book* book : books){
		if (book->get_auther() == author) {
			counter++;
			cout << "[" << counter << "] " << "Title = " << book->get_title() << endl;
			cout << "Auther = " << book->get_auther() << endl;
			cout << "ID = " << book->get_id() << endl;
			cout << "Bublisher = " << book->get_bublisher() << endl;
			cout << "Bublication Date = " << book->get_year() << endl;
			cout << "Available = " << book->isAvailable() << endl;
			exist = true;
		}
	}
	if (!exist) {
		cout << "There are no books for that author in the library\n";
	}
}


void Library::searchBytitle(string& title) const {
	cout << "Books with the title " << title << endl;
	bool exist;
	exist = false;
	int counter;
	counter = 0;
	for (const Book* book : books) {
		if (book->get_title() == title) {
			counter++;
			cout << "[" << counter << "] " <<  "Title = " << book->get_title() << endl;
			cout << "Auther = " << book->get_auther() << endl;
			cout << "ID = " << book->get_id() << endl;
			cout << "Bublisher = " << book->get_bublisher() << endl;
			cout << "Bublication Date = " << book->get_year() << endl;
			cout << "Available = " << book->isAvailable() << endl;
			exist = true;
		}
	}
	if (!exist) {
		cout << "There are no books for that author in the library\n";
	}
}

void Library::searchByID(int& ID) const {
	cout << "Books with the ID " << ID << endl;
	bool exist;
	exist = false;

	for (const Book* book : books) {
		if (book->get_id() == ID) {
			cout << "Title = " << book->get_title() << endl;
			cout << "Auther = " << book->get_auther() << endl;
			cout << "ID = " << book->get_id() << endl;
			cout << "Bublisher = " << book->get_bublisher() << endl;
			cout << "Bublication Date = " << book->get_year() << endl;
			cout << "Available = " << book->isAvailable() << endl;
			exist = true;
		}
	}
	if (!exist) {
		cout << "There is no book with that ID\n";
	}
}



void Library::searchByyear(int& year) const {
	cout << "Books with the Year " << year << endl;
	bool exist;
	exist = false;
	int counter;
	counter = 0;
	for (const Book* book : books) {
		if (book->get_year() == year) {
			counter++;
			cout << "[" << counter << "] " << "Title = " << book->get_title() << endl;
			cout << "Auther = " << book->get_auther() << endl;
			cout << "ID = " << book->get_id() << endl;
			cout << "Bublisher = " << book->get_bublisher() << endl;
			cout << "Bublication Date = " << book->get_year() << endl;
			cout << "Available = " << book->isAvailable() << endl;
			exist = true;
		}
	}
	if (!exist) {
		cout << "There are no books for that author in the library\n";
	}
}


void Library::borrowBook(const string& title) {
	for (Book* book : books) {
		if (book->get_title() == title) {
			if (!book->isAvailable()) {
				cout << "Book \"" << title << "\" is not Available.\n";
			}
			else {
				book->borowBook();
				cout << "Book \"" << title << "\" borrowed successfully.\n";
			}
			return;
		}
	}
	cout << "Ther is no book with the name \"" << title << "\" in the libraray.\n";
}

void Library::returnBook(const string& title) {
	for (Book* book : books) {
		if (book->get_title() == title) {
			if (!book->isAvailable()) {
				cout << "Book \"" << title << "\" returned successfully.\n";
				book->returnBook();
			}
			else {
				cout << "Book \"" << title << "\"  was not borrowed\n";
			}
			return;
		}
	}
	cout << "Ther is no book with the name \"" << title << "\" in the libraray.\n";
}


void Library::savebooks(const string& filename) const {
	ofstream outFile(filename);
	if (outFile.is_open()) {
		for (const Book* book : books) {
			outFile << book->get_title() << "," << book->get_auther() << "," << book->get_id() << "," << book->get_bublisher() << "," <<book->get_year() << "," << book->isAvailable() << "\n";
		}
		outFile.close();
	}
	else {
		cout << "File could not be accessed\n";
	}
}


void Library::getFileBooks(const std::string& filename) {
	std::ifstream inFile(filename);
	if (inFile.is_open()) {

		for (Book* book : books) {
			delete book;
		}
		books.clear();
		
		string line;
		while (getline(inFile, line)) {
			string title, author, bublisher;
			int year, id;
			bool avialable;
			istringstream iss(line);
			getline(iss, title, ',');
			getline(iss, author, ',');
			iss >> id;
			iss.ignore();
			getline(iss, bublisher, ',');
			iss >> year;
			iss.ignore();
			iss >> avialable;
			Book* book = create_book_from_file(title, author, id, bublisher, year);
			addBook(book);
			if (!avialable) {
				borrowBook(title);
			}
		}

		inFile.close();
		
	}
	else {
		cout << "File could not be opened for loading the data\n";
	}
}


//////////////////////////////////////////////////////////////////
Book* create_book_from_file(string title, string auther, int id, string bublisher, int year) {

	Book* newbook = new Book(title, auther, id, bublisher, year);
	return newbook;
	delete newbook;
}





Book* create_book() {
	string title, auther, bublisher, unusedline;
	int year, id;
	cout << "              CREATING A NEW BOOK              \n";

	cout << "\nEnter title: ";
	getline(cin, unusedline);
	getline(cin, title);
	cout << "\nEnter auther: ";
	getline(cin, auther);
	cout << "\nEnter bublisher: ";
	getline(cin, bublisher);
	while (true) {
		try{
			cout << "\nEnter id: ";
			cin >> id;

			if (cin.fail()) {
				throw runtime_error("Invalid input. Please enter an integer ID.");
			}
			else if (id < 0) {
				throw runtime_error("Invalid ID. Please enter a positive integer ID.");

			}
			break;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
	}
	

	while (true) {
		try {
			cout << "\nEnter bublication year: ";
			cin >> year;

			if (cin.fail()) {
				throw runtime_error("Invalid input. Please enter an integer Year.");
			}
			else if (id < 0) {
				throw runtime_error("Invalid Year. Please enter a positive integer Year.");

			}
			break;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
	

	Book *newbook = new Book(title, auther, id, bublisher, year);
	system("cls");
	cout << "\n      Book Added Successfully      \n";
	return newbook;

}


int Menue() {
	int choice;
	cout << "\n    MAIN MENUE    \n\n";

	cout << "[1]Add a Book\n";
	cout << "[2]Delete a Book\n";
	cout << "[3]View All Books\n";
	cout << "[4]Search for a Book\n";
	cout << "[5]Borrow a Book\n";
	cout << "[6]Return a Book\n";
	cout << "[7]Exit\n\n";
	


	while (true) {
		try {
			cout << "Choose option [1]:[7]: \n";
			cin >> choice;

			if (cin.fail()) {
				throw runtime_error("Invalid input. Please enter an integer value [1]:[7].");
			}
			else if (choice < 1 || choice > 7) {
				throw runtime_error("Invalid Option. Please Choose an option [1]:[7]");

			}
			break;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}

	
	system("cls");
	return choice;
}


void search_for_book(const Library& lib) {
	cout << "\nSearching for a Book\n";
	cout << "Search for a book by:\n";
	cout << "[1] Title\n";
	cout << "[2] Auther\n";
	cout << "[3] ID\n";
	cout << "[4] Year\n";

	
	string target, unusedline;
	int year, ID;
	int option;

	while (true) {
		try {
			cout << "Choose an option: ";
			cin >> option;

			if (cin.fail()) {
				throw runtime_error("Invalid input. Please enter an integer value [1]:[4].");
			}
			else if (option < 1 || option > 7) {
				throw runtime_error("Invalid Option. Please Choose an option [1]:[4]");

			}
			break;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
	

	switch (option)
	{
	case(1):
		cout << "\nWhat is Title of the Book? ";
		getline(cin, unusedline);
		getline(cin, target);
		system("cls");
		lib.searchBytitle(target);
		break;
	case(2):
		cout << "\nWhat is name of the Author? ";
		getline(cin, unusedline);
		getline(cin, target);
		system("cls");
		lib.searchByAuthor(target);
		break;
	case(3):

		while (true) {
			try {
				cout << "\nWhat is the book ID? ";
				cin >> ID;

				if (cin.fail()) {
					throw runtime_error("Invalid input. Please enter an integer ID.");
				}
				else if (ID < 0) {
					throw runtime_error("Invalid ID. Please enter a positive integer ID.");

				}
				break;
			}
			catch (const exception& e) {
				cout << "Error: " << e.what() << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		}
		
		system("cls");
		lib.searchByID(ID);
		break;
	case(4):

		while (true) {
			try {
				cout << "\nWhich Year? ";
				cin >> year;

				if (cin.fail()) {
					throw runtime_error("Invalid input. Please enter an integer Year.");
				}
				else if (year < 0) {
					throw runtime_error("Invalid Year. Please enter a positive integer Year.");

				}
				break;
			}
			catch (const exception& e) {
				cout << "Error: " << e.what() << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		}
		
		system("cls");
		lib.searchByyear(year);
		break;
	default:
		break;
	}

}






