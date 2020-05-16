/*
Matt Stevenson
CS202 program #3
05/15/2020

data.cpp

this file contains the function definitions for the Node and Data classes.
the data class functions are responsible for working on the Data object's
data structure (BST) and providing access to the data in the structure to
client programs.

the Node class functons provide functionality for linking objects in a BST
and provide the interface interacting with their Link objects.
*/


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
	//call Link's operator
	if (*link > compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name should be ordered before argument's
bool Node::operator < (const String &compare)
{
	//call Link's operator
	if (*link < compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name is the same as argument's
bool Node::operator == (const String &compare)
{
	//call Link's operator
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
	//call Link's operator
	if (*link > compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name should be ordered before argument's
bool Node::operator < (const Link &compare)
{
	//call Link's operator
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
	//call Link's operator
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
	//call Link's operator
	if (*link <= compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's name is the same as argument's
bool Node::operator == (const Link &compare)
{
	//call Link's operator
	if (*link == compare)
	{
		return true;
	}

	return false;
}



//returns true if link object's priority lvl is the same as argument's
bool Node::operator == (int p)
{
	//call Link's operator
	if (*link == p)
	{
		return true;
	}

	return false;
}



//returns true if link object's name not equal argument's
bool Node::operator != (const Link &compare)
{
	//call Link's operator
	if (*link == compare)
	{
		return true;
	}

	return false;
}



//replaces Node's Link object with a copy of argument's
Node & Node::operator = (const Node &to_copy)
{
	delete link;//delete current object
	link = new Link;//create new one
	*link = *to_copy.link;//copy argument data in to new object

	return *this;
}



//copies argument Link object to Node's link pointer
Node & Node::operator += (const Link &to_add)
{
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



//sets Node's right ptr to argument
void Node::set_right(Node *&node)
{
	right = node;
}



//sets Node's left ptr to argument
void Node::set_left(Node *&node)
{
	left = node;
}


//call read out function of Link object with ofstream object
void Node::read_out(ofstream &out)
{
	link->read_out(out);
}



//DATA CLASS FUNCTIONS//////////////////////////////////////////////////////////



//constructor
Data::Data()
{
	root = NULL;
}



//destructor
Data::~Data()
{
	if (root) //if root not null
	{
		if (remove_all(root))//call function to delete all Nodes
		{
			cout << "all links deleted" << endl;
		}
		
		root = NULL;
	}
}



//reads in data from argument external file and adds new objects to BST with
//each line in file providing info for each new object
bool Data::read_in()
{
	//MOVE FILE DEF TO CLIENT AND PASS AS ARG
	const char infile[] = "ext.txt";//define external file
	ifstream in;//initialize file variable
	in.open(infile);//set file variable to ext file
	
	Link *temp;//ptr to temp Link-derived object
	char *pre = new char [100];//holds read-in strings
	int p = 0;//hold priority lvl read in
	String check;//USE EXCLUSIVLEY IF THERE IS TIME

	if (in)//if file exists
	{
		//read in first string to determine object type
		in.get(pre, 100, ',');
		in.ignore(100, ',');

		check = pre;
		
		//while not at end of list
		while (in && !in.eof())
		{
			//check for object's class and create new object at ptr
			temp = &(type_cast(check));
			
			//get object's priority lvl
			in >> p;
			in.ignore(100, ',');
			
			//set p lvl
			temp->set_p(p);
			
			//set name of temp Link object
			in >> *temp;
			in.ignore(100, '\n');
			
			//copy new object into Data BST
			*this += *temp;
			
			//delete temp object
			delete temp;
			
			//check for next line in file
			in.get(pre, 100, ',');
			in.ignore(100, ',');

			check = pre;
		}
		
		delete [] pre;

		//return true when done
		return true;

	}

	else//if no file exit with fail
	{
		delete [] pre;

		return false;
	}
}



//checks for external file; if exists, open and call function to traverse BST
//and read out object member data to file, one object per line
bool Data::read_out()
{
	const char outfile[] = "ext.txt";//define external file
	ofstream out;//create object to hold output
	out.open(outfile);//open file
	
	if (!root) return false;//if BST empty exit

	if (out)//if file exists
	{
		//call recursive function with ofstream object
		read_out(root, out);
	}

	out.close();
	out.clear();

	cout << "file overwritten" << endl
		<< endl;
	
	return true;
}



//recursively traverse BST inorder and pass ofstream object to each Link object
//via object's read out function. 
bool Data::read_out(Node *root, ofstream &out)
{
	bool val = true;//store return value of function

	if (!root) return true;//if end of branch unwind
	
	//traverse left
	val = read_out(root->get_left(), out);
	
	//call object's read out function
	root->read_out(out);
	
	//traverse right
	val = read_out(root->get_right(), out);

	return val;
}



//checks argument for type of Link-derived object to create. once determined,
//creates a new Link-derived object and returns it
Link & Data::type_cast(const String &check)
{
	Link *temp = NULL;//ptr to new Link-derived object
	String str;//holds comparison strings

	str = "school";//check for school type object
	
	//if argument matches current type
	if (str == check)
	{
		//create new object of type and return it
		temp = new School;
		return *temp;
	}

	str = "work";

	//if argument matches current type
	if (str == check)
	{
		//create new object of type and return it
		temp = new Work;
		return *temp;
	}
	
	//if not school or work, assume fun type object and return
	else
	{
		//create new object of type and return it
		temp = new Fun;
		return *temp;
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
		//create new Node and add Link to Node's link ptr
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
		//create new Node and add Link to Node's link ptr
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
	
	//traverse all the way to the left
	val = display_all(root->get_left());
	
	//output with overloaded operator as stack unwinds
	cout << *root << endl
		<< endl;
	
	//traverse all the way to the right
	val = display_all(root->get_right());

	//return true when done
	return val;
}



//wrapper; calls recusrsive function find all objects with argument
//priority lvl and output their member data
bool Data::display_all_p(int p)
{
	//if BST empty 
	if (!root) return false;
	
	//call recusrive function
	return display_all_p(root, p);
}



//recursively traverse BST and compare object's priority lvls
//to argument. if match, output object's member data. return true when done
bool Data::display_all_p(Node *root, int p)
{
	bool val = true;//boolean variable to store return value 

	if (!root) return val;//if end of branch, unwind
	
	//traverse all the way to the left
	val = display_all_p(root->get_left(), p);
	
	//root's object's priority matches argument (uses overloaded operator)
	if (*root == p)
	{
		//output object's data with operator
		cout << *root << endl
			<< endl;
	}
	
	//traverse all the way to right
	val = display_all_p(root->get_right(), p);

	return val;
}



//wrapper; calls recusrsive function find all objects with argument
//subject and output their member data
bool Data::display_all_subject(const String &subject)
{
	//if BST empty 
	if (!root) return false;
	
	//call recusrive function
	return display_all_subject(root, subject);
}



//recursively traverse BST and compare object's subject
//to argument. if match, output object's member data. return true when done
bool Data::display_all_subject(Node *root, const String &subject)
{
	bool val = true;//boolean variable to store return value 

	if (!root) return val;//if end of branch, unwind
	
	//traverse all the way to the left
	val = display_all_subject(root->get_left(), subject);
	
	//root's object's subject matches argument (uses overloaded operator)
	if (*root == subject)
	{
		//output object's data with operator
		cout << *root << endl
			<< endl;
	}
	
	//traverse all the way to right
	val = display_all_subject(root->get_right(), subject);

	return val;
}



//wrapper; calls function to remove all objects from BST. returns false if BST
//is empty, true otherwise
bool Data::remove_all()
{
	if (!root) return false;

	return remove_all(root);
}



//recursive function to delete all objects in BST. returns true when done
bool Data::remove_all(Node *&root)
{
	bool val = true;//create variable to store return values

	if (!root) return true;//return true at end of branch
	
	//traverse all the way left, then right
	val = remove_all(root->get_left());
	val = remove_all(root->get_right());
	
	//delete as stack unwinds
	delete root;
	root = NULL;
	
	return val;
}



//call recursive function to remove Node with Link name matching argument
Data & Data::operator -= (const String &rem)
{
	//if BST empty, return Data object as is
	if (!root)
	{
		return *this;
	}
	
	//call recusrive function
	return remove(root, rem);
}



//recursive function to remove a single object from te BST. compares argument
//to each object in BST until a match is found or all Nodes have been checked.
//if a match is found, the match is deleted and Nodes are rearranged as needed
//to maintain the order of the BST
Data & Data::remove(Node *&root, const String &rem)
{
	//if end of branch, return Data object
	if (!root)
	{
		return *this;
	}
	
	//if match found
	if (*root == rem)
	{
		//if Node is childless, delete and return
		if (!root->get_left() && !root->get_right())
		{
			delete root;
			root = NULL;

			return *this;
		}
		
		//else if Node has one child
		if (root->get_right() || root->get_left())
		{
			//save Node's right ptr
			Node *current = &(*(root->get_right()));
			
			//if Node has object at right ptr
			if (current) 
			{
				//delete Node and set to Node's right
				delete root;
				root = current;

				return *this;
			}
			
			//otherwise, get Node's left, delete root and set root
			//to root's left
			else
			{
				current = root->get_left();
				delete root;
				root = current;

				return *this;
			}
		}
		
		//if Node has two children
		else
		{
			//save Node's right ptr and create a null prev ptr
			Node *current = &(*(root->get_right()));
			Node *prev = NULL;
			
			//loop until as far left as possible from Node
			while (current->get_left())
			{
				prev = current;
				current = current->get_left();
			}
			
			//use overload operator to copy current's Link to Node
			root = current;
			
			//if Nodes exist to right of current
			if (current->get_right())
			{
				//check for previous
				if (prev)
				{
					//set prev's left to current's right
					prev->set_left(current->get_right());
				}
				
				delete current;
				current = NULL;
			}

		}
		
		//return modified BST
		return *this;
	}
	
	//else, determine if left or right traversal required 
	if (*root < rem)
	{
		return remove(root->get_right(), rem);
	}

	else
	{
		return remove(root->get_left(), rem);
	}
}
				

		

		






