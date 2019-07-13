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
        sort(a.begin(), a.end(), greater<int>());
        int b[z][n];
        
        for(int j = 0; j < n; j++){
            b[0][j] = a[j] * (j+1);
        }
        
        for(int k = 1; k < z; k++){
            for(int j = k; j < n; j++){
            int minn = b[k-1][j-1] + a[j];
            for(int l = k-1; l < j-1; l++){
                int tmp = b[k-1][l] + (j-l)*a[j];
                if (tmp < minn) {minn = tmp;}
            }
            b[k][j] = minn;
            }
        }
        int minn = b[z-1][z-1];
        for(int k = z; k < n; k++){
            if (minn > b[z-1][k]) {minn = b[z-1][k];}
        }
        cout << minn << endl;
    }
    return 0;
}