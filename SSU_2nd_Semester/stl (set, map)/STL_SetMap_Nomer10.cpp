/*
Введите текст:
This is a check text. Oh is it? Yes it is! Oh ok then! One one two! One one one two?

Исходный текст:
This is a check text. Oh is it? Yes it is! Oh ok then! One one two! One one one two?

Слова, встречающиеся одновременно и в вопросительных, и в восклицательных предложениях
и их количество (выводится минимальное количество вхождения данного слова в нужные предложения):

Слово:  is      Количество: 1
Слово:  it      Количество: 1
Слово:  oh      Количество: 1
Слово:  one     Количество: 2
Слово:  two     Количество: 1
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;


// Функция getString обеспечивает ввод строки пользователем.
string getString()
{
	string str;
	cout << "Введите текст: " << endl;
	getline(cin, str);
	cout << endl << "Исходный текст: " << endl << str << endl;
	for (unsigned int i = 0; i < str.size(); ++i) {
		str[i] = tolower(str[i]);
	}
	cout << endl;
	return str;
}


// Функция splitToSentences разбивает текст на предложения.
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


/* Функция analyseSentence выполняет следующие действия:
*  1. Распределяет предложения по двум векторам: вопросительные в updated_str_qst, восклицательные в updated_str_excl.
*  2. Разбивает эти предложения на слова, помещая их в соответствующие мультисеты.
*  3. С помощью встроенной функции set_intersection находит слова, которые встречаются и в восклицательных, и в вопросительных предложениях.
*  4. С помощью map подсчитывает количество их вхождений в нужные предложения.
*  Функция разбита на блоки, соответствующие этому плану.
*/
void analyseSentence(vector<string>& sentences)
{
	// Распределяет предложения по двум векторам: вопросительные в updated_str_qst, восклицательные в updated_str_excl.
	vector<string> updated_str_excl, updated_str_qst;
	for (unsigned int i = 0; i < sentences.size(); ++i) {
		if ((sentences[i][sentences[i].size() - 1]) == '!') {
			updated_str_excl.push_back(sentences[i].substr(0,sentences[i].size() - 1));
		}
		else if ((sentences[i][sentences[i].size() - 1]) == '?') {
			updated_str_qst.push_back(sentences[i].substr(0, sentences[i].size() - 1));
		}
	}


	// Разбивает эти предложения на слова, помещая их в соответствующие мультисеты.
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


	// С помощью встроенной функции set_intersection находит слова, которые встречаются и в восклицательных, и в вопросительных предложениях.
	multiset<string> words_union;
	set_intersection(words_excl.begin(), words_excl.end(), words_qst.begin(), words_qst.end(), inserter(words_union, words_union.begin()));


	// С помощью map подсчитывает количество их вхождений в нужные предложения.
	map<string, int> words_count;
	for (auto it = words_union.begin(); it != words_union.end(); it++) {
		words_count[*it]++;
	}
	cout << "Слова, встречающиеся одновременно и в вопросительных, и в восклицательных предложениях" << endl \
		<< "и их количество (выводится минимальное количество вхождения данного слова в нужные предложения):"\
		<< endl << endl;
	for (auto it = words_count.begin(); it != words_count.end(); it++) {
		cout << "Слово:\t"<< it->first << "\tКоличество: " << it->second << endl;
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