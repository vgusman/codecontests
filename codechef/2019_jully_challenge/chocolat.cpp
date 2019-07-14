#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    int t, n, r, res;
    string s;
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s;
        r = 0;
        for (int l = 0; l< s.length(); l++){
            r = (r*10 + s[l] - '0') % n;
        }
        res = 2 * (min (r, n - r)) - ((r == n - r) ? 1 : 0);
        cout << res << endl;
    }
    return 0;
}