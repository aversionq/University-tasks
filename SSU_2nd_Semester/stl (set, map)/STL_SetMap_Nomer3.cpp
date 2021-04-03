/*
������� ����� ������������������: 6

������� �������� ������������������:
56
986
7
2013
268
4

��������������� �������� ������������������ (��� ����������):
4 7 56 268 986 2013

����� �� ������ ������������������, ������� �� ����������� �� � ����������, �� � ���������� ������:
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
	cout << "������� ����� ������������������: ";
	cin >> n;
	cout << endl << "������� �������� ������������������: " << endl;
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
	cout << endl << "��������������� �������� ������������������ (��� ����������): " << endl;
	for (auto it = mainSet.begin(); it != mainSet.end(); it++) {
		cout << *it << ' ';
	}


	set<int> result;
	set_difference(others.begin(), others.end(), two_and_three_digits.begin(), two_and_three_digits.end(), inserter(result,result.begin()));
	if (result.size() > 0) {
		cout << endl << endl << "����� �� ������ ������������������, ������� �� ����������� �� � ����������, �� � ���������� ������: " << endl;
		for (auto it = result.begin(); it != result.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	else {
		cout << endl << endl << "����, ������� ��� �� � ����������, �� � ���������� ������, ���." << endl;
	}
}