import queue

print('\n1. 깊이우선검색\n')


def kp(i, profit, weight):
    global bests
    global maxp
    if weight <= W and profit > maxp:
        maxp = profit
        bests = include[:]
    if promising(i, weight, profit):
        include[i+1] = 1
        kp(i+1, profit+p[i+1], weight+w[i+1])
        include[i+1] = 0
        kp(i+1, profit, weight)


def promising(i, weight, profit):
    global maxp
    if weight >= W:
        return 0
    else:
        j = i+1
        bound = profit
        totweight = weight
        while j < n and (totweight + w[j] <= W):
            totweight = totweight + w[j]
            bound = bound + p[j]
            j += 1
        if j < n:
            bound = bound + (W-totweight)*p[j]/w[j]

        return bound > maxp


n=4
W=16
p=[40,30,50,10]
w=[2,5,10,5]
maxp=0
include =[0,0,0,0]
bests = [0,0,0,0]
kp(-1,0,0)
print(maxp)
print(bests)


print('\n2. 최고우선검색\n')

class Node:
    def __init__(self, level, weight, profit, bound, include):
        self.level = level
        self.weight = weight
        self.profit = profit
        self.bound = bound
        self.include = include

    def __lt__(self, other):
        return self.bound < other.bound


def kp_Best_FS():
    global maxProfit
    global bestSet

    q = queue.PriorityQueue()

    temp = n*[0]
    v = Node(-1, 0, 0, 0.0, temp)
    maxProfit = 1
    q.put(v)

    while not q.empty():
        v = q.get()
        if v.bound < maxProfit:
            uLevel = v.level + 1
            uInclude = v.include.copy()
            uInclude[uLevel] = 1
            u = Node(uLevel, v.weight + w[uLevel], v.profit - p[uLevel], 0.0, uInclude)
            if u.weight <= W and u.profit < maxProfit:
                maxProfit = u.profit
                bestSet = u.include
            u.bound = compBound(u)
            if u.bound < maxProfit:
                q.put(u)
            x = Node(uLevel, v.weight, v.profit, 0.0, v.include.copy())
            x.bound = compBound(x)
            if x.bound < maxProfit:
                q.put(x)


def compBound(u):
    if u.weight >= W:
        return 0
    else:
        u.bound = u.profit
        j = u.level + 1
        totweight = u.weight
        while j < n and totweight <= W:
            totweight += w[j]
            u.bound -= p[j]
            j += 1
        if j < n:
            u.bound -= (W-totweight)*p[j]/w[j]
        return u.bound


# heap이 minheap이라 bound를 계산하여 -를 하여 리턴한다. 비교를 <maxProfit으로 수행한다
n=4
W=16
p=[40,30,50,10]
w=[2,5,10,15]
include = [0]*n
maxProfit = 0
bestSet = n*[0]
kp_Best_FS()
print(bestSet)
print(maxProfit)
