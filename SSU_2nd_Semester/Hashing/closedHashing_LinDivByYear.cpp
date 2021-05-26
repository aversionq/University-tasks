#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>


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


void getBirthYears(std::vector<people> ppl, std::vector<int>& birth_years) {
	for (int i = 0; i < ppl.size(); ++i) {
		birth_years.push_back(ppl[i].date_of_birth.year);
	}
}


void createClosedHash(std::vector<people> ppl, std::vector< std::vector<people> >& hash_table) {
	for (int i = 0; i < ppl.size(); ++i) {
		int help_hash = ppl[i].date_of_birth.year % hash_table.size(), k;
		k = 0;
		for (int j = 0; j < hash_table.size(); ++j) {
			int hash_index = help_hash + k;
			if (hash_table[hash_index][0].date_of_birth.year == -1) {
				hash_table[hash_index].erase(hash_table[hash_index].begin());
				hash_table[hash_index].push_back(ppl[i]);
				break;
			}
			else {
				k++;
			}
		}
	}
}


void findHashTable(std::vector< std::vector<people> > hash_table, int requested_element) {
	bool if_found = false;
	for (int i = 0; i < hash_table.size(); ++i) {
		for (int j = 0; j < hash_table[i].size(); ++j) {
			if (hash_table[i][j].date_of_birth.year == requested_element) {
				if_found = true;
				std::cout << "\nElement " << requested_element << " found in " << i << " row!\n";
				printStruct(hash_table[i][j]);
			}
		}
	}
	if (!if_found) {
		std::cout << "\nThere is no such element in this hash table.\n";
	}
}


void insertHashTable(std::vector< std::vector<people> >& hash_table, people elem_to_add) {
	int help_hash = elem_to_add.date_of_birth.year % hash_table.size(), k;
	k = 0;
	for (int j = 0; j < hash_table.size(); ++j) {
		int hash_index = help_hash + k;
		if (hash_table[hash_index][0].date_of_birth.year == -1) {
			hash_table[hash_index].erase(hash_table[hash_index].begin());
			hash_table[hash_index].push_back(elem_to_add);
			break;
		}
		else {
			k++;
		}
	}
}


void printHashTable(std::vector< std::vector<people> > hash_table){
	std::cout << std::endl;
	for (int i = 0; i < hash_table.size(); ++i) {
		std::cout << i << ": ";
		for (int j = 0; j < hash_table[i].size(); ++j) {
			if (hash_table[i][j].date_of_birth.year != -1) {
				printStruct(hash_table[i][j]);
			}
		}
		std::cout << std::endl;
	}
}


int main()
{
	int choice;
	std::vector<people> people_list = parseFile();
	std::vector<int> birth_years;
	getBirthYears(people_list, birth_years);
	std::vector< std::vector<people> > hash_table;

	while (true) {
		std::cout << "\n1. Create hash table\n" << "2. Find element in hash table\n" << \
			 "3. Add new element to hash table\n" << "4. Print hash table\n";
		std::cout << "\nChoose option: ";
		std::cin >> choice;
		if (choice == 1) {
			int hash_table_size;
			people skip_ppl;
			skip_ppl.date_of_birth.year = -1;
			//skip_ppl.date_of_birth.month = -1;
			//skip_ppl.date_of_birth.day = -1;
			//skip_ppl.post = "asd";
			//skip_ppl.surname = "qwe";
			//skip_ppl.salary = 10000;
			//skip_ppl.work_experience = 30;
			std::cout << "Input your hash table size: ";
			std::cin >> hash_table_size;
			hash_table.resize(hash_table_size);
			for (int i = 0; i < hash_table.size(); ++i) {
				hash_table[i].push_back(skip_ppl);
			}
			createClosedHash(people_list, hash_table);
		}

		if (choice == 2) {
			bool if_del = false;
			int* el_ptr;
			int requested_el;
			if (hash_table.size() > 0) {
				std::cout << "Input element that you want to find: ";
				std::cin >> requested_el;
				findHashTable(hash_table, requested_el);
			}
			else {
				std::cout << "\n Your hash table is empty or you simply didn't create it yet.\n";
			}
		}

		if (choice == 3) {
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
			insertHashTable(hash_table, elem_to_add);
		}

		if (choice == 4) {
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