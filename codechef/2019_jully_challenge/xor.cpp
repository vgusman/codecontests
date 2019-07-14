#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool even_ones (int x){
    int c = 0;
    while (x > 0){
        if (x % 2 == 0){x = x / 2;}
        else {x = (x-1) / 2; c++;}
    }
    return (c % 2 == 0);
}

int main () {
    int t, n, k, x;
    cin >> t;
    unordered_set<int> s,news;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        int np = 0;
        int ni = 0;
        s.clear();
        for(int j = 0; j < n; j++)
        {
            cin >> x;
            if (s.find(x) != s.end()) {cout << np << ' ' << ni << endl;}
            else {
                news.clear();
                for (auto it = s.begin(); it != s.end(); ++it) {
                    news.emplace(*it ^ x);
                }
                news.emplace(x);
                s.insert(news.begin(), news.end());
                if (even_ones(x)) {np = 2*np+1; ni = 2*ni;}
                else {np = np + ni; ni = np + 1;}
                cout << np << ' ' << ni << endl;
            }
        }
    }
    return 0;
}