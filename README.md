# Лабароторная работа №1

## Цель:
 
Исследовать функционирование и провести сравнительный анализ двух алгоритмов 
прямого поиска экстремума (пассивный поиск и поиск методом Фибоначчи) на примере
унимодальной функции одного переменного.

### Функция:

![picture](https://quicklatex.com/cache3/4e/ql_d935562e3347a742652f910e1235124e_l3.png)

[График](http://yotx.ru/#!1/3_h/sH%40xf7Rgzhf23/aP9g/2DfT0qt7W/%40E0nkjb3dfyB8Y293/2CfRMNu7JwyHk%403GI9blxe7%401v7AA==)

### Входные параметры:

- Длинна интервала неопределенности: 0.1
- Отрезок: [0, 3]

### Методы поиска:

1. Метод оптимального пассивного поиска
1. Метод поиска Фибоначчи

## Выводы:

### Табл. 1 Последовательный поиск (Фибоначчи)

_____________________________________________________________________________

| Начало        |       Конец       | Длина         |            |          |

| интервала     |     интервала     | интервала     |   f(ak)    |   f(bk)  |

| (ak)          |       (bk)        |       (l)     |            |          |

-----------------------------------------------------------------------------

|               |                   |               |            |          |

|               |                   |               |            |          |

|               |                   |               |            |          |

|               |                   |               |            |          |

|               |                   |               |            |          |

|               |                   |               |            |          |

|               |                   |               |            |          |

¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

### Табл. 2 Оптимальный пассивный поиск

_________________________________

|   Количество  |   Значение x  |

|   точек (N)   |   в минимуме  |

---------------------------------

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

|               |               |

¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

### Графики зависимости погрешности от числа точек

[График](http://yotx.ru/#!1/3_7f2D/YuDfSOG8L%402D4ST10gRDGH/YP9g309Kre1vbPG2IGe7Gzu8A8jp6Slid%40OCdwC5ON3dAPEOIDsXoAvE2e7GGe8AsgXaOdja2d045R1ADmAw0MXZ7v7OPomG3dg5ZTyebjEety4vdve39rf2N7Z4W5Cz3Y0d3hbkYHfjgncAQZztboB4B5DT3Y0z3gHkbHfjlHcAAe3AzhBbuxsI3gHkAnG2uwHjHUAuLi52Ny55B5CL3Y2tA94BZAexg9jd2NriHUB2znY3tnZ4B5CdiwPE6eXuxtYF7wCyswXagZ3ubmyBeAeQnd2NrTPeAWQLhjjb3dg65R1AthCnIMTW7sYWgncA2To9PT1F7G5swXgHkK0zBOzybHdj65J3ANk6293YOeAdQLZAO7AzxO7GzhbvALJ1cXpxCtrd2NnhHUC2Lg5AF2e7GzsXvAPI1s7Z7sYOiHcA2do52N3YOeMdQLa2zi5gZ7sbO6e8A8jW1tbW1tbuxg6CdwDZOkBsgS52N3ZgvAPI1sEFCATb3di55B1Atg4ODg4Odvd39kk07MYWDMF4PGA8Huzub%401v7QMG)

Результат выполнения программы показал, что метод поиска фибоначчи сработал
быстрее и ему понадобилось меньше точек для определения приблизительного экстремума при
заданной погрешности. Так, при оптимальном пассивном поиске, программе потребовалось 29 
точек, а при поиске методом Фибоначчи понадобилось всего лишь 6. Это говорит о том, что
при использовании давольно малой точности (или же при N > 2) метод Фибоначчи окажется
выгоднее. Сама программа работает стабильно, без ошибок и утечек памяти:

[![Build Status](https://travis-ci.com/OzoNeTT/TSiSA_01.svg?token=sV8byM9dvFxT9RH6zSKV&branch=master)](https://travis-ci.com/OzoNeTT/TSiSA_01)