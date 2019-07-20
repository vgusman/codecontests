#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[n];
    bool p[n];
    LL res = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i;
        p[i] = false;
    }
    for(int i = n-1; i >= 0; i--) {
        LL l = 0;
        LL r = 0;
        while ((b[i]-l>0) && p[b[i]-l-1]){l++;}
        while ((b[i]+r<n-1) && p[b[i]+r+1]){r++;}    
        p[b[i]] = true;
        LL c = ((l+1) * (r+1)) % 998244353;
        res = (res * c) % 998244353; 
    }
    cout << res;
    return 0;
}