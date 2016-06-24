/*
    What you can do is calculate the distances between each of the four points.
    If you find the following to be true, you have a square:

    There are two points, say A and C which are distance x from each other, and two other points,
    say B and D which are also distance x from each other.

    Each point {A, B, C, D} is an equal distance from the two points which aren't x away. i.e.:
    If A is x away from C, then it will be z away from both B and D.

    Incidentally, the distance z will have to be SQRT((x^2)/2), but you don't
    need to confirm this. If conditions 1 and 2 are true then you have a square.
    NOTE: Some people are concerned about the inefficiency of square root. I didn't say
    that you should do this calculation, I just said that if you did you would get a predictable result!

    The bare minimum of work that you would need to do would be to pick a point,
    say A and calculate the distance to each of the other three points. If you can find that A is x from
    one point and z from two other points, then you just need to check those two other points against each other.
    If they are also x from each other then you have a square. i.e.:

    AB = z
    AC = x
    AD = z
    Since AB = AD, check BD:

    BD = x
    Just to be sure, you need to check the other sides: BC and CD.

    BC = z
    CD = z
    Since AC = BD and AC = BC = CD, therefore this a square.

    Along the way, if you find more than two distinct edge distances then the figure
    cannot be a square, so you can stop looking.


    **Note - Use squres instead of square root to get correct result
 */

#include <iostream>
#include <cmath>

using namespace std;

double squareDistanceBetweenPoints(double a[4][4], int index1, int index2) {
    double sum = pow((a[index1][0] - a[index2][0]), 2.0) + pow((a[index1][1] - a[index2][1]), 2.0);
    return sum;
}

int main() {
    double testCase, a[4][4], d1, d2, d3;
    int i, j;
    cin >> testCase;

    for (j = 0; j < testCase; j++) {
        for (i = 0; i < 4; i++) {
            cin >> a[i][0];
            cin >> a[i][1];
        }

        d1 = squareDistanceBetweenPoints(a, 0, 1);
        d2 = squareDistanceBetweenPoints(a, 0, 2);
        d3 = squareDistanceBetweenPoints(a, 0, 3);

        if (d1 == d2 && d3 == (d1 * 2.0)) {
            cout << 1;
        } else if (d1 == d3 && d2 == (d1 * 2.0)) {
            cout << 1;
        } else if (d3 == d2 && d1 == (d2 * 2.0)) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}