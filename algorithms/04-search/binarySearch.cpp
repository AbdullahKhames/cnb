#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int guess = arr[mid];
        if (guess < target) {
            start = mid + 1;
        } else if (guess > target) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return (-1);
    
}
int main(){
    int n = 10;
    int arr[n] = {1, 3, 9, 17, 25, 35, 68, 78, 123, 245};
    int index1 = binarySearch(arr, n, 1);
    int index2 = binarySearch(arr, n, 17);
    int index3 = binarySearch(arr, n, 68);
    int index4 = binarySearch(arr, n, 123);
    int index5 = binarySearch(arr, n, 300);

    cout << "first try is " << (index1 == 0) << " at index " << index1 << endl;
    cout << "second try is " << (index2 == 3) << " at index " << index2 << endl;
    cout << "third try is " << (index3 == 6) << " at index " << index3 << endl;
    cout << "fourth try is " << (index4 == 8) << " at index " << index4 << endl;
    cout << "fifth try is not found " << (index5 == -1) << " at index " << index5 << endl;

    return (0);
}
