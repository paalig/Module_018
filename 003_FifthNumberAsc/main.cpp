#include <iostream>
#include <vector>

/*
 * С клавиатуры вводятся числа.
 * Когда пользователь вводит -1 -- необходимо выводить на экран пятое по возрастанию число среди введённых.
 * Когда пользователь вводит -2 -- программа завершает работу.
 * Пример:
 * ввод: 7 5 3 1 2 4 6 -1
 * вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
 * ввод: 1 1 1 -1
 * вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
 * ввод -2
 * завершение программы
 */

int InputValue() {
    int a;
    std::cout << "Input value: ";
    std::cin >> a;

    return a;
}

int main() {
    std::vector<int> vec(0);
    int value = InputValue();
    while (value != -2) {
        if (value == - 1) {
            if (vec.empty()) {
                std::cout << "No one number in the array" << std::endl;
            } else if (vec.size() < 5) {
                std::cout << "There is no 5 numbers in the array. Maximum is " << vec[vec.size() - 1] << std::endl;
            } else {
                std::cout << vec[4] << std::endl;
            }
        } else {
            if (vec.empty()) {
                vec.resize(1);
                vec[0] = value;
            } else {
                vec.push_back(value);
                for (int j = vec.size() - 1; j > 0; j--) {
                    if (vec[j - 1] > vec[j]) {
                        int temp = vec[j - 1];
                        vec[j - 1] = vec[j];
                        vec[j] = temp;
                    } else {
                        break;
                    }
                }
            }
        }
        value = InputValue();
    }
    std::cout << std::endl;
    std::cout << "Program finished";
}
