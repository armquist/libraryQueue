
//----------------------
#include "library.hpp"

Library::Library(){

}

Library::~Library(){

list<Employee*>::iterator it;

for (it = employeeList.begin(); it != employeeList.end(); it++){

//delete *it;
  Employees.erase(it);

}

}

void Library::add_book(string newBook){

Book Current_Book(newBook);

toBeCirculated.push_back(Current_Book);

}

void Library::add_employee(string name){

Employee *temp_Employee;

temp_Employee = new Employee(name);

employeeList.push_front(temp_employee);

}

void Library::circulate_book(string book_circulated, Date dayOfCirculation){

list<Book>::iterator it;

for (it = toBeCirculated.begin(); it != toBeCirculated.end(); it++){ // find book : O(n)

if (it->getname() == book_circulated){ // this is the book

it->temp_queue(employeeList); // create queue

it->setstartDate(dayOfCirculation); // save start date

break;

}

}

cerr << "Book not found" << endl;

}

void Library::pass_on(string book_circulated, Date date){

Employee *next, *prev; // prev is employee that is popped

list<Book>::iterator it;

for (it = toBeCirculated.begin(); it != toBeCirculated.end(); it++){ // find book : O(n)

if (it->getname() == book_circulated){

prev = it->pop_max(); // pop max, save to prev

prev->retain(date - it->getHeld()); // retain = current date - last pass of book

if (!it->isEmpty()){

next = it->top(); // next is now max

next->wait(date - it->getstartDate()); // wait = current date - book start date

it->setHeld(date); // save pass date for next employee

}

else{ // circulation complete

it->setarchived(true);

it->setendDate(date);

archived.push_back(*it); // archive

toBeCirculated.erase(it); // erase

}

break;

}

}

cerr << "Book not found" << endl;

}


