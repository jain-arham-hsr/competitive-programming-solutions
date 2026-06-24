#include <bits/stdc++.h>
using namespace std;

map<int, string> numToEnglish = {
    {1, "one"},        {2, "two"},       {3, "three"},     {4, "four"},
    {5, "five"},       {6, "six"},       {7, "seven"},     {8, "eight"},
    {9, "nine"},       {10, "ten"},      {11, "eleven"},   {12, "twelve"},
    {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},  {16, "sixteen"},
    {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},
    {30, "thirty"},    {40, "forty"},    {50, "fifty"},    {60, "sixty"},
    {70, "seventy"},   {80, "eighty"},   {90, "ninety"},   {100, "hundred"}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string res = "";

    if (n == 0) {
        cout << "zero";
        return 0;
    }
    if (n == 100) {
        cout << "hundred";
        return 0;
    }

    if (n == 1000) {
        cout << "thousand";
        return 0;
    }

    if (n % 100 <= 20)
        res = numToEnglish[n % 100];
    else {
        res = numToEnglish[((n % 100) - (n % 10))] + " " + numToEnglish[n % 10];
    }

    if (n / 100 > 0) {
        if (res == "")
            res = numToEnglish[n / 100] + " hundred";
        else
            res = numToEnglish[n / 100] + " hundred" + " " + res;
    }

    cout << res;

    return 0;
}
