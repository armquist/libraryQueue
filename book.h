
#ifndef Booklist_h
#define Booklist_h
#include <iostream>
#include <vector>
#include "Employee"
#include "Date.h"

template <typename T>
class Book{
public:
    Date start_date;
    Date end_date;
   void get_start_date (const &String date, DateFormat format);
    void get_end_date (const $String date, DateFormat format);
    void pop();
    void push(const T&the_data);
private:
    Queue <T> employees;
    T name;
};
#endif /* Booklist_h */
