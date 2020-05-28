inf = 1000
w = [[0, 7, 4, 6, 1], [inf, 0, inf, inf, inf], [inf, 2, 0, 5, inf], [inf, 3, inf, 0, inf], [inf, inf, inf, 1, 0]]
n = 5
f = set()
touch = n * [0]
length = n * [0]
save_length = n * [0]

for i in range(1, n):
    length[i] = w[0][i]
    touch[i] = 0

for k in range(1, n):
    min = inf
    vnear = -1
    for i in range(1, n):
        if 0 <= length[i] < min:
            min = length[i]
            vnear = i
            save_length[i] = length[i]
    f.add((touch[vnear], vnear))
    for i in range(1, n):
        if length[vnear]+w[vnear][i] < length[i]:
            length[i] = length[vnear] + w[vnear][i]
            touch[i] = vnear
            save_length[i] = length[i]
    length[vnear] = -1


print(f)
print(save_length)
