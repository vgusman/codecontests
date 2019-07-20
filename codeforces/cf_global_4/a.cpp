#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    int N, x;
    cin >> N;
    vector<int> a;
    int alice;
    cin >> alice;
    int coal = alice;
    int sum = alice;
    for(int i = 1; i < N; i++) {
        cin >> x;
        sum +=x;
        if (2 * x <= alice){
            a.push_back(i+1);
            coal += x;
        }
    }
    if (coal * 2 > sum){
        cout << a.size() + 1 << endl;
        for(auto it = a.begin(); it != a.end(); ++it) {
            cout << *it << ' ';
        }
        cout << '1';
    } else {
        cout << 0 << endl;
    } 
    
    return 0;
}