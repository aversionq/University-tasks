# Карасёв ИУ7 - 16Б.

row_member = []
elem = []

it_count = 0
x = float(input('Введите переменную: '))
eps = float(input('Введите точность: '))
step = int(input('Введите шаг печати: '))
max_iteration = int(input('Введите максимальное количество итераций: '))

k = x/2
y = 1 + k
i = 2

# Проверка на то,сошёлся ли ряд.
while (abs(k) - eps) > 1e-10:
    row_member.append(k)
    elem.append(y)
    it_count += 1
    if it_count <= max_iteration:
        k *= -((i-1)*x)/(i+2)
        y += k
        i += 2
    else:
        print('Ряд не сошёлся.')
        break
# Вывод на экран таблицы значений.
if it_count <= max_iteration:
    print ()
    print('Сейчас будет выведена таблица значений,где:\n N - номер итерации' 
    '\n T - текущий член последовательности \n S - промежуточная сумма')
    print()
    print('|-----------------------------|''\n'
    '|    N    |   T     |    S    |''\n'
    '|-----------------------------|')
    if len(elem) % step == 0:
        for i in range(1,len(elem) + step,step):
            print('|{0:^9}|{1:^9.4g}|{2:^9.4g}|'.format(i,row_member[i-1],elem[i-1]))
    else:
        for i in range(1,len(elem),step):
            print('|{0:^9}|{1:^9.4g}|{2:^9.4g}|'.format(i,row_member[i-1],elem[i-1]))