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
        capacity = 100;  // �⺻ �뷮�� 100���� ����
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
            cout << "������ ���� á���ϴ�." << endl;
            return;
        }

        arr[++top] = element;
        cout << element << "��(��) ���ÿ� �߰��߽��ϴ�." << endl;
    }

    T pop() {
        if (isEmpty()) {
            cout << "������ ����ֽ��ϴ�." << endl;
            return T();
        }

        T element = arr[top--];
        cout << element << "��(��) ���ÿ��� �����߽��ϴ�." << endl;

        return element;
    }

    void print() {
        if (isEmpty()) {
            cout << "������ ����ֽ��ϴ�." << endl;
            return;
        }

        cout << "������ ����: ";
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

        cout << element << "��(��) ť�� �߰��߽��ϴ�." << endl;
    }

    void pop() {
        if (mainStack.isEmpty()) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
            return;
        }

        T element = mainStack.pop();
        cout << element << "��(��) ť���� �����߽��ϴ�." << endl;
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
