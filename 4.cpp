#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>       // для std::abs
#include <iterator>    // для std::istream_iterator

using namespace std::placeholders;  // _1, _2, ...

/**
 * @brief - функциональный объект для сравнения абсолютных значений
 *
 * @details Наследуется от std::function<bool(int, int)>.
 * Переопределяет оператор() для сравнения модулей двух целых чисел.
 * Возвращает true, если модуль первого числа строго меньше модуля второго.
 */
struct less_abs : public std::function<bool(const int, const int)> {
    // Константная функция-член, сравнивающая абсолютные значения
    bool operator()(const int a, const int b) const {
        return std::abs(a) < std::abs(b);
    }
};

/**
 * @brief - основная функция программы
 *
 * @details Выполняет следующие операции:
 * 1. Запрашивает и проверяет пороговое значение K.
 * 2. Считывает вектор целых чисел с клавиатуры.
 * 3. Удаляет элементы, модуль которых меньше K.
 * 4. Выводит размер и содержимое результирующего вектора.
 */
int main() {
    /**
     * @brief - ввод и проверка значения K
     *
     * @details Запрашивает у пользователя целое число K.
     * Если введенное значение меньше или равно нулю, выводит сообщение
     * об ошибке и завершает программу.
     */
    int K;
    std::cout << "Enter K (>0): ";
    std::cin >> K;
    if (K <= 0) {
        std::cout << "Wrong input";
        return 0;
    }

    /**
     * @brief - считывание вектора чисел с клавиатуры
     *
     * @details Считывает целые числа с клавиатуры до конца ввода (EOF).
     * Для завершения ввода используйте Ctrl+D (Linux/Mac) или Ctrl+Z (Windows).
     * Выводит считанный вектор на экран.
     */
    std::vector<int> V;
    std::cout << "Enter integers (Ctrl+D(mac)/Ctrl+Z(win) to finish): ";
    
    // Читаем все целые числа до конца потока
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(V));
    
    // Очищаем состояние потока после EOF
    std::cin.clear();
    
    std::cout << "You entered: ";
    for (int x : V) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    /**
     * @brief - удаление элементов по условию (|x| < K)
     *
     * @details Связывает функциональный объект less_abs с числом K
     * с помощью std::bind, создавая предикат. Использует идиому
     * erase-remove (std::remove_if и метод erase) для удаления из вектора V
     * всех элементов, абсолютное значение которых строго меньше K.
     */
     // Предикат: less_abs(x, K) возвращает true, если |x| < K
    auto pred = std::bind(less_abs(), _1, K);
    V.erase(std::remove_if(V.begin(), V.end(), pred), V.end());

    /**
     * @brief - вывод результатов работы программы
     *
     * @details Выводит на экран новый размер вектора V после удаления
     * и все оставшиеся элементы, разделенные пробелами.
     */
    std::cout << "Size after removal: " << V.size() << std::endl;
    std::cout << "Remaining elements:";
    for (int x : V) {
        std::cout << " " << x;
    }
    std::cout << std::endl;

    return 0;
}
