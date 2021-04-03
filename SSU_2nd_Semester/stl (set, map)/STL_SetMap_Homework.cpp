#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
using namespace std;


void zadacha1(vector<int>& vec)
{
	cout << "Initial vector:  ";
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}


	nth_element(vec.begin(), vec.begin() + 4, vec.end());


	cout << endl << endl << "Changed vector:  ";
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
}


void zadacha2(list<int>& lst)
{
	cout << "Initial list:  ";
	for (auto it = lst.begin(); it != lst.end(); it++) {
		cout << *it << ' ';
	}


	auto max_el = max_element(lst.begin(), lst.end());
	//cout << endl << endl << "Max element = " << max_el;
	//vector<int> vec_to_rotate;


	//copy(lst.begin(), lst.end(), back_inserter(vec_to_rotate));
	//while (vec_to_rotate[0] != max_el) {
	rotate(lst.begin(), max_el , lst.end());
	//}

	
	//lst.clear();
	//copy(vec_to_rotate.begin(), vec_to_rotate.end(), back_inserter(lst));
	cout << endl << endl << "Changed list:  ";
	for (auto it = lst.begin(); it != lst.end(); it++) {
		cout << *it << ' ';
	}
}


void zadacha3(vector<int>& vec)
{
	cout << "Initial vector:  ";
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl << endl;


	make_heap(vec.begin(), vec.end());


	cout << "Changed vector:  ";
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
}


void zadacha4(list<int>& lst1, list<int>& lst2)
{
	int result = 0;
	vector<int> vec_1;
	vector<int> vec_2;


	cout << "Initial first list:  ";
	for (auto it = lst1.begin(); it != lst1.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl << endl << "Initial second list:  ";
	for (auto it = lst2.begin(); it != lst2.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl << endl;


	copy(lst1.begin(), lst1.end(), back_inserter(vec_1));
	copy(lst2.begin(), lst2.end(), back_inserter(vec_2));
	for (unsigned int i = 0; i < vec_1.size(); ++i) {
		result += vec_1[i] * vec_2[i];
	}


	cout << "Result of scalar multiplication = " << result;
}


void zadacha5(string str)
{
	set<char> str_in_set;
	int amount;
	cout << "Initial string: " << str << endl << endl;


	for (unsigned int i = 0; i < str.size(); ++i) {
		if (isalpha(str[i])) {
			str_in_set.insert(tolower(str[i]));
		}
	}


	cout << "String converted to set:  ";
	for (auto it = str_in_set.begin(); it != str_in_set.end(); it++) {
		cout << *it;
	}


	amount = str_in_set.size();
	cout << endl << endl<< "Amount of unique letters: " << amount;
}


int main()
{
	setlocale(LC_ALL, "ru");


	// Задача 1.
	cout << "1 Задача:" << endl << endl;
	vector <int> vector_1 = { 6,2,9,12,64,-14,54,783,10,78 };
	zadacha1(vector_1);


	// Задача 2.
	cout << endl << endl << "2 Задача:" << endl << endl;
	list<int> list_1 = { 6,2,9,12,64,-14,54,783,10,78 };
	zadacha2(list_1);


	// Задача 3.
	cout << endl << endl << "3 Задача:" << endl << endl;
	vector<int> vector_A = { 2, 7, 5, 8, 3 };
	zadacha3(vector_A);


	// Задача 4.
	cout << endl << endl << "4 Задача:" << endl << endl;
	list<int> list_A = { 6,2,9,12,64,-14,54,783,10,78 };
	list<int> list_B = { 1, 2, 3, -4, 0, 10, 13, 4, 20, 19 };
	zadacha4(list_A, list_B);


	// Задача 5.
	cout << endl << endl << "5 Задача:" << endl << endl;
	string str_1 = "Check sentence";
	zadacha5(str_1);
	cout << endl;


	return 0;
}