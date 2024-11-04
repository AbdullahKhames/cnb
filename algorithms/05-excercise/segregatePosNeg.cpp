#include <iostream>

using namespace std;
void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int *arr, int x, int y ) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
void segregate1(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] < 0 && arr[i] >= 0)
        {
            swap(arr, i, i + 1);
        } else if (i <= n - 2) {
            
        }
    }
}
void segregateWithMerge(int *arr, int start, int mid, int end){
    int i, j, k;
    int leftLength = (mid + 1 - start);
    int rightLength = (end - mid);
    int leftArr[leftLength];
    int rightArr[rightLength];
    for (i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[start + i];
    }
    for (j = 0; j < rightLength; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    // while (i < leftLength && j < rightLength)
    // {
    //     if (leftArr[i] < 0)
    //     {
    //         arr[k++] = leftArr[i++];
    //     }else{
    //         arr[k++] = rightArr[j++];
    //     }
    // }
    while (i < leftLength && leftArr[i] <=0)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < rightLength && rightArr[j] <= 0)
    {
        arr[k++] = rightArr[j++];
    }
    while (i < leftLength)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < rightLength)
    {
        arr[k++] = rightArr[j++];
    }
    
}
void segregate(int *arr, int start, int end) {
    if (end <= start)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    segregate(arr, start, mid);
    segregate(arr, mid + 1, end);
    segregateWithMerge(arr, start, mid, end); 
    
}

int main() {
    int n = 8;
    int arr [] = {9, -3, 5, -2, -8, -6, 1, 3};
    printArr(arr, n);
    segregate(arr, 0, n - 1);
    printArr(arr, n);
    return (0);
}
