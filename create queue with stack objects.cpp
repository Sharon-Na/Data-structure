#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    Stack() {
        capacity = 100;  // 기본 용량을 100으로 설정
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
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

        arr[++top] = element;
        cout << element << "을(를) 스택에 추가했습니다." << endl;
    }

    T pop() {
        if (isEmpty()) {
            cout << "스택이 비어있습니다." << endl;
            return T();
        }

        T element = arr[top--];
        cout << element << "을(를) 스택에서 제거했습니다." << endl;

        return element;
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

template <typename T>
class Queue {
private:
    Stack<T> mainStack;
    Stack<T> tempStack;

public:
    Queue() {}

    void push(T element) {
        while (!mainStack.isEmpty()) {
            tempStack.push(mainStack.pop());
        }

        mainStack.push(element);

        while (!tempStack.isEmpty()) {
            mainStack.push(tempStack.pop());
        }

        cout << element << "을(를) 큐에 추가했습니다." << endl;
    }

    void pop() {
        if (mainStack.isEmpty()) {
            cout << "큐가 비어있습니다." << endl;
            return;
        }

        T element = mainStack.pop();
        cout << element << "을(를) 큐에서 제거했습니다." << endl;
    }

    void print() {
        mainStack.print();
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
