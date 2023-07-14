#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    class Node {
    public:
        T data; // 데이터를 저장하는 변수
        Node* link; // 다음 노드를 가리키는 포인터
    };

    Node* first; // 첫 번째 노드를 가리키는 포인터
    Node* rear; // 마지막 노드를 가리키는 포인터

public:
    Queue(T token); // 생성자: 초기 큐의 값을 받아서 초기화
    void Push(T token); // 큐에 요소를 추가
    void Pop(); // 큐에서 요소를 제거
    void Print(); // 큐의 모든 요소를 출력
};

template<typename T>
Queue<T>::Queue(T token) {
    first = nullptr; // 첫 번째 노드를 NULL로 초기화
    rear = nullptr; // 마지막 노드를 NULL로 초기화
}

template<typename T>
void Queue<T>::Push(T token) {
    Node* newNode = new Node; // 새로운 노드 생성
    newNode->data = token; // 새로운 노드에 데이터 저장
    newNode->link = nullptr; // 새로운 노드의 다음 노드를 NULL로 초기화

    if (rear == nullptr) { // 큐가 비어있는 경우
        first = newNode; // 첫 번째 노드로 지정
        rear = newNode; // 마지막 노드로 지정
    }
    else {
        rear->link = newNode; // 현재 마지막 노드의 다음 노드로 새로운 노드를 지정
        rear = newNode; // 마지막 노드를 새로운 노드로 업데이트
    }

    cout << token << "을(를) 큐에 추가했습니다." << endl;
}

template<typename T>
void Queue<T>::Pop() {
    if (first == nullptr) { // 큐가 비어있는 경우
        cout << "큐가 비어있습니다." << endl;
        return;
    }

    T token = first->data; // 첫 번째 노드의 데이터 저장
    Node* temp = first; // 첫 번째 노드를 임시로 저장
    first = first->link; // 첫 번째 노드를 다음 노드로 변경
    delete temp; // 첫 번째 노드 삭제

    cout << token << "을(를) 큐에서 제거했습니다." << endl;

    if (first == nullptr) { // 큐가 비어있는 경우
        rear = nullptr; // 마지막 노드도 NULL로 초기화
    }
}

template<typename T>
void Queue<T>::Print() {
    if (first == nullptr) { // 큐가 비어있는 경우
        cout << "큐가 비어있습니다." << endl;
        return;
    }

    cout << "큐의 원소: ";
    Node* current = first;
    while (current != nullptr) { // 모든 노드를 순회하며 출력
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

int main(void) {
    Queue<int> queue(3);
    queue.Print();

    queue.Push(1);
    queue.Print();

    queue.Push(2);
    queue.Print();

    queue.Push(3);
    queue.Print();

    queue.Push(4);
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Push(5);
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Pop();

    return 0;
}
