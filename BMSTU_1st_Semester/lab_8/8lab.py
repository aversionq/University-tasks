# Карасёв ИУ7-16Б


import math as m


n_check = 1
integrals_final = []
integrals_diff = []
x1 = float(input('Введите начало интегрирования: '))
xn = float(input('Введите конец интегрирования: '))
n1 = int(input('Введите первое количество делений: '))
n2 = int(input('Введите второе количество делений: '))


# Задача функции
def function(x):
    y = x*x
    return(y)


# Метод правых прямоугольников
def RightsideRectangle(function , a , b , n):
    int1 = 0
    check = b
    try:
        h = (b-a) / n
        while check >= a:
            int1 += function(check) * h
            check -= h
    except ZeroDivisionError:
        print('Невозможно посчитать, т.к 0 делений.')
    return int1


# Метод Буля
def BoolMethod(function , a , b , n):
    int3 = 0
    try:
        h = (b - a) / n
        for i in range (n + 1):
            if i == n or i == 0:
                int3 += 7*function(a)
            elif i % 2 != 0:
                int3 += 32*function(a)
            elif i % 2 ==0 and i % 4 !=0:
                int3 += 12*function(a)
            elif i % 4 == 0:
                int3 += 14*function(a)
            a += h
        int3 *= (2*h) / 45
    except ZeroDivisionError:
        print('Невозможно посчитать, т.к 0 делений.')
    return int3

if x1 != xn:
    integral1 = RightsideRectangle(function , x1 , xn , n1)
    integral2 = RightsideRectangle(function , x1 , xn , n2)
    integral3 = BoolMethod(function , x1 , xn , n1)
    integral4 = BoolMethod(function , x1 , xn , n2)
    integrals = [integral1 , integral2 , integral3 , integral4]


    if n1 % 4 == 0 and n2 % 4 == 0 :
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|                              | {0:^30.8g} | {1:^30.8g} |'.format(n1,n2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('| Метод правых прямоугольников | {0:^30.8g} | {1:^30.8g} |'.format(integral1,integral2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|         Метод Буля           | {0:^30.8g} | {1:^30.8g} |'.format(integral3,integral4))
        print('|------------------------------|--------------------------------|--------------------------------|')
    elif n1 % 4 == 0 and n2 % 4 != 0:
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|                              | {0:^30.8g} | {1:^30.8g} |'.format(n1,n2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('| Метод правых прямоугольников | {0:^30.8g} | {1:^30.8g} |'.format(integral1,integral2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|         Метод Буля           | {0:^30.8g} |              ---               |'.format(integral3))
        print('|------------------------------|--------------------------------|--------------------------------|')
    elif n1 % 4 != 0 and n2 % 4 == 0:
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|                              | {0:^30.8g} | {1:^30.8g} |'.format(n1,n2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('| Метод правых прямоугольников | {0:^30.8g} | {1:^30.8g} |'.format(integral1,integral2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|         Метод Буля           |               ---              | {0:^30.8g} |'.format(integral4))
        print('|------------------------------|--------------------------------|--------------------------------|')
    elif n1 % 4 != 0 and n2 % 4 != 0:
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|                              | {0:^30.8g} | {1:^30.8g} |'.format(n1,n2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('| Метод правых прямоугольников | {0:^30.8g} | {1:^30.8g} |'.format(integral1,integral2))
        print('|------------------------------|--------------------------------|--------------------------------|')
        print('|         Метод Буля           |               ---              |              ---               |')
        print('|------------------------------|--------------------------------|--------------------------------|')


    # Определение самого неточного метода
    for i in range(len(integrals)):
        if integrals[i] > 0:
            integrals_final.append(integrals[i])
    average_integral = sum(integrals_final) / len(integrals_final)
    for i in range(len(integrals_final)):
        integrals_diff.append(abs(integrals_final[i] - average_integral))
    most_inaccurate_integral = integrals_diff.index(max(integrals_diff))
    if most_inaccurate_integral == 0 or most_inaccurate_integral == 1 or (integral3 == 0 and integral4 == 0):
        print('Метод правых прямоугольников самый неточный из представленных')
    elif most_inaccurate_integral == 2 or most_inaccurate_integral == 3:
        print('Метод Буля самый неточный из представленных')
    absolute_eps = abs(integrals_final[most_inaccurate_integral] - average_integral)
    relative_eps = abs(absolute_eps / average_integral)
    print('Абсолютная погрешность = ''{:6.4g}'.format(absolute_eps))
    print('Относительная погрешность = ''{:6.4g}'.format(relative_eps))


    # Вычисление итераций по заданной точности
    eps = float(input('Введите точность: '))
    if most_inaccurate_integral == 0 or most_inaccurate_integral == 1 or (integral3 == 0 and integral4 == 0):
        while abs(RightsideRectangle(function , x1 , xn , n_check) - RightsideRectangle(function , x1 , xn , n_check * 2)) > eps:
            n_check += 1
        print('Требуемое количество итераций для заданной точности: ', n_check)
        print('Значение после нужного количества итераций: ''{:8.6g}'.format(RightsideRectangle(function , x1 , xn , n_check)))
    elif most_inaccurate_integral == 2 or most_inaccurate_integral == 3:
        while abs(BoolMethod(function , x1 , xn , n_check) - BoolMethod(function , x1 , xn , n_check * 2)) > eps:
            n_check += 1
        print('Требуемое количество итераций для заданной точности: ', n_check)
        print('Значение после нужного количества итераций: ''{:8.6g}'.format(BoolMethod(function , x1 , xn , n_check)))