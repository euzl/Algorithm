#include <iostream>
#include <string>
using namespace std;

int main() {
    int w[2][5001] = {{0, 0}, };
    string word;
    cin >> word;
    
    int idx = word.length() - 1;
    bool isZero = false; // 직전 숫자가 0인지 체크
    bool isUndersix = false; // 6이하인경우 true
    
    w[0][idx] = 1;
    w[1][idx] = 0;
    
    if (word[idx] == '0') {
        isZero = true;
        isUndersix = true;
    } else if (word[idx] - '0' <= 6) {
        isUndersix = true;
    }
    while (idx > 0) {
        idx--;
        int wrd = word[idx] - '0';
        
        // 답이 없는 경우 (10, 20 제외 모든 경우)
        if (isZero) {
            if ((wrd != 1) && (wrd != 2)){
                w[0][idx] = w[1][idx] = 0;
                break;
            }
        }
        
        w[0][idx] = w[0][idx+1] + w[1][idx+1];
        
        if (((wrd == 2) && isUndersix) || (wrd == 1)) {
            // 2자리 연속이 한 단어가 되는 경우
            if (isZero) w[0][idx] = 0; // 10, 20은 무조건 2연속만 가능
            w[1][idx] = w[0][idx+1];
        } else {
            w[1][idx] = 0;
        }
        
        // 2자리 연속 가능 여부를 위한 bool변수 저장
        if (wrd == 0) isZero = true;
        else isZero = false;
        
        if (wrd <= 6) isUndersix = true;
        else isUndersix = false;
        
        w[0][idx] %= 1000000;
        w[1][idx] %= 1000000;
    }
    
    if (isZero) {
        // 맨 앞이 0이면 답은 0!
        cout << 0 << endl;
    } else {
        cout << (w[0][0] + w[1][0])%1000000 << endl;
    }
    return 0;
}
