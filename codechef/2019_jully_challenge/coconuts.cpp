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
        ll cur = res;
        for(int j = 1; j <= z; j++){
            cur -= a[n-1-z+j];
            int prev = j == 1 ? 0 : a[j-2];
            cur += (a[j-1] - prev) * (n-z+1); // TODO (will not work if there are the sames)
            if (cur < res) {res = cur;}
        }
        cout << res << endl;
    }
    return 0;
}