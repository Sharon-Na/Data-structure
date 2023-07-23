#include <iostream>
using namespace std;


// �պ� ��� �Լ�
void Merge(int* arr, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    // �ӽ� �迭 ����
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // ���� �迭�� �����͸� �ӽ� �迭�� ����
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[middle + 1 + i];

    // �� �ӽ� �迭�� �պ�, ���� �迭�� ���ĵ� ���·� ����
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    } 
  
    // ���� ���ҵ� ���� �迭�� ����
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // �ӽ� �迭 ��ȯ
    delete[] leftArr;
    delete[] rightArr;
}

// �պ� ���� �Լ�
void MergeSort(int* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);       // ���� ������ ����
        MergeSort(arr, middle + 1, right);  // ������ ������ ����
        Merge(arr, left, middle, right);    // ���ĵ� �� �迭�� �պ�
    }
}

// �׽�Ʈ�� �Լ�
void PrintArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 }; // �׽�Ʈ�� �迭
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "���� �� �迭: ";
    PrintArray(arr, size);

    // �պ����� ȣ��
    MergeSort(arr, 0, size - 1);

    cout << "���� �� �迭: ";
    PrintArray(arr, size);

    return 0;
}
