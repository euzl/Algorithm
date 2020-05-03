# (1)빠른정렬 프로그램
def quickSort(s, low, high):
    if high > low:
        pivotpoint = partition(s, low, high)
        quickSort(s, low, pivotpoint - 1)
        quickSort(s, pivotpoint + 1, high)


def partition(s, low, high):
    pivotitem = s[low]
    j = low
    for i in range(low+1, high+1):
        if s[i] < pivotitem:
            j += 1
            s[i], s[j] = s[j], s[i]
    s[low], s[j] = s[j], s[low]
    return j


s = [3, 5, 2, 9, 10, 14, 4, 8]
quickSort(s, 0, 7)
print(s)



# (2)큰 정수 곱셈 프로그램
def prod2(a, b):
    u = str(a)
    v = str(b)
    n = max(len(u), len(v))
    if a == 0 or b == 0:
        return 0
    elif n <= 4:  # threshold == 4 (가정)
        return a * b
    else:
        m = int(n/2)
        x = int(a / (10 ** m))
        y = a % (10 ** m)
        w = int(b / (10 ** m))
        z = b % (10 ** m)
        r = prod2(x+y, w+z)
        p = prod2(x, w)
        q = prod2(y, z)
        return p * pow(10, 2*m) + (r-p-q) * pow(10, m) + q


a = 1234567812345678
b = 2345678923456789

print(prod2(a, b))
print(a * b)
