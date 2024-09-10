#include <bits/stdc++.h>
///demo problem:
using namespace std;

int main() {
    long long n, t, sum = 0;
    cin >> n >> t;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int s = 0, e = 0;
    int maxLength = 0;

    while (e < n) {
        sum += a[e];

        while (sum > t && s <= e) {
            sum -= a[s];
            s++;
        }

        maxLength = max(maxLength, e - s + 1);
        e++;
    }

    cout << maxLength << endl;

    return 0;
}
