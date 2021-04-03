# Карасёв ИУ7-16Б. График функции

import math as m

y_num = []
y_help = []
x_help = []
check_sign = 1
sign_change = 0
dop1 = -1
dop2 = -1
dop3 = -1

bgn,end1,step = map(float,input('Введите начальную точку,'
'конечную точку и размер шага через пробел: ').split())

# Алгоритм для того,чтобы range работал с float
Abgn = bgn
Aend1 = end1
Astep = step
 
while abs(Astep % 10) != 0:
    dop3+=1
    Astep = Astep * 10
while abs(Abgn % 10) != 0:
    dop1+=1
    Abgn = Abgn * 10
while abs(Aend1 % 10) != 0:
    dop2+=1
    Aend1 = Aend1 * 10

biggestexp = [dop1,dop2,dop3]
dopF = max(biggestexp)

bgn = bgn * 10**dopF
end1 = end1 * 10**dopF
step = step * 10**dopF

# Заголовок для таблицы
print('|     z     |     p1     |     p2    |')
print('|------------------------------------|')


# Построение таблицы
for z1 in range (int(bgn),int(end1)+int(step),int(step)):
    z = z1/(10**dopF)
    if z1 < 0:
        p1 = z**4 - 3*z**3 + 8*z**2 - 5
        y_help.append(p1)
        x_help.append(z)
        print ('|{0:^10.4g} | {1:^10.4g} |Нет,т.к z<0|'.format(z,p1))
    else:
        p1 = z**4 - 3*z**3 + 8*z**2 - 5
        p2 = 10.125 * m.sqrt(z) - 20.15 * m.cos(m.pi/2 * z)
        y_help.append(p1)
        x_help.append(z)
        if z1 > int(bgn):
            if p2 / check_sign < 0:
                sign_change += 1
                check_sign = p2
            else:
                check_sign = p2
        else:
            check_sign = p2
        print ('|{0:^10.4g} | {1:^10.4g} | {2:^10.4g}|'.format(z,p1,p2))

print()
print()
print('Сколько раз функция p2 меняла свой знак: ',sign_change)
print()
print()

for i in range (len(x_help) - 1):
    for j in range(len(x_help)-2,i-1,-1):
        if x_help[j] > x_help[j+1]:
            x_help[j],x_help[j+1] = x_help[j+1],x_help[j]

ymax = max(y_help)
xmax = max(x_help)
ymin = min(y_help)
xmin = min(x_help) 

# Задаётся длина оси OY (const), пользователь вводит кол-во засечек
# Вычисляется периодичность расстановки засечек
y_length = 166
tics = int(input('Введите количество засечек от 4 до 8: '))
marks = y_length / tics
marks_num = (ymax - ymin) / tics

# Вычисление значений для засечек
for i in range (tics+1):
    if i == 0:
        y_num_digit = ymin
        y_num.append(y_num_digit)
    else:
        y_num_digit += abs(marks_num)
        y_num.append(y_num_digit)

# Наносим значения для засечек
for i in range(tics+1):
    if i == 0:
        print(' ' * 6,end='')
        print('{:4.2g}'.format(y_num[i]),end='')
    elif i < tics:
        print(' ' * int(round((marks-5))),end='')
        print('{:4.2g}'.format(y_num[i]),end='')
    else:
        print(' ' * int(round((marks-5))),end='')
        print('{:4.2g}'.format(y_num[i]))

# Чертим ось OY с засечками
for i in range (tics+1):
    if i == 0:
        print(' ' * 9,end='')
        print('|',end='')
    elif i < (tics):
        print('-' * int(round((marks-1))),end='')
        print('|',end='')
    else:
        print('-' * int(round((marks-1))),end='')
        print('|')

# Чертим ось OX и ставим точки
for i in range(len(x_help)):
    mshtb = int((abs((y_help[i]) - ymin) / marks_num) * (marks-3) +5)
    if ymin < 0:
        if y_help[i] < 0:
            print(' ' * 3,end='')
            print(' ' * mshtb,end='')
            print('*',end='')
            print(' ' * int((abs(ymin / marks_num) * (marks-3) +5 ) - mshtb),end='')
            print('{:4.2g}'.format(x_help[i]),end='')
            print('|')
        else:
            if tics>4:
                print(' ' * 4,end='')
                print(' ' * int(abs(ymin / marks_num) * (marks-3) +5 ),end='')
                print('{:4.2g}'.format(x_help[i]),end='')
                print('|',end='')
                print(' ' * int(abs(mshtb - (abs(ymin / marks_num) * (marks-3) +5 ))),end='')
                print('*')
            else:
                print(' ' * 4,end='')
                print(' ' * int(abs(ymin / marks_num) * (marks-2) +5 ),end='')
                print('{:4.2g}'.format(x_help[i]),end='')
                print('|',end='')
                print(' ' * int(abs(mshtb - (abs(ymin / marks_num) * (marks-3) +5 ))),end='')
                print('*')
    else:
        print('{:4.2g}'.format(x_help[i]),end='')
        print('|',end='')
        print(' ' * mshtb,end='')
        print('*')