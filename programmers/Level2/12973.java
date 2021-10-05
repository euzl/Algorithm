class Solution
{
    public int solution(String s)
    {
        int size = s.length();
        int [][] p = new int[size][2];
        for (int i=0; i<size; i++) {
            p[i][0] = i-1;
            p[i][1] = i+1;
        }
        
        int start = 0, end = size-1;
        int i, j;
        int rest = size;
        int prevRest;
        
        while(rest > 0) {
            i = start; j = p[i][1];
            prevRest = rest;
            while(j <= end) {
              if (s.charAt(i) == s.charAt(j)) {
                  rest -= 2;
                  
                    if (i == start) {
                        start = p[j][1];
                        if (start > end)break;
                        i = start;
                        j = p[start][1];
                    } else {
                        i = p[i][0];
                        j = p[j][1];
                        p[i][1] = j;
                        p[j][0] = i;
                    }
                 
                } else {
                  i=j;
                  j=p[i][1];
              }
                
                if (j >= end) break;
            }
            if (prevRest == rest) break;
            prevRest = rest;
        }
        
        return rest == 0 ? 1 : 0;
    }
}
