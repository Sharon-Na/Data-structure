#include <iostream>
using namespace std;

template <typename T>  // ���ø��� ����Ͽ� ������ ������ Ÿ�� T ����
class Queue {
private:
    T* arr;            // ť�� ������ ���� �迭
    int front;         // ť�� �� �� �ε���
    int rear;          // ť�� �� �� �ε���
    int capacity;      // ť�� �뷮 (�迭�� ũ��)
    int size;          // ���� ť�� ����� ������ ����

public:
    Queue(int size) {
        capacity = size;
        arr = new T[capacity];  // �뷮�� �°� ���� �迭 �Ҵ�
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;  // ���� �迭 �޸� ��ȯ
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void push(T element) {
        if (isFull()) {
            cout << "ť�� ���� á���ϴ�." << endl;
            return;
        }

        rear = (rear + 1) % capacity;  // rear �ε����� ���� ��ġ�� �̵�
        arr[rear] = element;           // rear ��ġ�� ���� ����
        size++;

        cout << element << "��(��) ť�� �߰��߽��ϴ�." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
            return;
        }

        T element = arr[front];        // front ��ġ�� ���Ҹ� ��ȯ
        front = (front + 1) % capacity;  // front �ε����� ���� ��ġ�� �̵�
        size--;

        cout << element << "��(��) ť���� �����߽��ϴ�." << endl;
    }

    void print() {
        if (isEmpty()) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
            return;
        }

        cout << "ť�� ����: ";
        int current = front;
        for (int i = 0; i < size; i++) {
            cout << arr[current] << " ";
            current = (current + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> queue(5);  // int Ÿ���� ������ �� �ִ� ũ�� 5�� ť ����

    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.print();

    queue.pop();
    queue.pop();

    queue.print();

    return 0;
}
