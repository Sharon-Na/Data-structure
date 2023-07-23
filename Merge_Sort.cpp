#include <iostream>
using namespace std;


// 합병 기능 함수
void Merge(int* arr, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    // 임시 배열 생성
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // 원본 배열의 데이터를 임시 배열로 복사
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[middle + 1 + i];

    // 두 임시 배열을 합병, 원본 배열에 정렬된 상태로 저장
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
  
    // 남은 원소들 원본 배열에 저장
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

    // 임시 배열 반환
    delete[] leftArr;
    delete[] rightArr;
}

// 합병 정렬 함수
void MergeSort(int* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);       // 왼쪽 절반을 정렬
        MergeSort(arr, middle + 1, right);  // 오른쪽 절반을 정렬
        Merge(arr, left, middle, right);    // 정렬된 두 배열을 합병
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

    // 합병정렬 호출
    MergeSort(arr, 0, size - 1);

    cout << "정렬 후 배열: ";
    PrintArray(arr, size);

    return 0;
}
