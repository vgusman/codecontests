#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool is_prime (int n) {
    for (int i = 2; i < sqrt(n)+1; i++){
        if (n % i == 0) {return false;}
    }   
    return true;
}

int main () {
    int n;
    cin >> n;
    int c = 0;
    while (!(is_prime(n+c))){c++;}
    cout << (n+c)<< endl;
    for(int i = 0; i < n - 1; i++) {
        cout << i+1 << ' ' << i+2 << endl;
    }
    cout << n << ' ' << 1 << endl;
    int x = n % 2 == 0 ? n / 2 : (n-1) / 2;
    for(int i = 0; i < c; i++) {
        cout << i+1 << ' ' << i + x + 1 << endl;
    }
    return 0;
}