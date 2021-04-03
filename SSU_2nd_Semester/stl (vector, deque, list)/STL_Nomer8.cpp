/*
������� ���������� ��������� ������������������: 7
������� �������� ������������������:
-10
20
30
120
56
3421
-12
������������������ � �������� �������:
-12 3421 56 120 30 20 -10
������� ������ � ����� ���������:
-20
20
������� X:101
��������� ������������������ (����� ������ �� X):
101 101 30 120 56 3421 101
��������������� ������������������:
30 56 101 101 101 120 3421
������� ����� �������:
101
��������������� ������������������ � ����� ���������:
30 56 101 101 101 101 120 3421
������������������, � ������� ����������� ������������� ��������:
30 56 101 120 3421
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int>& vec)
{
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
}


void reversePrint(vector<int>& vec)
{
	cout << "������������������ � �������� �������:" << endl;
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << ' ';
	}
	cout << endl;
}


void changeElement(vector<int>& vec)
{
	int Begin, End, x;
	cout << "������� ������ � ����� ���������: " << endl;;
	cin >> Begin >> End;
	cout << "������� X:";
	cin >> x;
	if (Begin > End) {
		cout << "������ ��������� ��������� ������ ��� �����, �������� ���� ������� ��������.";
		swap(Begin, End);
	}
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i] >= Begin && vec[i] <= End) {
			vec[i] = x;
		}
	}
	cout << "��������� ������������������ (����� ������ �� X): " << endl;
	printVector(vec);
	cout << endl;
}


void insertNew(vector<int>& vec)
{
	int new_el;
	cout << endl;
	cout << "������� ����� �������: " << endl;
	cin >> new_el;
	auto index = lower_bound(vec.begin(), vec.end(), new_el);
	vec.insert(index, new_el);
	cout << "��������������� ������������������ � ����� ���������:" << endl;
	printVector(vec);
}


void deleteDuplicates(vector<int>& vec)
{
	cout << endl;
	int count;
	vector<int> index_to_del;
	for (unsigned int i = 0; i < vec.size(); ++i) {
		count = 0;
		for (unsigned int j = i; j < vec.size(); ++j) {
			if (vec[i] == vec[j]) {
				count += 1;
			}
		}
		if (count > 1) {
			index_to_del.push_back(i);
		}
	}
	for (int k = index_to_del.size() - 1; k >= 0; k--) {
		auto it = vec.begin() + index_to_del[k];
		vec.erase(it);
	}
	cout << "������������������, � ������� ����������� ������������� ��������:" << endl;
	printVector(vec);
}


int main()
{
	setlocale(0, "");
	int n;
	cout << "������� ���������� ��������� ������������������: ";
	cin >> n;
	vector<int> mainVector(n);
	cout << "������� �������� ������������������: " << endl;
	for (unsigned int i = 0; i < mainVector.size(); ++i) {
		cin >> mainVector[i];
	}
	reversePrint(mainVector);
	changeElement(mainVector);
	sort(mainVector.begin(), mainVector.end());
	cout << "��������������� ������������������: " << endl;
	printVector(mainVector);
	insertNew(mainVector);
	deleteDuplicates(mainVector);
	return 0;
}