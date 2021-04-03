# Карасёв ИУ7-16Б


import pickle
dictionary = {}
dictionary_for_one = {}
value_info = []
space_check = 1


while True:
    try:
        choose = int(input(
                    '1 - Создание БД.''\n'
                    '2 - Добавление записи в БД.''\n'
                    '3 - Вывод всей БД.''\n'
                    '4 - Поиск записей по одному полю.''\n'
                    '5 - Поиск записей по двум полям.''\n'
                    'Введите пункт меню: '))
        if 1 <= choose <= 5:
            pass
        else:
            print()
            print('Вы ввели несуществующий пункт меню.')
        print()
    except ValueError:
        choose = None
        print()
        print('Вы ввели неправильный пункт меню.')
        print()


    if 'choose' in globals():
        if choose == 1:
            filename = input('Введите название файла: ')
            bd_meaning = input('Введите назначение этой БД: ')
            things_in_bd_meaning = input('Введите значение записей: ')
            n_fields = int(input('Введите количество полей: '))
            bd_info = [bd_meaning , n_fields , things_in_bd_meaning]
            for i in range(n_fields):
                print('Введите поле №',i+1,': ')
                input_field = input()
                bd_info.append(input_field)
                value_info.append([input_field])
            filename += '.bin'
            with open(filename , 'wb') as file_:
                pickle.dump(bd_info , file_)
                pickle.dump(value_info , file_)
            print()


        elif choose == 2:
            values_fix = []
            filename = input('Введите название файла, в который добавить запись: ')
            filename += '.bin'
            try:
                with open(filename , 'rb') as file_:
                    try:
                        check_file = pickle.load(file_)
                        values = pickle.load(file_)                          
                        try:
                            dictionary = pickle.load(file_)
                        except EOFError:
                            dictionary = {}                           
                        to_add_name = input('Введите название записи: ')
                        if to_add_name in dictionary:
                            space_check += 1                            
                            to_add_name += ' ' * space_check
                        print(to_add_name)
                        for i in range(3,len(check_file)):
                            to_add_values = input(str(check_file[i]) + ' которую(ый) надо ввести: ')
                            values[i-3].append(to_add_values)
                            with open(filename , 'wb') as file_:
                                pickle.dump(check_file , file_)
                                pickle.dump(values , file_)                            
                                values_fix.append(to_add_values)
                                dictionary.update({to_add_name : values_fix})
                                pickle.dump(dictionary,file_) 
                        print()                           
                    except EOFError:
                        print('БД не создана.')
                        print()                    
            except FileNotFoundError:
                print('Файл не найден.')
                print()


        elif choose == 3:
            filename = input('Введите название файла, содержимое которого вывести: ')
            filename += '.bin'
            print()
            try:
                with open(filename , 'rb') as file_:
                    try:
                        check_file = pickle.load(file_)
                        print('Эта БД ' + str(check_file[0]))
                        for i in range(2,len(check_file)-1):
                            print('-'*37 , end='')
                        print()
                        with open(filename , 'rb') as file_:
                            upper_text = pickle.load(file_)
                            for i in range(2,len(upper_text)):
                                print('{:30}'.format(upper_text[i]) , end='')
                            print()
                            values_to_pass = pickle.load(file_)                            
                            print()
                            main_text = pickle.load(file_)                
                            for line in main_text:
                                print('{:30}'.format(line), end='')                                
                                for signs in range(len(line)):
                                    try:
                                        print('{:30}'.format(main_text[line][signs]), end ='')
                                    except IndexError:
                                        pass
                                print()
                            print()
                        print()
                    except EOFError:
                        print('В файле ничего нет')
                        print()
            except FileNotFoundError:
                print('Файл не найден.')
                print()


        elif choose == 4:
            filename = input('Введите название файла, содержимое которого вывести: ')
            filename += '.bin'
            to_type_check = 0
            to_type_check_1 = 0
            try:
                with open(filename , 'rb') as file_:
                    try:
                        to_pass = pickle.load(file_)
                        values_check = pickle.load(file_)
                        check_file = pickle.load(file_)
                        to_search_field = input('Введите поле, по которому искать: ')
                        for i in range(len(values_check)):
                            if to_search_field.lower() == values_check[i][0].lower():
                                to_search_exact = input('Введите значение, которое искать в поле ' + str(values_check[i][0]) + ': ')
                                print()
                                for keys in check_file:
                                    if to_search_exact.lower() == check_file[keys][i].lower():
                                        print('{:30}'.format(keys), end='')
                                        for signs in range(len(keys)):
                                            try:
                                                print('{:30}'.format(check_file[keys][signs]), end ='')
                                            except IndexError:
                                                pass
                                        print()                                                                    
                        print()
                    except EOFError:
                        print('В файле ничего нет')
                        print()
            except FileNotFoundError:
                print('Файл не найден.')
                print()


        elif choose == 5:
            filename = input('Введите название файла, содержимое которого вывести: ')
            filename += '.bin'
            to_remember = []
            try:
                with open(filename , 'rb') as file_:
                    try:
                        to_pass = pickle.load(file_)
                        values_check = pickle.load(file_)
                        check_file = pickle.load(file_)
                        to_search_field_1 = input('Введите первое поле, по которому искать: ')
                        for i in range(len(values_check)):
                            if to_search_field_1.lower() == values_check[i][0].lower():
                                to_search_exact_1 = input('Введите значение, которое искать в поле ' + str(values_check[i][0]) + ': ')
                                print()
                                for keys in check_file:
                                    if to_search_exact_1.lower() == check_file[keys][i].lower():
                                        to_remember.append(keys)
                        to_search_field_2 = input('Введите второе поле, по которому искать: ')
                        for i in range(len(values_check)):
                            if to_search_field_2.lower() == values_check[i][0].lower():
                                to_search_exact_2 = input('Введите значение, которое искать в поле ' + str(values_check[i][0]) + ': ')
                                print()
                                for j in to_remember:
                                    for keys in check_file:
                                        if to_search_exact_2.lower() == check_file[keys][i].lower() and keys == j:
                                            print('{:30}'.format(keys), end='')
                                            for signs in range(len(keys)):
                                                try:
                                                    print('{:30}'.format(check_file[keys][signs]), end ='')
                                                except IndexError:
                                                    pass
                                            print()  
                                print()                                         
                    except EOFError:
                        print('В файле ничего нет')
                        print()
            except FileNotFoundError:
                print('Файл не найден.')
                print()