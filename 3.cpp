#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/**
 * @brief - основная функция программы
 *
 * @details Выполняет следующие операции:
 * 1. Группирует слова из V2 по длине в отображение M
 * 2. Сортирует V1 в алфавитном порядке
 * 3. Сортирует каждый вектор в M в обратном алфавитном порядке
 * 4. Формирует вектор V пар строк путём внутреннего объединения
 * 5. Выводит размер V и все пары на экран
 */
int main() {
    // Исходные данные (можно изменить или ввести с клавиатуры)
    vector<string> V1 = { "CAT", "DOG", "BIRD", "FISH" };
    vector<string> V2 = { "ANT", "BAG", "CAR", "RAG", "ELEPHANT" };

    /**
     * @brief - группировка слов из V2 по их длине
     *
     * @details Проходит по всем элементам V2, вычисляет длину каждого слова
     * и добавляет его в соответствующий вектор в отображении M, где ключ -
     * длина слова. Порядок элементов сохраняется как в исходном векторе V2.
     */
    map<int, vector<string>> M;
    for (auto it = V2.begin(); it != V2.end(); ++it) {
        int len = it->length();
        M[len].push_back(*it);               // сохраняется порядок из V2
    }

    /**
     * @brief - сортировка вектора V1
     *
     * @details Сортирует элементы вектора V1 в алфавитном порядке
     * (по возрастанию) с использованием стандартной функции sort().
     */
    sort(V1.begin(), V1.end());

    /**
     * @brief - сортировка векторов в отображении M
     *
     * @details Проходит по всем элементам отображения M и сортирует
     * каждый вектор строк в обратном алфавитном порядке (по убыванию)
     * с использованием компаратора greater<string>().
     */
    for (auto itM = M.begin(); itM != M.end(); ++itM) {
        vector<string>& vec = itM->second;
        sort(vec.begin(), vec.end(), greater<string>());
    }

    /**
     * @brief - формирование вектора пар V (внутреннее объединение)
     *
     * @details Для каждого слова из V1 находит в отображении M вектор
     * слов из V2 с такой же длиной. Для каждой найденной пары слов
     * (из V1 и соответствующего вектора из M) создаёт пару и добавляет
     * её в результирующий вектор V. Реализует операцию inner join.
     */
    vector<pair<string, string>> V;
    for (auto it1 = V1.begin(); it1 != V1.end(); ++it1) {
        const string& w1 = *it1;
        int key = w1.length();
        auto itM = M.find(key);
        if (itM != M.end()) {
            const vector<string>& v2_words = itM->second;
            for (auto it2 = v2_words.begin(); it2 != v2_words.end(); ++it2) {
                V.push_back({ w1, *it2 });
            }
        }
    }

    /**
     * @brief - вывод результатов работы программы
     *
     * @details Выводит на экран:
     * - размер результирующего вектора V
     * - все пары строк из V в формате "слово1 слово2"
     * Каждая пара выводится на отдельной строке.
     */
    cout << "Size of V: " << V.size() << endl;
    for (auto itV = V.begin(); itV != V.end(); ++itV) {
        cout << itV->first << " " << itV->second << endl;
    }

    return 0;
}