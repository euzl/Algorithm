// 11721::열 개씩 끊어 출력하기
#include <iostream>
using namespace std;

int main() {
    int a = 0;
    char input[101];
    cin.getline(input ,101);

    while (a < 101) {
        if (input[a] == '\0') {
            return 0;
        }
        cout<<input[a];
        a++;
        if(a%10 == 0) {
            cout<<endl;
        }
    }
    return 0;
}
