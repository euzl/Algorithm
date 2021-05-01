#include <string>
#include <vector>

using namespace std;

bool findSame(int &cnt, string &result, string &temp, string s, int n, int &i) {
    // printf("i %d n %d\n", i, n);
    int size = s.size();
    for (int j=0; j<n; j++) {
        if (i + j == size) return false;
        if (temp[j] != s[i+j]) { // 불일치
            // printf("???\n");
            return false;
        }
        // printf("temp %c s[i+j] %c\n", temp[j], s[i+j]);
    }
    ++cnt;
    i += n;
    if (i >= size) {
            // printf("???222\n");
        return false;
    }
    return true;
}

int cutting(string s, int n) {
    // printf("몇개? %d\n", n);
    string result = "";
    int size = s.size();
    int cnt = 1;
    string temp = "";
    bool isCon = true;
    for (int i=0; i<size;) {
        if (temp == "") { // init
            cnt = 1;
            for (int j=0; j<n; j++) {
                temp += s[i+j];
                if (i + j == size - 1) {
                    i = size - 1;
                    isCon = false;
                    break;
                }
            }
            i += n; // 건너뛰기
            // printf("%d\n", i);
        } else { // temp 지정되어있음
            isCon = findSame(cnt, result, temp, s, n, i);
            // printf("%d\n", i);
        }
        
        if (!isCon) {
            if (cnt > 1 ) result = result + to_string(cnt) + temp;
            else result = result + temp;
            temp = "";
        }
        isCon = true;
        // printf("[i:%d] : %s | temp : %s\n", i, result.c_str(), temp.c_str());
    }
    // printf("%s ", result.c_str());
    return result.size();
}

int solution(string s) {
    int answer = 1000;
    int size = s.size();
    int length = 0;
    for (int i=1; i<=size; i++) {
        length = cutting(s, i);
        // printf(" result %d \n", length);
        if (length < answer) answer = length;
    }
    return answer;
}
