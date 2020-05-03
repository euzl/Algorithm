import utility


def opt(i, j, a, b, table, minindex):
    c1 = -1
    c2 = -1
    c3 = -1
    if i < 0:
        return
    if a[i] == b[j]:
        c1 = table[i + 1][j + 1]
    else:
        c1 = table[i + 1][j + 1] + 1
    c2 = table[i + 1][j] + 2
    c3 = table[i][j + 1] + 2
    if c1 < c2:
        if c1 < c3:
            table[i][j] = c1
            minindex[i][j] = (i + 1, j + 1)
        else:
            table[i][j] = c3
            minindex[i][j] = (i, j + 1)
    else:
        if c2 < c3:
            table[i][j] = c2
            minindex[i][j] = (i + 1, j)
        else:
            table[i][j] = c3
            minindex[i][j] = (i, j + 1)


def dpalignment(a, b):
    m = len(a)
    n = len(b)

    table = [[0 for j in range(0, n + 1)] for i in range(0, m + 1)]
    minindex = [[(0, 0) for j in range(0, n + 1)] for i in range(0, m + 1)]

    for j in range(n - 1, -1, -1):
        table[m][j] = table[m][j + 1] + 2

    for i in range(m - 1, -1, -1):
        table[i][n] = table[i + 1][n] + 2

    for d in range(1, m):
        j = n
        for i in range(m - d, m):
            if i <= 0:
                break
            j -= 1
            if j < 0:
                break
            opt(i, j, a, b, table, minindex)

    for d in range(n - 1, -1, -1):
        for i in range(0, d + 1):
            if i > m-1:
                break
            j = d - i
            opt(i, j, a, b, table, minindex)

    utility.printMatrix(table)
    x = 0
    y = 0

    print()
    while x < m and y < n:
        tx, ty = x, y
        print(minindex[x][y])
        (x, y) = minindex[x][y]
        if x == tx + 1 and y == ty + 1:
            print(a[tx], " ", b[ty])
        elif x == tx and y == ty + 1:
            print(" - ", " ", b[ty])
        else:
            print(a[tx], " ", " - ")


print("(1번)\n")
a1 = ['A', 'A', 'C', 'A', 'G', 'T', 'T', 'A', 'C', 'C']
b1 = ['T', 'A', 'A', 'G', 'G', 'T', 'C', 'A']
dpalignment(a1, b1)

print()
print("(2번)\n")

a2 = ['T', 'G', 'A', 'C', 'A', 'A', 'G', 'T']
b2 = ['T', 'A', 'C', 'A', 'A', 'T', 'T']
dpalignment(a2, b2)
