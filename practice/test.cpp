#include <stdio.h>
#include <iostream>

using namespace std;

void scanSpaceAsInput() {
    char *str;
    scanf(" %[^\n]s",str); // \n just sets the delimiter for the scanned string.
    printf("%s", str);
}

int main() {
    return 0;
}