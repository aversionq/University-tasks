/*
Введите длину последовательности: 6

Введите элементы последовательности:
56
986
7
2013
268
4

Отсортированная введённая последовательность (без повторений):
4 7 56 268 986 2013

Цифры из данной последовательности, которые не встречаются ни в двузначных, ни в трёхзначных числах:
0 1 3 4 7
*/


#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");


	int n, value;
	set<int> mainSet;
	set<int> two_and_three_digits;
	set<int> others;
	cout << "Введите длину последовательности: ";
	cin >> n;
	cout << endl << "Введите элементы последовательности: " << endl;
	for (int i = 0; i < n; ++i) {
		cin >> value;
		if (value <= 999 && value >= 10) {
			int number, to_add;
			number = value;
			while (number > 0) {
				to_add = number % 10;
				two_and_three_digits.insert(to_add);
				number /= 10;
			}
		}
		else {
			int number, to_add;
			number = value;
			while (number > 0) {
				to_add = number % 10;
				others.insert(to_add);
				number /= 10;
			}
		}
		mainSet.insert(value);
	}
	cout << endl << "Отсортированная введённая последовательность (без повторений): " << endl;
	for (auto it = mainSet.begin(); it != mainSet.end(); it++) {
		cout << *it << ' ';
	}


	set<int> result;
	set_difference(others.begin(), others.end(), two_and_three_digits.begin(), two_and_three_digits.end(), inserter(result,result.begin()));
	if (result.size() > 0) {
		cout << endl << endl << "Цифры из данной последовательности, которые не встречаются ни в двузначных, ни в трёхзначных числах: " << endl;
		for (auto it = result.begin(); it != result.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	else {
		cout << endl << endl << "Цифр, которых нет ни в двузначных, ни в трёхзначных числах, нет." << endl;
	}
}