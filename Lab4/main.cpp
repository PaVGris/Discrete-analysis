#include <iostream>
#include <vector>

using namespace std;

vector<int> zFunction(string& s) {
    int n = s.length();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string strForFunc, pattern;
    cin >> strForFunc;
    cin >> pattern;
    string finalString = pattern + "#" + strForFunc;
    vector<int> zV = zFunction(finalString);
    int patternSize = pattern.length();
    for (int i = patternSize; i < zV.size(); i++) {
        if (zV[i] == patternSize) cout << i - 1 - patternSize << "\n";
    }
}
