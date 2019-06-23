# 11720 : 숫자의 합
# C로 안풀려서 일단 파이썬으로 풀어보았다.
size = input()
number = input()

sum = 0
idx = 0

while idx < len(number):
    sum += int(number[idx])
    idx += 1

print(sum)
