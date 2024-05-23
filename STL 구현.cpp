#include <iostream>

// Node 클래스 정의
template <class T>
class Node {
public:
	T value;
	Node* next;

	Node(T val) : value(val), next(nullptr) {}
};

//단일 링크리스트 클래스 정의
template <class T>
class singleLinkedList {
public: 
	singleLinkedList();     //생성자 
	~singleLinkedList();    //소멸자
	void push(T element);    //이동
	void show();       //출력

private:
	Node<T>* head;   //head = 첫 번째 원소
	Node<T>* tail;   //tail =  마지막 원소
};

//생성자 정의
template <typename T>
singleLinkedList<T>::singleLinkedList() {
	head = nullptr;
	tail = nullptr;
}

//소멸자 정의
template <typename T>
singleLinkedList<T>::~singleLinkedList() {
	Node<T>* 현재노드 = head;
	while (현재노드 != nullptr) {
		Node<T>* next = 현재노드->next;
		delete 현재노드;
		현재노드 = next;
	}
}

//push 함수 정의
template <typename T>
void singleLinkedList<T>::push(T element) {
	Node<T>* 다음노드 = new Node<T>(element);
	if (tail == nullptr) {
		head = tail = 다음노드;
	}
	else {
		tail->next = 다음노드;
		tail = 다음노드;
	}
}

//show 함수 정의
template <typename T>
void singleLinkedList<T>::show() {
	Node<T>* 현재노드 = head;
	while (현재노드 != nullptr) {
		std::cout << 현재노드->value << " -> ";
		현재노드 = 현재노드->next;
	}
	std::cout << std::endl; 
}

//main 함수
int main() {
	singleLinkedList<int>* idx = new singleLinkedList<int>();
	idx->push(1);
	idx->push(2);
	idx->push(3);
	idx->push(4);
	idx->push(5);
	idx->show();

	delete idx;  //동적 메모리 해제

	return 0;
}
