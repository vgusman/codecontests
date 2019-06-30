#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n;
    string line;
    cin >> line;
    istringstream iss (line);
    char c;
    map<char, map <int, int>> mp;
    map<char, int> nbs;
    map<char, map <int, int>>::iterator it;
    map<char, int>::iterator itt;
    
    int i = 1;
    while (iss>>c) {
        it = mp.find(c);
        if (it != mp.end())
            {
                nbs[c] = nbs[c]+1;
                mp[c][nbs[c]] = i;
            }
        else
            {
                map<int,int> tmp;
                tmp[1] = i;
                mp[c] = tmp;               
                nbs[c] = 1;
            }
        i++;            
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        map<char, int> tmp;
        cin >> line;
        istringstream iss (line);
        int res = 0;
        while (iss>>c) {
            itt = tmp.find(c);
            if (itt != tmp.end())       
                {tmp[c] = tmp[c] + 1;}
            else
                {
                    tmp[c] = 1;
                }
            for (itt = tmp.begin(); itt != tmp.end(); itt++){
                res = max (res, mp[itt->first][itt->second]);
            }
        }
        cout << res << endl;
    }
    return 0;
}