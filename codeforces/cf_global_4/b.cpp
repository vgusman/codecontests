#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    string s;
    cin >> s;
    LL N = s.length();
    LL a[N];
    LL nn = 0;
    LL i = 0;
    while (i < N) {
        int k = 0;
        while ((i < N)&& (s[i] == 'v')) {
            k++; i++;
        }
        a[nn] = k > 0 ? k - 1 : 0;
        nn++;
        k = 0;
        while ((i < N)&& (s[i] == 'o')) {
            k++; i++;
        }
        a[nn] = k;
        nn++;
    }
    if (a[nn-1] == 0) {nn--;} else {a[nn] = 0; nn++;}
    LL b[N];
    LL c[N];
    b[nn - 1] = a[nn - 1];
    if (nn > 1) {c[nn - 2] = a[nn - 2] * a[nn - 1];}
    for(int i = nn-3; i > 0; i -=2) {
        b[i] = a[i] + b[i + 2];
        c[i-1] = a[i-1] * b[i] + c[i+1];
    }
    LL res = 0;
    for(int i = 0; i < nn-1; i+=2) {
        res +=a[i] * c[i+1];
    }
    cout << res;
    return 0;
}