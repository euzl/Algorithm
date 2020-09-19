#include <string>
#include <vector>

using namespace std;

vector<int> getBinaryMap(int num, int n) {
    vector<int> result;
    while (num > 0) {
        result.push_back(num%2);
        num /= 2;
    }
    while (result.size() != n) {
        result.push_back(0);
    }
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> map1;
    vector<vector<int>> map2;
    for (int i=0; i < n; i++) {
        map1.push_back(getBinaryMap(arr1[i], n));
        map2.push_back(getBinaryMap(arr2[i], n));
    }
    
    for (int i=0; i<n; i++) {
        answer.push_back("");
        for ( int j=n-1; j>=0; j--) {
            if (map1[i][j] == 1 || map2[i][j] == 1) {
                answer.back() += "#";
            } else {
                answer.back() += " ";
            }
        }
    }
    return answer;
}
