#include <iostream>

using namespace std;

long long int bubbleSwaps(long long int *a, long long int len) {
    long long int swap = 0, i, j, temp;
    int flag;
    for (i = 0; i < len - 1; i++) {
        int flag = 1;
        for (j = i + 1; j < len; j++) {
            if (a[j] < a[i]) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                swap++;
                flag = 0;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return swap;
}

long long int power(long long int x, unsigned long long int y, unsigned long long int m)
{
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}

int main() {
    long long int len, *a, i, totalSwapping, totalSwappingModulo, mod = 1000000007, sum = 0;
    cin >> len;

    a = new long long int(len);
    
    for (i = 0; i < len; i++) {
        cin >> a[i];
    }

    // long long int defaultSwap = bubbleSwaps(a, len);

    totalSwapping = (len * (len + 1)) / 2;
    totalSwappingModulo = power(totalSwapping, mod - 2, mod);

    long long int noOfSwapping;
    long long int noOfTimeItOccur, temp;

    for (i = 1; i <= len; i++) {
        noOfSwapping = ((i * (i - 1)) / 2) % mod;
        noOfTimeItOccur = (len - i + 1) % mod;
        temp = (noOfTimeItOccur * noOfSwapping * totalSwappingModulo) % mod;
        sum += temp;
        sum %= mod;
    }

    cout << sum << endl;

    return 0;
}
