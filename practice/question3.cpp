/*
    Method 1
        Using O(n^2) time complexity O(1) space complexity
        Loop for each and multiply it with other element and check it

    Method 2
        Using O(n) time complexity O(M) space complexity     M is the maximum element present in the array

        Maintain an array upto size of max of element in input and value of it will be count number of times it is present
        else it will be zero.

        Divide first number with product and check its modulo is zero if it is than check division result is present in
        array or not if it is present than return true else false

        ** Note- Take care 0f zero division

    Method 3
        Same as Method 2 but using C++ in_built functions to reduce number of loops
 */

#include <iostream>
#include <unordered_set>

using namespace std;

int MAX = 1000;

bool method1(int *a, int N, long long int product) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if ((a[i] * a[j]) == product) {
                return true;
            }
        }
    }
    return false;
}

bool method2(int *a, int N, long long int product) {
    int numberPresent[MAX];
    int i;
    long long remainder;

    if (product == 0) {
        for (i = 0; i < N; i++) {
            if (a[i] == 0) {
                return true;
            }
        }
        return false;
    }

    for (i = 0; i < MAX; i++) {
        numberPresent[i] = 0;
    }
    for (i = 0; i < N; i++) {
        numberPresent[a[i]]++;
    }
    for (i = 0; i < N; i++) {
        if (a[i] == 0) {
            continue;
        }
        if (product % a[i] == 0) {
            remainder = product / a[i];
            if (remainder == a[i]) {
                if (numberPresent[a[i]] > 1) {
                    return true;
                } else {
                    continue;
                }
            }

            if (numberPresent[remainder] > 0) {
                return true;
            }
        }
    }
    return false;
}

bool method3(int *a, int N, long long int product) {
    unordered_set<long long int> present;
    int i;

    if (product == 0) {
        for (i = 0; i < N; i++) {
            if (a[i] == 0) {
                return true;
            }
        }
        return false;
    }

    for (i = 0; i < N; i++) {
        if (a[i] == 0) {
            continue;
        }
        if (product % a[i] == 0) {
            if (present.find(product / a[i]) != present.end()) {
                return true;
            }
            present.insert(a[i]);
        }
    }
    return false;
}

int main() {
    int testCase, N, *a;

    long long int product;
    cin >> testCase;
    for (int i = 0; i < testCase; ++i) {
        cin >> N >> product;
        a = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }

        if (N < 2) {
            cout << "No" << endl;
            continue;
        }

        if (method2(a, N, product)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}