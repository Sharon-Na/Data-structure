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

int main() {
    Stack<int> stack(5);  // int 타입을 저장할 수 있는 크기 5인 스택 생성

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}

