// https://www.eolymp.com/en/problems/10281
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, height, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &height);
        ans = max(ans, height);
    }
    printf("%d\n", ans);
    return 0;
}
