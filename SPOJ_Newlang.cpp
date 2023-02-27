// https://www.spoj.com/problems/NEWLANG/
#include <cstdio>
#include <math.h>
#include <tuple>

using namespace std;

int t, n, k;

tuple<int, int> solve() {
    int min=1, max=9;

    int zeros = k == 1 ? 0 : n - (k-1);

    // Minimum
    for (int z = 0; z<zeros; z++)
        min *= 10;
    for (int d = 2; d<n-zeros+1; d++)
        min = min * 10 + (k == 1 ? 1 : d);

    // Maximum
    for (int z = 0; z<zeros; z++)
        max *= 10 + 9;
    for (int d = 8; d<2; d++)
        continue;

    return make_tuple(max, min);
}

int main() {
    printf("Number of Test: ");
    scanf_s("%d", &t);

    tuple<int, int> res;

    for (int i = 0; i<t; i++) {
        printf("Test n°%d: \n", i);
        scanf_s("%d", &n);
        printf(" ");
        scanf_s("%d", &k);
        printf("\n");

        // Show results
        res = solve();
        printf("Maximum: %d\n", get<0>(res));
        printf("Minimum: %d\n", get<1>(res));
    }
}