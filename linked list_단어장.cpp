#include<iostream>
using namespace std;

class Dictionary {
private:
    class Node {
    public:
        string data; // �ܾ �����ϴ� ����
        Node* link; // ���� ��带 ����Ű�� ������
    };

    Node* first; // ù ��° ��带 ����Ű�� ������

public:
    Dictionary(string word); // �ܾ�� ��ųʸ� ������
    void Find(string word); // �ܾ �ִ� ��ġ�� ����ϰų� �ܾ ���ٴ� �޽��� ���
    void Insert(string word); // �ܾ �˸��� ��ġ�� ���� (���ĺ� ����)
    void Delete(string word); // �ܾ ��ųʸ����� ����
    void Display(); // ��ųʸ��� ������ ���
};

Dictionary::Dictionary(string word) {
    first = new Node; // ù ��° ��� ����
    first->data = word; // ù ��° ��忡 �ܾ� ����
    first->link = nullptr; // ù ��° ����� ���� ��带 NULL�� �ʱ�ȭ
}

void Dictionary::Find(string word) {
    int count = 1; // �ܾ��� ��ġ�� �����ϴ� ����
    Node* current = first; // ���� ��带 ����Ű�� ������

    while (current != nullptr) { // ��� ��带 ��ȸ
        if (current->data == word) { // �ܾ ã�� ���
            cout << "'" << word << "' is found at position " << count << endl;
            return;
        }
        current = current->link; // ���� ���� �̵�
        count++;
    }

    cout << "'" << word << "' is not found in the dictionary." << endl; // �ܾ ã�� ���� ���
}

void Dictionary::Insert(string word) {
    Node* newNode = new Node; // ���ο� ��� ����
    newNode->data = word; // ���ο� ��忡 �ܾ� ����

    if (first == nullptr || word < first->data) { // ��ųʸ��� ����ְų� ������ �ܾ ù ��° �ܾ�� ���� ���
        newNode->link = first; // ���ο� ��带 ù ��° ���� ����
        first = newNode; // ù ��° ���� ���ο� ��带 ������Ʈ
        cout << "'" << word << "' is inserted into the dictionary." << endl;
        return;
    }

    Node* current = first;
    while (current->link != nullptr && word > current->link->data) { // ���ĺ� ������ �´� ��ġ�� ã�� ������ ��ȸ
        current = current->link;
    }

    newNode->link = current->link; // ���ο� ����� ���� ��带 ���� ����� ���� ���� ����
    current->link = newNode; // ���� ����� ���� ���� ���ο� ��带 ����
    cout << "'" << word << "' is inserted into the dictionary." << endl;
}

void Dictionary::Delete(string word) {
    if (first == nullptr) { // ��ųʸ��� ����ִ� ���
        cout << "Dictionary is empty." << endl;
        return;
    }

    if (first->data == word) { // ù ��° ��忡 �ִ� �ܾ �����ϴ� ���
        Node* temp = first; // �ӽ÷� ù ��° ��带 ����
        first = first->link; // ù ��° ��带 ���� ���� ����
        delete temp; // ù ��° ��� ����
        cout << "'" << word << "' is deleted from the dictionary." << endl;
        return;
    }

    Node* current = first;
    while (current->link != nullptr && current->link->data != word) { // ������ �ܾ ã�� ������ ��ȸ
        current = current->link;
    }

    if (current->link == nullptr) { // ������ �ܾ ���� ���
        cout << "'" << word << "' is not found in the dictionary." << endl;
        return;
    }

    Node* temp = current->link; // ������ ��带 �ӽ÷� ����
    current->link = current->link->link; // ���� ����� ���� ��带 ������ ����� ���� ���� ����
    delete temp; // ������ ��� ����
    cout << "'" << word << "' is deleted from the dictionary." << endl;
}

void Dictionary::Display() {
    if (first == nullptr) { // ��ųʸ��� ����ִ� ���
        cout << "Dictionary is empty." << endl;
        return;
    }

    cout << "Dictionary contents: ";
    Node* current = first;
    while (current != nullptr) { // ��� ��带 ��ȸ�ϸ� ���
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

int main() {
    Dictionary Dt("ABC"); // "ABC"�� �ʱ� �ܾ�� ������ ��ųʸ� ����
    int input = 1;
    string word;

    while (input) {
        cout << "(1)Insert    (2)Delete    (3)Display    (4)Find    (0)END" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Word to insert: ";
            cin >> word;
            Dt.Insert(word);
        }
        else if (input == 2) {
            cout << "Word to delete: ";
            cin >> word;
            Dt.Delete(word);
        }
        else if (input == 3) {
            Dt.Display();
        }
        else if (input == 4) {
            cout << "Word to find: ";
            cin >> word;
            Dt.Find(word);
        }
    }

    return 0;
}
