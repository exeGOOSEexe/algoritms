#include <iostream>
#include <stack>

#define MAX 1000000
void findmax(std::stack<int>& stack) {
	int max = 0;
	while (!stack.empty()) {
		if (stack.top() > max) {
			max = stack.top();
		}
		stack.pop();
	}
	std::cout << "Max number: " << max << std::endl;
}
int main() {
	std::stack<int> stack;
	int number = 0;
	int n = 0;

	std::cout << "Enter the number of random numbers to generate: ";
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		number = rand() % MAX;
		stack.push(number);
	}
	findmax(stack);
	return 0;
}