/*
������� �����:
This is a check text. Oh is it? Yes it is! Oh ok then! One one two! One one one two?

�������� �����:
This is a check text. Oh is it? Yes it is! Oh ok then! One one two! One one one two?

�����, ������������� ������������ � � ��������������, � � ��������������� ������������
� �� ���������� (��������� ����������� ���������� ��������� ������� ����� � ������ �����������):

�����:  is      ����������: 1
�����:  it      ����������: 1
�����:  oh      ����������: 1
�����:  one     ����������: 2
�����:  two     ����������: 1
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;


// ������� getString ������������ ���� ������ �������������.
string getString()
{
	string str;
	cout << "������� �����: " << endl;
	getline(cin, str);
	cout << endl << "�������� �����: " << endl << str << endl;
	for (unsigned int i = 0; i < str.size(); ++i) {
		str[i] = tolower(str[i]);
	}
	cout << endl;
	return str;
}


// ������� splitToSentences ��������� ����� �� �����������.
vector<string> splitToSentences(string text)
{
	vector<string> sentences;
	string sep = ".!?";
	int check_end, find_sep = 0;
	while ((check_end = text.find_first_not_of(sep, find_sep)) != text.npos) {
		find_sep = text.find_first_of(sep, check_end);
		sentences.push_back(text.substr(check_end,find_sep - check_end + 1));
		check_end = find_sep;
	}
	return sentences;
}


/* ������� analyseSentence ��������� ��������� ��������:
*  1. ������������ ����������� �� ���� ��������: �������������� � updated_str_qst, ��������������� � updated_str_excl.
*  2. ��������� ��� ����������� �� �����, ������� �� � ��������������� ����������.
*  3. � ������� ���������� ������� set_intersection ������� �����, ������� ����������� � � ���������������, � � �������������� ������������.
*  4. � ������� map ������������ ���������� �� ��������� � ������ �����������.
*  ������� ������� �� �����, ��������������� ����� �����.
*/
void analyseSentence(vector<string>& sentences)
{
	// ������������ ����������� �� ���� ��������: �������������� � updated_str_qst, ��������������� � updated_str_excl.
	vector<string> updated_str_excl, updated_str_qst;
	for (unsigned int i = 0; i < sentences.size(); ++i) {
		if ((sentences[i][sentences[i].size() - 1]) == '!') {
			updated_str_excl.push_back(sentences[i].substr(0,sentences[i].size() - 1));
		}
		else if ((sentences[i][sentences[i].size() - 1]) == '?') {
			updated_str_qst.push_back(sentences[i].substr(0, sentences[i].size() - 1));
		}
	}


	// ��������� ��� ����������� �� �����, ������� �� � ��������������� ����������.
	multiset<string> words_excl;
	if (updated_str_excl.size() != 0) {
		for (unsigned int i = 0; i < updated_str_excl.size(); ++i) {
			int check_end, find_sep = 0;
			for (unsigned int j = 0; j < updated_str_excl[i].size(); ++j) {
				while ((check_end = updated_str_excl[i].find_first_not_of(' ', find_sep)) != updated_str_excl[i].npos) {
					find_sep = updated_str_excl[i].find_first_of(' ', check_end);
					words_excl.insert(updated_str_excl[i].substr(check_end, find_sep - check_end));
					check_end = find_sep;
				}
			}
		}
	}
	multiset<string> words_qst;
	if (updated_str_qst.size() != 0) {
		for (unsigned int i = 0; i < updated_str_qst.size(); ++i) {
			int check_end, find_sep = 0;
			for (unsigned int j = 0; j < updated_str_qst[i].size(); ++j) {
				while ((check_end = updated_str_qst[i].find_first_not_of(' ', find_sep)) != updated_str_qst[i].npos) {
					find_sep = updated_str_qst[i].find_first_of(' ', check_end);
					words_qst.insert(updated_str_qst[i].substr(check_end, find_sep - check_end));
					check_end = find_sep;
				}
			}
		}
	}


	// � ������� ���������� ������� set_intersection ������� �����, ������� ����������� � � ���������������, � � �������������� ������������.
	multiset<string> words_union;
	set_intersection(words_excl.begin(), words_excl.end(), words_qst.begin(), words_qst.end(), inserter(words_union, words_union.begin()));


	// � ������� map ������������ ���������� �� ��������� � ������ �����������.
	map<string, int> words_count;
	for (auto it = words_union.begin(); it != words_union.end(); it++) {
		words_count[*it]++;
	}
	cout << "�����, ������������� ������������ � � ��������������, � � ��������������� ������������" << endl \
		<< "� �� ���������� (��������� ����������� ���������� ��������� ������� ����� � ������ �����������):"\
		<< endl << endl;
	for (auto it = words_count.begin(); it != words_count.end(); it++) {
		cout << "�����:\t"<< it->first << "\t����������: " << it->second << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "RU");


	string text;
	text = getString();


	vector<string> splitted_text;
	splitted_text = splitToSentences(text);


	analyseSentence(splitted_text);


	return 0;
}