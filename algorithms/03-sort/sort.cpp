#include <iostream>

using namespace std;
void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int* createArr(int n){
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cout << "enter number " << i + 1 << "elemnt of the array\n";
        cin >> arr[i];
    }
    return (arr);
}

void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
            }else {
                break;
            }
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(int *arr, int start, int mid, int end) {
    int i, j, k;
    int leftLength = mid + 1 - start;
    int rightLength = end - mid;
    int *leftArr = (int *) malloc(sizeof(int) * leftLength);
    int *rightArr = (int *) malloc(sizeof(int) * rightLength);

    for (i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[start + i];
    }
    for (j = 0; j < rightLength; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    cout << "printing left side before merging" << endl;
    printArr(leftArr, leftLength);
    cout << "printing right side before merging" << endl;
    printArr(rightArr, rightLength);
    
    i = 0;
    j = 0;
    k = start;
    while (i < leftLength && j < rightLength) {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftLength)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < rightLength)
    {
        arr[k++] = rightArr[j++];
    }
    free(leftArr);
    free(rightArr);
}

void mergeSort(int *arr, int start, int end) {
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}


int main() {
    // cout << "enter size of the array to be sorted" << endl;
    // int n;
    // cin >> n;
    // int *arr = createArr(n);
    int n = 5;
    int arr[5] = {5, 4, 3, 2, 1};
    cout << "printing the array before sorting" << endl;
    printArr(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "printing the array after sorting" << endl;
    printArr(arr, n);
    // free(arr);
    return (0);
}
