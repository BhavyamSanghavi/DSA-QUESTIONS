class Solution {
  void generateNumbers(int current_num, int last_digit, int remaining_digits, std::vector<int>& result) {
        if (remaining_digits == 0) {
            result.push_back(current_num);
            return;
        }

        for (int next_digit = last_digit + 1; next_digit <= 9; ++next_digit) {
            generateNumbers(current_num * 10 + next_digit, next_digit, remaining_digits - 1, result);
        }
    }

public:
    std::vector<int> increasingNumbers(int n) {
        std::vector<int> result;

        if (n == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }

        for (int i = 1; i <= 9; ++i) {
            generateNumbers(i, i, n - 1, result);
        }

        return result;
    }
};