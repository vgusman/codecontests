#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ff (int idx, int n, int NdeadBefore) {
    if (idx < n-1) {return idx;}
    else {//TODO
        return ((idx - n + 1) / 2);
    }
}

int main () {
    int t, n, f, Nviv, Ninit, Ndead_beforeJ;
    ll dmin, d, pmin;
    int a[100000];
    cin >> t;
    vector<int> v;
    for (int i = 0; i<t; i++){
        v.clear();
        cin >> n;
        for (int j = 0; j<n-1; j++){
            cin >> a[j];
        }
        cin >> f;
        for (int j = 0; j<n-1; j++){
            if (a[j] <= f) {v.push_back(j);}
        }
        if (v.empty()) {
            cout << "impossible" << endl;
        }
        else {
            cout << "possible" << endl;
            dmin = 11000000000;
            pmin = -1;
            for(auto it = v.begin(); it != v.end(); ++it){
                d = 0;
                // Before Josh
                if (*it % 2 != 0) {d = a[*it - 1]; Ndead_beforeJ = (*it - 1) / 2;}
                else {Ndead_beforeJ = *it / 2;}
                Nviv = n - Ndead_beforeJ;
                Ninit = Nviv;
                // Log N loop
                int k = 2;
                while (Nviv > 2) {
                    if (Nviv % 2 == 0) {
                        int idx = ff (k/2*(Nviv - 2) + *it, n, Ndead_beforeJ);
                        d += a[idx];}
                    k *= 2;
                    if (Nviv % 2 == 0) {Nviv = Nviv / 2 + 1;}
                    else {Nviv = (Nviv + 1) / 2;}
                }
                if (d < dmin) {dmin = d; pmin = *it + 1;}
            }
            cout << pmin << ' ' << dmin + f << endl;
        }
    }
    return 0;
}