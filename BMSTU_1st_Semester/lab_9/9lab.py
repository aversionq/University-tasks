# Карасёв ИУ7-16Б


def ToViginere(string , key , alphabet_):
    string_new = ''
    key_repl = key.replace(' ','')
    # Определяем ключ, в зависимости от длины строки
    if len(string) > len(key_repl):
        to_time = len(string) // len(key_repl)
        to_div = len(string) % len(key_repl)
        new_key = key_repl*to_time + key_repl[:to_div]
    elif len(key_repl) > len(string):
        new_key = key_repl[:len(string)]
    else:
        new_key = key_repl
    t = 0
    new_key = new_key.lower()
    string = string.lower()
    # Замена символов
    for i in range(len(new_key)):
        if string[i] in alphabet_:
            ind_to_change = int(alphabet_.index(string[i])) + int(alphabet_.index(new_key[i + t]))
            if ind_to_change < len(alphabet_):
                letter_change = ind_to_change
            else:
                letter_change = ind_to_change - len(alphabet_)
            string_new += alphabet_[letter_change]
        else:
            t -= 1
            string_new += string[i]
    return string_new


def FromViginere(string , key , alphabet_):
    string_new = ''
    key_repl = key.replace(' ','')
    # Определяем ключ, в зависимости от длины строки
    if len(string) > len(key_repl):
        to_time = len(string) // len(key_repl)
        to_div = len(string) % len(key_repl)
        new_key = key_repl*to_time + key_repl[:to_div]
    elif len(key_repl) > len(string):
        new_key = key_repl[:len(string)]
    else:
        new_key = key_repl
    t = 0
    new_key = new_key.lower()
    string = string.lower()
    # Замена символов
    for i in range(len(new_key)):
        if string[i] in alphabet_:
            ind_to_change = int(alphabet_.index(string[i])) - int(alphabet_.index(new_key[i + t]))
            if ind_to_change < len(alphabet_):
                letter_change = ind_to_change
            else:
                letter_change = ind_to_change - len(alphabet_)
            string_new += alphabet_[letter_change]
        else:
            t -= 1
            string_new += string[i]
    return string_new


while True:
    try:
        choose = int(input('Введите пункт меню:''\n'
                    '1 - Ввод строки''\n'
                    '2 - Настройка шифрующего алгоритма''\n'
                    '3 - Шифрование строки, используя шифр Виженера''\n'
                    '4 - Расшифровывание строки''\n'
                    'Введите пункт меню: '))
        if 1 <= choose <= 4:
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
            main_string = input('Введите строку: ')
            print()
            while True:
                if len(main_string) == 0:
                    print('В строке нет символов.')
                    print()
                    break
                else:
                    print('Результат: ',main_string)
                    print()
                    break


        if choose == 2:
            key9 = input('Введите ключ: ')
            print()
            while True:
                if len(key9) == 0:
                    print('В ключе нет символов.')
                    print()
                    break
                else:
                    print('Результат: ',key9)
                    print()
                    break


        if choose == 3:
            try:
                alphabet_high = 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'
                alphabet_low = alphabet_high.lower()
                alphabet = alphabet_low
                print('Результат: ',ToViginere(main_string , key9 , alphabet))
                print()
            except NameError:
                print('Вы ещё не ввели строку.')
        

        if choose == 4:
            try:
                alphabet_high = 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'
                alphabet_low = alphabet_high.lower()
                alphabet = alphabet_low
                print('Результат: ', FromViginere(main_string , key9 , alphabet))
                print()
            except NameError:
                print('Вы ещё не ввели строку.')