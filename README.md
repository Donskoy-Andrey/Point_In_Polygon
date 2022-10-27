## Постановка задачи
Задан массив пар чисел `x_i, y_i`, которые определяют вершины произвольного многоугольника (в общем случае невыпуклого, с самопересечениями). Задана произвольная точка на плоскости с координатами `x, y`.

* Необходимо разработать программу, которая определит принадлежит ли указанная точка `(x,y)` внутренней области многоугольника. 
* Опционально программа должна определять  принадлежит ли указанная точка границе многоугольника.

## Входные данные:
Пара вещественных чисел `(x, y)` задаёт координаты тестируемой точки. Эти числа передаются в качестве аргументов командной строки.
Файл `{name}.txt` (находится в папке **data**) содержит в себе координаты вершин многоугольника. Каждая строчка содержит координаты одной вершины — два вещественных числа, разделённых пробелом:
```
x1 y1
x2 y2
...
xn yn
```

## Выходные данные:
Вывод в консоль в зависимости от полученного результата.
```
The point (x,y) is inside the polygon
The point (x,y) is outside of the polygon
The point (x,y) is on the edge of the poly
```
А также отрисовка всей задачи в файл `{name}.png` (находится в папке **data/images**).

## Запуск программы
Для запуска программы необходимо с помощью **CMakeLists.txt** создать исполняемый файл в папке **build**:
```commandline
$ mrdir build
$ cd build
$ cmake ..
$ make 
```

Параметры программы передаются в командной строке следующим образом:
```
$ ./main <file_path> <x> <y>
```
Например,
```
$ ./main ../data/1.txt -10.5 34
```

## Пример работы
![](https://github.com/Donskoy-Andrey/Point_In_Polygon/blob/master/data/images/1.png?raw=true#centered) 
![](https://github.com/Donskoy-Andrey/Point_In_Polygon/blob/master/data/images/2.png?raw=true#centered)
![](https://github.com/Donskoy-Andrey/Point_In_Polygon/blob/master/data/images/3.png?raw=true#centered)
![](https://github.com/Donskoy-Andrey/Point_In_Polygon/blob/master/data/images/4.png?raw=true#centered)