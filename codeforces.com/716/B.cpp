#include <bits/stdc++.h>
using namespace std;

string createNiceWord(unordered_map<char, int> &alphaCount, string wordMask,
                      int start, int end) {
    char upperAlphaBegin = 65;
    vector<char> alphas;
    alphas.reserve(26);
    for (int i = 0; i < 26; i++) {
        if (alphaCount[upperAlphaBegin + i] == 0) {
            alphas.push_back(upperAlphaBegin + i);
        }
    }
    int curr = 0;
    for (int i = 0; i < wordMask.size(); i++) {
        if (wordMask[i] == '?') {
            if (i < start || i > end) {
                wordMask[i] = 'A';
            } else {
                wordMask[i] = alphas[curr++];
            }
        }
    }
    return wordMask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int totalCount = 0;
    unordered_map<char, int> alphaCount;

    if (s.size() < 26) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        alphaCount[s[i]]++;
        if ((s[i] >= 65 && s[i] <= 90 && alphaCount[s[i]] == 1) || s[i] == '?')
            totalCount++;
    }

    if (totalCount == 26) {
        cout << createNiceWord(alphaCount, s, 0, 25);
        return 0;
    }

    for (int i = 26; i < s.size(); i++) {
        alphaCount[s[i - 26]]--;
        if ((s[i - 26] >= 65 && s[i - 26] <= 90 &&
             alphaCount[s[i - 26]] == 0) ||
            s[i - 26] == '?') {
            totalCount--;
        }
        alphaCount[s[i]]++;
        if ((s[i] >= 65 && s[i] <= 90 && alphaCount[s[i]] == 1) || s[i] == '?')
            totalCount++;
        if (totalCount == 26) {
            cout << createNiceWord(alphaCount, s, i - 26 + 1, i);
            return 0;
        }
    }
    cout << -1;

    return 0;
}
