#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<long long> L(n), R(n);
        long long cur = a[0];
        L[0] = cur;
        for (int i = 1; i < n; ++i) {
            cur = max(a[i], cur + a[i]);
            L[i] = cur;
        }

        cur = a[n - 1];
        R[n - 1] = cur;
        for (int i = n - 2; i >= 0; --i) {
            cur = max(a[i], cur + a[i]);
            R[i] = cur;
        }

        long long M = L[0];
        for (int i = 1; i < n; ++i) M = max(M, L[i]);

        if (k % 2 == 0) {
            cout << M << '\n';
            continue;
        }
        long long  result = M;

        for (int i = 0; i < n; ++i) {
            long long G = L[i] + R[i] - a[i];

            result = max(result, G + b[i]);
            result = max(result, G - b[i]);
        }

        cout << result << '\n';
    }

    return 0;
}
