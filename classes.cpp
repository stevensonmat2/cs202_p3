/*
Matt Stevenson
CS202 program #3
05/15/2020

classes.cpp

this file contains the function defintions for the String, Link, and Link
derived classes.

the String class functions provides easy to use functionality for working with
and comparing arrays of characters.

the Link class functions are common to all derived classes, and serve to allow
users to compare and work with other Link objects.

the three derived classes feature no new functions, and only their contructors
include unique functinality in that they set their subject field to match their
class type.
*/

#include "classes.h"



//constructor
String::String()
{
	chars = NULL;
}



//copy constructor
String::String(const String &to_copy)
{
	//call overloaded operator to copy argument data into new object
	*this = to_copy;
}



//destructor. deallocates dynamic memory
String::~String()
{
	if (chars) delete [] chars;

	chars = NULL;
}



//copies argument data into calling object
String & String::operator = (const String &new_string)
{
	if (chars)
		if (*this == new_string) return *this;
	
	//delete existing array if present
	if (chars) delete [] chars;
	
	//create new array sized to argument's and copy
	chars = new char[strlen(new_string.chars)+1];
	strcpy(chars, new_string.chars);

	return *this;
}



//copies argument data into calling object
String & String::operator = (const char *new_chars)
{
	//delete existing array if present
	if (chars) delete [] chars;

	//create new array sized to argument's and copy
	chars = new char[strlen(new_chars)+1];
	strcpy(chars, new_chars);

	return *this;
}



//returns true if argument array greater than calling object's
bool String::operator < (const String &compare)
{
	//compare calling object's array to argument's
	if (strcmp(chars, compare.chars) < 0)
	{
		return true;
	}

	return false;
}



//returns true if argument array less than calling object's
bool String::operator > (const String &compare)
{
	//compare calling object's array to argument's
	if (strcmp(chars, compare.chars) > 0)
	{
		return true;
	}

	return false;
}



//returns true if argument array less than or equal to object's
bool String::operator >= (const String &compare)
{
	//compare calling object's array to argument's
	if (strcmp(chars, compare.chars) >= 0)
	{
		return true;
	}

	return false;
}



//returns true if argument array greater than/equal object's
bool String::operator <= (const String &compare)
{
	//compare calling object's array to argument's
	if (strcmp(chars, compare.chars) <= 0)
	{
		return true;
	}

	return false;
}



//returns true if argument array equal to calling object's
bool String::operator == (const String &compare)
{
	//compare calling object's array to argument's
	if (strcmp(chars, compare.chars) == 0)
	{
		return true;
	}
	
	//if first indicies match, check for a partial match
	if (chars[0] == compare.chars[0])
	{
		int i = 1;//create index tracker
		
		//call recursive partial match function
		return partial_name(compare, i);
	}

	return false;
}



//recursive function to check if user input is partial match to String's
//array. returns true if so
bool String::partial_name(const String &compare, int i)
{
	//if current index is less than total length of argument's array
	if (i < (int)strlen(compare.chars))
	{
		//if current indicies match
		if (chars[i] == compare.chars[i])
		{
			//check next index
			return partial_name(compare, ++i);
		}
		
		//if a mismatch is found, exit with false
		else
		{
			return false;
		}
	}
	
	//if no mismatches found, return true
	return true;
}



//returns true if argument array equal to calling object's
bool String::operator == (const char *check)
{
	//compare calling object's array to argument's
	if (strcmp(chars, check) == 0)
	{
		return true;
	}

	return false;
}



//returns true if argument array not equal to calling object's
bool String::operator != (const String &compare)
{
	//compare calling object's array to argument's
	if (strcmp(chars, compare.chars) != 0)
	{
		return true;
	}

	return false;
}



//outputs String's character array
ostream & operator << (ostream &out, const String &word)
{
	out << word.chars;

	return out;
}



//sets object's array to input
istream & operator >> (istream &in, String &word)
{
	char temp[100];//create temp char array to hold input
	
	//set input from buffer to temp array
	in.get(temp, 100, '\n');
	
	//delete existing array if present
	if (word.chars) delete [] word.chars;

	//create new array sized to argument's and copy
	word.chars = new char [strlen(temp)+1];
	strcpy(word.chars, temp);

	return in;
}



//LINK FUNCTIONS/////////////////////////////////////////////////////////////// 



//constructor
Link::Link()
{
	name = NULL;
	subject = NULL;
	priority = 0;

}



//copy constructor
Link::Link(const Link &to_copy)
{
	name = to_copy.name;
	subject = to_copy.subject;
	priority = to_copy.priority;
}



//destructor
Link::~Link()
{
	if (name) delete name;

	name = NULL;

	if (subject) delete subject;

	subject = NULL;
}



//sets calling link object's data to argument's
Link & Link::operator = (const Link &to_copy)
{
	//create new String object at pointer
	name = new String;

	//copy argument data into new object
	*name = *to_copy.name;
	
	subject = new String;

	*subject = *to_copy.subject;

	priority = to_copy.priority;

	return *this;
}



//LINK:LINK COMPARISON//////////////////////////////////////////////////////



//returns true if argument's name greater than calling object's
bool Link::operator < (const Link &compare)
{
	//call String's operator
	if (*name < *compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name less than calling object's
bool Link::operator > (const Link &compare)
{
	//call String's operator
	if (*name > *compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name greater/equal to object's
bool Link::operator <= (const Link &compare)
{
	//call String's operator
	if (*name <= *compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name less than/equal to object's
bool Link::operator >= (const Link &compare)
{
	//call String's operator
	if (*name >= *compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name equal to calling object's
bool Link::operator == (const Link &compare)
{
	//call String's operator
	if (*name == *compare.name)
	{
		return true;
	}

	return false;
}



//LINK:STRING COMPARISON//////////////////////////////////////////////////////



//returns true if argument array greater than calling object's
bool Link::operator < (const String &compare)
{
	if (*name < compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array less than calling object's
bool Link::operator > (const String &compare)
{
	//call String's operator
	if (*name > compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array less than or equal to object's
bool Link::operator <= (const String &compare)
{
	//call String's operator
	if (*name <= compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array greater than/equal object's
bool Link::operator >= (const String &compare)
{
	//call String's operator
	if (*name >= compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array equal to calling object's
bool Link::operator == (const String &compare)
{
	//check if Link object's name matches or partial matches
	if (*name == compare)
	{
		return true;
	}
	
	//checks if Link subject matches or partial matches
	if (*subject == compare)
	{
		return true;
	}

	return false;
}



//returns true if argument's priority equal to argument
bool Link::operator == (int p)
{
	if (priority == p)
	{
		return true;
	}

	return false;
}



//returns true if argument array not equal to calling object's
ostream & operator << (ostream &out, const Link &link)
{
	out << *link.name << endl
	    << *link.subject << endl
	    << link.priority;

	return out;
}



//sets input to calling object's name member
istream & operator >> (istream &in, Link &link)
{
	if (!link.name) link.name = new String;

	in >> *link.name;

	return in;
}


//sets calling object's priority to argument
void Link::set_p(int p)
{
	priority = p;
}



//returns member data via argument ofstream object
void Link::read_out(ofstream &out)
{
	out << *subject << ","
		<< priority << ","
		<< *name << endl;
}



//SCHOOL CLASS/////////////////////////////////////////////////////////////////



//constructor; set subject to class type and call parent constructor
School::School(): Link()
{
	subject = new String;
	*subject = "school";
}



//copy constructor
School::School(const Link &to_copy): Link(to_copy)
{
	subject = new String;
	*subject = "school";
}


School::~School()
{
}



//WORK CLASS///////////////////////////////////////////////////////////////////



//constructor; set subject to class type and call parent constructor
Work::Work(): Link()
{
	subject = new String;
	*subject = "work";
}



//copy constructor
Work::Work(const Link &to_copy): Link(to_copy)
{
	subject = new String;
	*subject = "work";
}



Work::~Work()
{
}



//FUN CLASS////////////////////////////////////////////////////////////////////



//constructor; set subject to class type and call parent constructor
Fun::Fun(): Link()
{
	subject = new String;
	*subject = "fun";
}



//copy constructor
Fun::Fun(const Link &to_copy): Link(to_copy)
{
	subject = new String;
	*subject = "fun";
}



Fun::~Fun()
{
}

