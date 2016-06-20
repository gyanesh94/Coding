#include <iostream>
#include <cmath>
using namespace std;

long double akatsuki[20][2], leaf[20][2], maxDistance = 0;
int number;

void calculateDistance(int *a) {
    long double sum = 0;
    for (int i = 0; i < number; i++) {
        sum = sum + abs(akatsuki[a[i]][0] - leaf[a[i]][0]) + abs(akatsuki[a[i]][1] - leaf[a[i]][1]);
    }
    if (sum > maxDistance) {
        maxDistance = sum;
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a, int l, int r)
{
    int i;
    if (l == r)
        calculateDistance(a);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i));
        }
    }
}


int main() {
    int i, *a;
    cin >> number;
    
    a = new int[number];
    
    for (i = 0; i < number; i++) {
        a[i] = i;
        cin >> akatsuki[i][0];
        cin >> akatsuki[i][1];
    }
    for (i = 0; i < number; i++) {
        cin >> leaf[i][0];
        cin >> leaf[i][1];
    }

    permute(a, 0, number - 1);

    cout << maxDistance << endl;

    return 0;
} 