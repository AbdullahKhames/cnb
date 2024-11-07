#include "../main.h"


void swap(int *arr, int x, int y ) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* createIntArr(int n){
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cout << "enter number " << i + 1 << "elemnt of the array\n";
        cin >> arr[i];
    }
    return (arr);
}

float* createArr(int arrSize){
    float *arr;
    arr = new float[arrSize];
    for (int i = 0; i < arrSize; i++){
        cout << "enter the number " << i + 1 << " element\t";
        cin >> arr[i];
    }
    return arr;
}

float calculateMean(float *arr, int arrSize) {
    if (arrSize <= 0)
    {
        return 0.0;
    }
    
    float sum = 0.0;
    for (size_t i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    return sum / arrSize;
    
}

SampleData* createSampleData(int size) {
    SampleData* sample  = (SampleData*) malloc(sizeof(SampleData));
    sample->size = size;
    sample->average = 0;
    sample->data = (float*) malloc(sizeof(float) * size);
    return sample;
}

SampleData** createSampleDataArr(int size) {
    int i = 0;
    SampleData* firstSample  = createSampleData(size);
    SampleData* secondSample = createSampleData(size);
    SampleData** samples = (SampleData**) malloc(sizeof(SampleData) * 2);
    samples[0] = firstSample;
    samples[1] = secondSample;

    for (; i < size; i++) {
        cout << "enter number " << i + 1 << " element in first samples \n";
        cin >> firstSample->data[i];
        firstSample->average += firstSample->data[i];
        cout << "enter number " << i + 1 << " element in second samples \n";
        cin >> secondSample->data[i];
        secondSample->average += secondSample->data[i];
    }
    firstSample->average = firstSample->average / size;
    secondSample->average = secondSample->average / size;
    
    return samples;
}
