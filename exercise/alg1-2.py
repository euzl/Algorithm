# 배열의 수 더하기
def sum1(s):
    result = 0
    for a in s:
        result += a
    return result


def sum2(s):
    result = 0
    for a in range(len(s)):
        result += s[a]
    return result


s = [3, 5, 2, 1, 7, 9]
answer1 = sum1(s)
answer2 = sum2(s)
print(answer1, answer2)
