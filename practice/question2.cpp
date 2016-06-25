/*
    Method 1 Check whether any one of the corner point lie in the square or not but it will take 8 conditions

    Method 2 Check for condition when two rectangles don't overlap
        It occurs under two conditions
        1) One rectangle is above top edge of other rectangle.
        2) One rectangle is on left side of left edge of other rectangle.

    ** Note - It is on assumption that line or point touching is not considered as overlapping.
              If it is than add '=' in method 1 or remove '=' in method 2
*/

#include <iostream>
#include <cmath>

using namespace std;

typedef struct point {
    int x, y;
} point;

bool method1(point tl1, point tl2, point br1, point br2) {
    if (tl1.x < br2.x && tl1.x > tl2.x && tl1.y > br2.y && tl1.y < tl2.y) {
        return true;
    } else if (br1.x < br2.x && br1.x > tl2.x && br1.y > br2.y && br1.y < tl2.y) {
        return true;
    } else if (tl1.x < br2.x && tl1.x > tl2.x && br1.y > br2.y && br1.y < tl2.y) {
        return true;
    } else if (br1.x < br2.x && br1.x > tl2.x && tl1.y > br2.y && tl1.y < tl2.y) {
        return true;
    } else if (tl2.x < br1.x && tl2.x > tl1.x && tl2.y > br1.y && tl2.y < tl1.y) {
        return true;
    } else if (br2.x < br1.x && br2.x > tl1.x && br2.y > br1.y && br2.y < tl1.y) {
        return true;
    } else if (tl2.x < br1.x && tl2.x > tl1.x && br2.y > br1.y && br2.y < tl1.y) {
        return true;
    } else if (br2.x < br1.x && br2.x > tl1.x && tl2.y > br1.y && tl2.y < tl1.y) {
        return true;
    }
    return false;
}

bool method2(point tl1, point tl2, point br1, point br2) {
    // One rectangle is above top edge of other rectangle.
    if (tl1.x >= br2.x || tl2.x >= br1.x) {
        return false;
    }
    // One rectangle is above top edge of other rectangle.
    if (tl1.y <= br2.y || tl2.y <= br1.y) {
        return false;
    }
    return true;
}

int main() {
    point tl1, br1, tl2, br2;
    int testCase, i;
    cin >> testCase;
    for (i = 0; i < testCase; ++i) {
        cin >> tl1.x >> tl1.y >> br1.x >> br1.y;
        cin >> tl2.x >> tl2.y >> br2.x >> br2.y;
        cout << method2(tl1, tl2, br1, br2) << endl;
    }
    return 0;
}