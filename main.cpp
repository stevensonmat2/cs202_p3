#include "client.h"



int main()
{
	Client session;
	
	session.read_in();
	
	session.display_name();

/*
	session.menu();
	Data data;

	if (!data.read_in())
	{
		cout << "no" << endl;
	}

	data.display_all();

	*/

	return 0;
}
