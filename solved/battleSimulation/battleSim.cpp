#include "iostream"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string input;
    string res = "";
    ll i;
    unordered_map<char, bool> used;
    unordered_map<char, char> counter;

    cin >> input;
    input += "  ";

    used['R'] = false;
    used['B'] = false;
    used['L'] = false;
    counter['R'] = 'S';
    counter['B'] = 'K';
    counter['L'] = 'H';
    counter[' '] = 'Q';

    for (i = 0; i < input.length() - 2; i++) {
        used[input[i]] = true;
        used[input[i+1]] = true;
        used[input[i+2]] = true;
        if (used['R'] && used['B'] && used['L']) {
            res += 'C';
            i += 2;
        } else {
            res += counter[input[i]];
        }
        used['R'] = false;
        used['B'] = false;
        used['L'] = false;
    }
    cout << res << "\n";
    return 0;
}
