/*
Matt Stevenson
CS202 program #3
05/15/2020

main.cpp

this program allows a user to store and search through a collection of Link
objects which represent various online resources a user would like to keep
track of. each Link object has a name (could be a url, or something they want
to research), a subject (work, school, fun) and a priority level (1-5).

the collection of Link objects is prepopulated by an external file, and users
can save changes to the collection (Links added or removed) to the same file.
*/



#include "client.h"



int main()
{
	//create Client object
	Client session;
	
	//read in Link objects from external file
	session.read_in();
	
	//output main menu until user exits
	session.menu();

	return 0;
}
