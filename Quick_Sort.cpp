#include <iostream>

// �����Ŀ��� ���Ǵ� ��Ƽ�� �Լ�
int Partition(int* arr, int low, int high) {
    int pivot = arr[high]; // �ǹ����� �迭�� ������ ���� ����
    int i = low - 1; // �ǹ����� ���� ���ҵ��� ã�� ���� �ε���

    // �ǹ����� ���� ���Ҹ� �������� �̵���Ŵ
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // �ǹ��� ���ĵ� ��ġ�� �̵�
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// �� ���� �Լ�
void QuickSort(int* arr, int low, int high) {
    if (low < high) {
        int partitionIndex = Partition(arr, low, high); // ��Ƽ�� �Լ��� ȣ���Ͽ� �ǹ��� �ε����� ����
        QuickSort(arr, low, partitionIndex - 1); // ���� �κ� �迭�� ����
        QuickSort(arr, partitionIndex + 1, high); // ������ �κ� �迭�� ����
    }
}

// �׽�Ʈ�� ���� �Լ�
void PrintArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 }; // �׽�Ʈ�� �迭
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "���� �� �迭: ";
    PrintArray(arr, size);

    // ������ ȣ��
    QuickSort(arr, 0, size - 1);

    std::cout << "���� �� �迭: ";
    PrintArray(arr, size);

    return 0;
}
