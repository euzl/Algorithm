class Solution {
    int [][] road = new int[21][21];
    
    int [] dr = {-1, 1, 0, 0};
    int [] dc = {0, 0, 1, -1};
    
    // current Cord. init = (10, 10)
    int r = 10;
    int c = 10;
    
    public int solution(String dirs) {
        int answer = 0;
        int size = dirs.length();
        
        int dir;
        for (int d=0; d<size; d++) {
            if (dirs.charAt(d) == 'U') dir = 0;
            else if (dirs.charAt(d) == 'D') dir = 1;
            else if (dirs.charAt(d) == 'R') dir = 2;
            else dir = 3;
            
            answer += move(dir);
        }
        return answer;
    }
    
    public int move(int dir) {
        // Change current cord
        r += 2*dr[dir];
        c += 2*dc[dir];
        
        // out of range (Rollback)
        if (r<0||r>=21||c<0||c>=21) {
             r -= 2*dr[dir];
             c -= 2*dc[dir];
            return 0;
        }
        
        // check visit
        if (road[r-dr[dir]][c-dc[dir]] == 1) {
            // System.out.println("visited");
            return 0;
        } else {
            // System.out.println("first");
            road[r-dr[dir]][c-dc[dir]] = 1;
            return 1;
        }
    }
}
