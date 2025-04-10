        (n[i] < limit ? dfs(i + 1, limit, n, s) : 0);
}
long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
    string hi = to_string(finish), lo = to_string(start - 1);
    for (int i = s.size(); i < hi.size(); ++i)
        cnt[i] = i == s.size() ? 1 : cnt[i - 1] * (limit + 1);
    return cnt[hi.size() - 1] + dfs(0, '1' + limit, hi, s) 
        - (cnt[lo.size() - 1] + dfs(0, '1' + limit, lo, s));
}
