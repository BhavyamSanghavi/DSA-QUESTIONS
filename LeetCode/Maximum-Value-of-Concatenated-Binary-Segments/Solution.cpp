class Solution {
public:
    int binarytodecimal(const string& s) {
        const int MOD = 1e9 + 7;
        long long value = 0;
        for (char c : s) {
            value = (value * 2 + (c - '0')) % MOD;
        }
        return value;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        
        vector<string> seg(n);
        for (int i = 0; i < n; i++) {
            string s;
            s.append(nums1[i], '1');
            s.append(nums0[i], '0');
            seg[i] = s;
        }

        sort(seg.begin(), seg.end(), [](const string& a, const string& b) {
            return (a + b) > (b + a);
        });

        string final_str = "";
        for (int i = 0; i < n; i++) final_str += seg[i];

        return binarytodecimal(final_str);
    }
};