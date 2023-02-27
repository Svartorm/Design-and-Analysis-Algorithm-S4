//
// Created by hugof on 27/02/2023.
// https://www.spoj.com/problems/LDCSUMAB/
//

#include <cstdio>
#include <math.h>

float t, k;

void solve() {
    int n = 0, m, nmax, kmax;

    // Determine n
    //while (k>s)
    //    s += ++n;
    n = floor(sqrt(2*k) + 1.0/2.0);

    // Determine m
    nmax = n;
    kmax = k;
    while (nmax == n)
        nmax = floor(sqrt(2*(++kmax)) + 1.0/2.0);
    m = n - (kmax - k);

    // Show result
    printf("%d %d\n", m, n);
}

int main() {
    // Input
    scanf_s("%f",&t);

    for (int test = 0; test <t; test++) {
        scanf("%f", &k);
        solve();
    }

    return 0;
}