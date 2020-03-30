# 피보나찌 수 구하기 (반복적 방법)
def fib2(n):  # n번째까지 피보나찌 수를 만드는 함수
    a = [0]
    if n > 0:
        a.append(1)
        for j in range(2, n+1):
            a.append(a[j-1] + a[j-2])
    return a


arr = fib2(10)
for i in range(10):
    print(arr[i])
