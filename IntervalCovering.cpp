//
// Created by hugof on 07/03/2023.
//

#include <cstdio>
#include <utility>

using namespace std;

int G, L;

int main () {
    while (true) {
        scanf_s("Number of gas stations: %d", &G);
        scanf_s("Length of road: %d", &L);

        ::pair<int, int> gs[G];
        while (--G) {
            scanf_s("-> %d %d", gs[0], gs[1]);
        }
    }

    return 0;
}