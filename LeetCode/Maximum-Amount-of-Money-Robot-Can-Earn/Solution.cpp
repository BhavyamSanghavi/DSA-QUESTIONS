public long helper(int i, int j, int[][] coins, int ability, Long[][][] dp) {
    if (i < 0 || j < 0) {
        return Long.MIN_VALUE;
    }
    if (dp[i][j][ability] != null) {
        return dp[i][j][ability];
    }

    if (i == 0 && j == 0) {
        long val = coins[i][j];
        if (val < 0 && ability > 0) return 0;
        return val;
    }

    long up = Long.MIN_VALUE;
    long left = Long.MIN_VALUE;

    if (coins[i][j] >= 0) {
        up = coins[i][j] + helper(i - 1, j, coins, ability, dp);
        left = coins[i][j] + helper(i, j - 1, coins, ability, dp);
    } else {
        if (ability > 0) {
            up = helper(i - 1, j, coins, ability - 1, dp); // Don't add coins[i][j]
            left = helper(i, j - 1, coins, ability - 1, dp); // Don't add coins[i][j]
        } else {
            up = coins[i][j] + helper(i - 1, j, coins, ability, dp);
            left = coins[i][j] + helper(i, j - 1, coins, ability, dp);
        }
    }

    return dp[i][j][ability] = Math.max(up, left);
}