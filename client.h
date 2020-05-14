#include "data.h"



class Client
{
	public:
		Client();
		~Client();

		void menu();

		void add();
		void display_name();
		void display_all();
		void display_all_p();
		void display_all_subject();
		void remove();
		void remove_all();
		void edit_priority();
		void save_to_file();
		void read_in();
	
	private:
		void build();
		Data *data;
};
