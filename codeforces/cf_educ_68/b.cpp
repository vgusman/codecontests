#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    int q, n, m;
    string s;
    cin >> q;
    for(int x = 0; x < q; x++) {
        cin >> n >> m;
        int r[n];
        int c[m];
        bool a[n][m];
        for(int j = 0; j < m; j++) {
            c[j] = 0;
        }
        for(int j = 0; j < n; j++) {
            r[j] = 0;
        }
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(int j = 0; j < m; j++) {
                if (s[j]=='*') {r[i]++; c[j]++; a[i][j] = true;}
                else {a[i][j] = false;}
            }
        }
        int minr = m;
        int minc = n;
        for(int j = 0; j < m; j++) {
            if (n - c[j] < minc) {minc= n - c[j];}
        }
        for(int j = 0; j < n; j++) {
            if (m - r[j] < minr) {minr= m - r[j];}
        }
        vector<int> cs;
        vector<int> rs;
        for(int j = 0; j < m; j++) {
            if (n - c[j] == minc) {cs.push_back(j);}
        }
        for(int j = 0; j < n; j++) {
            if (m - r[j] == minr) {rs.push_back(j);}
        }
        bool pp = false;
        for (auto itc = cs.begin(); itc != cs.end(); ++itc){
            for (auto itr = rs.begin(); itr != rs.end(); ++itr){
                if (!a[*itr][*itc]) {pp = true;}
            }
        }

        if (pp) {cout << minc + minr - 1 << endl;}
        else {cout << minc + minr << endl;}
    }
    return 0;
}