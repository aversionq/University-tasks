/*
Введите количество элементов последовательности: 7
Введите последовательность:
10
-32
99
546
67
-32
43
Изменённая последовательность:
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
	cout << "Введите количество элементов последовательности: ";
	cin >> n;
	vector<int> mainVector(n);
	cout << "Введите последовательность: " << endl;
	for (int i = 0; i < n; ++i) {
		cin >> mainVector[i];
	}
	insertMax(mainVector);
	cout << "Изменённая последовательность:" << endl;
	printVector(mainVector);
	return 0;
}