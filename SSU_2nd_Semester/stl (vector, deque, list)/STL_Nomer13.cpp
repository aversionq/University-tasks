/*
������� ���������� ��������� ������ ������������������: 5

������� �������� ������ ������������������:
54
65
-14
71
1023
������� ���������� ��������� ������ ������������������: 7

������� �������� ������ ������������������:
542
65
123
987
-124
-50
1023

������ ������������������:
54 65 -14 71 1023

������ ������������������:
542 65 123 987 -124 -50 1023

��������� ������������������:
54 -14 71

������� X: 5
��������� �������, ������� X. ������� ����� �������: 102
��������� �������, ������� X. ������� ����� �������: 47

��������� ������������������:
542 65 102 123 987 -124 -50 47 1023

��������������� ������ ������������������:
-14 54 71

��������������� ������ ������������������:
-124 -50 47 65 102 123 542 987 1023

���������� ��������������� ������������������:
-124 -50 -14 47 54 65 71 102 123 542 987 1023
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void printVector(vector<int>& vec)
{
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl;
}


void vectorDifference(vector<int>& vec1, vector<int>& vec2)
{
	int count;
	vector<int> index_to_del;
	for (unsigned int i = 0; i < vec1.size(); ++i) {
		count = 0;
		for (unsigned int j = 0; j < vec2.size(); ++j) {
			if (vec1[i] == vec2[j]) {
				count += 1;
			}
		}
		if (count > 0) {
			index_to_del.push_back(i);
		}
	}
	for (int k = index_to_del.size() - 1; k >= 0; k--) {
		auto it = vec1.begin() + index_to_del[k];
		vec1.erase(it);
	}
	cout << "��������� ������������������: " << endl;
	printVector(vec1);
	cout << endl;
}


void insertAfterX(vector<int>& vec)
{
	int x, new_el;
	cout << "������� X: ";
	cin >> x;
	for (unsigned int i = 0; i < vec.size(); ++i) {
		if (vec[i] % x == 0) {
			cout << "��������� �������, ������� X. ������� ����� �������: ";
			cin >> new_el;
			vec.insert(vec.begin() + i + 1, new_el);
			i++;
		}
	}
	cout << "��������� ������������������: " << endl;
	printVector(vec);
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n1, n2;
	cout << "������� ���������� ��������� ������ ������������������: ";
	cin >> n1;
	cout << endl;
	vector<int> vector_1(n1);
	cout << "������� �������� ������ ������������������: " << endl;
	for (unsigned int i = 0; i < vector_1.size(); ++i) {
		cin >> vector_1[i];
	}
	cout << "������� ���������� ��������� ������ ������������������: ";
	cin >> n2;
	cout << endl;
	vector<int> vector_2(n2);
	cout << "������� �������� ������ ������������������: " << endl;
	for (unsigned int i = 0; i < vector_2.size(); ++i) {
		cin >> vector_2[i];
	}
	cout << "������ ������������������:" << endl;
	printVector(vector_1);
	cout << "������ ������������������:" << endl;
	printVector(vector_2);
	vectorDifference(vector_1, vector_2);
	cout << endl;
	insertAfterX(vector_2);
	sort(vector_1.begin(), vector_1.end());
	sort(vector_2.begin(), vector_2.end());
	cout << "��������������� ������ ������������������:" << endl;
	printVector(vector_1);
	cout << "��������������� ������ ������������������:" << endl;
	printVector(vector_2);
	vector<int> vector_3(vector_1.size() + vector_2.size());
	merge(vector_1.begin(), vector_1.end(), vector_2.begin(), vector_2.end(), vector_3.begin());
	cout << "���������� ��������������� ������������������:" << endl;
	printVector(vector_3);
	return 0;
}