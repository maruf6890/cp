#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 2, 3, 4, 5, 8, 15, 16, 16, 16, 18, 22};
    int k = 16;

    // Find the lower bound (first position where element >= k)
    auto it = lower_bound(a.begin(), a.end(), k);
    int lower_bound_pos = it - a.begin();
    cout << "Lower Bound Position: " << lower_bound_pos << endl;

    // Find the number of elements less than k (using lower_bound)
    int lessThan = lower_bound_pos;
    cout << "Number of elements less than " << k << ": " << lessThan << endl;

    // Find the number of elements greater than or equal to k (using lower_bound)
    int greaterThanAndEqual = a.size() - lessThan;
    cout << "Number of elements greater than or equal to " << k << ": " << greaterThanAndEqual << endl;

    // Check if the exact element k is found at the lower bound position
    if (lower_bound_pos < a.size() && a[lower_bound_pos] == k) {
        cout << "Element " << k << " found at position: " << lower_bound_pos << endl;
    } else {
        cout << "Element " << k << " not found" << endl;
    }

    // Find the upper bound (first position where element > k)
    auto it2 = upper_bound(a.begin(), a.end(), k);
    int upper_bound_pos = it2 - a.begin();
    cout << "Upper Bound Position: " << upper_bound_pos << endl;

    // Number of elements greater than k (using upper_bound)
    cout << "Number of elements greater than " << k << ": " << a.size() - upper_bound_pos << endl;

    // Number of elements less than or equal to k (using upper_bound)
    cout << "Number of elements less than or equal to " << k << ": " << upper_bound_pos << endl;

    return 0;
}
