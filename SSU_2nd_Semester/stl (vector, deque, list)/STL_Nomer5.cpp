/*
������� ���������� ��������� ������������������: 7
������� ������������������:
10
-32
99
546
67
-32
43
��������� ������������������:
10 -32 546 99 546 67 -32 546 43
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
}


void insertMax(vector<int> &vec)
{
	int max_el = *max_element(vec.begin(), vec.end());
	int min_el = *min_element(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == min_el) {
			auto it2 = vec.begin() + i + 1;
			vec.insert(it2, max_el);
			i++;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "������� ���������� ��������� ������������������: ";
	cin >> n;
	vector<int> mainVector(n);
	cout << "������� ������������������: " << endl;
	for (int i = 0; i < n; ++i) {
		cin >> mainVector[i];
	}
	insertMax(mainVector);
	cout << "��������� ������������������:" << endl;
	printVector(mainVector);
	return 0;
}