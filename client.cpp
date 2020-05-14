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
			<< "(8) edit a Link's priority" << endl
			<< "(9) save Links to file" << endl
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

			case 8: //edit a Link's priority
				edit_priority();
				break;

			case 9: //save Links to file (append or overwrite)
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
			//temp = new School;
			//build(temp);
			break;
		case 2: //create a Work class object
			//temp = new Work;
			//build(temp);
			break;
		case 3: //create a Fun class object
			//temp = new Fun;
			//build(temp);
			break;
	}

	//copy new object into BST
	*data += *temp;
}



void Client::display_name()
{
	String temp;

	cout << "enter name: ";
	
	cin >> temp;
	cin.ignore(100, '\n');

	//use data search operator to find object matching user input
	Link *link = NULL;
	link = &((*data)[temp]);
	
	cout << *link;
}



void Client::display_all()
{

}



void Client::display_all_p()
{

}



void Client::display_all_subject()
{

}



void Client::remove()
{

}


void Client::remove_all()
{

}



void Client::edit_priority()
{

}



void Client::save_to_file()
{

}



//prompts user for info needed to construct Link derived object
void Client::build()
{
	char temp[100];//stores user input
	int input = 0;//stores user input

	cout << "enter name: ";

	//use overloaded operator to set objects name to user input
	cin >> temp;
	cin.ignore(100, '\n');

	cout << "enter url (eg 'www.link1.com'): ";

	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	
	//call object's set url function
	//temp.set_url(temp);	

	do//prompt user for priorty until valid input given
	{
		cout << "enter priority (1-5): ";

	} while (input < 1 || input > 5);

	cin >> input;
	cin.ignore(100, '\n');
	
	//call object's set priority function
	//temp.set_priority(input);
}



void Client::read_in()
{
	data->read_in();
}

