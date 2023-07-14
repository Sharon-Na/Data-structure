#include<iostream>
using namespace std;

class Polynomial
{
private:
    class Node
    {
    public:
        float coef; // 계수를 저장하는 변수
        int exp; // 지수를 저장하는 변수
        Node* link; // 다음 노드를 가리키는 포인터

        Node(float c, int e = 0) { // 노드 생성자
            coef = c; // 계수 초기화
            exp = e; // 지수 초기화
        }
    };

    Node* first; // 첫 번째 노드를 가리키는 포인터

public:
    Polynomial() { first = NULL; } // 다항식 생성자
    void Get_Polynomial(); // 다항식을 입력받는 함수
    void Insert(float c, int e); // 계수 c와 지수 e를 가지는 항을 다항식에 추가
    Polynomial operator +(const Polynomial& b); // 다항식 덧셈 연산자 오버로딩
    void Print(); // 다항식을 내림차순으로 출력
};

void Polynomial::Get_Polynomial()
{
    float C; // 계수를 입력받을 변수
    int E; // 지수를 입력받을 변수

    cout << "다항식 생성 시작 (계수에 0을 입력하면 생성을 중단합니다)" << endl;

    while (1) // 아래 조건문에 의해 중단되기 전까지 무한반복
    {
        cout << "추가할 항의 계수(실수)와 지수(정수)를 입력하세요 : ";
        cin >> C >> E; // 계수와 지수 입력받음

        if (C == 0) // 계수로 0을 입력받으면
            break; // 함수 종료 (다항식 생성 중단)

        Insert(C, E); // 계수 C와 지수 E를 가지는 항을 추가
    }
}

void Polynomial::Insert(float c, int e)
{
    Node* newNode = new Node(c, e); // 새로운 노드 생성

    if (first == NULL) // 다항식이 비어있는 경우
    {
        first = newNode; // 새로운 노드를 첫 번째 노드로 지정
        return;
    }

    Node* current = first;
    while (current->link != NULL) // 다항식의 마지막 노드까지 순회
    {
        current = current->link;
    }

    current->link = newNode; // 마지막 노드의 다음 노드로 새로운 노드를 지정
}

Polynomial Polynomial::operator +(const Polynomial& b)
{
    Polynomial result; // 두 다항식의 덧셈 결과를 저장할 다항식
    Node* ai = this->first; // 첫 번째 다항식의 노드를 가리키는 포인터
    Node* bi = b.first; // 두 번째 다항식의 노드를 가리키는 포인터

    while (ai != NULL && bi != NULL) // ai와 bi가 모두 NULL이 아닐 때까지 반복
    {
        if (ai->exp > bi->exp) // ai의 지수가 bi의 지수보다 큰 경우
        {
            result.Insert(ai->coef, ai->exp); // ai의 항을 결과 다항식에 추가
            ai = ai->link; // 다음 ai로 이동
        }
        else if (ai->exp < bi->exp) // bi의 지수가 ai의 지수보다 큰 경우
        {
            result.Insert(bi->coef, bi->exp); // bi의 항을 결과 다항식에 추가
            bi = bi->link; // 다음 bi로 이동
        }
        else // ai와 bi의 지수가 같은 경우
        {
            float sum = ai->coef + bi->coef; // 계수를 더함
            if (sum != 0) // 합이 0이 아닌 경우에만 결과 다항식에 추가
                result.Insert(sum, ai->exp);
            ai = ai->link; // 다음 ai로 이동
            bi = bi->link; // 다음 bi로 이동
        }
    }

    // 남은 항들을 결과 다항식에 추가
    while (ai != NULL)
    {
        result.Insert(ai->coef, ai->exp);
        ai = ai->link;
    }

    while (bi != NULL)
    {
        result.Insert(bi->coef, bi->exp);
        bi = bi->link;
    }

    return result; // 덧셈이 완료된 다항식 반환
}

void Polynomial::Print()
{
    if (first == NULL) // 다항식이 비어있는 경우
    {
        cout << "다항식이 비어있습니다." << endl;
        return;
    }

    Node* current = first;
    while (current != NULL) // 모든 노드를 순회하며 출력
    {
        cout << current->coef << "x^" << current->exp << " ";
        current = current->link;
    }
    cout << endl;
}

int main()
{
    Polynomial A, B;

    cout << "[A] ";
    A.Get_Polynomial();
    cout << "[B] ";
    B.Get_Polynomial();

    cout << "[A] = ";
    A.Print();
    cout << "[B] = ";
    B.Print();

    Polynomial C = A + B;

    cout << "[A] + [B] = ";
    C.Print();

    return 0;
}
