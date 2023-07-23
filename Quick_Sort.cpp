#include <iostream>

// 퀵정렬에서 사용되는 파티션 함수
int Partition(int* arr, int low, int high) {
    int pivot = arr[high]; // 피벗으로 배열의 마지막 원소 선택
    int i = low - 1; // 피벗보다 작은 원소들을 찾기 위한 인덱스

    // 피벗보다 작은 원소를 왼쪽으로 이동시킴
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // 피벗을 정렬된 위치로 이동
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 퀵 정렬 함수
void QuickSort(int* arr, int low, int high) {
    if (low < high) {
        int partitionIndex = Partition(arr, low, high); // 파티션 함수를 호출하여 피벗의 인덱스를 얻음
        QuickSort(arr, low, partitionIndex - 1); // 왼쪽 부분 배열을 정렬
        QuickSort(arr, partitionIndex + 1, high); // 오른쪽 부분 배열을 정렬
    }
}

// 테스트를 위한 함수
void PrintArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 }; // 테스트용 배열
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "정렬 전 배열: ";
    PrintArray(arr, size);

    // 퀵정렬 호출
    QuickSort(arr, 0, size - 1);

    std::cout << "정렬 후 배열: ";
    PrintArray(arr, size);

    return 0;
}
