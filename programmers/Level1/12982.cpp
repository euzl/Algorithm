#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    // d sort. budget에서 빼면서 카운트
    int answer = 0;
    sort(d.begin(), d.end());
    for (int cost : d) {
        budget -= cost;
        if (budget < 0) break;
        ++answer;
    }
    
    return answer;
}
