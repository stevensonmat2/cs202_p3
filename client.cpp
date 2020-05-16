/*
Matt Stevenson
CS202 program #3
05/15/2020

client.cpp

this file contains all function definitions for the Client class.

these functions provide access to the Client's Data object, enabling the use
of CRUD functionality of the BST of Link derived objects.

*/



#include "client.h"



//constructor. instantiates a new Data object at the Data pointer
Client::Client()
{
	data = new Data;
}



//destructor
Client::~Client()
{
	delete data;
}



//main menu function. provides command interface for user to access
//class functions
void Client::menu()
{
	int input = 0;//variable to store user commands

	do//display menu until user exits program
	{
		cout << "choose a command: " << endl
			<< endl
			<< "(1) add a new Link" << endl
			<< "(2) display a Link" << endl
			<< "(3) display all Links" << endl
			<< "(4) display all Links of priority" << endl
			<< "(5) display all Links of subject" << endl
			<< "(6) remove a Link by name" << endl
			<< "(7) remove all Links" << endl
			<< "(8) save Links to file" << endl
			<< "(0) exit program" << endl
			<< endl
			<< "choose command: ";

		cin >> input;
		cin.ignore(100, '\n');

		cout << endl;

		switch (input)
		{
			case 1: //add new Link object to BST
				add();
				break;

			case 2: //display Link by name
				display_name();
				break;

			case 3: //display all Links
				display_all();
				break;

			case 4: //display all Link of same priority
				display_all_p();
				break;

			case 5: //display all Links of same subject
				display_all_subject();
				break;

			case 6: //remove a Link by name
				remove();
				break;

			case 7: // remove all Links from BST
				remove_all();
				break;

			case 8: //save Links to file (append or overwrite)
				save_to_file();
				break;

			case 0: //exit program
				break;
		}

	} while (input != 0);//loop until user enters '0' to exit


}



//lets user add new Link object. prompts user for object info and passees 
//data to Data object via Link object
void Client::add()
{
	int input = 0;//variable to store user commands
	Link *temp = NULL;//variable to hold temp Link object

	do//display choices until user enters valid input
	{
		cout << "what type of Link?" << endl
			<< endl
			<< "(1) school" << endl
			<< "(2) work" << endl
			<< "(3) fun" << endl
			<< endl
			<< "choose type: ";

		cin >> input;
		cin.ignore(100, '\n');

		cout << endl;


	} while (input > 3 || input < 1);//loop until user enters valid input

	switch (input)
	{
		case 1: //create a school class object
			temp = new School;
			build(*temp);
			break;

		case 2: //create a Work class object
			temp = new Work;
			build(*temp);
			break;

		case 3: //create a Fun class object
			temp = new Fun;
			build(*temp);
			break;
	}

	//copy new object into BST
	*data += *temp;

	delete temp;

	cout << "added!" << endl
		<< endl;
}



//prompts user for the name of a Link object to display; if found, object
//is retrieved and its display operator is invoked
void Client::display_name()
{
	String temp;//create String to store name

	cout << "enter name: ";
	
	//store name in String obj
	cin >> temp;
	cin.ignore(100, '\n');

	//use Data search operator to find object matching user input
	Link *link = NULL;
	link = &((*data)[temp]);
	
	//if found, use operator to display obj data
	if (link) cout << *link << endl << endl;

	else cout << "no match found" << endl << endl;
}



//outputs data for all Link objects in BST by calling data object's
//display all function
void Client::display_all()
{
	if (!data->display_all())
	{
		cout << "no links saved" << endl
			<< endl;
	}
}



//outputs data for all Link objects with priority lvl matching user input
//by calling data object's function
void Client::display_all_p()
{
	int input = 0;//stores user input

	cout << "enter priority lvl (1-5): ";

	cin >> input;
	cin.ignore(100, '\n');

	if (!data->display_all_p(input))
	{
		cout << "no matches found" << endl
			<< endl;
	}
}



//outputs data for all Link objects of user provided subject by calling data
//objects display all by subject function
void Client::display_all_subject()
{
	String temp;//stores user input

	cout << "enter subject (work, school, fun): ";

	cin >> temp;
	cin.ignore(100, '\n');

	if (!data->display_all_subject(temp))
	{
		cout << "no matches found" << endl
			<< endl;
	}
}



//prompts user for name of Link object to remove. if found, it is removed
//from Data object's BST
void Client::remove()
{
	String remove;//create String object to store name

	cout << "enter name to remove: ";
	
	//use String's operator to store user input
	cin >> remove;
	cin.ignore(100, '\n');
	
	cout << endl;
	
	//search for matcing object and save result to ptr
	Link *link = NULL;
	link = &((*data)[remove]);

	//if object matching String is found
	if (link)
	{
		//use Data's operator to remove object
		*data -= remove;

		cout << "link removed!" << endl << endl;
	}

	else
	{
		cout << "link not found" << endl
			<< endl;
	}
}


//calls Data object's remove all function to delete all Link objects
void Client::remove_all()
{
	if (!data->remove_all())
	{
		cout << "nothing to delete" << endl
			<< endl;
	}

	cout << "links deleted!" << endl << endl;
}



//calls data object's function to write BST to external file
void Client::save_to_file()
{
	if (!data->read_out())
	{
		cout << "data not saved" << endl
			<< endl;
	}
}



//prompts user for info needed to construct Link derived object
void Client::build(Link &obj)
{
	int input = 0;//stores user input

	cout << "enter name: ";

	//use overloaded operator to set objects name to user input
	cin >> obj;
	cin.ignore(100, '\n');

	do//prompt user for priorty until valid input given
	{
		cout << "enter priority (1-5): ";

		cin >> input;
		cin.ignore(100, '\n');

	} while (input < 1 || input > 5);

	//call object's set priority function
	obj.set_p(input);
}



//calls Data objects read in function and passes in name of external
//file to read from
void Client::read_in()
{
	data->read_in();
}

