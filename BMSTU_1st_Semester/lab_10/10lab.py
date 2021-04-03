# Карасёв ИУ7-16Б


def max_length(array):
    max_len = 0
    for i in range(len(array)):
        if len(array[i]) > max_len:
            max_len = len(array[i])
    return(max_len)

punct_marks = ('.' , ',' , ':' , '!' , '?')
strings = ['Проснувшись однажды утром после беспокойного сна, Грегор',
           ' Замза обнаружил, что он у себя в постели превратился в страшное насекомое. Лежа на ппррааа панцирнотвердой спине, он видел, стоило ему приподнять голову,',
           ' свой щщщззззаааппвв коричневый, выпуклый, разделенный дугообразными чешуйками живот, на верхушке которого еле держалось готовое аапп скоро окончательно сползти',
           ' одеяло. Его многочисленные, убого тонкие по 11+2*2^2 сравнению с остальным телом ножки беспомощно копошились у него перед глазами.Это не было сном. Его комната,',
           ' настоящая, разве что ааггголл слишком маленькая, но обычная комната, шшшпппвв мирно покоилась в своих четырех ффппььээ хорошо знакомых стенах.']


while True:
    try:
        choose = int(input(
                    '1 - Выравнивание текста по левому краю.''\n'
                    '2 - Выравнивание текста по правому краю.''\n'
                    '3 - Выравнивание текста по ширине.''\n'
                    '4 - Удаление заданного слова.''\n'
                    '5 - Замена одного слова другим во всем тексте.''\n'
                    '6 - Вычисление арифметического выражения.''\n'
                    '7 - Найти предложение, в котором максимальное количество слов, в которых каждая буква входит не менее двух раз.''\n'
                    'Введите пункт меню: '))
        if 1 <= choose <= 7:
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
            print()
            for i in range(len(strings)):
                if strings[i][0] == ' ':
                    string_to_change = strings[i][1:]
                    print(string_to_change)
                else:
                    print(strings[i])
            print()

        elif choose == 2:
            print()
            max_len = max_length(strings)
            for i in range(len(strings)):
                if len(strings[i]) != max_len:
                    print(' ' * (max_len - len(strings[i])) + strings[i])
                else:
                    print(strings[i])
            print()
        

        elif choose == 3:
            print()
            strings_shirina = []
            out_check = 0
            max_len = max_length(strings)
            for i in range(len(strings)):
                if strings[i][0] == ' ':
                    strings_shirina.append(strings[i][1:])
                else:
                    strings_shirina.append(strings[i])
            for i in range(len(strings_shirina)):
                length = len(strings_shirina[i])
                while length < max_len:
                    for j in range(length):
                        if strings_shirina[i][j] == ' ' and strings_shirina[i][j-1] != ' ':
                            strings_shirina[i] = strings_shirina[i][:j] + ' ' + strings_shirina[i][j:]
                            length += 1
                            if length == max_len:
                                break
            for i in range(len(strings_shirina)):
                print(strings_shirina[i])


        elif choose == 4:
            print()
            text_to_delete = input('Введите слово, которое нужно удалить: ')
            print()
            for i in range(len(strings)):
                splitted_strings = strings[i].split()
                for j in range(len(splitted_strings)):
                    if (text_to_delete == splitted_strings[j]) or (text_to_delete == splitted_strings[j][:-1] and splitted_strings[j][-1] in punct_marks):
                        splitted_strings[j] = splitted_strings[j].replace(text_to_delete,'')
                strings[i] = ' '.join(splitted_strings)
            for i in range(len(strings)):
                print(strings[i])
            print()


        elif choose == 5:
            print()
            text_old = input('Введите слово, которое нужно заменить: ')
            text_new = input('Введите слово,на которое нужно заменить: ')
            print()
            for i in range(len(strings)):
                splitted_strings = strings[i].split()
                for j in range(len(splitted_strings)):
                    if (text_old == splitted_strings[j]) or (text_old == splitted_strings[j][:-1] and splitted_strings[j][-1] in punct_marks):
                        splitted_strings[j] = splitted_strings[j].replace(text_old,text_new)
                strings[i] = ' '.join(splitted_strings)
            for i in range(len(strings)):
                print(strings[i])
            print()
        

        elif choose == 6:
            print()
            plus1 = ''
            plus2 = ''
            mult2 = ''
            mult1 = ''
            to_pow = ''
            stepen = ''
            div1 = ''
            div2 = ''
            min1 = ''
            min2 = ''
            to_count = []
            math_check = ('0','1','2','3','4','5','6','7','8','9','*','/','^','+','-')
            nums = [str(i) for i in range(0,10000)]
            for i in range(len(strings)):
                on_sent = strings[i].split()
                for j in range(len(on_sent)):
                    if on_sent[j][0] in math_check:
                        to_change_in_text = [i,j]
            for i in range(len(strings)):
                for j in range(len(strings[i])):
                    if strings[i][j] in math_check:
                        to_count.append(strings[i][j])
            while len(to_count) > 1:
                if '^' in to_count:
                    ind_pow = to_count.index('^')
                    ind_pow_begin = ind_pow
                    try:
                        while str(to_count[ind_pow+1]) in nums and ind_pow <= len(to_count):
                            stepen += str(to_count[ind_pow+1])
                            ind_pow += 1
                    except IndexError:
                        pass
                    for i in range(ind_pow,ind_pow_begin,-1):
                        to_count.pop(i)
                    ind_pow = to_count.index('^')
                    ind_pow_begin = ind_pow
                    while str(to_count[ind_pow-1]) in nums and ind_pow >= 0:
                        to_pow += str(to_count[ind_pow-1])
                        ind_pow -= 1
                    for i in range(ind_pow_begin,ind_pow,-1):
                        to_count.pop(i)
                    to_count[ind_pow] = int(to_pow)**int(stepen)
                    to_count[ind_pow] = int(to_count[ind_pow])
                

                elif '*' in to_count:
                    ind_mult = to_count.index('*')
                    ind_mult_begin = ind_mult
                    try:
                        while str(to_count[ind_mult+1]) in nums and ind_mult <= len(to_count):
                            mult2 += str(to_count[ind_mult+1])
                            ind_mult += 1
                    except IndexError:
                        pass
                    for i in range(ind_mult,ind_mult_begin,-1):
                        to_count.pop(i)
                    ind_mult = to_count.index('*')
                    ind_mult_begin = ind_mult
                    while str(to_count[ind_mult-1]) in nums and ind_mult >= 0:
                        mult1 += str(to_count[ind_mult-1])
                        ind_mult -= 1
                    for i in range(ind_mult_begin,ind_mult,-1):
                        to_count.pop(i)
                    to_count[ind_mult] = int(mult1) * int(mult2)
                    to_count[ind_mult] = int(to_count[ind_mult])                    
                

                elif '/' in to_count:
                    ind_divide = to_count.index('/')
                    ind_divide_begin = ind_divide
                    try:
                        while str(to_count[ind_divide+1]) in nums and ind_divide <= len(to_count):
                            div2 += str(to_count[ind_divide+1])
                            ind_divide += 1
                    except IndexError:
                        pass
                    for i in range(ind_divide,ind_divide_begin,-1):
                        to_count.pop(i)
                    ind_divide = to_count.index('/')
                    ind_divide_begin = ind_divide
                    while str(to_count[ind_divide-1]) in nums and ind_divide >= 0:
                        div1 += str(to_count[ind_divide-1])
                        ind_divide -= 1
                    for i in range(ind_divide_begin,ind_divide,-1):
                        to_count.pop(i)
                    to_count[ind_divide] = int(div1) / int(div2)
                    to_count[ind_divide] = int(to_count[ind_divide])                    


                elif '+' in to_count:
                    ind_plus = to_count.index('+')
                    ind_plus_begin = ind_plus
                    try:
                        while str(to_count[ind_plus+1]) in nums and ind_plus <= len(to_count):
                            plus2 += str(to_count[ind_plus+1])
                            ind_plus += 1
                    except IndexError:
                        pass
                    for i in range(ind_plus,ind_plus_begin,-1):
                        to_count.pop(i)
                    ind_plus = to_count.index('+')
                    ind_plus_begin = ind_plus
                    while str(to_count[ind_plus-1]) in nums and ind_plus >= 0:
                        plus1 += str(to_count[ind_plus-1])
                        ind_plus -= 1
                    for i in range(ind_plus_begin,ind_plus,-1):
                        to_count.pop(i)
                    to_count[ind_plus] = int(plus1) + int(plus2)
                    to_count[ind_plus] = int(to_count[ind_plus])                    
                

                elif '-' in to_count:
                    ind_minus = to_count.index('-')
                    ind_minus_begin = ind_minus
                    try:
                        while str(to_count[ind_minus+1]) in nums and ind_minus <= len(to_count):
                            min2 += str(to_count[ind_minus+1])
                            ind_minus += 1
                    except IndexError:
                        pass
                    for i in range(ind_minus,ind_minus_begin,-1):
                        to_count.pop(i)
                    ind_minus = to_count.index('-')
                    ind_minus_begin = ind_minus
                    while str(to_count[ind_minus-1]) in nums and ind_minus >= 0:
                        min1 += str(to_count[ind_minus-1])
                        ind_minus -= 1
                    for i in range(ind_minus_begin,ind_minus,-1):
                        to_count.pop(i)
                    to_count[ind_minus] = int(min1) - int(min2)
                    to_count[ind_minus] = int(to_count[ind_minus])                       

            split_to_print = strings[to_change_in_text[0]].split()
            split_to_print[to_change_in_text[1]] = str(to_count[0])
            strings[to_change_in_text[0]] = ' '.join(split_to_print)
            for i in range(len(strings)):
                print(strings[i])
            print()
        

        elif choose == 7:
            print()
            sentence_with_doubles = []
            all_sentences = ''
            for i in range(len(strings)):
                all_sentences += strings[i]
            setnences_divided = all_sentences.split('.')
            setnences_divided.pop(-1)
            for i in range(len(setnences_divided)):
                sentence_with_doubles.append([])
                sentence_split = setnences_divided[i].split()
                for j in range(len(sentence_split)):
                    if ',' in sentence_split[j]:
                        sentence_split[j] = sentence_split[j].replace(',','')
                    words = list(sentence_split[j])
                    double_check = []
                    for k in range(len(words)):
                        if words[k] not in double_check:
                            double_check.append(words[k])
                    amount_check = []
                    for k in range(len(double_check)):
                        amount_check.append(words.count(double_check[k]))
                    amount_count = 0
                    for k in range(len(amount_check)):
                        if amount_check[k] >= 2:
                            amount_count += 1
                    to_add = 0
                    if amount_check == len(amount_check):
                        to_add += 1
                    sentence_with_doubles[i].append(to_add)
            index_to_print = sentence_with_doubles.index(max(sentence_with_doubles))
            print(setnences_divided[index_to_print])
            print()    