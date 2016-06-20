/* 
    Got top right corner element value by using formula (dimension - 1) * dimension + 1
    Then loop to get value of four corners starting from above mentioned corner
    Then go on decreasing by 2 to get inner square
*/

#include <iostream>
using namespace std;

#define max 1000000009

long long int leafAndLimelightAttackArray[10000001];

void leafAndLimelightAttack () {
    long long int topRightElement, topLeftElement, bottomRightElement, bottomLeftElement, dimension, sum;

    leafAndLimelightAttackArray[0] = 0;
    leafAndLimelightAttackArray[1] = 1;

    for (dimension = 2; dimension < 10000001; dimension++) {
        sum = 0;

        topRightElement = (dimension - 1) * dimension + 1;
        sum+=(topRightElement);
        sum%=max;

        topLeftElement = topRightElement + dimension - 1;
        sum+=(topLeftElement);
        sum%=max;

        bottomRightElement = topRightElement - dimension + 1;
        sum+=(bottomRightElement);
        sum%=max;

        bottomLeftElement = bottomRightElement - dimension + 1;
        sum+=(bottomLeftElement);
        sum%=max;

        leafAndLimelightAttackArray[dimension] = (sum + leafAndLimelightAttackArray[dimension - 2]) % max;
    }
}

int main()
{
    long long int numberOfTestCases, result, i, testCase;
    cin >> numberOfTestCases;
    leafAndLimelightAttack();
    for (i = 1; i <= numberOfTestCases; i++) {
        cin >> testCase;
        cout << leafAndLimelightAttackArray[testCase] << endl;
    }
    return 0;
}
