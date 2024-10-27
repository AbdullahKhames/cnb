#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct SampleData{
    float *data;
    float average;
    int size;
}SampleData;

SampleData** createSampleData(int size) {
    int i = 0;
    SampleData* firstSample  = (SampleData*) malloc(sizeof(SampleData));
    SampleData* secondSample = (SampleData*) malloc(sizeof(SampleData));
    SampleData** samples = (SampleData**) malloc(sizeof(SampleData) * 2);
    samples[0] = firstSample;
    samples[1] = secondSample;
    firstSample->size = size;
    secondSample->size = size;
    secondSample->average = 0;
    firstSample->average = 0;
    firstSample->data = (float*) malloc(sizeof(float) * firstSample->size);
    secondSample->data = (float*) malloc(sizeof(float) * firstSample->size);

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

float calculateCoefficient(SampleData *firstSample, SampleData *secondSample){
    float numerator = 0, denominator = 0, firstSampleSum = 0, secondSampleSum = 0, firstSampleTerm = 0, secondSampleTerm = 0;
    int i = 0;
    for (; i < firstSample->size; i++) {
        firstSampleTerm = firstSample->data[i] - firstSample->average;
        secondSampleTerm = secondSample->data[i] - secondSample->average;
        numerator += firstSampleTerm * secondSampleTerm;
        firstSampleSum += pow(firstSampleTerm, 2);
        secondSampleSum += pow(secondSampleTerm, 2);
    }
    denominator = sqrt(firstSampleSum * secondSampleSum);
    return numerator / denominator;
}

float calculateCorrelationCoefficient() {
    SampleData* firstSample;
    SampleData* secondSample;
    float correlationCoefficient = 0;
    cout << "calculate Correlation Coefficient\n";
    int sampleSize;
    cout << "enter the size of the Sample Size\n";
    cin >> sampleSize;
    if (sampleSize <= 0)
    {
        return (0.0);
    }

    SampleData** samples = createSampleData(sampleSize);
    firstSample = samples[0];
    secondSample = samples[1];
    correlationCoefficient = calculateCoefficient(firstSample, secondSample);
    free(firstSample->data);
    free(secondSample->data);
    free(firstSample);
    free(secondSample);
    free(samples);
    return correlationCoefficient;
}

int main(){
    float result = calculateCorrelationCoefficient();
    cout << fixed << setprecision(2) << result << endl;
    return (0);
}
