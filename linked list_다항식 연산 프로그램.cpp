#include<iostream>
using namespace std;

class Polynomial
{
private:
    class Node
    {
    public:
        float coef; // ����� �����ϴ� ����
        int exp; // ������ �����ϴ� ����
        Node* link; // ���� ��带 ����Ű�� ������

        Node(float c, int e = 0) { // ��� ������
            coef = c; // ��� �ʱ�ȭ
            exp = e; // ���� �ʱ�ȭ
        }
    };

    Node* first; // ù ��° ��带 ����Ű�� ������

public:
    Polynomial() { first = NULL; } // ���׽� ������
    void Get_Polynomial(); // ���׽��� �Է¹޴� �Լ�
    void Insert(float c, int e); // ��� c�� ���� e�� ������ ���� ���׽Ŀ� �߰�
    Polynomial operator +(const Polynomial& b); // ���׽� ���� ������ �����ε�
    void Print(); // ���׽��� ������������ ���
};

void Polynomial::Get_Polynomial()
{
    float C; // ����� �Է¹��� ����
    int E; // ������ �Է¹��� ����

    cout << "���׽� ���� ���� (����� 0�� �Է��ϸ� ������ �ߴ��մϴ�)" << endl;

    while (1) // �Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        cout << "�߰��� ���� ���(�Ǽ�)�� ����(����)�� �Է��ϼ��� : ";
        cin >> C >> E; // ����� ���� �Է¹���

        if (C == 0) // ����� 0�� �Է¹�����
            break; // �Լ� ���� (���׽� ���� �ߴ�)

        Insert(C, E); // ��� C�� ���� E�� ������ ���� �߰�
    }
}

void Polynomial::Insert(float c, int e)
{
    Node* newNode = new Node(c, e); // ���ο� ��� ����

    if (first == NULL) // ���׽��� ����ִ� ���
    {
        first = newNode; // ���ο� ��带 ù ��° ���� ����
        return;
    }

    Node* current = first;
    while (current->link != NULL) // ���׽��� ������ ������ ��ȸ
    {
        current = current->link;
    }

    current->link = newNode; // ������ ����� ���� ���� ���ο� ��带 ����
}

Polynomial Polynomial::operator +(const Polynomial& b)
{
    Polynomial result; // �� ���׽��� ���� ����� ������ ���׽�
    Node* ai = this->first; // ù ��° ���׽��� ��带 ����Ű�� ������
    Node* bi = b.first; // �� ��° ���׽��� ��带 ����Ű�� ������

    while (ai != NULL && bi != NULL) // ai�� bi�� ��� NULL�� �ƴ� ������ �ݺ�
    {
        if (ai->exp > bi->exp) // ai�� ������ bi�� �������� ū ���
        {
            result.Insert(ai->coef, ai->exp); // ai�� ���� ��� ���׽Ŀ� �߰�
            ai = ai->link; // ���� ai�� �̵�
        }
        else if (ai->exp < bi->exp) // bi�� ������ ai�� �������� ū ���
        {
            result.Insert(bi->coef, bi->exp); // bi�� ���� ��� ���׽Ŀ� �߰�
            bi = bi->link; // ���� bi�� �̵�
        }
        else // ai�� bi�� ������ ���� ���
        {
            float sum = ai->coef + bi->coef; // ����� ����
            if (sum != 0) // ���� 0�� �ƴ� ��쿡�� ��� ���׽Ŀ� �߰�
                result.Insert(sum, ai->exp);
            ai = ai->link; // ���� ai�� �̵�
            bi = bi->link; // ���� bi�� �̵�
        }
    }

    // ���� �׵��� ��� ���׽Ŀ� �߰�
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

    return result; // ������ �Ϸ�� ���׽� ��ȯ
}

void Polynomial::Print()
{
    if (first == NULL) // ���׽��� ����ִ� ���
    {
        cout << "���׽��� ����ֽ��ϴ�." << endl;
        return;
    }

    Node* current = first;
    while (current != NULL) // ��� ��带 ��ȸ�ϸ� ���
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
