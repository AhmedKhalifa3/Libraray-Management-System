#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H	



#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Book {
private:
	string title;
	string auther;
	int id;
	string bublisher;
	int year;
	bool available;
	

public:
	~Book();
	Book(string title, string auther, int id, string bublisher, int year);
	string get_title() const;
	string get_auther() const;
	int get_id() const;
	string get_bublisher() const;
	int get_year() const;
	bool isAvailable() const;
	void borowBook();
	void returnBook();
};



class Member {
private:
	string name;
	string address;
	string phone;
	string email;
	bool membership_status;

public:
	Member(string name, string address, string phone, string email);
	string get_name() const;

	string get_address() const;

	string get_phone() const;

	string get_email() const;

	bool isMember() const;

	void becomeMember() ;

	void cancelMemebership();

};

class Library {
private:
	vector <Book*> books;
public:
	~Library();
	void addBook(Book* book);
	void displaybooks() const;
	void deleteBook(const string& title);
	void searchByAuthor(string& author) const;
	void searchBytitle(string& author) const;
	void searchByID(int& ID) const;
	void searchByyear(int& year) const;
	void borrowBook(const string& title);
	void returnBook(const string& title);
	void savebooks(const string& filename) const;
	void getFileBooks(const std::string& filename);
	};




Book* create_book();
int Menue();
void search_for_book(const Library& lib);
Book* create_book_from_file(string title, string auther, int id, string bublisher, int year);
#endif 