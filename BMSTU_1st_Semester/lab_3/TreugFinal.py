#Карасёв ИУ7-16Б. Что делает программа:
# 1. Находит длины сторон треугольника по заданным целочисленным координатам вершин.
# 2. Определяет, тупоугольный ли треугольник.
# 3. Определяет, находится ли точка с заданными координатами в треугольнике. Если находится, то программа находит расстояние от этой точки до ближайшей стороны.
# 4. Величину биссектрисы,проведённой из наименьшего угла треугольника.
import math as m

checktrue=True

ax,ay=map(int,input('Введите координаты первой точки (A) через пробел: ').split())    #Ввод координат первой точки (A)
bx,by=map(int,input('Введите координаты второй точки (B) через пробел: ').split())    #Ввод координат второй точки (B)
cx,cy=map(int,input('Введите координаты третьей точки (C) через пробел: ').split())   #Ввод координат третьей точки (C)

st1=m.sqrt((bx-ax)**2 + (by-ay)**2)    #Расчёт длины 1 стороны (AB)
st2=m.sqrt((cx-bx)**2 + (cy-by)**2)    #Расчёт длины 2 стороны (BC)
st3=m.sqrt((cx-ax)**2 + (cy-ay)**2)    #Расчёт длины 3 стороны (AC)
mssvside=[st1,st2,st3]        #Список из трёх сторон
maxside=max(mssvside)         #Вычисление наибольшей стороны
while checktrue==True:
    if (abs(((bx-ax)*(cy-ay)) - ((cx-ax)*(by-ay))) <= 1e-6 ):
        print('Все точки лежат на одной прямой. Треугольник невозможен.')
        checktrue=False
        break
    else:
        print('Сторона 1 = ''{:1.5g}'.format(st1))
        print('Сторона 2 = ''{:1.5g}'.format(st2))
        print('Сторона 3 = ''{:1.5g}'.format(st3))

        k1=0                          #Счётчик на случай,если будет выполнено 2 условия (когда достаточно 1)
        if maxside==st1:                                #Проверка равенства,чтобы понять,с какими сторонами надо сранивать наибольшую
            k1+=1                                       #Работа счётчика
            if round(maxside**2) > round(st2**2) + round(st3**2):             # c**2 > a**2 + b**2 ,где c - наибольшая сторона. Условие тупоугольного треугольника
                print('Треугольник тупоугольный.')
            else:
                print('Треугольник не тупоугольный.')
        if maxside==st2 and k1==0:                       #Проверка равенства,чтобы понять,с какими сторонами надо сранивать наибольшую
            k1+=1                                        #Работа счётчика
            if round(maxside**2) > round(st1**2) + round(st3**2):             # c**2 > a**2 + b**2 ,где c - наибольшая сторона. Условие тупоугольного треугольника
                print('Треугольник тупоугольный.')
            else:
                print('Треугольник не тупоугольный.')
        if maxside==st3 and k1==0:                       #Проверка равенства,чтобы понять,с какими сторонами надо сранивать наибольшую
            if round(maxside**2) > round(st2**2) + round(st1**2):             # c**2 > a**2 + b**2 ,где c - наибольшая сторона. Условие тупоугольного треугольника
                print('Треугольник тупоугольный.')
            else:
                print('Треугольник не тупоугольный.')

        nx,ny,=(map(int,input('Введите через пробел координаты точки (N) ,которую нужно проверить на нахождение в треугольнике: ').split()))

        sda=m.sqrt((nx-ax)**2 + (ny-ay)**2)                 #Вычисление длины AN
        sdb=m.sqrt((nx-bx)**2 + (ny-by)**2)                 #Вычисление длины BN
        sdc=m.sqrt((nx-cx)**2 + (ny-cy)**2)                 #Вычисление длины CN
        pp1=(sda+sdc+st3)/2                                 #Вычисление полупериметра треугольника ANC
        pls1=m.sqrt(pp1*(pp1-sda)*(pp1-sdc)*(pp1-st3))      #Вычисление площади треугольника ANC по формуле Герона
        pp2=(sda+sdb+st1)/2                                 #Вычисление полупериметра треугольника ANB
        pls2=m.sqrt(pp2*(pp2-sda)*(pp2-sdb)*(pp2-st1))      #Вычисление площади треугольника ANB по формуле Герона
        pp3=(sdb+sdc+st2)/2                                 #Вычисление полупериметра треугольника BNC
        pls3=m.sqrt(pp3*(pp3-sdb)*(pp3-sdc)*(pp3-st2))      #Вычисление площади треугольника BNC по формуле Герона
        sum3pl=pls3+pls2+pls1                               #Сумма площадей трёх треугольников
        pol=(st1+st2+st3)/2                                 #Вычисление полупериметра большого треугольника (ABC)
        sob=m.sqrt(pol*(pol-st1)*(pol-st2)*(pol-st3))       #Вычисление площади треугольника ABC по формуле Герона

        if (abs(sob-sum3pl) <= 0.00001) :            #Сравнение суммы площадей ANC , ANB , BNC и площади ABC с учётом погрешности
            print('Точка находится в треугольнике!')
            h1 = (2*pls1)/st3                               #Вычисление перпендикуляра от точки N до стороны AC
            h2 = (2*pls2)/st1                               #Вычисление перпендикуляра от точки N до стороны AB
            h3 = (2*pls3)/st2                               #Вычисление перпендикуляра от точки N до стороны BC
            mssv=[h1,h2,h3]                                 #Список из найденных перпендикуляров
            dobl=min(mssv)                                  #Нахождение расстояния до ближайшей стороны
            print('Расстояние от точко до ближайшей стороны = ''{:1.5g}'.format(dobl))
        else:
            print("Точка вне треугольника.")

        k2=0                                    #Счётчик на случай,если будет выполнено 2 условия (когда достаточно 1)
        if st2!=maxside:                        #Проверка на случай,если угол - тупой (надо найти минимальный угол)
            ug1=(2*sob)/(st1*st3)               #Вычисление синуса угла BAC
            ug11=m.asin(ug1)                    #Вычисление угла BAC (в радианах) 
            ugf1=m.degrees(ug11)                #Перевод угла из радианов в градусы
        else:
            ugf1=180                            #Задаётся максимально возможное значение,для последующей проверки
        if st3!=maxside:                        #Проверка на случай,если угол - тупой (надо найти минимальный угол)
            ug2=(2*sob)/(st1*st2)               #Вычисление синуса угла ABC
            ug22=m.asin(ug2)                    #Вычисление угла ABC (в радианах) 
            ugf2=m.degrees(ug22)                #Перевод угла из радианов в градусы
        else:
            ugf2=180                            #Задаётся максимально возможное значение,для последующей проверки
        if st1!=maxside:                        #Проверка на случай,если угол - тупой (надо найти минимальный угол)
            ug3=(2*sob)/(st2*st3)               #Вычисление синуса угла BCA
            ug33=m.asin(ug3)                    #Вычисление угла BCA (в радианах) 
            ugf3=m.degrees(ug33)                #Перевод угла из радианов в градусы
        else:
            ugf3=180                            #Задаётся максимально возможное значение,для последующей проверки
        mug=[ugf1,ugf2,ugf3]                 #Список с величинами углов
        minug=min(mug)                       #Поиск наименьшего угла
        if ugf1==minug:                             #Проверка равенства данного угла наименьшему углу
            k2+=1                                   #Работа счётчика
            ugf1t=(ugf1)/2                          #Угол BAC делится пополам из-за биссектрисы
            ugf1d=m.radians(ugf1t)                  #Перевод поделенного угла из градусов в радианы
            biss=(sob)/(st3*(m.sin(ugf1d)))         #Вычисление величины биссектрисы,проведённой из угла BAC
            print('Биссектриса,проведённая из наименьшего угла = ''{:1.5g}'.format(biss))
        if ugf2==minug and k2==0:                   #Проверка равенства данного угла наименьшему углу (с учётом счётчика)
            k2+=1                                   #Работа счётчика
            ugf2t=(ugf2)/2                          #Угол ABC делится пополам из-за биссектрисы
            ugf2d=m.radians(ugf2t)                  #Перевод поделенного угла из градусов в радианы
            biss=(sob)/(st1*(m.sin(ugf2d)))         #Вычисление величины биссектрисы,проведённой из угла ABC
            print('Биссектриса,проведённая из наименьшего угла = ''{:1.5g}'.format(biss))
        if ugf3==minug and k2==0:                   #Проверка равенства данного угла наименьшему углу (с учётом счётчика)
            ugf3t=(ugf3)/2                          #Угол BCA делится пополам из-за биссектрисы
            ugf3d=m.radians(ugf3t)                  #Перевод поделенного угла из градусов в радианы
            biss=(sob)/(st2*(m.sin(ugf3d)))         #Вычисление величины биссектрисы,проведённой из угла BCA
            print('Биссектриса,проведённая из наименьшего угла = ''{:1.5g}'.format(biss))
    checktrue=False