# 합병정렬
def mergesort(n, s):
    h = int(n/2)
    m = n-h
    if n > 1:
        u = s[:h]
        v = s[h:]
        mergesort(h, u)
        mergesort(m, v)
        merge(h, m, u, v, s)


def merge(h, m, u, v, s):
    i = 0
    j = 0
    k = 0
    while i < h and j < m:
        if u[i] < v[j]:
            s[k] = u[i]
            i += 1
        else:
            s[k] = v[j]
            j += 1
        k += 1
    if i >= h:
        s[k:h+m] = v[j:m]
    else:
        s[k:h+m] = u[i:h]


s = [3, 5, 2, 9, 10, 14, 4, 8]
mergesort(8, s)
print(s)
