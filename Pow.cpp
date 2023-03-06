//
// Created by hugof on 06/03/2023.
//

#include <cstdio>
#include <cmath>

using namespace std;

int a, b;

long IntPow (int a, int b, bool eff) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    long res = a;
    // -> Precise +++; fast ++
    if (eff)
        res = ::pow(a, b);
    // -> Precise ++++; fast -
    else
        while (--b) res *= a;

    return res;
}

long solve (int a, int b, bool eff = false) {
    long p, res = 0, r;

    // Get A^b
    p = IntPow(a, b, eff);

    // Keep only the 6 last digits
    for (int i = 0; p && i<6; i++) {
        r = p % 10;
        p /= 10;
        res = (r * IntPow(10, i, eff)) + res;
    }

    return res;
}

int main () {

    while (true) {
        scanf_s("%i", &a);
        scanf_s("%i", &b);
        printf("-> %ld", solve(a, b));
    }

    return 0;
}
