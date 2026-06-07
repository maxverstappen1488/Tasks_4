#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cout << "Press Ctrl-C for stop program.\n";
    cout << "Input text:\n";

    // Итератор для чтения символов (не пропускает пробелы и переводы строк)
    istreambuf_iterator<char> ptin_iterator(cin);
    istreambuf_iterator<char> end;  // концевой итератор

    // Итератор для вывода символов
    ostreambuf_iterator<char> ptout_iterator(cout);

    // Алгоритм replace_copy_if
    replace_copy_if(
        ptin_iterator, end,
        ptout_iterator,
        [](char ch) {
            return isdigit(static_cast<unsigned char>(ch));
        },
        '_'
    );

    return 0;
}