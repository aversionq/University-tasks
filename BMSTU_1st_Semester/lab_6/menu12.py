# Карасёв ИУ7-16Б

import random as r
import math as m
main_list = []

while True:
    try:
        choose = int(input('Введите пункт меню:''\n'
                    '1 - Проинициализировать список первыми N элементами заданного ряда''\n'
                    '2 - Добавить элемент в произвольное место списка''\n'
                    '3 - Удалить произвольный элемент из списка''\n'
                    '4 - Очистить список''\n'
                    '5 - Найти значение K-го экстремума в списке, если он является списком чисел''\n'
                    '6 - Найти наиболее длинную возрастающую последовательность простых чисел''\n'
                    '7 - Найти последовательность, включающую в себя наибольшее количество элементов-строк с двойными согласными''\n'
                    'Введите пункт меню: '))
        if 1 <= choose <= 7:
            pass
        else:
            print('Вы ввели несуществующий пункт меню.')
        print()
    except ValueError:
        choose = None
        print('Вы ввели неправильный пункт меню.')
        print()


    if 'choose' in globals():
        if choose == 1:
            n = int(input('Введите, какие первые N элементов проинициализировать: '))
            x = float(input('Введите переменную x: '))
            init_list = []
            def menu_1 (n,x,k = x/2, y=1 + x/2, i=2):
                global init_list
                for j in range(n):
                    init_list.append(y)
                    k *= -((i-1)*x)/(i+2)
                    y += k
                    i += 2
                return(init_list)
            print('Результат: ',menu_1(n,x))
            main_list = init_list
            print()


        elif choose == 2:
            add_ind = int(input('Введите индекс добавления: '))
            symb = input('Введите элемент,который нужно добавить: ')
            if symb.isdigit():
                symb_final = float(symb)
            else:
                symb_final = symb
            main_list.insert(add_ind,symb_final)
            print('Результат: ',main_list)
            print()


        elif choose == 3:
            if len(main_list) > 0:
                del_ind = int(input('Введите индекс удаления: '))
                try:
                    main_list.pop(del_ind)
                    print('Результат: ',main_list)
                    print()
                except IndexError:
                    print('Элемента с таким индексом нет в массиве.')
            else:
                print('Невозможно, так как в массиве нет элементов.')


        elif choose == 4:
            if len(main_list) > 0:
                main_list.clear()
                print('Результат: ',main_list)
                print()
            else:
                print('Невозможно, так как в массиве и так нет элементов.')


        elif choose == 5:
            if len(main_list) == 0:
                print('Невозможно, так как в массиве нет элементов.')
            else:
                extr_ind = int(input('Введите номер экстремума, который нужно найти: '))
                extremum_list = []
                main_list_5 = []
                for i in range(len(main_list)):
                    if type(main_list[i]) == float:
                        main_list_5.append(main_list[i])
                for i in range(len(main_list_5)):
                    if 0 < i < len(main_list_5) - 1:
                        if (main_list_5[i-1] < main_list_5[i] and main_list_5[i] > main_list_5[i+1]) or (main_list_5[i-1] > main_list_5[i] and main_list_5[i] < main_list_5[i+1]):
                            extremum_list.append(main_list_5[i])
                if extr_ind <= len(extremum_list):
                    extremum_req = extremum_list[extr_ind-1]
                    print('Результат: ',extremum_req)
                else:
                    print('Экстремума с таким номером нет в массиве.')
                print()


        elif choose == 6:
            if len(main_list) == 0:
                print('Невозможно, так как в массиве нет элементов.')
            else:
                prime_list = []
                main_list_6 = []
                # Функция для определения простого числа
                def isprime(n):
                    a = 2
                    while n % a != 0:
                        a += 1
                    return a == n
                for i in range(len(main_list)):
                    if type(main_list[i]) == float:
                        main_list_6.append(main_list[i])
                if len(main_list_6) > 0:
                    for i in range(len(main_list_6)):
                        if main_list_6[i] - int(main_list_6[i]) == 0:
                            if isprime(main_list_6[i]) == True:
                                prime_list.append(main_list_6[i])
                    if len(prime_list) > 0:
                        k1 = 0
                        start_ind = 0
                        prime_row = []
                        prime_row_1 = []
                        for i in range(len(prime_list) - 1):
                            if prime_list[i] < prime_list[i+1]:
                                if k1 == 0:
                                    start_ind = i
                                k1 += 1
                                if k1 >= len(prime_row_1):
                                    prime_row_1.append(prime_list[i])
                                    end_ind = i
                                    prime_row = prime_list[start_ind:end_ind + 1]
                            else:
                                if k1 >= len(prime_row_1):
                                    prime_row = prime_row_1
                                k1 = 0
                        if len(prime_row) > 0:
                            prime_row.append(prime_list[end_ind + 1])
                        if len(prime_row) <= 1:
                            print('Такой последовательности нет в этом массиве.')
                        else:
                            print('Результат: ', prime_row)
                    else:
                        print('Такой последовательности нет в этом массиве.')
                else:
                    print('Такой последовательности нет в этом массиве.')


        elif choose == 7:
            if len(main_list) == 0:
                print('Невозможно, так как в массиве нет элементов.')
            else:
                d_check = 0
                main_list_str = []
                word_row = []
                word_row_ind = []
                word_row_f = []
                # Создание кортежей с русскими и английскими согласными буквами разных регистров
                rus_letters_str = 'БВГДЖЗЙКЛМНПРСТФХЦЧШЩ'
                rus_letter_str_low = rus_letters_str.lower()
                rus_letter_tuple = tuple(rus_letters_str)
                rus_letter_tuple_low = tuple(rus_letter_str_low)
                eng_letter_str = 'BCDFGHJKLMNPQRSTVWXYZ'
                eng_letter_str_low = eng_letter_str.lower()
                eng_letter_tuple = tuple(eng_letter_str)
                eng_letter_tuple_low = tuple(eng_letter_str_low)
                test_tuple = rus_letter_tuple + rus_letter_tuple_low + eng_letter_tuple +eng_letter_tuple_low
                for i in range(len(main_list)):
                    if type(main_list[i]) == str:
                        main_list_str.append(main_list[i])
                for i in range(len(main_list_str)):
                    word_list = list(main_list_str[i])
                    for j in range(len(word_list)-1):
                        if word_list[j] == word_list[j+1] and (word_list[j] in test_tuple):
                            d_check += 1
                    if d_check > 0:
                        word_row.append(main_list_str[i])
                        word_row_ind.append(i)
                        d_check = 0
                if len(word_row_ind) > 1:
                    for i in range(len(word_row_ind) - 1):
                        if word_row_ind[i+1] - word_row_ind[i] == 1:
                            word_row_f.append(word_row[i])
                            last_ind = i
                    word_row_f.append(word_row[last_ind + 1])
                else:
                    last_ind = 0
                if len(word_row_f) == 0:
                    print('Такой последовательности нет в этом массиве.')
                else:
                    print('Результат: ',word_row_f)