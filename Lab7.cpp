// The original has time complexity of O(n^2), my new function has O(n).
// I have essentially a scalar multiple of loops with O(n) complexity, then
// by dropping the constant, as n is the most significant term, then
// it is at most O(n) time complexity.

// Justification:
// By starting from the middle, I effectively halve the number of times I need to find
// the new sum of the left and right.

#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// int findSplit(int a[], int aSize) {
//     int x, y;
//     for (int i = 0; i < aSize; i++) {
//         x = 0;
//         y = 0;
//         for (int j = 0; j <= i; j++)
//             x += a[j];
//         for (int k = i + 1; k < aSize; k++)
//             y += a[k];
//         if (x == y)
//             return i;
//     }
//     return -1;
// }

int findSplitHelper(vector<int> numbers, int numSize, int temp) {
    int sumLeft = accumulate(numbers.begin(), numbers.begin() + temp, 0);
    int sumRight = accumulate(numbers.begin() + temp, numbers.end(), 0);

    if (sumLeft == sumRight) {
        return temp;
    } else if (sumLeft < sumRight) {
        for (int i = temp; i < numSize; i++) {
            sumLeft += numbers[i];
            sumRight -= numbers[i];

            if (sumLeft == sumRight) {
                return i + 1;
            }
        }

    } else if (sumLeft > sumRight) {
        for (int i = temp; i >= 0; i--) {
            sumLeft -= numbers[i];
            sumRight += numbers[i];

            if (sumLeft == sumRight) {
                return i + 1;
            }
        }
    }

    return -1;
}

int findSplit(int a[], int aSize) {
    // Convert a into a vector
    vector<int> numbers(a, a + aSize);
    int temp = aSize / 2;
    int split = findSplitHelper(numbers, aSize, temp) - 1;

    return split;
}

int main() {
    int numbers[] = {12, 2, 5, 3, 8, 2, 6};
    int index = findSplit(numbers, 7);

    if (index == -1)
        printf("not possible");
    else
        printf("Split at index %2i", index);

    return 0;
}
