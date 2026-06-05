class Solution {
  public:
    int numOfWays(int n, int m) {
    long long N = n, M = m;

    long long total = N * M * (N * M - 1);

    long long attack = 4LL * (N - 1) * (M - 2)
                     + 4LL * (N - 2) * (M - 1);

    return (int)(total - attack);
}
};