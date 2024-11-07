#include "../main.h"

float calculateNextIter(float x, float mean){
    float num = x - mean;
    return num * num;
}
float calculateTopTerm(float *arr, int arrSize, float mean){
    float sum = 0;
    for (int i = 0; i < arrSize; i++){
        sum += calculateNextIter(arr[i], mean);
    }
    return sum;
}

float standardDeviation(){
    cout << "calculate standardDeviation\n";
    int arrSize;
    cout << "enter the size of the array\n";
    cin >> arrSize;
    if (arrSize <= 0)
    {
        return (0.0);
    }
    float *arr = createArr(arrSize);
    float mean = calculateMean(arr, arrSize);
    float topTerm = calculateTopTerm(arr, arrSize, mean);
    float insideTerms = topTerm / arrSize;
    float answer = sqrt(insideTerms);
    free(arr);
    return answer;
}

// int main(){
//     float result = standardDeviation();
//     cout << fixed << setprecision(2) << result << endl;
//     return (0);
// }
