//
// Created by hugof on 06/03/2023.
//

#include <cstdio>
#include <cmath>

using namespace std;

long long int a, b;

// Binary exponentiation
long long int binEx (long long int a, long long int b) {

}

// Fast exponentiation
long long int fastEx (int a, int b) {

}

long long int solve (long long int a,long long int b, bool bin = false) {
    long long int p;

    // Get A^b
    p = bin ? binEx(a, b) : fastEx(a, b);

    // Keep only the 6 last digits
    p %= 1000000;

    return p;
}

int main () {

    while (true) {
        scanf_s("%llu", &a);
        scanf_s("%llu", &b);
        printf("-> %llu", solve(a, b));
    }

    return 0;
}
