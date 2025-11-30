#if __has_include(<bits/stdc++.h>)
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;
        int len = 2 * n;

        vector<int> cnt(2 * n + 1, 0);
        for (int i = 0; i < len; ++i) {
            int x;
            cin >> x;
            if (x >= 0 && x <= 2 * n)
                cnt[x]++;
        }

        int odd_cnt = 0, even_cnt = 0;
        for (int c : cnt) {
            if (c == 0) continue;
            if (c & 1) odd_cnt++;
            else       even_cnt++;
        }

        int ans = 0;

        if (odd_cnt == 0) {
            int t = min(even_cnt, n);
            if ((t & 1) != (n & 1)) t--; 
            if (t < 0) t = 0;
            ans = 2 * t;
        } else {
    
            int capacity = n - odd_cnt / 2;    
            int t = min(even_cnt, capacity);
            ans = odd_cnt + 2 * t;
        }

        cout << ans << '\n';
    }

    return 0;
}