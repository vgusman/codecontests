#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    int t;
    LL n, k;
    cin >> t;
    for(int x = 0; x < t; x++) {
        cin >> n >> k;
        if (k % 3 == 0) {
            int r = (n % (k+1));
            if (r == k) {cout << "Alice" << endl;}
            else if (r % 3 == 0) {cout << "Bob" << endl;}
            else {cout << "Alice" << endl;}
        }
        else {
            if (n % 3 == 0) {cout << "Bob" << endl;}
            else {cout << "Alice" << endl;}
        }
    }
    return 0;
}