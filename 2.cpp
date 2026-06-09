#include <iostream>
#include <list>
#include <numeric>   // для std::iota
#include <cstdlib>   // для rand, srand
#include <ctime>     // для time

using namespace std;

/**
 * @brief выводит элементы списка в консоль
 * @param L - список целых чисел для вывода
 */
void print_list(const list<int>& L) {
    for (const int& i : L) {
        cout << i << ' ';
    }
    cout << endl;
}

/**
 * @brief удаляет элементы с нечетными индексами из первой половины списка
 * @param L - список для обработки (изменяется)
 * @details Функция находит середину списка и удаляет каждый второй элемент
 *          (с нечетными индексами: 1, 3, 5...) из первой половины списка
 */
void del_first_half_odd_indexes(list<int>& L) {
    auto end = L.begin();
    advance(end, L.size() / 2);
    for (auto it = L.begin(); it != end; ++it) {
        it = L.erase(it);   // удаляем текущий элемент, it указывает на следующий
        if (it == end) break;
    }
}

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 * @details Создает список размером от 4 до 36 элементов (кратное 4),
 *          заполняет его последовательными числами, выводит исходный список,
 *          применяет алгоритм удаления и выводит результат
 */
int main() {
    srand(time(0));
    size_t size = (rand() % 9 + 1) * 4;   // от 4 до 36

    list<int> L(size);                   // создаём список нужного размера
    iota(L.begin(), L.end(), 1);         // заполняем числами 1,2,...,size

    print_list(L);                       // вывод исходных данных
    del_first_half_odd_indexes(L);       // алгоритм по заданию
    print_list(L);                       // вывод результата

    return 0;
}
