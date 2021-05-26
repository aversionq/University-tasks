#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iomanip>


struct date
{
	int day, month, year;
};


struct people
{
	std::string surname, post;
	date date_of_birth;
	int work_experience, salary;
};


date convertTodate(std::string full_date)
{
	date structed_date;
	std::string temp = full_date.substr(0, 2);
	structed_date.day = atoi(temp.c_str());
	temp = full_date.substr(3, 2);
	structed_date.month = atoi(temp.c_str());
	temp = full_date.substr(6, 4);
	structed_date.year = atoi(temp.c_str());


	return structed_date;
}


// Функция printStruct была сделана для промежуточной проверки сортировок. Она выводит на экран информацию о каждом человеке из списка.
void printStruct(people sequence)
{
	std::cout << std::endl << sequence.surname << ' ' << sequence.post << ' ' << sequence.date_of_birth.day << '.' \
		<< sequence.date_of_birth.month << '.' << sequence.date_of_birth.year \
		<< ' ' << sequence.work_experience << ' ' << sequence.salary << std::endl;
}


std::vector<people> parseFile()
{
	std::vector<people> list_of_people;
	std::ifstream in;
	people to_fill_vector;
	in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		in.open("people.txt");
		while (!in.eof()) {
			std::string temp;
			in >> to_fill_vector.surname;
			in >> to_fill_vector.post;
			in >> temp;
			to_fill_vector.date_of_birth = convertTodate(temp);
			in >> to_fill_vector.work_experience;
			in >> to_fill_vector.salary;
			list_of_people.push_back(to_fill_vector);
		}
		return list_of_people;
	}
	catch (std::exception)
	{
		std::cout << "An error occured while opening file!" << std::endl;
	}
	in.close();


	return list_of_people;
}


struct list
{
	people inf;
	list* next;
	list* prev;
};


void push(list*& h, list*& t, people x)
{
	list* r = new list;
	r->inf = x;
	r->next = 0;
	if (!h && !t) {
		r->prev = 0;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}


//void print(list* h, list* t)
//{
//	list* p = h;
//	while (p) {
//		std::cout << p->inf << ' ';
//		p = p->next;
//	}
//}


//list* find(list* h, list* t, int x)
//{
//	list* p = h;
//	while (p) {
//		if (p->inf == x) {
//			break;
//		}
//		p = p->next;
//	}
//
//
//	return p;
//}


//void insert_after(list*& h, list*& t, list* r, int y)
//{
//	list* p = new list;
//	p->inf = y;
//	if (r == t) {
//		p->next = 0;
//		p->prev = r;
//		r->next = p;
//		t = p;
//	}
//	else {
//		r->next->prev = p;
//		p->next = r->next;
//		p->prev = r;
//		r->next = p;
//	}
//}


void del_node(list*& h, list*& t, list* r) {
	if (r == h && r == t) {
		h = t = 0;
	}
	else if (r == h) {
		h = h->next;
		h->prev = 0;
	}
	else if (r == t) {
		t = t->prev;
		t->next = 0;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}


void del_list(list*& h, list*& t)
{
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = 0;
		delete p;
	}
}


void getBirthMonths(std::vector<people> ppl, std::vector<int>& birth_monrth) {
	for (int i = 0; i < ppl.size(); ++i) {
		birth_monrth.push_back(ppl[i].date_of_birth.month);
	}
}


void createHashTableDivByMonth(std::vector<int> birth_months, std::vector< std::pair<list*, list*> >& hash_table, std::vector<people> ppl) {
	int hash_index;
	for (int i = 0; i < hash_table.size(); ++i) {
		hash_table[i].first = 0;
		hash_table[i].second = 0;
	}
	for (int i = 0; i < birth_months.size(); ++i) {
		hash_index = birth_months[i] % hash_table.size();
		push(hash_table[hash_index].first, hash_table[hash_index].second, ppl[i]);
	}
}


void printHashTable(std::vector< std::pair<list*, list*> > hash_table) {
	std::cout << std::endl;
	if (hash_table.size() > 0) {
		for (int i = 0; i < hash_table.size(); ++i) {
			list* p = hash_table[i].first;
			std::cout << i << ": ";
			while (p) {
				printStruct(p->inf);
				p = p->next;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "\n Your hash table is empty or you simply didn't create it yet.\n";
	}
}


void insertInHashTable(std::vector< std::pair<list*, list*> >& hash_table, people element_to_add) {
	int hash_index;
	hash_index = element_to_add.date_of_birth.month % hash_table.size();
	push(hash_table[hash_index].first, hash_table[hash_index].second, element_to_add);
}


void findOrDeleteFromHashTable(std::vector< std::pair<list*, list*> >& hash_table, int requested_element, bool if_delete) {
	bool if_found = false;
	for (int i = 0; i < hash_table.size(); ++i) {
		list* p = hash_table[i].first;
		while (p) {
			if (p->inf.date_of_birth.month == requested_element) {
				if_found = true;
				if (if_delete) {
					del_node(hash_table[i].first, hash_table[i].second, p);
					std::cout << "\nElement " << requested_element << " deleted!\n";
					p = hash_table[i].first;
					continue;
				}
				else {
					std::cout << "\nElement " << requested_element << " found in " << i << " row!\n";
					printStruct(p->inf);
				}
			}
			p = p->next;
		}
	}
	if (!if_found) {
		std::cout << "\nThere is no such element in this hash table.\n";
	}
}


int main()
{
	int choice;
	std::vector<people> people_list = parseFile();
	std::vector<int> birth_months;
	getBirthMonths(people_list, birth_months);
	std::vector< std::pair<list*, list*> > hash_table;

	while (true) {
		std::cout << "\n1. Create hash table\n" << "2. Find element in hash table\n" << \
			"3. Delete element from hash table\n" << "4. Add new element to hash table\n" << "5. Print hash table\n";
		std::cout << "\nChoose option: ";
		std::cin >> choice;
		if (choice == 1) {
			int hash_table_size;
			std::cout << "Input your hash table size: ";
			std::cin >> hash_table_size;
			hash_table.resize(hash_table_size);
			createHashTableDivByMonth(birth_months, hash_table, people_list);
		}

		if (choice == 2) {
			bool if_del = false;
			int* el_ptr;
			int requested_el;
			if (hash_table.size() > 0) {
				std::cout << "Input element that you want to find: ";
				std::cin >> requested_el;
				findOrDeleteFromHashTable(hash_table, requested_el, if_del);
			}
			else {
				std::cout << "\n Your hash table is empty or you simply didn't create it yet.\n";
			}
		}

		if (choice == 3) {
			bool if_del = true;
			int* el_ptr;
			int requested_el;
			if (hash_table.size() > 0) {
				std::cout << "Input element that you want to find: ";
				std::cin >> requested_el;
				findOrDeleteFromHashTable(hash_table, requested_el, if_del);
			}
			else {
				std::cout << "\n Your hash table is empty or you simply didn't create it yet.\n";
			}
		}

		if (choice == 4) {
			people elem_to_add;
			std::cout << "Input first surname: ";
			std::cin >> elem_to_add.surname;
			std::cout << "\nInput post: ";
			std::cin >> elem_to_add.post;
			std::cout << "\nInput day of birth: ";
			std::cin >> elem_to_add.date_of_birth.day;
			std::cout << "\nInput month of birth: ";
			std::cin >> elem_to_add.date_of_birth.month;
			std::cout << "\nInput year of birth: ";
			std::cin >> elem_to_add.date_of_birth.year;
			std::cout << "\nInput salary: ";
			std::cin >> elem_to_add.salary;
			std::cout << "\nInput work experience: ";
			std::cin >> elem_to_add.work_experience;
			insertInHashTable(hash_table, elem_to_add);
		}

		if (choice == 5) {
			if (hash_table.size() > 0) {
				printHashTable(hash_table);
			}
			else {
				std::cout << "\n Your hash table is empty or you simply didn't create it yet.\n";
			}
		}

		else if (choice < 1 || choice > 5) {
			std::cout << "There is no such function.";
		}
	}
}