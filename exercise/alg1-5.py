# 이분검색 알고리즘
def bs(d, item, low, high):
    location = 0
    mid = 0
    while low <= high and location == 0:
        mid = int((low + high) / 2)
        if item == d[mid]:
            location = mid
            return location
        elif item < d[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return -1  # 찾지 못함


data = [1, 3, 5, 6, 7, 9, 10, 14, 17, 19]
n = 10
loca = bs(data, 17, 0, n-1)
print(loca)
