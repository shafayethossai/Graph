#include <bits/stdc++.h>
using namespace std;

string BigIntSubtract(string x, string y) {
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int len1 = x.size();
    int len2 = y.size();

    if (len1 < len2) {
        int gap = len2 - len1;
        while (gap--) {
            x.push_back('0');
        }
    }
    else{
        int gap = len1 - len2;
        while (gap--) {
            y.push_back('0');
        }
    }

    int n = x.size();
    string result = "";
    int borrow = 0;

    for (int i = 0; i < n; i++) {
        int p = x[i] - '0' - borrow;
        int q = y[i] - '0';

        if (p < q) {
            p += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        int diff = p - q;
        char digit = diff + '0';
        result.push_back(digit);
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string x, y;

    cin >> x >> y;

    cout << "Difference: " << BigIntSubtract(x, y) << endl;

    return 0;
}
