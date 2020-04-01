# 합병정렬
# 해결하지 못했음. s를 어떻게 선언하느냐에 따라 성공/실패가 갈림. 왜이럴까 ㅜㅜ 
# 앞 절반은 잘 되는데 뒷 절반이 잘 안된다. 다시 봐야 될 듯
def mergesort2(s, low, high):
    if low < high:
        mid = int((low+high)/2)
        mergesort2(s, low, mid)
        mergesort2(s, mid+1, high)
        merge2(s, low, mid, high)


def merge2(s, low, mid, high):
    u = [0]*(high+1)  # 이부분을 고치면 문제가 해결될 것 같다.
    i = low
    j = mid + 1
    k = low
    while i <= mid and j <= high:
        if s[i] <= s[j]:
            u[k] = s[i]
            i += 1
        else:
            u[k] = s[j]
            j += 1
        k += 1
    if i > mid:
        u[k:high] = s[j:high]
    else:
        u[k:high] = s[i:mid]
    s[low:high] = u[low:high]


s = [3, 5, 2, 7, 1, 9, 8, 17]
mergesort2(s, 0, 7)
print(s)
