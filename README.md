# Лабароторная работа №1

## Цель:
 
Исследовать функционирование и провести сравнительный анализ двух алгоритмов 
прямого поиска экстремума (пассивный поиск и поиск методом Фибоначчи) на примере
унимодальной функции одного переменного.

### Функция:

![picture](https://quicklatex.com/cache3/4e/ql_d935562e3347a742652f910e1235124e_l3.png)

![Picture](https://i.screenshot.net/89z3xc4)

### Входные параметры:

- Длинна интервала неопределенности: 0.1
- Отрезок: [0, 3]

### Методы поиска:

1. Метод оптимального пассивного поиска
1. Метод поиска Фибоначчи

## Выводы:

### Табл. 1 Последовательный поиск (Фибоначчи)

Начало интервала (ak) | Конец интервала (bk) | Длина интервала (l) | f(ak) | f(bk)
-------- | -------- | -------- | -------- | --------
0 | 3 | 3 | -0 | -0.244427
1 | 2.33333 | 1.33333 | -0.841471 | -1.10453
1.56 | 2.28 | 0.72 | -1.24893 | -1.14588
1.59375 | 2.0625 | 0.46875 | -1.26211 | -1.266
1.72189 | 2.00592 | 0.284024 | -1.29726 | -1.28433
1.7619 | 1.93878 | 0.176871 | -1.3032 | -1.29919
1.80104 | 1.91003 | 0.108997 | -1.30661 | -1.30328
1.78645 | 1.85455 | 0.0680992 | -1.30562 | -1.30736

Минимальное значение при: x = 1.820496 +- 0.034050

### Табл. 2 Оптимальный пассивный поиск

Количество точек (N) | Значение x в минимуме
-------- | --------
1 | 1.500000 +- 1.500000
2 | 2.000000 +- 1.000000
3 | 2.000000 +- 0.750000
4 | 1.800000 +- 0.600000
5 | 1.800000 +- 0.500000
6 | 1.800000 +- 0.428571
7 | 1.800000 +- 0.375000
8 | 1.800000 +- 0.333333
9 | 1.800000 +- 0.300000
10 | 1.800000 +- 0.272727
11 | 1.800000 +- 0.250000
12 | 1.846154 +- 0.230769
13 | 1.846154 +- 0.214286
14 | 1.846154 +- 0.200000
15 | 1.846154 +- 0.187500
16 | 1.846154 +- 0.176471
17 | 1.833333 +- 0.166667
18 | 1.833333 +- 0.157895
19 | 1.833333 +- 0.150000
20 | 1.833333 +- 0.142857
21 | 1.833333 +- 0.136364
22 | 1.833333 +- 0.130435
23 | 1.833333 +- 0.125000
24 | 1.833333 +- 0.120000
25 | 1.833333 +- 0.115385
26 | 1.833333 +- 0.111111
27 | 1.833333 +- 0.107143
28 | 1.833333 +- 0.103448
29 | 1.833333 +- 0.100000

### Табл. 3 Точки и значения функций в методе пассивного поиска

Точка Nk | Xk | Значение функции в Xk
-------- | -------- | --------
1 | 0.100000 | -0.031570
2 | 0.200000 | -0.088848
3 | 0.300000 | -0.161863
4 | 0.400000 | -0.246290
5 | 0.500000 | -0.339005
6 | 0.600000 | -0.437370
7 | 0.700000 | -0.538991
8 | 0.800000 | -0.641623
9 | 0.900000 | -0.743129
10 | 1.000000 | -0.841471
11 | 1.100000 | -0.934706
12 | 1.200000 | -1.020998
13 | 1.300000 | -1.098625
14 | 1.400000 | -1.166000
15 | 1.500000 | -1.221677
16 | 1.600000 | -1.264372
17 | 1.700000 | -1.292973
18 | 1.800000 | -1.306554
19 | 1.900000 | -1.304385
20 | 2.000000 | -1.285941
21 | 2.100000 | -1.250909
22 | 2.200000 | -1.199194
23 | 2.300000 | -1.130918
24 | 2.400000 | -1.046423
25 | 2.500000 | -0.946268
26 | 2.600000 | -0.831221
27 | 2.700000 | -0.702257
28 | 2.800000 | -0.560542
29 | 2.900000 | -0.407427

Extremum: 1.800000		Interval: 0.100000		Function: -1.306554

При N = 29 достигается заданная неопределенность в методе оптимального пассивного поиска.

### Графики зависимости погрешности от числа точек

![График](https://i.screenshot.net/llo1mud)

Результат выполнения программы показал, что метод поиска фибоначчи оказался выгоднее
и ему понадобилось меньше точек для определения приблизительного экстремума при
заданной погрешности. Так, при оптимальном пассивном поиске, программе потребовалось 29 
точек, а при поиске методом Фибоначчи понадобилось всего лишь 8. Это говорит о том, что
при использовании давольно малой точности (или же при N > 2) метод Фибоначчи окажется
выгоднее. Сама программа работает стабильно, без ошибок и утечек памяти:

[![Build Status](https://travis-ci.com/OzoNeTT/TSiSA_01.svg?token=sV8byM9dvFxT9RH6zSKV&branch=master)](https://travis-ci.com/OzoNeTT/TSiSA_01)