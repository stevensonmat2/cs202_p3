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

	return *this;
}



//LINK:LINK COMPARISON//////////////////////////////////////////////////////



//returns true if argument's name greater than calling object's
bool Link::operator < (const Link &compare)
{
	if (name < compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name less than calling object's
bool Link::operator > (const Link &compare)
{
	if (name > compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name greater/equal to object's
bool Link::operator <= (const Link &compare)
{
	if (name <= compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name less than/equal to object's
bool Link::operator >= (const Link &compare)
{
	if (name >= compare.name)
	{
		return true;
	}

	return false;
}



//returns true if argument's name equal to calling object's
bool Link::operator == (const Link &compare)
{
	if (name == compare.name)
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
	if (*name > compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array less than or equal to object's
bool Link::operator <= (const String &compare)
{
	if (*name <= compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array greater than/equal object's
bool Link::operator >= (const String &compare)
{
	if (*name >= compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array equal to calling object's
bool Link::operator == (const String &compare)
{
	if (*name == compare)
	{
		return true;
	}

	return false;
}



//returns true if argument array not equal to calling object's
ostream & operator << (ostream &out, const Link &link)
{
	out << *link.name << endl;
//	    << *link.subject << endl
	    //<< link.priority;

	return out;
}



//sets input to calling object's name member
istream & operator >> (istream &in, Link &link)
{
	if (!link.name) link.name = new String;

	in >> *link.name;

	return in;
}
