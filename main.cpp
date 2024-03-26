#include <iostream>
#include <string>

class Node {
public:
	std::string place_name; // наименование района
	std::string naming; // наименование продукта
	int date; // предпологаемая дата сбора (месяц)
	double S_ga; // площадь га
	double yield; // урожайность
	double price_1kg; // цена за 1 кг
	double less; // поетеря при транспортировке
	double price_product; // стоимость продукта
	Node* next;
public:
	Node(std::string place_name, std::string naming, int date, double S_ga, double yield, double price_1kg, double less, double price_product) {
		this->place_name = place_name;
		this->naming = naming;
		this->date = date;
		this->S_ga = S_ga;
		this->yield = yield;
		this->price_1kg = price_1kg;
		this->less = less;
		this->price_product = price_product;
		this->next = NULL;
	}
};
class OneLinkedList {
public:
	Node* head, * tail;
public:
	OneLinkedList() {
		this->head = this->tail = NULL;
	}
	~OneLinkedList() {
		while (head != NULL) pop_front();
	}
	void pop_front() { // метод удаления элемента из начала списка
		if (head == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}
		Node* node = head;
		head = node->next;
		delete node;
	}
	void push_back(std::string place_name, std::string naming, int date, double S_ga, double yield, double price_1kg, double less, double price_product) {
		Node* node = new Node(place_name, naming, date, S_ga, yield, price_1kg, less, price_product);
		if (head == NULL) head = node;
		if (tail != NULL) tail->next = node;
		tail = node;
	}
	void push_front(std::string place_name, std::string naming, int date, double S_ga, double yield, double price_1kg, double less, double price_product) {
		Node* node = new Node(place_name, naming, date, S_ga, yield, price_1kg, less, price_product);
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;
	}

	void pop_back() {
		if (tail == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}
		Node* node = head;
		for (; node->next != tail; node = node->next);
		node->next = NULL;
		delete tail;
		tail = node;
	}

	Node* getAt(int k) {
		if (k < 0) return NULL;

		Node* node = head;
		int n = 0;
		while (node && n != k && node->next) {
			node = node->next;
			n++;
		}

		return (n == k) ? node : NULL;
	}
	Node* find_by_place_name(const std::string place_name){
   		Node* node = head;

    	while (node) {
        	if (node->place_name == place_name){
            	std::cout << "\n Место: " << node->place_name << std::endl;
            	std::cout << " Наименование: " << node->naming << std::endl;
            	std::cout << " Дата: " << node->date << " " << "м" << std::endl;
            	std::cout << " Площадь: " << node->S_ga << " " << "га" << std::endl;
            	std::cout << " Урожайность: " << node->yield << " " << "кг/га" << std::endl;
            	std::cout << " Цена за 1 кг: " << node->price_1kg << std::endl;
            	std::cout << " Потери при транспортировке: " << node->less << " " << "%" << std::endl;
            	std::cout << " Стоимость продукта: " << node->price_product << std::endl << std::endl;
            	return node;
        	}
        	node = node->next;
			if (node == NULL){
				std::cout << "Такого элемента нет!" << std::endl;
			}
    	}
    	return NULL;
	}
	Node* find_by_date(const int date){
   		Node* node = head;

    	while (node) {
        	if (node->date == date){
            	std::cout << "\n Место: " << node->place_name << std::endl;
            	std::cout << " Наименование: " << node->naming << std::endl;
            	std::cout << " Дата: " << node->date << " " << "м" << std::endl;
            	std::cout << " Площадь: " << node->S_ga << " " << "га" << std::endl;
            	std::cout << " Урожайность: " << node->yield << " " << "кг/га" << std::endl;
            	std::cout << " Цена за 1 кг: " << node->price_1kg << std::endl;
            	std::cout << " Потери при транспортировке: " << node->less << " " << "%" << std::endl;
            	std::cout << " Стоимость продукта: " << node->price_product << std::endl << std::endl;
            	return node;
        	}
        	node = node->next;
			if (node == NULL){
				std::cout << "Такого элемента нет!" << std::endl;
			}
    	}
    	return NULL;
	}
	Node* find_by_yield(const double yield){
   		Node* node = head;

    	while (node) {
        	if (node->yield == yield){
            	std::cout << "\n Место: " << node->place_name << std::endl;
            	std::cout << " Наименование: " << node->naming << std::endl;
            	std::cout << " Дата: " << node->date << " " << "м" << std::endl;
            	std::cout << " Площадь: " << node->S_ga << " " << "га" << std::endl;
            	std::cout << " Урожайность: " << node->yield << " " << "кг/га" << std::endl;
            	std::cout << " Цена за 1 кг: " << node->price_1kg << std::endl;
            	std::cout << " Потери при транспортировке: " << node->less << " " << "%" << std::endl;
            	std::cout << " Стоимость продукта: " << node->price_product << std::endl << std::endl;
            	return node;
        	}
        	node = node->next;
			if (node == NULL){
				std::cout << "Такого элемента нет!" << std::endl;
			}
    	}
    	return NULL;
	}

	void sort_by_place_name() {
    	Node *start = head;
    	Node *traverse;
    	Node *current;

    	double tempDouble;
		int tempInt;
    	std::string tempStr;

    	if (head == NULL) {
        	return;
    	}

    	for (current = start; current->next != NULL; current = current->next) {
        	for (traverse = current->next; traverse != NULL; traverse = traverse->next) {
            	if (current->place_name > traverse->place_name) {
                	// меняем местами данные в узлах
                	tempStr = current->place_name;
                	current->place_name = traverse->place_name;
                	traverse->place_name = tempStr;

                	tempStr = current->naming;
                	current->naming = traverse->naming;
                	traverse->naming = tempStr;

                	tempInt = current->date;
                	current->date = traverse->date;
                	traverse->date = tempInt;

                	tempDouble = current->S_ga;
                	current->S_ga = traverse->S_ga;
                	traverse->S_ga = tempDouble;

                	tempDouble = current->yield;
                	current->yield = traverse->yield;
                	traverse->yield = tempDouble;

                	tempDouble = current->price_1kg;
                	current->price_1kg = traverse->price_1kg;
                	traverse->price_1kg = tempDouble;

                	tempDouble = current->less;
                	current->less = traverse->less;
                	traverse->less = tempDouble;

                	tempDouble = current->price_product;
                	current->price_product = traverse->price_product;
                	traverse->price_product = tempDouble;
            	}
        	}
    	}
	}
	void sort_by_yield() {
    	Node *start = head;
    	Node *traverse;
    	Node *current;

    	double tempDouble;
		int tempInt;
    	std::string tempStr;

    	if (head == NULL) {
        	return;
    	}

    	for (current = start; current->next != NULL; current = current->next) {
        	for (traverse = current->next; traverse != NULL; traverse = traverse->next) {
            	if (current->yield < traverse->yield) {
                	// меняем местами данные в узлах
                	tempStr = current->place_name;
                	current->place_name = traverse->place_name;
                	traverse->place_name = tempStr;

                	tempStr = current->naming;
                	current->naming = traverse->naming;
                	traverse->naming = tempStr;

                	tempInt = current->date;
                	current->date = traverse->date;
                	traverse->date = tempInt;

                	tempDouble = current->S_ga;
                	current->S_ga = traverse->S_ga;
                	traverse->S_ga = tempDouble;

                	tempDouble = current->yield;
                	current->yield = traverse->yield;
                	traverse->yield = tempDouble;

                	tempDouble = current->price_1kg;
                	current->price_1kg = traverse->price_1kg;
                	traverse->price_1kg = tempDouble;

                	tempDouble = current->less;
                	current->less = traverse->less;
                	traverse->less = tempDouble;

                	tempDouble = current->price_product;
                	current->price_product = traverse->price_product;
                	traverse->price_product = tempDouble;
            	}
        	}
    	}
	}
	void sort_by_data() {
    	Node *start = head;
    	Node *traverse;
    	Node *current;

    	double tempDouble;
		int tempInt;
    	std::string tempStr;

    	if (head == NULL) {
        	return;
    	}

    	for (current = start; current->next != NULL; current = current->next) {
        	for (traverse = current->next; traverse != NULL; traverse = traverse->next) {
            	if (current->date > traverse->date) {
                	// меняем местами данные в узлах
                	tempStr = current->place_name;
                	current->place_name = traverse->place_name;
                	traverse->place_name = tempStr;

                	tempStr = current->naming;
                	current->naming = traverse->naming;
                	traverse->naming = tempStr;

                	tempInt = current->date;
                	current->date = traverse->date;
                	traverse->date = tempInt;

                	tempDouble = current->S_ga;
                	current->S_ga = traverse->S_ga;
                	traverse->S_ga = tempDouble;

                	tempDouble = current->yield;
                	current->yield = traverse->yield;
                	traverse->yield = tempDouble;

                	tempDouble = current->price_1kg;
                	current->price_1kg = traverse->price_1kg;
                	traverse->price_1kg = tempDouble;

                	tempDouble = current->less;
                	current->less = traverse->less;
                	traverse->less = tempDouble;

                	tempDouble = current->price_product;
                	current->price_product = traverse->price_product;
                	traverse->price_product = tempDouble;
            	}
        	}
    	}
	}

	void prints() {
		Node* node = head;
		while (node) {
			std::cout << "\n Место: " << node->place_name << std::endl;
			std::cout << " Наименование: " << node->naming << std::endl;
			std::cout << " Дата: " << node->date << " " << "м" << std::endl;
			std::cout << " Площадь: " << node->S_ga << " " << "га" << std::endl;
			std::cout << " Урожайность: " << node->yield << " " << "кг/га" << std::endl;
			std::cout << " Цена за 1 кг: " << node->price_1kg << std::endl;
			std::cout << " Потери при транспортировке: " << node->less << " " << "%" << std::endl;
			std::cout << " Стоимость продукта: " << node->price_product << std::endl << std::endl;
			node = node->next;
		}
		for(int i = 0; i < 40; i++){
			std::cout << "_";
		}
		std::cout << std::endl;
	}

};
int main()
{
	OneLinkedList lst;
	lst.push_front("Москва", "Картофель", 8, 10.0, 53.0, 333.0, 0.1, 111.0);
	lst.push_front("Воронеж", "Клубника", 3, 43.0, 23.0, 453.0, 0.3, 444.0);
	lst.push_front("Челябинск", "Перец", 5, 21.0, 12.0, 742.0, 0.2, 333.0);
	lst.push_front("Астрахань", "Арбузы", 12, 5.0, 76.0, 643.0, 0.01, 222.0);
	lst.push_front("Краснодар","помидор", 4, 12.0, 45.0, 100.0, 0.1, 450.0);
	lst.sort_by_place_name();
	lst.prints();
	lst.sort_by_yield();
	lst.prints();
	lst.sort_by_data();
	lst.prints();
	lst.find_by_place_name("Челябинск");
	lst.find_by_date(3);
	lst.find_by_yield(53.0);
	return 0;
}