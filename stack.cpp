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

int main() {
    Stack<int> stack(5);  // int Ÿ���� ������ �� �ִ� ũ�� 5�� ���� ����

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}

