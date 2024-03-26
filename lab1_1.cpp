#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

int main() {
    std::vector<int> numbers = {40, 30222, 4255, 452, 6346, -1442, 5423, 543, 543, 745, 865, 52};
    int pos = -1;
    int value = 0;
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < 0 && (value == 0 || abs(value) > abs(numbers[i])))
        {
            value = numbers[i];
            pos = i;
        }
    }
    if (pos == -1)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << pos << std::endl;
    }
    return 0;
}
