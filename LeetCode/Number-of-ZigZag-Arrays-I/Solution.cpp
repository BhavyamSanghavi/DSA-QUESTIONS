int zigZagArrays(int n, int l, int r) {

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(r + 1, vector<long long>(2, 0)));

    for (int i = l; i <= r; i++) {
        dp[1][i][0] = 1;
        dp[1][i][1] = 1;
    }

    for (int len = 2; len <= n; len++) {
        vector<long long> pre0(r + 2, 0), pre1(r + 2, 0);
        for (int i = l; i <= r; i++) {
            pre0[i] = (pre0[i - 1] + dp[len - 1][i][0]) % mod;
            pre1[i] = (pre1[i - 1] + dp[len - 1][i][1]) % mod;
        }

        for (int el = l; el <= r; el++) {
            long long sum = (pre1[r] - pre1[el] + mod) % mod;
            dp[len][el][0] = sum;

            sum = (pre0[el - 1] + mod) % mod;
            dp[len][el][1] = sum;
        }
    }

    long long ans = 0;
    for (int i = l; i <= r; i++) {
        ans = (ans + dp[n][i][0] + dp[n][i][1]) % mod;
    }

    return ans;
}