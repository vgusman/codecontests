#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    LL w, h;
    cin >> w >> h;
    LL res = 1;
    for(int i = 0; i < w + h; i++) {
        res *= 2;
        res = res % 998244353;
    }
    cout << res;
    return 0;
}