def printMatrix(d):
    m = len(d)
    n = len(d[0])

    for i in range(0, m):
        for j in range(0, n):
            print("%4d" % d[i][j], end="")
        print()


def printMatrixF(d):
    n = len(d[0])
    for i in range(0, n):
        for j in range(0, n):
            print("%5.2f" % d[i][j], end="")
        print()


def order(p, i, j):
    if i == j:
        print(" A%d " % j, end="")
    else:
        k = p[i][j]
        print("(", end="")
        order(p, i, k)
        order(p, k+1, j)
        print(")", end="")


d = [5, 2, 3, 4, 6, 7, 8]
n = len(d) - 1

m = [[0 for j in range(1, n+2)] for i in range(1, n+2)]
p = [[0 for j in range(1, n+2)] for i in range(1, n+2)]


def minmult(n, d, p, m):
    for i in range(1, n+1):
        m[i][i] = 0
    for diagonal in range(1, n):
        for i in range(1, n-diagonal+1):
            j = i + diagonal
            mini = m[i][i] + m[i+1][j] + d[i-1]*d[i]*d[j]
            mink = i
            for k in range(i+1, j):
                mincompare = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j]
                if mincompare < mini:
                    mini = mincompare
                    mink = k
            m[i][j] = mini
            p[i][j] = mink


print("(1) 11쪽----------------------------------\n")
minmult(n, d, p, m)
printMatrix(m)
print()
printMatrix(p)
order(p, 1, 6)


def print_inOrder(root):
    if not root:
        return
    print_inOrder(root.l_child)
    print(root.data)
    print_inOrder(root.r_child)


def print_preOrder(root):
    if not root:
        return
    print(root.data)
    print_preOrder(root.l_child)
    print_preOrder(root.r_child)


class Node:
    def __init__(self, data):
        self.l_child = None
        self.r_child = None
        self.data = data


def tree(key, r, i, j):
    k = r[i][j]
    if k == 0:
        return
    else:
        p = Node(key[k])
        p.l_child = tree(key, r, i, k-1)
        p.r_child = tree(key, r, k+1, j)
        return p


key = [" ", "A", "B", "C", "D"]
pp = [0, 0.375, 0.375, 0.125, 0.125]  # p 랑 혼동될까봐 pp 으로 함
nn = len(pp) - 1  # n 이랑 혼동될까봐 nn 으로 함

a = [[0 for j in range(0, nn+2)] for i in range(0, nn+2)]
r = [[0 for j in range(0, nn+2)] for i in range(0, nn+2)]


def optsearchtree(n, p, a, r):
    for i in range(1, n+1):
        a[i][i-1] = 0
        a[i][i] += p[i]
        r[i][i] = i
        r[i][i-1] = 0
    a[n+1][n] = 0
    r[n+1][n] = 0
    for diagonal in range(1, n):
        for i in range(1, n-diagonal+1):
            j = i + diagonal
            mini = a[i][i-1] + a[i+1][j]
            mink = i
            for k in range(i + 1, j):
                mincompare = a[i][k-1] + a[k+1][j]
                if mincompare < mini:
                    mini = mincompare
                    mink = k
            for m in range(i, j+1):
                mini += p[m]
            a[i][j] = mini
            r[i][j] = mink


print("\n\n(2) 23쪽----------------------------------\n")
optsearchtree(nn, pp, a, r)
printMatrixF(a)
print()
printMatrix(r)

root = tree(key, r, 1, nn)
print_inOrder(root)
print()
print_preOrder(root)
