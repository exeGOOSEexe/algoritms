#include <iostream>
#include <vector>
#include <algorithm>

class Work {
public:
    static const int y = 4;
    int array[y];

public:
    void shake_sort_odd() {
        // Сбор нечетных элементов
        std::vector<int> odd_elements;
        for (int i = 0; i < y; i++) {
            if (array[i] % 2 != 0) {
                odd_elements.push_back(array[i]);
            }
        }

        // Шейкерная сортировка нечетных элементов
        bool swapped;
        int start = 0;
        int end = odd_elements.size() - 1;
        do {
            swapped = false;
            for (int i = start; i < end; ++i) {
                if (odd_elements[i] > odd_elements[i + 1]) {
                    std::swap(odd_elements[i], odd_elements[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
            swapped = false;
            --end;
            for (int i = end - 1; i >= start; --i) {
                if (odd_elements[i] > odd_elements[i + 1]) {
                    std::swap(odd_elements[i], odd_elements[i + 1]);
                    swapped = true;
                }
            }
            ++start;
        } while (swapped);

        // Вставка отсортированных нечетных элементов обратно в массив
        int odd_index = 0;
        for (int i = 0; i < y; i++) {
            if (array[i] % 2 != 0) {
                array[i] = odd_elements[odd_index++];
            }
        }
    }

    void selection_sort_odd() {
        // Сбор нечетных элементов
        std::vector<int> odd_elements;
        for (int i = 0; i < y; i++) {
            if (array[i] % 2 != 0) {
                odd_elements.push_back(array[i]);
            }
        }

        // Сортировка выбором нечетных элементов
        for (size_t i = 0; i < odd_elements.size(); ++i) {
            int min_index = i;
            for (size_t j = i + 1; j < odd_elements.size(); ++j) {
                if (odd_elements[j] < odd_elements[min_index]) {
                    min_index = j;
                }
            }
            std::swap(odd_elements[i], odd_elements[min_index]);
        }

        // Вставка отсортированных нечетных элементов обратно в массив
        int odd_index = 0;
        for (int i = 0; i < y; i++) {
            if (array[i] % 2 != 0) {
                array[i] = odd_elements[odd_index++];
            }
        }
    }

    void massive_user() {
        std::cout << "Enter elements in your array" << std::endl;
        for (int i = 0; i < y; i++) {
            std::cin >> array[i];
        }
    }

    void display() {
        std::cout << "\narray = {";
        for (int i = 0; i < y; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "}\n";
    }
};

int main() {
    Work w;
    w.massive_user();
    w.display();

    w.shake_sort_odd();
    std::cout << "After shake sort on odd elements:";
    w.display();

    w.selection_sort_odd();
    std::cout << "After selection sort on odd elements:";
    w.display();

    return 0;
}
