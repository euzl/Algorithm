# 피보나찌 수 구하기 (재귀적 방법)
def fib1(n):
    if n <= 1:
        return n
    else:
        return fib1(n-1) + fib1(n-2)


for i in range(1, 10):
    print(fib1(i))
