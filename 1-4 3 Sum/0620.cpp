#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

unordered_map<int, int> m;

int main() {
    int n;
    ll target;
    cin >> n >> target;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        m[a[i]] = i;
    }

    sort(a.begin(), a.end());

    for (int i = 1; i <= n-2; ++i) {
        int cur = a[i];
        int L = i + 1, R = n;

        while (L < R) {
            ll two_sum = a[L] + a[R];
            if (two_sum < target - cur) {
                L++;
            } else if (two_sum > target - cur) {
                R--;
            } else {
                cout << m[a[i]] << " " << m[a[L]] << " " << m[a[R]] << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
