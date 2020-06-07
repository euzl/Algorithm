class Heap(object):
    n = 0  # 배열의 크기 (heap size)
    data = []

    def __init__(self, data):
        self.data = data
        # heap size를 하나 줄여야 한다. 인덱스는 1부터 인덱스의 2* 연산 가능하도록
        self.n = len(self.data) - 1

    def addElt(self, elt):
        self.data.append(elt)
        self.n += 1
        self.siftUp(self.n)

    def siftUp(self, i):
        while i >= 2:
            if self.data[int(i/2)] < self.data[i]:
                parent = self.data[int(i/2)]
                self.data[int(i/2)] = self.data[i]
                self.data[i] = parent
            i = int(i/2)

    def siftDown(self, i):
        siftKey = self.data[i]
        parent = i
        spotfound = 0

        while 2*parent <= self.n and spotfound != 1:
            if 2*parent < self.n and self.data[2*parent] < self.data[2*parent+1]:
                largerChild = 2*parent + 1
            else:
                largerChild = 2*parent

            if siftKey < self.data[largerChild]:
                self.data[parent] = self.data[largerChild]
                parent = largerChild
            else:
                spotfound = 1
        self.data[parent] = siftKey

    def makeHeap2(self):
        for i in range(int(self.n/2), 0, -1):
            self.siftDown(i)

    def root(self):
        keyout = self.data[1]
        self.data[1] = self.data[self.n]
        self.n -= 1
        self.siftDown(1)

        if self.n > 0:
            # 추가하였음. 힙이 더이상 없을 때엔 down 없음
            return keyout
        return 0

    def removeKeys(self):
        self.data = self.data[1:]


def heapSort(a):
    c = Heap(a)
    c.makeHeap2()
    c.root()
    c.removeKeys()
    return c.data


# 인덱스를 간단히 하기 위해 처음 엘리먼트 0 추가
a = [0,11,14,2,7,6,3,9,5]
b = Heap(a)
b.makeHeap2()
print(b.data)
b.addElt(50)
print(b.data)
s = heapSort(a)
print(s)
