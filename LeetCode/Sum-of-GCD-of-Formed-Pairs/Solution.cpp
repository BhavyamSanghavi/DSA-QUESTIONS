int gcd(int a, int b) {
        if(b == 0 || a == b) return a;
        LL t = ((LL)a << 30) | b;
        if(memo.count(t)) return memo[t];
        return memo[t] = gcd(b, a % b);
    }