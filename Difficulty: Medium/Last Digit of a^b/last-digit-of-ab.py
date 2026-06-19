class Solution:
    def getLastDigit(self, a, b):
        if b == "0":
            return 1
        last_digit_a = ord(a[-1]) - ord("0")
        if last_digit_a in [0, 1, 5, 6]:
            return last_digit_a
        exp = int(b[-2:]) % 4
        if exp == 0:
            exp = 4
        return last_digit_a**exp % 10