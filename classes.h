#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;



//class for managing character array operations
class String
{
	public:
		String();
		String(const String &);
		~String();
		
		//copies argument data into calling object
		String & operator = (const String &);

		//copies argument data into calling object
		String & operator = (const char *);

		//returns true if argument array greater than calling object's
		bool operator < (const String&);
		
		//returns true if argument array less than calling object's
		bool operator > (const String&);
		
		//returns true if argument array less than or equal to object's
		bool operator >= (const String&);
		
		//returns true if argument array greater than/equal object's
		bool operator <= (const String&);
		
		//returns true if argument array equal to calling object's
		bool operator == (const String&);
		
		//returns true if argument array not equal to calling object's
		bool operator != (const String&);
		
		//outputs String's character array
		friend ostream & operator << (ostream &, const String&);

		//sets object's array to input
		friend istream & operator >> (istream &, String &);

	private:
		//pointer to array of characters
		char *chars;	
};


//abstract base class. serves as parent for School, Work, and Fun classes.
//provides common base functions and data members for derived classes
class Link
{
	public:
		Link();

		//copy constructor
		Link(const Link &);
		
		//destructor
		~Link();
		
		//LINK OPERATORS///////////////////////////////////////////////

		//sets calling link object's data to argument's
		Link & operator = (const Link&);

		//returns true if argument's name greater than calling object's
		bool operator < (const Link&);
	
		//returns true if argument's name less than calling object's
		bool operator > (const Link&);
	
		//returns true if argument's name greater/equal to object's
		bool operator <= (const Link&);
		
		//returns true if argument's name less than/equal to object's
		bool operator >= (const Link&);
		
		//returns true if argument's name equal to calling object's
		bool operator == (const Link&);
		
		//returns true if argument's name not equal to calling object's
		bool operator != (const Link&);

		//STRING OPERATORS/////////////////////////////////////////////

		//returns true if argument array greater than calling object's
		bool operator < (const String&);
		
		//returns true if argument array less than calling object's
		bool operator > (const String&);
		
		//returns true if argument array less than or equal to object's
		bool operator >= (const String&);
		
		//returns true if argument array greater than/equal object's
		bool operator <= (const String&);
		
		//returns true if argument array equal to calling object's
		bool operator == (const String&);
		
		//returns true if argument array not equal to calling object's
		bool operator != (const String&);
		
		//outputs argument's member data
		friend ostream & operator << (ostream &, const Link &);

		//sets input to calling object's name member
		friend istream & operator >> (istream &, Link &);

	protected:
		//name of of object
		String *name;

		//subject of object
		String *subject;

		//priority of object
		int priority;
};
