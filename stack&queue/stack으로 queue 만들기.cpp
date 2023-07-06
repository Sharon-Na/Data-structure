#include <iostream>
using namespace std;

template <typename T>  // 템플릿을 사용하여 임의의 데이터 타입 T 설정
class Stack {
private:
    T* arr;            // 스택을 저장할 동적 배열
    int top;           // 스택의 가장 위 원소의 인덱스
    int capacity;      // 스택의 용량 (배열의 크기)

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];  // 용량에 맞게 동적 배열 할당
        top = -1;              // 스택이 비어있는 상태로 초기화
    }

    ~Stack() {
        delete[] arr;  // 동적 배열 메모리 반환
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(T element) {
        if (isFull()) {
            cout << "스택이 가득 찼습니다." << endl;
            return;
        }

        arr[++top] = element;  // top을 증가시키고 원소를 삽입
        cout << element << "을(를) 스택에 추가했습니다." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "스택이 비어있습니다." << endl;
            return;
        }

        T element = arr[top--];  // top 위치의 원소를 반환하고 top을 감소시킴
        cout << element << "을(를) 스택에서 제거했습니다." << endl;
    }

    void print() {
        if (isEmpty()) {
            cout << "스택이 비어있습니다." << endl;
            return;
        }

        cout << "스택의 원소: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


template <typename T>  // 템플릿을 사용하여 임의의 데이터 타입 T를 지원
class Queue {
private:
    Stack<T> inbox;   // 입력 스택
    Stack<T> outbox;  // 출력 스택

public:
    void push(T element) {
        inbox.push(element);  // 입력 스택에 원소 추가
        cout << element << "을(를) 큐에 추가했습니다." << endl;
    }

    void pop() {
        if (outbox.isEmpty()) {
            // 출력 스택이 비어있는 경우, 입력 스택의 원소를 모두 출력 스택으로 이동
            while (!inbox.isEmpty()) {
                outbox.push(inbox.top());  // 입력 스택의 top 원소를 출력 스택에 추가
                inbox.pop();               // 입력 스택에서 top 원소 제거
            }
        }

        if (outbox.isEmpty()) {
            cout << "큐가 비어있습니다." << endl;
            return;
        }

        T element = outbox.top();  // 출력 스택의 top 원소를 반환
        outbox.pop();              // 출력 스택에서 top 원소 제거

        cout << element << "을(를) 큐에서 제거했습니다." << endl;
    }

    void print() {
        if (outbox.isEmpty()) {
            // 출력 스택이 비어있는 경우, 입력 스택의 원소를 모두 출력 스택으로 이동
            while (!inbox.isEmpty()) {
                outbox.push(inbox.top());  // 입력 스택의 top 원소를 출력 스택에 추가
                inbox.pop();               // 입력 스택에서 top 원소 제거
            }
        }

        if (outbox.isEmpty()) {
            cout << "큐가 비어있습니다." << endl;
            return;
        }

        cout << "큐의 원소: ";
        outbox.print();  // 출력 스택의 내용을 출력
    }
};

int main() {
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.print();

    queue.pop();
    queue.pop();

    queue.print();

    return 0;
}