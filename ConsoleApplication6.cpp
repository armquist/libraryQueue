// ConsoleApplication6.cpp : This is the main file where the project code is called and executed.
//

#include "stdafx.h"
#include "library.h"
using namespace std;

int main() {
	library library; //make library object
	library.add_book("Software Engineering"); //add book 
	library.add_book("Chemistry"); //add book
	library.add_employee("Adam"); //add employee to employes list and integrates into book queues
	library.add_employee("Sam");  //add employee to employes list and integrates into book queues
	library.add_employee("Ann");  //add employee to employes list and integrates into book queues
	library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));  //adds book to circulation list, set statrt date 
	library.circulate_book("Software Engineering", Date(2015, 4, 1, DateFormat::US)); //adds book to circulation list, set statrt date 
	library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US));  //pass from Adam to Sam
	library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));  //pass from Sam to Ann
	library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US)); //pass from Ann to Archive
	library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));   //pass from Sam to Adam
	library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));  //pass from Adam to Ann
	library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));  //pass from Ann to Archive
	system("pause"); //visual studio function to pause terminal so users can read input
	return 0;
}
