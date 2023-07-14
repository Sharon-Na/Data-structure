#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    class Node {
    public:
        T data; // �����͸� �����ϴ� ����
        Node* link; // ���� ��带 ����Ű�� ������
    };

    Node* first; // ù ��° ��带 ����Ű�� ������
    Node* rear; // ������ ��带 ����Ű�� ������

public:
    Queue(T token); // ������: �ʱ� ť�� ���� �޾Ƽ� �ʱ�ȭ
    void Push(T token); // ť�� ��Ҹ� �߰�
    void Pop(); // ť���� ��Ҹ� ����
    void Print(); // ť�� ��� ��Ҹ� ���
};

template<typename T>
Queue<T>::Queue(T token) {
    first = nullptr; // ù ��° ��带 NULL�� �ʱ�ȭ
    rear = nullptr; // ������ ��带 NULL�� �ʱ�ȭ
}

template<typename T>
void Queue<T>::Push(T token) {
    Node* newNode = new Node; // ���ο� ��� ����
    newNode->data = token; // ���ο� ��忡 ������ ����
    newNode->link = nullptr; // ���ο� ����� ���� ��带 NULL�� �ʱ�ȭ

    if (rear == nullptr) { // ť�� ����ִ� ���
        first = newNode; // ù ��° ���� ����
        rear = newNode; // ������ ���� ����
    }
    else {
        rear->link = newNode; // ���� ������ ����� ���� ���� ���ο� ��带 ����
        rear = newNode; // ������ ��带 ���ο� ���� ������Ʈ
    }

    cout << token << "��(��) ť�� �߰��߽��ϴ�." << endl;
}

template<typename T>
void Queue<T>::Pop() {
    if (first == nullptr) { // ť�� ����ִ� ���
        cout << "ť�� ����ֽ��ϴ�." << endl;
        return;
    }

    T token = first->data; // ù ��° ����� ������ ����
    Node* temp = first; // ù ��° ��带 �ӽ÷� ����
    first = first->link; // ù ��° ��带 ���� ���� ����
    delete temp; // ù ��° ��� ����

    cout << token << "��(��) ť���� �����߽��ϴ�." << endl;

    if (first == nullptr) { // ť�� ����ִ� ���
        rear = nullptr; // ������ ��嵵 NULL�� �ʱ�ȭ
    }
}

template<typename T>
void Queue<T>::Print() {
    if (first == nullptr) { // ť�� ����ִ� ���
        cout << "ť�� ����ֽ��ϴ�." << endl;
        return;
    }

    cout << "ť�� ����: ";
    Node* current = first;
    while (current != nullptr) { // ��� ��带 ��ȸ�ϸ� ���
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
