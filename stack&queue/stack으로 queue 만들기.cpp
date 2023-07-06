#include <iostream>
using namespace std;

template <typename T>  // ���ø��� ����Ͽ� ������ ������ Ÿ�� T ����
class Stack {
private:
    T* arr;            // ������ ������ ���� �迭
    int top;           // ������ ���� �� ������ �ε���
    int capacity;      // ������ �뷮 (�迭�� ũ��)

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];  // �뷮�� �°� ���� �迭 �Ҵ�
        top = -1;              // ������ ����ִ� ���·� �ʱ�ȭ
    }

    ~Stack() {
        delete[] arr;  // ���� �迭 �޸� ��ȯ
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

        arr[++top] = element;  // top�� ������Ű�� ���Ҹ� ����
        cout << element << "��(��) ���ÿ� �߰��߽��ϴ�." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "������ ����ֽ��ϴ�." << endl;
            return;
        }

        T element = arr[top--];  // top ��ġ�� ���Ҹ� ��ȯ�ϰ� top�� ���ҽ�Ŵ
        cout << element << "��(��) ���ÿ��� �����߽��ϴ�." << endl;
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


template <typename T>  // ���ø��� ����Ͽ� ������ ������ Ÿ�� T�� ����
class Queue {
private:
    Stack<T> inbox;   // �Է� ����
    Stack<T> outbox;  // ��� ����

public:
    void push(T element) {
        inbox.push(element);  // �Է� ���ÿ� ���� �߰�
        cout << element << "��(��) ť�� �߰��߽��ϴ�." << endl;
    }

    void pop() {
        if (outbox.isEmpty()) {
            // ��� ������ ����ִ� ���, �Է� ������ ���Ҹ� ��� ��� �������� �̵�
            while (!inbox.isEmpty()) {
                outbox.push(inbox.top());  // �Է� ������ top ���Ҹ� ��� ���ÿ� �߰�
                inbox.pop();               // �Է� ���ÿ��� top ���� ����
            }
        }

        if (outbox.isEmpty()) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
            return;
        }

        T element = outbox.top();  // ��� ������ top ���Ҹ� ��ȯ
        outbox.pop();              // ��� ���ÿ��� top ���� ����

        cout << element << "��(��) ť���� �����߽��ϴ�." << endl;
    }

    void print() {
        if (outbox.isEmpty()) {
            // ��� ������ ����ִ� ���, �Է� ������ ���Ҹ� ��� ��� �������� �̵�
            while (!inbox.isEmpty()) {
                outbox.push(inbox.top());  // �Է� ������ top ���Ҹ� ��� ���ÿ� �߰�
                inbox.pop();               // �Է� ���ÿ��� top ���� ����
            }
        }

        if (outbox.isEmpty()) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
            return;
        }

        cout << "ť�� ����: ";
        outbox.print();  // ��� ������ ������ ���
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