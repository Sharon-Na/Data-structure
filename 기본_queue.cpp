#include <iostream>
using namespace std;

template <typename T>  // 템플릿을 사용하여 임의의 데이터 타입 T 설정
class Queue {
private:
    T* arr;            // 큐를 저장할 동적 배열
    int front;         // 큐의 맨 앞 인덱스
    int rear;          // 큐의 맨 뒤 인덱스
    int capacity;      // 큐의 용량 (배열의 크기)
    int size;          // 현재 큐에 저장된 원소의 개수

public:
    Queue(int size) {
        capacity = size;
        arr = new T[capacity];  // 용량에 맞게 동적 배열 할당
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;  // 동적 배열 메모리 반환
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void push(T element) {
        if (isFull()) {
            cout << "큐가 가득 찼습니다." << endl;
            return;
        }

        rear = (rear + 1) % capacity;  // rear 인덱스를 다음 위치로 이동
        arr[rear] = element;           // rear 위치에 원소 삽입
        size++;

        cout << element << "을(를) 큐에 추가했습니다." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "큐가 비어있습니다." << endl;
            return;
        }

        T element = arr[front];        // front 위치의 원소를 반환
        front = (front + 1) % capacity;  // front 인덱스를 다음 위치로 이동
        size--;

        cout << element << "을(를) 큐에서 제거했습니다." << endl;
    }

    void print() {
        if (isEmpty()) {
            cout << "큐가 비어있습니다." << endl;
            return;
        }

        cout << "큐의 원소: ";
        int current = front;
        for (int i = 0; i < size; i++) {
            cout << arr[current] << " ";
            current = (current + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> queue(5);  // int 타입을 저장할 수 있는 크기 5인 큐 생성

    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.print();

    queue.pop();
    queue.pop();

    queue.print();

    return 0;
}
