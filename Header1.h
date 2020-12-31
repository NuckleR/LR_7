#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class List
{
private:
	int size;

	class Node;
	friend class Node;

	class Node
	{
	public:
		Node* next;
		Node* prev;
		T val;

		friend class List<T>;
		friend class Iterator;

		Node(T node_val) : val(node_val) {
			next = nullptr;
			prev = nullptr;
		}
		Node() {
			next = nullptr;
			prev = nullptr;
		}

		void setValue(T value) {
			this->val = value;
		}

		void print_val() { cout << val; }
	};

	Node* head, * tail;

public:
	class Iterator;
	friend class Iterator;

	List() {
		head = tail = new Node();
		size = 0;
	}

	~List() {
		cout << "Destructor\n";
		Node* node = head;
		for (Node* sn = head; sn != tail;)
		{
			sn = sn->next;
			delete node;
			node = sn;
		}
		delete node;
	}

	List(int size) : List() {
		Node* node = new Node(), * tmp;
		head->next = node;
		tail = node;
		tail->prev = head;
		for (int i = 2; i < size; i++) {
			node = new Node();
			tmp = tail;
			tail->next = node;
			tail = node;
			tail->prev = tmp;
		}
		this->size = size;
	}

	List(int size, T value) : List(size) {
		Node* tmp = head;
		for (int i = 0; i < size; i++, tmp = tmp->next)
			tmp->setValue(value);
	}

	T front() {
		return head->val;
	}

	T back() {
		return tail->val;
	}

	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(tail->next);
	}


	void resize(int newSize) {
		Node* tmp;
		if (size > newSize) {
			tmp = head;
			for (int i = 0; i < newSize; i++, tmp = tmp->next);
			tmp->next = nullptr;
		}
		else
			for (int i = size; i < newSize; i++) {
				tmp = new Node();
				tail->next = tmp;
				tail = tmp;
			}
		size = newSize;
	}

	inline bool isEmpty() {
		return !size;
	}

	inline int _size() {
		return size;
	}

	void find(T val) {
		Node* node = head;
		while (node != tail) {
			if (node->val == val) {
				cout << "Совпадение найдено!\n\n" << val << endl;
				return;
			}
			node = node->next;
		}
		cout << "Совпадений нет!";
	}

	void pushFront(T val) {
		Node* node = new Node(val);
		node->next = head;
		head = node;
		size++;
	}

	void pushBack(T val) {
		Node* node = new Node(val);
		node->prev = tail;
		tail->next = node;
		tail = node;
		size++;
	}

	inline void popBack() {
		tail = tail->prev;
		if (tail) {
			delete tail->next;
			tail->next = nullptr;
		}
		size--;
	}

	void popFront() {
		head = head->next;
		if (head) {
			delete head->prev;
			head->prev = nullptr;
		}
		size--;
	}

	void clear() {
		Node* node = head;
		for (Node* sn = head; sn != tail;)
		{
			sn = sn->next;
			delete node;
			node = sn;
		}
		delete node;
		size = 0;
	}

	class Iterator
	{
	private:
		Node* data;
	public:
		friend class List<T>;

		Iterator() : data(nullptr) {}

		Iterator(Node* p) : data(p) {}

		Iterator(const Iterator& it) : data(it.data) {}

		Iterator& operator=(const Iterator& other) {
			data = other.data;
			return *this;
		}

		inline void operator++(int) {
			data = data->next;
		}

		inline void operator--(int) {
			data = data->prev;
		}

		T& operator*() const {
			return data->val;
		}

		bool operator==(const Iterator& other) const {
			return data == other.data;
		}

		bool operator!=(const Iterator& other) const {
			return data != other.data;
		}

		bool operator<=(const Iterator& other) const {
			return data <= other.data;
		}
	};


	List<T> Puzir_Sort(List<T> L) {
		T temp;
		for (int i = 0; i < size; i++) {
			temp = L[i];
			for (int j = size - 1; j > i; j--) {
				if (L[j - 1] > L[j]) {
					temp = L[j - 1];
					L[j - 1] = L[j];
					L[j] = temp;
				}
			}
		}
		return L;
	}

	T& operator=(const T& other) {
		this->data = T;
		return *this;
	}
	T& operator[](const int index) {
		int counter = 0;
		Node* current = this->head;
		while (current != nullptr) {
			if (counter == index) {
 				return current->val;
			}
			current = current->next;
			counter++;
		}
	}
};


class Exception
{
protected:
	int error;
public:
	Exception()
	{
		error = 0;
	}
	Exception(int _error)
	{
		error = _error;
	}
	~Exception()
	{

	};
	void Print()
	{
		if (this->error == 1)
		{
			std::cout << "Input error! Enter int!" << std::endl;
		}
		if (this->error == 2)
		{
			std::cout << "Input error! Enter double!" << std::endl;
		}
		if (this->error == 3)
		{
			std::cout << "The stack is empty!" << std::endl;
		}
	}
};
//#pragma once
//
////--------------------------- Класс-очередь
//template<typename T>
//class Queue {
//
//public:
//	Queue();
//	~Queue();
//	//----------------------------- Добавить в очередь
//	void Push_Back (T data){
//		if (Head == nullptr) {
//			Head = new Node<T>(data);
//		}
//		else {
//			Node<T>* current = this->Head;
//
//			while (current->pNext != nullptr) {
//				current = current->pNext;
//			}
//			current->pNext = new Node<T>(data);
//			current->pNext->pPrev = current;
//			Tail = current->pNext;
//		}
//		size++;
//	}
//	T& operator[](const int index) {
//		int counter = 0;
//		Node<T>* current = this->Head;
//		while (current != nullptr) {
//			if (counter == index) {
//				return current->data;
//			}
//			current = current->pNext;
//			counter++;
//		}
//	}
//
//	//------------------------------------ Класс контейнер
//	template<typename T>
//	class Node {
//	public:
//		Node* pNext, * pPrev;
//		T data;
//
//		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
//			this->data = data;
//			this->pNext = pNext;
//			this->pPrev = pPrev;
//		}
//
//		friend std::ostream& operator<< (std::ostream& out, const Node<T>& message);
//	};
//
//	Node<T>* Head, * Tail;
//	int size;
//
//
//	//-------------------------------- Класс-итератор
//	template<typename T>
//	class Iterator {
//		Node<T>* cur;
//	public:
//		Iterator(Node<T>* first) {
//			cur = first;
//		}
//
//		//Iterator& operator+ (int n) { return *(cur + n); }
//		//Iterator& operator- (int n) { return *(cur - n); }
//		//Iterator& operator++ (int) { return *cur++; }
//		//Iterator& operator-- (int) { return *cur--; }
//		//Iterator& operator++ () {
//		//	cur = cur->next;
//		//	return *this;
//		//}
//		//Iterator& operator-- () {
//		//	cur = cur->prev;
//		//	return *this;
//		//}
//
//		//bool operator!= (const Iterator& it) { return cur != it.cur; }
//		//bool operator== (const Iterator& it) { return cur == it.cur; }
//		//Iterator& operator* () { return *cur; }
//
//		Node<T> operator+ (int n) { return *(cur + n); }
//		Node<T> operator- (int n) { return *(cur - n); }
//		Node<T> operator++ (int) { return *cur++; }
//		Node<T> operator-- (int) { return *cur--; }
//		Node<T> operator++ () {
//			cur = cur->next;
//			return *this;
//		}
//		Node<T> operator-- () {
//			cur = cur->prev;
//			return *this;
//		}
//
//		bool operator!= (const Iterator& it) { return cur != it.cur; }
//		bool operator== (const Iterator& it) { return cur == it.cur; }
//		Node<T> operator* () { return *cur; }
//	};
//	Iterator<T> begin() { return Iterator<T>(this->Head); }
//	Iterator<T> end() { return Iterator<T>(this->Tail); }
//};
//
//template<typename T>
//Queue<T>::Queue() {
//	size = 0;
//	Head = nullptr;
//	Tail = nullptr;
//};
//
//template<typename T>
//Queue<T>::~Queue() {
//};
//
//template<typename T>
//std::ostream& operator<< (std::ostream& out, const Queue<T>& message) {
//	out << "Point(" << message << ")";
//
//	return out;
//};
////template<typename T>
////std::ostream& operator<< (std::ostream& out, Node<T>& message)
////{
////	
////	out << "Point(" << message << ")";
////
////	return out;
////}
//
//class Exception
//{
//protected:
//	int error;
//public:
//	Exception()
//	{
//		error = 0;
//	}
//	Exception(int _error)
//	{
//		error = _error;
//	}
//	~Exception()
//	{
//
//	};
//	void Print()
//	{
//		if (this->error == 1)
//		{
//			std::cout << "Input error! Enter int!" << std::endl;
//		}
//		if (this->error == 2)
//		{
//			std::cout << "Input error! Enter double!" << std::endl;
//		}
//		if (this->error == 3)
//		{
//			std::cout << "The stack is empty!" << std::endl;
//		}
//	}
//};