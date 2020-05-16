/*
Matt Stevenson
CS202 program #3
05/15/2020

client.h

this file contains the class definition for the Client class and the prototypes
for its functions. this class serves as the user interface for working with the
Client's Data object. the functions prototyped herein provide CRUD 
functionality for working with a BST of Link derived objects.

*/


#include "data.h"



//main program class. provides user interface to work with BST of Link
//derived objects. provides access to all CRUD functionality of Data class
class Client
{
	public:
		//destructor
		Client();

		//constructor
		~Client();
		
		//main menu function. outputs list of commands and calls
		//class functions corresponding to user input
		void menu();
		
		//allows user to add new Link object
		void add();

		//allows user to display member data for a Link object
		//that matches user provided name
		void display_name();

		//displays member data for all Link objects in BST
		void display_all();

		//displays member data of all Link objects of user 
		//provided priority lvl
		void display_all_p();

		//displays member data for all Link derived objects of subclass
		//specified by user
		void display_all_subject();

		//allows user to remove a Link object matching provided name
		void remove();

		//deletes all Link objects
		void remove_all();

		//allows user to save current Link objects to external file;
		//can either append or overwrite
		void save_to_file();

		//allows user to populate BST with Link objects defined by
		//external file
		void read_in();
	
	private:
		//prompts user for data and copies it into Link derived object
		void build(Link &);

		//pointer to Data object that manages BST
		Data *data;
};
