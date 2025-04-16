#include "../main.h"

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

void mergeSort(int *arr, int size) {
    mergeSort(arr, 0, size - 1);
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



void mergeSortTwoDimension(int **arr, int size) {
    mergeSortTwoDimension(arr, 0, size - 1);
}


void mergeSortTwoDimension(int **arr, int start, int end) {
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSortTwoDimension(arr, start, mid);
    mergeSortTwoDimension(arr, mid + 1, end);
    mergeTwoDimension(arr, start, mid, end);
}

void mergeTwoDimension(int **arr, int start, int mid, int end) {
    int i, j, k;
    int leftLength = mid + 1 - start;
    int rightLength = end - mid;
    int **leftArr = (int **) malloc(sizeof(int *) * leftLength);
    int **rightArr = (int **) malloc(sizeof(int *) * rightLength);
    for (i = 0; i < leftLength; i++)
    {
        leftArr[i] = (int *)malloc(2 * sizeof(int));
        leftArr[i][0] = arr[start + i][0];
        leftArr[i][1] = arr[start + i][1];
    }
    for (j = 0; j < rightLength; j++)
    {
        rightArr[j] = (int *)malloc(2 * sizeof(int));
        rightArr[j][0] = arr[mid + 1 + j][0];
        rightArr[j][1] = arr[mid + 1 + j][1];
    }
    
    i = 0;
    j = 0;
    k = start;
    while (i < leftLength && j < rightLength) {
        if (leftArr[i][1] <= rightArr[j][1])
        {
            arr[k][0] = leftArr[i][0];
            arr[k][1] = leftArr[i][1];
            i++; k++;
        }
        else {
            arr[k][0] = rightArr[j][0];
            arr[k][1] = rightArr[j][1];
            j++; k++;
        }
    }

    while (i < leftLength)
    {
        arr[k][0] = leftArr[i][0];
        arr[k][1] = leftArr[i][1];
        k++;
        i++;
    }

    while (j < rightLength)
    {
        arr[k][0] = rightArr[j][0];
        arr[k][1] = rightArr[j][1];
        k++;
        j++;
    }
    for (int i = 0; i < leftLength; i++)
    {
        free(leftArr[i]);

    }
    for (int i = 0; i < rightLength; i++)
    {
        free(rightArr[i]);

    }
    free(leftArr);
    free(rightArr);
}

// int main() {
//     // cout << "enter size of the array to be sorted" << endl;
//     // int n;
//     // cin >> n;
//     // int *arr = createIntArr(n);
//     int n = 5;
//     int arr[5] = {5, 4, 3, 2, 1};
//     cout << "printing the array before sorting" << endl;
//     printArr(arr, n);
//     mergeSort(arr, 0, n - 1);
//     cout << "printing the array after sorting" << endl;
//     printArr(arr, n);
//     // free(arr);
//     return (0);
// }
