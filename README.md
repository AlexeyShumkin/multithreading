# multithreading
repo for section "multithreading"

26.9
 - Wrapper - класс-обёртка над вектором случайных целых чисел;
 - в конструкторе класса параметры left и right служат для задания диапазона, в котором генерируются случайные числа;
 - Wrapper::multiThreadSum - метод суммирования чисел массива в нескольких потоках;
 - Wrapper::singleThreadSum - метод суммирования чисел массива в основном потоке;
 - в main.cpp замеряется время работы двух вышеперечисленных методов.

 28.9 Merge sorting
 - добавлены методы mergeSort и merge в Wrapper;
 - в main.cpp замеряется время сортировки массива.

 29.7 Fine-grained lock
 - insertIntoMiddle(value, position) - попытка реализации потокобезопасного метода с гранулярными блокировками;
 - вставка производится в позицию, принадлежащую интервалу [1, lenght + 1];
 - другие методы - вспомогательные и нисколько не являются потокобезопасными.

 30.7 Thread pool
    Данное решение - попытка реализации функции быстрой сортировки с помощью пула потоков. Основная проблема - увеличение вероятности взаимоблокировки с ростом количества элементов в массиве (при size = 1000000, вероятность почти 100%). Пока не удалось найти решение, которое исключило бы взаимоблокировку и при этом правильно отсортировывало входной массив.

