#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;


struct date
{
	int day, month, year;
};


struct people
{
	string surname, post;
	date date_of_birth;
	int work_experience, salary;
};


date convertTodate(string full_date)
{
	date structed_date;
	string temp = full_date.substr(0, 2);
	structed_date.day = atoi(temp.c_str());
	temp = full_date.substr(3, 2);
	structed_date.month = atoi(temp.c_str());
	temp = full_date.substr(6, 4);
	structed_date.year = atoi(temp.c_str());


	return structed_date;
}


// Функция printStruct была сделана для промежуточной проверки сортировок. Она выводит на экран информацию о каждом человеке из списка.
void printStruct(vector<people> sequence)
{
	for (unsigned int i = 0; i < sequence.size(); ++i) {
		cout << endl << sequence[i].surname << ' ' << sequence[i].post << ' ' << sequence[i].date_of_birth.day << '.' \
			<< sequence[i].date_of_birth.month << '.' << sequence[i].date_of_birth.year \
			<< ' ' << sequence[i].work_experience << ' ' << sequence[i].salary << endl;
	}
}


vector<people> parseFile()
{
	vector<people> list_of_people;
	ifstream in;
	people to_fill_vector;
	in.exceptions(ifstream::failbit | ifstream::badbit);
	try 
	{
		in.open("people.txt");
		cout << endl << "File opened!" << endl;
		while (!in.eof()) {
			string temp;
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
	catch(exception)
	{
		cout << "Error!" << endl;
	}
	in.close();


	return list_of_people;
}


void quickSort_salary(vector<people>& vec, int start, int stop)
{
	int i = start, j = stop;
	int pind = (rand() % stop);
	int pivot = vec[pind].salary;
	while (i <= j) {
		while (vec[i].salary < pivot) {
			i++;
		}
		while (vec[j].salary > pivot) {
			j--;
		}
		if (i <= j) {
			swap(vec[i], vec[j]);
			i++;
			j--;
		}
	}
	if (j > start) {
		quickSort_salary(vec, start, j);
	}
	if (i < stop) {
		quickSort_salary(vec, i, stop);
	}
}


void combSort_year_exp(vector<people>& vec)
{
	int inc = vec.size() / 1.247;
	while (inc >= 1) {
		if (inc < 1) {
			inc = 1;
		}
		for (unsigned int i = 0; i < (vec.size() - inc); ++i) {
			if ((vec[i].date_of_birth.year > vec[i + inc].date_of_birth.year) || \
				(vec[i].date_of_birth.year == vec[i + inc].date_of_birth.year \
					&& vec[i].work_experience > vec[i + inc].work_experience)) {
				swap(vec[i], vec[i + inc]);
			}
		}
		inc /= 1.247;
	}
}


void shakerSort_dateOfbirth(vector<people>& vec)
{
	int left = -1, right = vec.size() - 1;
	while (left < right) {
		bool flag = false;
		left++;
		for (int i = left; i < right; ++i) {
			if ((vec[i].date_of_birth.year > vec[i + 1].date_of_birth.year) || \
				(vec[i].date_of_birth.year == vec[i + 1].date_of_birth.year && \
					vec[i].date_of_birth.month > vec[i + 1].date_of_birth.month) || \
				(vec[i].date_of_birth.year == vec[i + 1].date_of_birth.year && \
					vec[i].date_of_birth.month == vec[i + 1].date_of_birth.month && \
					vec[i].date_of_birth.day > vec[i + 1].date_of_birth.day)) {
				swap(vec[i], vec[i + 1]);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
		flag = false;
		right--;
		for (int i = right; i > (left - 1); --i) {
			if ((vec[i].date_of_birth.year > vec[i + 1].date_of_birth.year) || \
				(vec[i].date_of_birth.year == vec[i + 1].date_of_birth.year && \
					vec[i].date_of_birth.month > vec[i + 1].date_of_birth.month) || \
				(vec[i].date_of_birth.year == vec[i + 1].date_of_birth.year && \
					vec[i].date_of_birth.month == vec[i + 1].date_of_birth.month && \
					vec[i].date_of_birth.day > vec[i + 1].date_of_birth.day)) {
				swap(vec[i], vec[i + 1]);
				flag = true;
			}
		}
	}
}


void printFile(vector<people>& vec, int choice)
{
	ofstream out("outFile.txt", ios::app);
	switch (choice)
	{
	case 1: out << "Quicksort by salary:\n\n"; break;
	case 2: out << "\n" << "Comb sort by the year of birth and then by work experience: \n\n"; break;
	case 3: out << "\n" << "Shaker sort by the date of birth: \n\n"; break;
	}
	for (int i = vec.size() - 1; i > -1; --i) {             // for (int i = 0; i < vec.size(); ++i) - для записи от min к max,
		out << setw(12) << left << vec[i].surname;         // т.е на первой строчке будет наименьший элемент.
		out << setw(20) << left << vec[i].post;
		if (vec[i].date_of_birth.day < 10) {
			out << left << '0' << vec[i].date_of_birth.day << '.';
		}
		else {
			out << left << vec[i].date_of_birth.day << '.';
		}
		if (vec[i].date_of_birth.month < 10) {
			out << left << '0' << vec[i].date_of_birth.month << '.';
		}
		else {
			out << left << vec[i].date_of_birth.month << '.';
		}
		out << setw(6) << left << vec[i].date_of_birth.year;
		out << setw(4) << left << vec[i].work_experience;
		out << setw(8) << left << vec[i].salary;
		out << "\n";
	}
	out.close();
}


int main()
{
	ofstream out("outFile.txt");
	out.close();
	vector<people>people_list = parseFile();
	quickSort_salary(people_list, 0, people_list.size() - 1);
	printFile(people_list, 1);
	combSort_year_exp(people_list);
	printFile(people_list, 2);
	shakerSort_dateOfbirth(people_list);
	printFile(people_list, 3);
	cout << "Sorting ended. You can check your 'outFile.txt' file." << endl;


	return 0;
}