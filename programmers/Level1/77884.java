
class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        for (int i=left; i<=right; i++) {
            if (isYakeven(i)) answer += i;
            else answer -= i;
        }
        return answer;
    }
    
    public boolean isYakeven(int num) {
        
        int sq = (int)Math.sqrt(num);
        if (sq*sq == num) return false;
        else return true;
    }
}
