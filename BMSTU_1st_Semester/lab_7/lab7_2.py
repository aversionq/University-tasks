# Карасёв ИУ7-16Б

min_ind_list = []
Z = []
r = []
a = []
j = 25
t = 1
even_sum = 0

i = int(input('Введите i(<=40): '))
print('Введите массив a: ')
for q in range(i):
    a.append(float(input()))
print('Введите массив r: ')
for q in range(j):
    r.append(float(input()))
# Заполнение массива Z
for q in range(0,i):
    if q == 0:
        Z.append(1)
    else:
        if a[q] <= 0:
            Z.append(Z[q-1])
        else:
            for k in range(j):
                t *= (r[k] + 0.5)
            Z.append(Z[q-1] - a[q]*t)
# Вычисление суммы чётных элементов
if i % 2 == 0:
    for q in range(1,i+1,2):
        even_sum += Z[q]
else:
    for q in range(1,i,2):
        even_sum += Z[q]
# Замена минимума на сумму чётных элементов
Zmin = min(Z)
count_mins = Z.count(Zmin)
for q in range(count_mins):
    min_ind = Z.index(Zmin)
    Z[min_ind] = even_sum
    min_ind_list.append(min_ind)
print('Минимальное значение Z = {:8.4g}'.format(Zmin))
print('Порядковый(ые) номер(а) минимального Z = ',*min_ind_list)
print('Массив Z(после изменений): ')
for q in range(len(Z)):
    if q != len(Z) - 1:
        print('{:8.4g}'.format(Z[q]),end=' , ')
    else:
        print('{:8.4g}'.format(Z[q]))