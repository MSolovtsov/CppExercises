#include <iostream>

using namespace std;

void merge(float array[], int left, int mid, int right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    float leftArray[subArrayOne];
    float rightArray[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int i = 0; i < subArrayTwo; i++)
        rightArray[i] = array[mid + 1 + i];

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergeArray = left;

    // Объединяем временные массивы обратно в массив [слева.. справа]
    while (indexOfSubArrayOne < subArrayOne
                && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
                >= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergeArray++;
    }

    //Скопируем оставшиеся элементы в left[], если такие есть
    while (indexOfSubArrayOne < subArrayOne){
        array[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergeArray++;
    }

    //Скопируем оставшиеся элементы в right[], если такие есть
    while (indexOfSubArrayTwo < subArrayTwo){
        array[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergeArray++;
    }
}

void mergeSort(float array[], int begin, int end){
    if (begin >= end)
        return; // Возвращает рекурсивно
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(float A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main() {
    cout << "\n#2  Sorting\n" << endl;

    float arr[] = { 1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1,
                    1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251 };

    cout << "Given arrat is \n";
    printArray(arr, 15);

    mergeSort(arr, 0, 14);

    cout << "\nSorted array is \n";
    printArray(arr,  15);

    return 0;
}
