/*
實際上如果這邊根本是平的，那我們只要讓二分艘找到最小的P讓他的切點不超過K，那就保證了這條線會貼在上面
ll mid = (l+r < 0 ? (l + r) / 2: (l + r + 1) / 2)
while(l < r){
    int m = (l + r) / 2;
    if(calc(m) <= K) r = m;
    else l = m + 1;
}
*/
#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;

bool operator<(const pair<int, int> &a, const pair<int, int> &b) {
    return a.F < b.F or (a.F == b.F and a.S > b.S);
}
#define chmax(a, b) a = (a) < (b) ? (b) : (a)
int n, k;
int a[1000005];
pair<int, int> dp[1000005];
vector<int> last(100005, 0);

pair<int, int> DP(int penalty) {
    last.assign(100005, 0);
    pair<int, int> ans = {0, 0};
    int l = 0;
    for (int i = 1; i <= n; i++) {
        while (l < last[a[i]]) {
            l++;
            chmax(ans, dp[l]);
        }
        dp[i] = {ans.F + i - l - penalty, ans.S + 1};
        last[a[i]] = i;
    }
    while (l < n) {
        l++;
        chmax(ans, dp[l]);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = -1, r = 2000000;
    while (l < r - 1) {
        int m = (l + r) / 2;
        pair<int, int> res = DP(m);
        if (res.S <= k) {
            r = m;
        } else
            l = m;
    }
    auto res = DP(r);
    cout << res.F + k * r << '\n';
}