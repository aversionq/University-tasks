#Карасёв ИУ7-16Б. Программа вычисляет корни квадратного уравнения и их количество. Входные данные: a,b,c.
from math import sqrt

a=float(input('Введите старший коэффицент (a): '))         #Ввод коэффицента a
b=float(input('Введите второй коэффицент (b): '))          #Ввод коэффицента b
c=float(input('Введите свободный член (c): '))             #Ввод коэффицента c

if a==0:                                                   #Проверка равенства a нулю
    if b==0:                                               #Проверка равенства b нулю
        if c==0:                                           #Проверка равенства c нулю
            print('Решений бесконечно много.')
        else:                                              #Если c не равно нулю,то:
            print('Нет корней.')
    else:                                                  #Если b не равно нулю,то:
        x=(-c)/b                                           #Вычисление корня уравнения
        print('1 корень :''{:2.5g}'.format(x))
else:                                                      #Если a не равно нулю,то:
    d=b**2 - 4 * a * c                                     #Вычисление дискриминанта
    if d>0:                                                #Проверяется,больше ли нуля дискриминант
        x1=((-b) + sqrt(d))/(2*a)                                  #Вычисление первого корня,если дискриминант больше нуля
        x2=((-b) - sqrt(d))/(2*a)                                  #Вычисление второго корня,если дискриминант больше нуля
        print('2 корня: ')
        print('Первый корень = ''{:5.5g}'.format(x1))
        print('Второй корень = ''{:5.5g}'.format(x2))
    elif d<0:                                              #Проверяется,меньше ли нуля дискриминант
        print('Нет корней.')
    else:                                                  #Проверяется,равен ли дискриминант нулю
        x=(-b)/(2*a)                                       #Вычисление корня уравнения при дискриминанте равном нулю
        print('1 корень: ''{:1.5g}'.format(x))