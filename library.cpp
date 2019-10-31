#include "stdafx.h"
#include "library.h"

using namespace std;

library::library() { //constructor

}

library::~library() { //destructor

}

void library::add_book(string newBook) {
	book tempBook(newBook); // created a new book with the name newBook
	books_circulated.push_back(tempBook); // push the newBook to the list of books to be circulated
	cout << "Book " << newBook << " has been added to the database." << endl; // let the user know a new book with the indicated name has been added
}

void library::add_employee(string name) {
	employee *temp; // creates pointer 
	temp = new employee(name); // make the pointer temp point to the employee with the indicated name
	employees.push_back(temp); // push the new employee to the end of the list
	cout << "Employee " << name << " has been added to the database." << endl; // prints the name of the new employee 
	list<book>::iterator iter; // creates an iterator
	for (iter = books_circulated.begin(); iter != books_circulated.end(); iter++) { // the iter iterates thourgh the books  circulated list 
		iter->pushToQueue(employees.back()); // push the item pointed to by the iterator to the back of the employees list
	}
}

void library::pass_on(string bookName, Date& book_pass ) { //book_pass =  the date the book is passed
	list<book>::iterator iter;  
	bool isThere = false;
	for (iter = books_circulated.begin(); iter != books_circulated.end(); iter++) { // iterates through the list
		if (iter->getName() == bookName) {  // compares the book name with the name of the books to be passed 
			iter->passOn(book_pass); // make the iterator points to the element holding when the date when the book was passed on 
			isThere = true;
			if (iter->getArchived()) { // returns the archived book
				books_archived.push_back(*iter);
				books_circulated.erase(iter);
				return;
			}
		}
	}
	if (isThere = false) {
		throw std::exception("Book not found"); 
	}
}

void library::circulate_book(string bookName, Date& date_cir) {
	cout << "Book " << bookName << " has been circulated as of " << date_cir << endl;
	list<book>::iterator iter;
	for (iter = books_circulated.begin(); iter != books_circulated.end(); iter++) {
		if (iter->getName() == bookName) { // compares the name of the book to be circualted with the name of the book in the list
			iter->set_start_date(date_cir); // sets the start date to the date when the  book was circulated 
			return;
		}
	}
	throw std::exception("Book not found"); 
}

