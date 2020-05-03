import numpy as np


def bin(n, k):
    if k == 0 or n == k:
        return 1
    else:
        return bin(n-1, k-1) + bin(n-1, k)


def bin2(n, k):
    B = [[0 for i in range(k+1)] for j in range(n+1)]
    for i in range(0, n+1):
        for j in range(0, min(i, k)+1):
            if j == 0 or j == i:
                B[i][j] = 1
            else:
                B[i][j] = B[i-1][j-1] + B[i-1][j]
    return B[n][k]


print("(1) bin, bin2 알고리즘")
print(bin(10, 5), bin2(10, 5))


def allShortestPath(g, n):
    p = [[0 for i in range(n)] for j in range(n)]
    d = np.array(g)
    for k in range(1, n+1):
        for i in range(n):
            for j in range(n):
                if d[i][k-1] + d[k-1][j] < d[i][j]:
                    p[i][j] = k
                    d[i][j] = d[i][k-1] + d[k-1][j]
    return d, p


def _path(p, q, r):
    if p[q][r] != 0:
        _path(p, q, p[q][r]-1)
        print(" v%d" % p[q][r], end=" ")
        _path(p, p[q][r]-1, r)


# 경로 출력 함수
def path(p, q, r):
    print("v%d" % q, end=" ")  # 시작노드 출력
    _path(p, q-1, r-1)
    print("v%d" % r, end=" ")  # 끝 노드 출력


def printMatrix(d):
    m = len(d)
    n = len(d[0])

    for i in range(0, m):
        for j in range(0, n):
            print("%4d" % d[i][j], end=" ")
        print()


inf = 1000
g = [[0, 1, inf, 1, 5],
     [9, 0, 3, 2, inf],
     [inf, inf, 0, 4, inf],
     [inf, inf, 2, 0, 3],
     [3, inf, inf, inf, 0]]
d, p = allShortestPath(g, 5)
print("\n(2) wrapper방식")
print()
printMatrix(g)
print()
printMatrix(d)
print()
printMatrix(p)

path(p, 5, 3)
