# (n*n)행렬곱셈
def matrix_multiplication(a, b):
    n = len(a)
    c = []
    for i in range(n):
        d = []
        for j in range(n):
            total = 0
            for k in range(n):
                total += a[i][k]*b[k][j]
            d.append(total)
        c.append(d)
    return c


ab = [[1, 2], [3, 4]]
bb = [[4, 1], [1, 0]]

print(matrix_multiplication(ab, bb))

