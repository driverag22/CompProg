#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    string line;
    int pos = 0;

    vector<int> avCookies;
    while (getline(cin, line)) {
        if (line == "#") {
            pos = ceil( avCookies.size() / 2);
            cout << avCookies[pos] << endl;
            avCookies.erase(avCookies.begin() + pos);
        } else {
            avCookies.push_back(stoi(line));
            sort(avCookies.begin(), avCookies.end());
        }
    }

    return 0;
}
