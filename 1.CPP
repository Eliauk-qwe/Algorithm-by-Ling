#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll X;
ll best;
vector<pair<ll, int>> factors;

void dfs(int idx, ll cur) {
    if (idx == factors.size()) {
        if (cur > X) {
            best = min(best, cur);
        }
        return;
    }

    auto [p, e] = factors[idx];

    ll val = 1;
    for (int i = 0; i <= 2 * e; i++) {
        dfs(idx + 1, cur * val);
        val *= p;
    }
}-

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> X;

        factors.clear();

        ll n = X;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                factors.push_back({i, cnt});
            }
        }

        if (n > 1) {
            factors.push_back({n, 1});
        }

        best = X * X;

        dfs(0, 1);

        cout << best - X << '\n';
    }

    return 0;
}