//
// Created by hugof on 27/02/2023.
// https://www.spoj.com/problems/LDCSUMAB/
//

#include <cstdio>
#include <math.h>

int t, k;

void solve() {
    int n = 0, m, kmax;

    // Determine n
    n = floor(sqrt(2*k) + 1.0/2.0);

    // Determine m
    kmax = n*(n+1) / 2;
    m = n - (kmax + 1 - k);

    // Show result
    printf("%d %d\n", m, n);
}

int main() {
    // Input
    scanf_s("%d",&t);

    for (int test = 0; test <t; test++) {
        scanf("%d", &k);
        solve();
    }

    return 0;
}