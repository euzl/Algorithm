# 순차검색 알고리즘
def seqsearch(s, x):
    for location in range(len(s)):
        if s[location] == x:
            return location + 1
        location += 1
    return 0


a = [3, 5, 2, 1, 7, 9]
loc = seqsearch(a, 4)
print(loc)
