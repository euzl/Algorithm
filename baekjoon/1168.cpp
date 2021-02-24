#include <cstdio>

struct Node {
    int data;
    Node* next;
    Node() {
        data = 1;
        next = this;
    }
    Node(int num, Node* cur) { // cur다음에 num 추가
        data = num;
        next = cur->next;
        cur->next = this;
    }
    void nextDelete() {
        Node* temp = next;
        next = next->next;
        delete temp;
    }
};

struct CircularQueue {
    Node* cur;
    int size;
    CircularQueue(int n) {
        cur = new Node();
        size = 1;
        for (int i=2; i<=n; i++) {
            cur = new Node(i, cur);
            ++size;
        }
    }
    ~CircularQueue() {
        while (size > 1) {
            cur->next->nextDelete();
        }
        delete cur;
        --size;
    }
    int getCur(int k) {
        for (int i=1; i<k; i++) {
            cur = cur->next;
        }
        int result = cur->next->data;
        cur->nextDelete();
        --size;
        return result;
    }
    void printList(int k) {
        printf("<%d", getCur(k));
        while (size) {
            printf(", %d", getCur(k));
        }
        printf(">");
    }
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    CircularQueue* cq = new CircularQueue(n);
    cq->printList(k);

    return 0;
}
