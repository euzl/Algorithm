#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* prev;
    Node* next;
    Node() {
        prev = NULL;
        next = NULL;
    }
    Node(char d, Node* node) {
        // 파라미터node의 prev에 추가
        data = d;
        prev = node->prev;
        node->prev = this;
        next = node;
        prev->next = this;
    }
    void selfDelete() {
        prev->next = next;
        next->prev = prev;
        delete this;
    }
    void printData() {
        cout << data;
    }
};
struct DoubleLinkedList {
    Node* head;
    Node* tail;
    Node* cursor; // 커서 역할
    DoubleLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cursor = tail;
    }
    ~DoubleLinkedList() {
        while (head->next != tail) {
            head->next->selfDelete();
        }
        delete head;
        delete tail;
    }
    void init() {
        char input[100001];
        cin >> input;
        for (int i=0; input[i]; i++) {
            new Node(input[i], cursor);
        }
    }
    void printList() {
        cursor = head;
        while (cursor->next != tail) {
            cursor = cursor->next;
            cursor->printData();
        }
    }
    void commandL() {
        if (cursor != head->next) cursor = cursor->prev;
    }
    void commandD() {
        if (cursor != tail) cursor = cursor->next;
    }
    void commandB() {
        if (cursor != head->next) cursor->prev->selfDelete();
    }
    void commandP() {
        char d;
        cin >> d;
        new Node(d, cursor);
    }
};
int main() {
    DoubleLinkedList* dll = new DoubleLinkedList();
    dll->init();
    int n;
    cin >> n;
    char s;
    for (int i=0; i<n; i++) {
        cin >> s;
        switch(s) {
            case 'L':
                dll->commandL();
                break;
            case 'D':
                dll->commandD();
                break;
            case 'B':
                dll->commandB();
                break;
            case 'P':
                dll->commandP();
                break;
        }
    }
    dll->printList();
    delete dll;
    return 0;
}
