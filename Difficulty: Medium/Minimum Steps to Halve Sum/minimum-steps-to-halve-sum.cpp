class Solution {
  public:
    int minOperations(vector<int>& arr) {
    priority_queue<double> q;
    double sum = 0;
    for (int i : arr) {
        q.push((double)i);
        sum += i;
    }

    int ans = 0;
    double target = sum / 2.0;
    while (sum > target) {
        ans++;
        double top = q.top(); q.pop();
        double half = top / 2.0;
        sum -= half;
        q.push(half);
    }

    return ans;
}

};