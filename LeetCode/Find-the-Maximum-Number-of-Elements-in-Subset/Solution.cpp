x = num
len = 0

while freq[x] >= 2:
    len += 2
    x = x * x

if freq[x] >= 1:
    len += 1
else:
    len -= 1

ans = max(ans, len)