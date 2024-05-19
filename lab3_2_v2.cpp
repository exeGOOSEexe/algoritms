//1.	В очереди вещественных чисел вычислить среднее арифметическое и заменить им все четные значения элементов.

#include <iostream>
#include <string>
#include <iomanip>

class Node {
public:
	double data;
	Node* next, * prev;
public:
	Node(double data) {
		this->data = data;
		this->next = this->prev = NULL;
	}
};
class LinketList {
public:
	Node* head, * tail;
	double result;
	int count;
public:
	LinketList() {
		head = tail = NULL;
	}
	~LinketList() {
		while (head != NULL) pop_front();
	}
	Node* push_front(double data) {
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != NULL)
			head->prev = ptr;
		if (tail == NULL)
			tail = ptr;
		head = ptr;

		return ptr;
	}

/*	Node* push_back(double data) {
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != NULL)
			tail->next = ptr;
		if (head == NULL)
			head = ptr;
		tail = ptr;

		return ptr;
	}*/
	void pop_front() {
		if (head == NULL) return;

		Node* ptr = head->next;
		if (ptr != NULL)
			ptr->prev = NULL;
		else
			tail = NULL;

		delete head;
		head = ptr;
	}
/*	void pop_back() {
		if (tail == NULL) return;

		Node* ptr = tail->prev;
		if (ptr != NULL)
			ptr->next = NULL;
		else
			head = NULL;

		delete tail;
		tail = ptr;
	}*/
	void results() {
		Node* ptr = head;
		result = 0;
		count = 0;

		while (head != NULL) {
			result += head->data;
			head = head->next;
			count += 1;
		}
		head = ptr;
		result = result / count;
	}
	void replaces() {
		Node* current = head;
		int sec = 1;

		while (current != NULL) {
			if (sec % 2 == 0) {
				current->data = result;
			}
			sec++;
			current = current->next;
		}
	}
	void display() {
		Node* node = head;
		while (node) {
			std::cout << "|" << std::setw(10) << node->data << std::setw(3) << "|" << std::endl;
			node = node->next;
		}
		std::cout << "\n" << "Average: " << result << std::endl;
	}
};
int main() {
	LinketList lst;
	lst.push_front(5.634);
	lst.push_front(2.3);
	lst.push_front(15);
	lst.push_front(3);
	lst.push_front(9);
	lst.push_front(20.433);
	lst.results();
	lst.replaces();
	lst.display();
	return 0;
}
