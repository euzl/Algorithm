#include <string>
#include <vector>

using namespace std;
int total = 0;
int N = 0;
void DFS(vector<int> numbers, int target, int sum, int idx) {
    if (idx == N) {
        if (sum == target) ++total;
        return;
    }
    DFS(numbers, target, sum+numbers[idx], idx+1);
    DFS(numbers, target, sum-numbers[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    DFS(numbers, target, 0, 0);
    return total;
}
