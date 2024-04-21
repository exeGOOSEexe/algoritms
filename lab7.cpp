#include <iostream>
#include <string>
class Node {
public:
	std::string name_planet;
	double distance;
	double mass;
	Node* next,* prev;
public:
	Node(std::string name_planet, double distance, double mass) {
		this->name_planet = name_planet;
		this->distance = distance;
		this->mass = mass;
		this->next = this->prev = NULL;
	}
};
class LinketList {
public:
	Node* head, * tail;
public:
	LinketList() {
		head = tail = NULL;
	}
	~LinketList() {
		while (head != NULL) pop_front();
	}
	Node* push_front(std::string name_planet, double distance, double mass) {
		Node* ptr = new Node(name_planet, distance, mass);
		ptr->next = head;
		if (head != NULL)
			head->prev = ptr;
		if (tail == NULL)
			tail = ptr;
		head = ptr;

		return ptr;
	}

	Node* push_back(std::string name_planet, double distance, double mass) {
		Node* ptr = new Node(name_planet, distance, mass);
		ptr->prev = tail;
		if (tail != NULL)
			tail->next = ptr;
		if (head == NULL)
			head = ptr;
		tail = ptr;

		return ptr;
	}
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
	void pop_back() {
		if (tail == NULL) return;

		Node* ptr = tail->prev;
		if (ptr != NULL)
			ptr->next = NULL;
		else
			head = NULL;

		delete tail;
		tail = ptr;
	}
	void sort() {
		Node* start = head;
		Node* firth;
		Node* second;

		std::string temp_name_planet;
		double temp_distance;
		double temp_mass;

		if (head == NULL) return;

		for (firth = start; firth->next != NULL; firth = firth->next) {
			for (second = firth->next; second != NULL; second = second->next) {
				if (firth->mass > second->mass) {
					
					temp_name_planet = firth->name_planet;
					firth->name_planet = second->name_planet;
					second->name_planet = temp_name_planet;

					temp_distance = firth->distance;
					firth->distance = second->distance;
					second->distance = temp_distance;

					temp_mass = firth->mass;
					firth->mass = second->mass;
					second->mass = temp_mass;
				}
			}
		}
	}
	void display() {
		Node* node = head;
		while (node) {
			std::cout << std::endl;
			std::cout << "Name: " << node->name_planet << std::endl;
			std::cout << "Distance: " << node->distance << std::endl;
			std::cout << "Mass: " << node->mass << std::endl;
			for (int i = 0; i < 15; i++) {
				std::cout << "_" << "|";
			}
			node = node->next;
		}
	}
};
int main() {
	LinketList lst;
	lst.push_front("Mercury", 58, 0.33);
	lst.push_front("Venus", 108, 4.87);
	lst.push_front("Earth", 150, 5.9742);
	lst.push_front("Mars", 228, 0.642);
	//lst.push_front("Jupiter", 775.5, 1898);
	//lst.push_front("Saturn", 1427, 568);
	//lst.push_front("Uranus", 2860, 86.8);
	//lst.push_front("Neptune", 4500, 102);
	lst.sort();
	lst.display();
	return 0;
}
