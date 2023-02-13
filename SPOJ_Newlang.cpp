// https://www.spoj.com/problems/NEWLANG/
#include <cstdio>
#include <tuple>

using namespace std;

int t, n, k;

tuple<int, int> solve() {
    int min, max;

    // Minimum


    // Maximum

    return make_tuple(max, min);
}

int main() {
    printf("Number of Test: ");
    scanf_s("%d", t);

    tuple<int, int> res;

    for (int i = 0; i<t; i++) {
        printf("Test n°%d: \n", i);
        scanf_s("%d", n);
        printf(" ");
        scanf_s("%d", k);
        printf("\n");

        // Show results
        res = solve();
        printf("Maximum: %d\n", get<0>(res));
        printf("Minimum: %d\n", get<1>(res));
    }
}