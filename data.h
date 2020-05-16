/*
Matt Stevenson
CS202 program #3
05/15/2020

data.h

this file contains the class definitions and prototypes for the Node and Data
classes.

the Data class provides functionality for working with a BST of Node objects,
while the Nodes provide functionality to work with Link objects to which they
point.

the Data class provides access to the objects in the BST for client programs.

*/



#include "classes.h"



//class for organizing objects in a balanced search tree. each Node points to
//two other Node's (left and right) and a Link-derived object
class Node {

	public:
		//constructor
		Node();

		//destructor
		~Node();

		//copy constructor
		Node(const Node &);
		
		//returns Node's right pointer object
		Node *& get_right();

		//returns Node's left pointer object
		Node *& get_left();

		//returns Node's Link object
		Link & get_link();
		
		//sets Node's right pointer to argument Node
		void set_right(Node *&);

		//sets Node's left pointer to argument Node
		void set_left(Node *&);
		
		//passes ofstream object to Link object
		void read_out(ofstream &);

		//LINK COMPARISONS/////////////////////////////////////////////
		//following functions compare Node's Link object's name to 
		//argument Link's name and return true or false

		//returns true if argument name greater than Node's
		bool operator > (const Link &compare);

		//returns true if argument name less than than Node's
		bool operator < (const Link &compare);

		//return true if argument's name > or == Node's
		bool operator >= (const Link &compare);

		//return true if argument's name < or == Node's
		bool operator <= (const Link &compare);

		//return true if argument's name is equal to Node's
		bool operator == (const Link &compare);

		//return true if argument's name does not equal Node's
		bool operator != (const Link &compare);

		//STRING COMPARISONS///////////////////////////////////////////
		//following functions compare Node's Link object's name to 
		//argument String's character array and return true or false

		//returns true if argument name greater than Node's
		bool operator > (const String &compare);

		//returns true if argument name less than than Node's
		bool operator < (const String &compare);

		//return true if argument's name is equal to Node's
		bool operator == (const String &compare);
		
		//returns true if link object's priority lvl is the same as argument's
		bool operator == (int);

		//OTHER OVERLOADS//////////////////////////////////////////////
		
		//copies argument's Link object to Node's link ptr
		Node & operator = (const Node &);

		//sets Node's link pointer to argument Link object
		Node & operator += (const Link&);
		
		//outputs Node's Link object's member data
		friend ostream & operator << (ostream &, const Node &);

	private:
		//pointer to right Node
		Node *right;

		//pointer to left Node
		Node *left;
		
		//pointer to Link object
		Link *link;
};



//class for managing search tree operations. root pointer points to first
//Node object in BST. supports all CRUD operations
class Data {

	public:
		//constructor
		Data();

		//destructor
		~Data();
		
		//reads in data from argument external file and creates a new
		//for each line of data in file
		bool read_in();
		
		//writes Link object's data from BST to external file
		bool read_out();
		
		//copies argument object into BST
		Data & operator += (const Link &);
		
		//removes Link object matching argument from BST
		Data & operator -= (const String &);

		//returns Node object containing Link object with name that
		//matches argument String object
		Link & operator [] (const String &);

		//outputs member data for all objects in BST
		bool display_all();
		
		//outputs member data for all objects of argument priority
		bool display_all_p(int);
		
		//outputs member  data for all objects of argument subject
		bool display_all_subject(const String &);
		
		//deletes all objects in BST
		bool remove_all();

	private:
		//pointer to first Node in BST
		Node * root;	
		
		//recursive function to add argument Link object to BST
		Data & add(const Link &source, Node *&root);
		
		//recursively searchs for object matching argument and deletes
		Data & remove(Node *&, const String &);

		//recursive function  to find and return Node with Link object
		//matching argument String
		Link & search_name(const String &find, Node *root);

		//recursive function to output all member data for all objects
		//in BST
		bool display_all(Node *root);
		
		//recursively outputs member data for all objects matching
		//argument priority
		bool display_all_p(Node *, int);
		
		//recursively outputs member data for all objects matching
		//argument subject
		bool display_all_subject(Node *, const String &);
		
		//recusively deletes all objects in BST
		bool remove_all(Node *&);
	
		//returns Link derived object matching argument 	
		Link & type_cast(const String &check);
		
		//recursively writes member data for each object in BST to
		//external file
		bool read_out(Node *root, ofstream &);
};
