#include <bits/stdc++.h>

using namespace std;

int main () {
    string line, s;
    getline (cin, line);
    istringstream iss (line);
    while (iss >> s) {
        cout << s << endl;
    }
    return 0;
}