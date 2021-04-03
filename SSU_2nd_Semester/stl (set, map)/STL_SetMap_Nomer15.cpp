///*
//Файл успешно открыт!
//
//Исходный текст:
//one two 2 8683 two three 3 3 three three 782 1 1 1 four four four four 4 444
//
//Введите число - требуемое количество вхождений слова в текст: 3
//
//Слова, количество которых в тексте = 3:
//three
//*/
//
//
//#include <iostream>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <fstream>
//#include <cstring>
//#include <string>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string text;
//	ifstream file_in;
//	file_in.exceptions(ifstream::badbit | ifstream::failbit); // Подключаем обработку исключений для класса ifstream.
//
//
//	multiset<string> words;
//	try
//	{
//		file_in.open("to_check.txt");
//		cout << "Файл успешно открыт!" << endl;
//		cout << endl << "Исходный текст: " << endl;
//
//
//		// Отделяем слова от чисел и записываем их в мультисет words.
//		while (!file_in.eof()) {
//			bool flag;
//			file_in >> text;
//			cout << text << ' ';
//			for (unsigned int i = 0; i < text.size(); ++i) {
//				flag = false;
//				if (!isalpha(text[i])) {
//					flag = true;
//				}
//				if (flag) {
//					break;
//				}
//			}
//			if (!flag) {
//				words.insert(text);
//			}
//		}
//		file_in.close();
//
//
//		// Считаем количество вхождений слов в текст.
//		map <string, int> words_count;
//		for (auto it = words.begin(); it != words.end(); it++) {
//			words_count[*it]++;
//		}
//
//
//		int requestedAmount;
//		vector<string> words_to_print;
//		cout << endl << endl << "Введите число - требуемое количество вхождений слова в текст: ";
//		cin >> requestedAmount;
//		if (requestedAmount <= 0) {
//			cout << endl << "Вы ввели неположительное число, такой поиск невозможен." << endl;
//		}
//		else {
//			for (auto it = words_count.begin(); it != words_count.end(); it++) {
//				if (it->second == requestedAmount) {
//					words_to_print.push_back(it->first);
//				}
//			}
//
//
//			if (words_to_print.size() > 0) {
//				cout << endl << "Слова, количество которых в тексте = " << requestedAmount << ":" << endl;
//				for (unsigned int i = 0; i < words_to_print.size(); ++i) {
//					cout << words_to_print[i] << endl;
//				}
//			}
//			else {
//				cout << endl << "В данном тексте нет слов, колиечство вхождений в текст которых = " << requestedAmount << "." << endl;
//			}
//		}
//	}
//	catch (exception)
//	{
//		cout << endl << "Ошибка открытия файла!" << endl;
//	}
//
//
//	return 0;
//}


// normal_distribution
#include <iostream>
#include <random>
#include <vector>


//void randomGen(int seed)
//{
//
//}
//
//
//int main()
//{
//    const int nrolls = 1000;  // number of experiments
//    const int nstars = 100;    // maximum number of stars to distribute
//
//    std::default_random_engine generator;
//    std::normal_distribution<double> distribution(5.0, 1.0);
//
//    int p[30] = {};
//    std::vector<double> check;
//
//    for (int i = 0; i < nrolls; ++i) {
//        double number = distribution(generator);
//        if ((number >= 0.0) && (number < 30.0)) {
//            ++p[int(number)];
//            check.push_back(number);
//        }
//
//    }
//
//    std::cout << "normal_distribution (5.0,2.0):" << std::endl;
//
//    for (int i = 0; i < 30; ++i) {
//        //std::cout << i << "-" << (i + 1) << ": ";
//        //std::cout << std::string(p[i] * nstars / nrolls, '=') << std::endl;
//        std::cout << check[i] << std::endl;
//    }
//
//    return 0;
//}


int main()
{
	double x = 0.55;
	double result;
	do
	{
		xk = xk1;
		ouble t = xk / sqrt_2;
		xk1 = xk - sqrt_pi_2 * exp(t * t) * (erf(t) + b);
		it++;
	}

    while (fabs(xk - xk1) >= eps);
	std::cout << 1 / result;
}