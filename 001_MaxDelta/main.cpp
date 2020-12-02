#include <iostream>
#include <vector>

/*
 * Вам даётся массив целых чисел.
 * Необходимо найти такие два индекса i и j в этом массиве, что сумма a[i], a[i+1], a[i+2], … a[j]
 *  будет максимально возможной и вывести их.
 * Пример: a = {-2,1,-3,4,-1,2,1,-5,4}
 * Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6.
 * Необходимо вывести 3 и 6
 */

int main() {
    std::vector<int> vec = {3,1,-3,4,1,2,1,-5,4};
    int max = vec[0] + vec[1];
    int a = 0;
    int b = 1;
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] + vec[i + 1] > max) {
            a = i;
            b = i + 1;
            max = vec[i] + vec[i + 1];
        }
    }

    int delta = max;
    for (int i = b + 1; i < vec.size(); i++) {
        delta += vec[i];
        if (delta >= max) {
            max = delta;
            b = i;
        }
    }

    delta = max;
    for (int i = a - 1; i >= 0; i--) {
        delta += vec[i];
        if (delta >= max) {
            max = delta;
            a = i;
        }
    }

    std::cout << a << " " << b << std::endl;
}
