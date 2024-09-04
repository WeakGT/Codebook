int solve(int n, vector<int> &a, vector<int> &m){
    int M = 1;
    for(auto i : m) M *= i;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int m1 = M / m[i], m2 = extgcd(m1, m[i]).X;
        ans += (a[i] * m1 * m2) % M;
    }
    ans = ans % M + M;
    ans %= M;
    return ans;
}