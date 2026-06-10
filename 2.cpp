#include <iostream>
#include <list> 
#include <iterator> 

using namespace std;

/**
 * @brief выводит элементы списка в консоль
 * @param L - список целых чисел для вывода
 */
void print_list(const list<int>& L);

/**
 * @brief удаляет элементы с нечетными индексами из первой половины списка
 * @param L - список для обработки (изменяется)
 * @details Функция находит середину списка и удаляет каждый второй элемент
 *          (с нечетными индексами: 1, 3, 5...) из первой половины списка
 */
void del_first_half_odd_indexes(list<int>& L); 

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 * @details Создает список размером от 4 до 36 элементов (кратное 4),
 *          заполняет его последовательными числами, выводит исходный список,
 *          применяет алгоритм удаления и выводит результат
 */

int main() {
    list<int> L;                   
    
    cout << "Введите числа (завершите Ctrl+D или Ctrl+Z): ";
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(L));    

    print_list(L);                       
    del_first_half_odd_indexes(L);       
    print_list(L);                       

    return 0;
}

void print_list(const list<int>& L) {
    for (const int& i : L) {
        cout << i << ' ';
    }
    cout << endl;
}

void del_first_half_odd_indexes(list<int>& L) {
    auto end = L.begin();
    advance(end, L.size() / 2);
    for (auto it = L.begin(); it != end; ++it) {
        it = L.erase(it);   // удаляем текущий элемент, it указывает на следующий 
        if (it == end) break;
    }
}
