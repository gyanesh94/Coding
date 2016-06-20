#include <iostream>
#include <cmath>
using namespace std;

void merge(double **junctionCost, int low, int high, int mid){
    double **c = new double*[500];
    int i = low, k = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (junctionCost[i][1] > junctionCost[j][1]) {
            c[k] = junctionCost[i];
            i++;
            k++;
        } else {
            c[k] = junctionCost[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        c[k] = junctionCost[i];
        i++;
        k++;
    }
    while (j <= high) {
        c[k] = junctionCost[j];
        j++;
        k++;
    }
    for (i = low; i < k; i++)
    {
        junctionCost[i] = c[i];
    }
}

void mergeSort(double **junctionCost, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(junctionCost, low, mid);
        mergeSort(junctionCost, mid + 1, high);
        merge(junctionCost, low, high, mid);
    }
}

int main() {
    long int numberOfjunctions, numberOfUndirectedRoads, maxNubmerOfSurveillanceCamera;

    long int i, j, tempSourceJunction, tempDestinationJunction, tempCost;

    double totalAvgCost = 0;

    cin >> numberOfjunctions;
    cin >> numberOfUndirectedRoads;
    cin >> maxNubmerOfSurveillanceCamera;

    double **junctionCost = new double*[numberOfjunctions];

    for (i = 0; i < numberOfjunctions; i++) {
        junctionCost[i] = new double[3];
        junctionCost[i][0] = i + 1;
        junctionCost[i][1] = 0;
        junctionCost[i][2] = 0;
    }

    for (i = 0; i < numberOfUndirectedRoads; i++) {
        cin >> tempSourceJunction;
        cin >> tempDestinationJunction;
        cin >> tempCost;

        totalAvgCost = totalAvgCost + tempCost;

        junctionCost[tempSourceJunction - 1][1] += tempCost;
        junctionCost[tempSourceJunction - 1][2]++;

        junctionCost[tempDestinationJunction - 1][1] += tempCost;
        junctionCost[tempDestinationJunction - 1][2]++;
    }

    totalAvgCost = totalAvgCost / numberOfUndirectedRoads;

    for (i = 0; i < numberOfjunctions; i++) {
        junctionCost[i][1] = junctionCost[i][1]/(maxNubmerOfSurveillanceCamera * junctionCost[i][2] * totalAvgCost);
    }

    mergeSort(junctionCost, 0, numberOfjunctions - 1);

    int *result = new int[maxNubmerOfSurveillanceCamera];
    for (i = 0; i < maxNubmerOfSurveillanceCamera && junctionCost[i][1] > 0; i++) {
        result[i] = junctionCost[i][0];
    }

    cout << i << endl;

    for (j = 0; j < i; j++) {
        cout << result[j];
        if (j < i - 1) {
            cout << " ";
        }
    }
    return 0;
}