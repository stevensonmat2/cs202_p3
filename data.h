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
		
		//OTHER OVERLOADS//////////////////////////////////////////////

		//sets Node's link pointer to argument Link object
		Node & operator += (const Link&);
		
		//outputs Node's Link object's member data
		friend ostream & operator << (ostream &, const Node &);

/*DELETE
		//sets Node's right pointer to argument Node
		void set_right(Node *&);

		//sets Node's left pointer to argument Node
		void set_left(Node *&);
*/
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
		Data();
		~Data();
		
		//reads in data from argument external file and creates a new
		//for each line of data in file
		bool read_in();
		
		//copies argument object into BST
		Data & operator += (const Link &);

		//returns Node object containing Link object with name that
		//matches argument String object
		Link & operator [] (const String &);

		//DELETE Node & search_name(const String &, Node *);
		
		//outputs member data for all objects in BST
		bool display_all();

		bool remove_all();

		//bool remove();
		
	private:
		//pointer to first Node in BST
		Node * root;	
		
		//Link & rtti(const Link &);
		
		//recursive function to add argument Link object to BST
		Data & add(const Link &source, Node *&root);

		//recursive function  to find and return Node with Link object
		//matching argument String
		Link & search_name(const String &find, Node *root);

		//recursive function to output all member data for all objects
		//in BST
		bool display_all(Node *root);

		bool remove_all(Node *&);
};
