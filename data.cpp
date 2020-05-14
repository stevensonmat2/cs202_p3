#include "data.h"


//constructor
Node::Node()
{
	left = NULL;
	right = NULL;
	link = NULL;
}

//NEEDED? NOT SURE
//copy constructor
Node::Node(const Node &node)
{

}


//destructor
Node::~Node()
{
	//delete link object
	if (link) delete link;
}


//NODE::STRING OPERATORS////////////////////////////////////////////////////////
//compare Node's link object's name to argument's



//returns true if link object's name should be ordered after argument's
bool Node::operator > (const String &compare)
{
	if (*link > compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name should be ordered before argument's
bool Node::operator < (const String &compare)
{
	if (*link < compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name is the same as argument's
bool Node::operator == (const String &compare)
{
	if (*link == compare)
	{
		return true;
	}

	return false;
}



//NODE::LINK OPERATORS////////////////////////////////////////////////////////
//compare Node's link object's name to argument's



//returns true if link object's name should be ordered after argument's
bool Node::operator > (const Link &compare)
{
	if (*link > compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name should be ordered before argument's
bool Node::operator < (const Link &compare)
{
	if (*link < compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name should be ordered after or is the same as
//argument's name
bool Node::operator >= (const Link &compare)
{
	if (*link >= compare)
	{
		return true;
	}

	return false;
}




//returns true if link object's name should be ordered before or is the same as
//argument's name
bool Node::operator <= (const Link &compare)
{
	if (*link <= compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name is the same as argument's
bool Node::operator == (const Link &compare)
{
	if (*link == compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name not equal argument's
bool Node::operator != (const Link &compare)
{
	if (*link == compare)
	{
		return true;
	}

	return false;
}



//copies argument Link object to Node's link pointer
Node & Node::operator += (const Link &to_add)
{
	//DO RRTI HERE
	link = new Link;
	*link = to_add;

	return *this;
}



//outputs Node's link object's member data
ostream & operator << (ostream &out, const Node &node)
{

	out << *node.link;

	return out;
}



//returns Node's right pointer object
Node *& Node::get_right()
{
	return right;
}



//returns Node's left pointer object
Node *& Node::get_left()
{
	return left;
}


//returns Node's Link object
Link & Node::get_link()
{
	return *link;
}
/* 	DELETE
void Node::set_right(Node *&node)
{
	right = node;
}



void Node::set_left(Node *&node)
{
	left = node;
}
*/


//DATA CLASS FUNCTIONS//////////////////////////////////////////////////////////



//constructor
Data::Data()
{
	root = NULL;
}



//destructor
Data::~Data()
{
	if (root) delete root;

	root = NULL;
}



//reads in data from argument external file and adds new objects to BST with
//each line in file providing info for each new object
bool Data::read_in()
{
	//MOVE FILE DEF TO CLIENT AND PASS AS ARG
	const char infile[] = "ext.txt";//define external file
	ifstream in;//initialize file variable
	in.open(infile);//set file variable to ext file
	
	Link temp;//USE RTTI FUNCTION

	if (in)
	{
		in >> temp;
		in.ignore(100, '\n');

		while (in && !in.eof())//if name found
		{
			*this += temp;

			in >> temp;
			in.ignore(100, '\n');
		}
		
		return true;
	}

	else
	{
		return false;
	}
}
		



//wrapper; if root null, create new Node at root and set Link object to Node's
//Link pointer. otherwise, call recursive insert function with root and
//new Link object
Data & Data::operator += (const Link &source)
{
	//if no BST, create root and set root's Link ptr to new object
	if (!root)
	{
		root = new Node;
		*root += source;

		return *this;
	}
	
	//else, call recursive insert function
	return add(source, root);
}



//recursive insert function. compares new Link object to those of current Nodes
//in BST. if new object name is greater than current Node's, traverse to Node's
//right pointer; otherwise, traverse to left pointer. once and empty ptr is
//found, insert new Node and set its link ptr to argument Link object
Data & Data::add(const Link &source, Node *&root)
{
	//if empty spot found, insert and set Node's link ptr
	if (!root)
	{
		root = new Node;
		*root += source;

		return *this;
	}
	
	//if new Link object's name greater than curret Node's, traverse right
	if (*root < source)
	{
		return add(source, root->get_right());
	}
	
	//else, traverse left
	return add(source, root->get_left());
}



//takes a String object as an argument and searches BST for object with
//name matching the argument. if found, returns the object; otherwise
//returns null
Link & Data::operator [] (const String &find)
{
	//if BST empty return null
	if (!root)
	{
		//return *root;
		Link *temp = NULL;
		return *temp;
	}
	
	//else call recursive search functon
	return search_name(find, root);
}



//recursive search function; checks each Node's name in BST against
//argument String. if a match is found, returns the matching Node;
//otherwise returns null
Link & Data::search_name(const String &find, Node *root)
{
	//return null if no match found, otherwise return matching Node
//	if (!root || *root == find)
	if (!root)
	{
		//return *root;
		Link *temp = NULL;
		return *temp;
	}

	else if (*root == find)
	{
		return root->get_link();
	}
	
	//if new Link object's name greater than curret Node's, traverse right
	if (*root < find)
	{
		return search_name(find, root->get_right());
	}

	//else, traverse left
	return search_name(find, root->get_left());
}



//wrapper; if BST not empty, call recursive function to out all data for
//all objects in BST; return false if BST empty, true otherwise
bool Data::display_all()
{
	if (!root) return false;

	//call recursive function with root pointer
	return display_all(root);
}



//recursively traverse BST and call each object's overloaded output operator
bool Data::display_all(Node *root)
{
	bool val;//boolean variable to store return value 

	if (!root) return true;//if end of branch, unwind
	
	//traverse all the way to the right
	val = display_all(root->get_right());
	
	//traverse all the way to the left
	val = display_all(root->get_left());
	
	//output with overloaded operator as stack unwinds
	cout << *root;
	
	//return true when done
	return val;
}






/*	
Data & Data::operator -= (Node &remove)
{
	if (!root)
	{
		return *this;
	}

	return remove(root, remove);
}




Data & Data::remove(Node *&root, Node &remove)
{
	if (!root)
	{
		return *this;
	}

	if (*root == remove)
	{
		delete remove;

*/





