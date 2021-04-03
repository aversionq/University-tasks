# Карасёв ИУ7-16Б

D = []
check_ind = []
R_max = []

n = int(input('Введите количество строчек матрицы: '))
m = int(input('Введите количество столбцов матрицы: '))
ms_str1 = input('Введите через пробел номера строк, в которых искать максимум: ')
# Преобразование строки в массив, так же перевод элементов в тип int
ms_list1 = ms_str1.split()
for i in range(len(ms_list1)):
    check_ind.append(int(ms_list1[i]))
# Проверка на наличие требуемых строк в матрице
if len(check_ind) < 0 or len(check_ind) > n:
    print('Вы ввели больше строк, чем есть в матрице.')
elif max(check_ind) > n:
    print('Вы ввели номер строки,которого нет в матрице.')
else:
    print('Заполните матрицу слева направо, начиная с 1 элемента 1 строки: ')
    for i in range(n):
        D.append([])
        for j in range(m):
            D[i].append(float(input()))
        print('Строка №',i+1,'заполнена!')
    print('Матрица успешно заполнена!')
    print()
    # Поиск масимумов
    for i in check_ind:
        R_max.append(max(D[i-1]))
    max_average = sum(R_max) / len(R_max)
    print('Матрица,которую вы ввели: ')
    for i in range(n):
        print(D[i])
    print()
    print('Массив номеров строк, где искали максимум: ',check_ind)
    print()
    print('Массив максимальных значений из запрошенных строк: ',R_max)
    print()
    print('Среднее арифметическое значение максимумов: {:3.3g}'.format(max_average))