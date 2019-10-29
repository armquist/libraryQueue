#include "stdafx.h"
#include "library.h"

using namespace std;

library::library() {

}

library::~library() {
	list<employee*>::iterator it;
	for (it == employees.begin(); it != employees.end(); it++) {
		delete *it;
	}
}

void library::add_book(string& newBook) {
	book tempBook(newBook);
	books_circulated.push_back(tempBook);
	list<book>::iterator iter = books_circulated.begin();
	while (iter != books_circulated.end()) {
		iter->add_employee(employees.back());
		++iter;
	}
}

void library::add_employee(string& name) {
	employee *temp;
	temp = new employee(name);
	employees.push_front(temp);
}

void library::pass_on(string& bookName, Date& book_pass) {
	list<book>::iterator iter = books_circulated.begin();
	while (iter != books_circulated.end()) {
		if (iter->getName() == bookName) { 
			iter->passOn(book_pass);
			if (iter->getArchived()) {
				books_archived.push_back(*iter);
				books_circulated.erase(iter);
				return;
			}
		}
		++iter;
	}
}


void library::circulate_book(string& bookName, Date& date_cir) {
	list<book>::iterator it;
	for (it = books_circulated.begin(); it != books_circulated.end(); it++) {
		if (it->getName() == bookName) {
			it->set_start_date(date_cir); 
			return;
		}
	}
	throw std::exception("Book not found"); 
}

