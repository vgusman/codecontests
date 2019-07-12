#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    int t, n, z, x;
    cin >> t;
    vector<int> a;

    for(int i = 0; i < t; i++)
    {
        cin >> n >> z;
        a.clear();
        for(int j = 0; j < n; j++)
        {   
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        ll res = 0;
        for(int j = n-1; j > n-1-z; j--){
            res += a[j];
        }
        int id = 0;
        int b[z];
        int prev = 0;
        while (id < z) {
            int x = a[id];
            int c = 0;
            while ((id < n) && (a[id]==x)){c++;id++;}
            //int rr1 = (a[n-z+id-c] == x ? 0 : (n - z + 1 - c));
            b[id-c]= x + (n-z - c + 1)*(x-prev) - a[n-z+id-c];
            for (int l = id - c + 1; l< id; l++){
                int rr2 = a[n-z+l] == x ? 0 : x-prev;    
                b[l] = x + rr2 - a[n-z+l];
            }
            prev = x;
        }
        ll cur = res;
        for(int j = 0; j < z; j++){
            cur += b[j];
            if (cur < res) {res = cur;}
        }
        cout << res << endl;
    }
    return 0;
}