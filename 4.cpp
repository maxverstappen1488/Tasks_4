#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>       // для std::abs
#include <random>

using namespace std::placeholders;  // _1, _2, ...

/**
 * @brief - функциональный объект для сравнения абсолютных значений
 *
 * @details Наследуется от std::function<bool(int, int)>.
 * Переопределяет оператор() для сравнения модулей двух целых чисел.
 * Возвращает true, если модуль первого числа строго меньше модуля второго.
 */
struct less_abs : public std::function<bool(int, int)> {
    // Константная функция-член, сравнивающая абсолютные значения
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};

/**
 * @brief - основная функция программы
 *
 * @details Выполняет следующие операции:
 * 1. Запрашивает и проверяет пороговое значение K.
 * 2. Генерирует вектор случайных целых чисел.
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
     * @brief - генерация вектора случайных чисел
     *
     * @details Запрашивает количество элементов n. Создает вектор V
     * размера n и заполняет его случайными целыми числами
     * в диапазоне от -99 до 99 с использованием генератора mt19937.
     * Выводит сгенерированный вектор на экран.
     */
    std::vector<int> V;
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    std::cout << "Generate vector: ";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-99, 99);
    V.resize(n);
    std::generate(V.begin(), V.end(), [&]() { return dis(gen); });
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