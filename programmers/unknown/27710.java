// 1번
class Solution {
    public int solution(int n) {
        int answer = 0;
        for (int i=1; i<n; i++) {
            if (n%i == 1) return i;
        }
        return answer;
    }
}

// 2번 (70점)
import java.util.*;

class Solution {
    int [] arr;
    int size;
    public int[] solution(int n, long left, long right) {
        size = Math.toIntExact(right-left)+1;
        makeArr(n, left);
    
        return arr;
    }
    
    private void makeArr(int n, long start) {
        arr = new int[size];
        
        int d = (int)(start/n);
        long idx = d*n-1;
        int k=0;
        for (int i=d+1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                idx++;
                if (idx < start) continue;
                if (idx == start) k = -1;
                k++;
                if (k == size) return;
                arr[k] = Math.max(i,j);
            }
        }
    }
}
/**
 * arr[r][c] = max(r, c)
 */
