#include <iostream>
#include <vector>
/*
 * Вам даётся массив целых чисел и одно число -- результат.
 * Необходимо найти в массиве 2 числа, сумма которых будет давать результат, и вывести их на экран.
 * Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
 * Пример: a = {2, 7, 11, 15}. Результат = 9
 * 2 + 7 = 9, так что надо вывести числа 2 и 7
 */

int main() {
    std::vector<int> vec = {15, 11, 2, 7};
    int result = 26;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

    bool checkResult = false;
    int a;
    int b;
    for (int i = 0; i < vec.size() && !checkResult; i++) {
        for (int j = i + 1; j < vec.size() && !checkResult; j++) {
            if (vec[i] + vec[j] == result) {
                a = vec[i];
                b = vec[j];
                checkResult = true;
            }
        }
    }

    if (checkResult) {
        std::cout << a << " " << b << std::endl;
    } else {
        std::cout << "There is no required result in array of numbers";
    }
}
