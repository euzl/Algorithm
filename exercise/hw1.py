import random

n = input("3이상의 정수 n을 입력해주세요 : ")
n = int(n)
while n < 3:
    n = input("[오류] 3이상의 정수를 입력해주세요 : ")
    n = int(n)

s = []
for d in range(n):
    s.append(random.randint(1, 10))

while 1:
    m = input('n보다 작은 양의 정수 m를 입력해주세요 : ')
    m = int(m)
    while m < 0 or m >= n:
        m = input('[오류] n보다 작은 양의 정수를 입력해주세요 : ')
        m = int(m)
    if m == 0:
        print('프로그램을 종료합니다.')
        break
    d = []
    for i in range(n - m + 1):
        h = 0
        for j in range(m):
            h += s[i+j]
        d.append(h)
    tmax = max(d)
    tmin = min(d)
    print("최대 tmax=", tmax, ", 최소 tmin=", tmin)
