#include<iostream>
using namespace std;

class Dictionary {
private:
    class Node {
    public:
        string data; // 단어를 저장하는 변수
        Node* link; // 다음 노드를 가리키는 포인터
    };

    Node* first; // 첫 번째 노드를 가리키는 포인터

public:
    Dictionary(string word); // 단어로 딕셔너리 생성자
    void Find(string word); // 단어가 있는 위치를 출력하거나 단어가 없다는 메시지 출력
    void Insert(string word); // 단어를 알맞은 위치에 삽입 (알파벳 순서)
    void Delete(string word); // 단어를 딕셔너리에서 삭제
    void Display(); // 딕셔너리의 내용을 출력
};

Dictionary::Dictionary(string word) {
    first = new Node; // 첫 번째 노드 생성
    first->data = word; // 첫 번째 노드에 단어 저장
    first->link = nullptr; // 첫 번째 노드의 다음 노드를 NULL로 초기화
}

void Dictionary::Find(string word) {
    int count = 1; // 단어의 위치를 저장하는 변수
    Node* current = first; // 현재 노드를 가리키는 포인터

    while (current != nullptr) { // 모든 노드를 순회
        if (current->data == word) { // 단어를 찾은 경우
            cout << "'" << word << "' is found at position " << count << endl;
            return;
        }
        current = current->link; // 다음 노드로 이동
        count++;
    }

    cout << "'" << word << "' is not found in the dictionary." << endl; // 단어를 찾지 못한 경우
}

void Dictionary::Insert(string word) {
    Node* newNode = new Node; // 새로운 노드 생성
    newNode->data = word; // 새로운 노드에 단어 저장

    if (first == nullptr || word < first->data) { // 딕셔너리가 비어있거나 삽입할 단어가 첫 번째 단어보다 작은 경우
        newNode->link = first; // 새로운 노드를 첫 번째 노드로 지정
        first = newNode; // 첫 번째 노드로 새로운 노드를 업데이트
        cout << "'" << word << "' is inserted into the dictionary." << endl;
        return;
    }

    Node* current = first;
    while (current->link != nullptr && word > current->link->data) { // 알파벳 순서에 맞는 위치를 찾을 때까지 순회
        current = current->link;
    }

    newNode->link = current->link; // 새로운 노드의 다음 노드를 현재 노드의 다음 노드로 지정
    current->link = newNode; // 현재 노드의 다음 노드로 새로운 노드를 지정
    cout << "'" << word << "' is inserted into the dictionary." << endl;
}

void Dictionary::Delete(string word) {
    if (first == nullptr) { // 딕셔너리가 비어있는 경우
        cout << "Dictionary is empty." << endl;
        return;
    }

    if (first->data == word) { // 첫 번째 노드에 있는 단어를 삭제하는 경우
        Node* temp = first; // 임시로 첫 번째 노드를 저장
        first = first->link; // 첫 번째 노드를 다음 노드로 변경
        delete temp; // 첫 번째 노드 삭제
        cout << "'" << word << "' is deleted from the dictionary." << endl;
        return;
    }

    Node* current = first;
    while (current->link != nullptr && current->link->data != word) { // 삭제할 단어를 찾을 때까지 순회
        current = current->link;
    }

    if (current->link == nullptr) { // 삭제할 단어가 없는 경우
        cout << "'" << word << "' is not found in the dictionary." << endl;
        return;
    }

    Node* temp = current->link; // 삭제할 노드를 임시로 저장
    current->link = current->link->link; // 현재 노드의 다음 노드를 삭제할 노드의 다음 노드로 변경
    delete temp; // 삭제할 노드 삭제
    cout << "'" << word << "' is deleted from the dictionary." << endl;
}

void Dictionary::Display() {
    if (first == nullptr) { // 딕셔너리가 비어있는 경우
        cout << "Dictionary is empty." << endl;
        return;
    }

    cout << "Dictionary contents: ";
    Node* current = first;
    while (current != nullptr) { // 모든 노드를 순회하며 출력
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

int main() {
    Dictionary Dt("ABC"); // "ABC"를 초기 단어로 가지는 딕셔너리 생성
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
