#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main () {
    int t;
    string s;
    ll tmp, r1, r2, x = 31622;
    ll x2 = x * x;
    cin >> t;
    set <ll> v;
    map <ll, ll> m;
    for (int i = 0; i<t; i++){
        v.clear();
        m.clear();
        cout << 1 << ' '<< x << endl;
        cout.flush();
        cin >> r1;
        if (r1 == -1) {return 0;}
        tmp= x2-r1;
        if (tmp > 0) {
            ll p = 2;
            ll pr = 1;
            while (p <= sqrt(tmp)) {
                if (tmp % p == 0) {
                    v.emplace(p);
                    pr *= p;
                    while (tmp % p == 0) {
                        tmp /= p;
                    }
                }
                p++;
            }
            if (tmp > 1) {
                v.emplace(tmp);
                pr *= tmp;
            }
            ll y = 0;
            for(auto t=v.begin(); t!=v.end(); ++t){
                tmp = pr / *t;
                ll rem = (tmp * tmp) % *t;
                ll scale = 1, rr = rem;
                while (m.find(rr) != m.end()) {
                    scale++;
                    rr = (rem * scale * scale) % *t; 
                }
                m[rr] = *t;
                y += (pr * scale / *t) % pr;
            }
            y = y % pr;
            if (y == 0) {y += pr;}
            cout << 1 << ' '<< y << endl;
            cout.flush();
            cin >> r2;
            if (r2 == -1) {return 0;}
            ll res = m[r2];
            cout << 2 << ' '<< res << endl;
            cout.flush();
            cin >> s;
            if (s == "No") {return 0;}
        } else {
            cout << 1 << ' '<< 31623 << endl;
            cout.flush();
            cin >> r2;
            cout << 2 << ' ' << (1000014129 - r2) << endl;
            cout.flush();
            cin >> s;
            if (s == "No") {return 0;}
        }
    }
    return 0;
}