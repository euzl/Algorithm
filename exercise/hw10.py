# (1) 부분집합의 합
def promising(i, weight, total):
    return weight+total >= W and (weight == W or weight+w[i+1] <= W)


def s_s(i, weight, total, include):
    if promising(i, weight, total):
        if weight == W:
            print("sol", include)
        else:
            include[i+1] = 1
            s_s(i+1, weight+w[i+1], total-w[i+1], include)
            include[i+1] = 0
            s_s(i+1, weight, total-w[i+1], include)


n = 4
w = [1, 4, 2, 6]

W = 6
print("items =", w, "W =", W)
include = n * [0]
total = 0
for k in w:
    total += k
s_s(-1, 0, total, include)



# (2) m-coloring

n = 4
W = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]


def m_coloring(i, vcolor):
    if promising2(i, vcolor):
        i = i+1
        if i == n:
            print(vcolor)
        else:
            for color in range(1, m+1):
                vcolor[i] = color
                m_coloring(i, vcolor)


def promising2(i, vcolor):
    j = 0
    while j < i:
        if W[i][j] and (vcolor[i] == vcolor[j]):
            return 0
        j += 1
    return 1


vcolor = n * [0]
m = 3
m_coloring(-1, vcolor)
