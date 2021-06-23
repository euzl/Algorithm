#include <vector>
#include <iostream>
using namespace std;

int isSosu(int number) {
    int left=2, right=number;
    
    while(left <= right) {
        if (number%left == 0) return 0;
        right = number/left;
        ++left;
    }
    return 1;
}

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();
    for (int i=0; i<size-2; i++) {
        for (int j=i+1; j<size-1; j++) {
            for (int k=j+1; k<size; k++) {
                answer += isSosu(nums[i]+nums[j]+nums[k]);
            }
        }
    }

    return answer;
}
