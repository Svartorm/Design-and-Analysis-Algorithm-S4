// https://www.eolymp.com/en/problems/10296
#include <map>
#include <cstdio>

using namespace std;

typedef long long ll;
map<ll, ll> mp;

ll n;

ll solve_rec(ll n) {
    if (n == 0) return 1;
    return solve_rec(n / 2) + solve_rec(n / 3);
}

ll solve_dynam(ll n) {
    if (mp.count(n)) return mp[n];
    ll newval = solve_dynam(n / 2) + solve_dynam(n / 3);
    mp[n] = newval;
    return newval;
}

int main() {
    mp[0] = 1;
    scanf("%lld", &n);
    printf("%lld", solve_dynam(n));
    return 0;
}

