# Карасёв ИУ7-16Б
# Вводится матрица, найти столбец,в котором больше всего 0, перенести его в конец (сдвиг матрицы).

mtrx = []
zero_count = 0
to_compare = 0
zero_index = 0

m = int(input('Введите количество строк в матрице: '))
n = int(input('Введите количество столбцов в матрице: '))
print('Введите матрицу: ')
for i in range(m):
    mtrx.append([])
    for j in range(n):
        mtrx[i].append(float(input()))
    print('Строка №',i+1,'заполнена!')
print('Изначальная матрица: ')
for i in range(m):
    print(mtrx[i])
print('-'*(n+4*n))
for i in range(n):
    for j in range(m):
        if mtrx[j][i] == 0:
            zero_count += 1
        if zero_count > to_compare:
            zero_index = i
            to_compare = zero_count
    zero_count = 0
for i in range(m):
    t = mtrx[i][zero_index]
    mtrx[i][zero_index] = mtrx[i][n-1]
    mtrx[i][n-1] = t
print('Матрица после перестановки: ')
for i in range(m):
    print(mtrx[i])