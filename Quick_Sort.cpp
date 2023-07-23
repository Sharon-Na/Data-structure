#include <iostream>
using namespace std;

// 퀵정렬에서 사용되는 파티션 함수
int Partition(int* arr, int low, int high) {
    int pivot = arr[high]; // 피벗으로 배열의 마지막 원소 선택
    int i = low - 1; // 피벗보다 작은 원소들을 찾기 위한 인덱스

    // 피벗보다 작은 원소를 왼쪽으로 이동
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // 피벗 정렬된 위치로 이동
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 퀵 정렬 함수
void QuickSort(int* arr, int low, int high) {
    if (low < high) {
        int partitionIndex = Partition(arr, low, high); // 파티션 함수를 호출해 피벗의 인덱스를 얻기
        QuickSort(arr, low, partitionIndex - 1); // 왼쪽 부분 배열 정렬
        QuickSort(arr, partitionIndex + 1, high); // 오른쪽 부분 배열 정렬
    }
}

// 테스트용 함수
void PrintArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 }; // 테스트용 배열
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "정렬 전 배열: ";
    PrintArray(arr, size);

    // 퀵정렬 호출
    QuickSort(arr, 0, size - 1);

    cout << "정렬 후 배열: ";
    PrintArray(arr, size);

    return 0;
}
