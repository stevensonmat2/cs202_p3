/*
Matt Stevenson
CS202 program #3
05/15/2020

classes.h

this file containts the class defintions and prototypes for the String, Link,
and Link derived classes (School, Work, Fun). 

the String class provides functionality to work with arrays of characters. 

the Link class is a base class that provides common functionality for its 
derived classes. 

the three derived classes represent types of online resources a user may want
to keep track of.
*/

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

		//copies argument data into calling object
		//String & operator = (const char []);

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
		
		//returns true if argument array equal to calling object's
		bool operator == (const char *);

		//returns true if argument array not equal to calling object's
		bool operator != (const String&);
		
		//outputs String's character array
		friend ostream & operator << (ostream &, const String&);

		//sets object's array to input
		friend istream & operator >> (istream &, String &);

	private:
		//pointer to array of characters
		char *chars;	
		
		bool partial_name(const String &, int);
};


//base class. serves as parent for School, Work, and Fun classes.
//provides common base functions and data members for derived classes
class Link
{
	public:
		//constructor
		Link();

		//copy constructor
		Link(const Link &);
		
		//destructor
		virtual ~Link();
		
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
		
		//returns true if argument's priority equal to argument
		bool operator == (int);
		
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

		void set_p(int);

		void read_out(ofstream &);

	protected:
		//name of of object
		String *name;

		//subject of object
		String *subject;

		//priority of object
		int priority;
};



//derived class of Link
class School:public Link
{
	public:
		School();
		School(const Link &);
		~School();


};



//derived class of Link
class Work:public Link
{
	public:
		Work();
		Work(const Link &);
		~Work();

};



//derived class of Link
class Fun:public Link
{
	public:
		Fun();
		Fun(const Link &);
		~Fun();


};
