﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 100000
int main() {
    std::vector<int> numbers;
    int number = 0;
    int n = 0;
    

    std::cout << "Enter the number of random numbers to generate: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        number = rand() % MAX;
        numbers.push_back(number);
    }

    //numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int number) { return number % 2 != 0; }), numbers.end());
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 != 0){
            numbers.erase(numbers.begin() + i);
            i--;
        }
    }
    //numbers.erase_if(v, [](int number) { return number % 2 != 0; }); // C++20 
    // c++17

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}