#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    int q;
    string s, t, p;
    cin >> q;
    for(int x = 0; x < q; x++) {
        cin >> s;  cin >> t; cin >> p;
        int a[30];
        for(int i = 0; i < 30; i++) {a[i] = 0;}
        int i=0, j = 0;
        while ((i< s.length()) && (j< t.length())) {
            if (s[i] == t[j]) {i++; j++;}
            else {a[t[j]-'a']++; j++;}
        }
        
        if (i< s.length()) {cout << "NO" << endl;}
        else {
            while (j< t.length()) {
                a[t[j]-'a']++;j++;
            }
            for(int i = 0; i < p.length(); i++) {
                a[p[i] - 'a']--;
            }
            bool pp = true;
            for(int i = 0; i < 30; i++) {
                if (a[i] > 0) {pp = false;}
            }
            if (pp) {cout << "YES" << endl;}
            else {cout << "NO" << endl;}
        }
    }
    return 0;
}