import java.util.*;

class Solution {
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        
        int [][] map = new int[N+1][N+1];
        boolean [] visit = new boolean[N+1];
        
        // map setting
        for (int [] rd : road) {
            if (map[rd[0]][rd[1]] == 0 || map[rd[0]][rd[1]] > rd[2]) {
                map[rd[0]][rd[1]] = rd[2];
                map[rd[1]][rd[0]] = rd[2];
            }
        }
        
        // Dijkstra
        int idx;
        int j;
        while(true) {
            idx = getShortest(N, map, visit);
            if (idx == -1) break;
            visit[idx] = true;
            
            for (j=2; j<=N; j++) {
                if (visit[j] || map[idx][j] == 0) continue;
                if (map[1][j] == 0 || map[1][j] > map[1][idx] + map[idx][j]) {
                    // 최소거리 갱신
                    map[1][j] =  map[1][idx] + map[idx][j]; 
                    map[j][1] =  map[1][idx] + map[idx][j]; 
                }
            }
        }
        
        for (int i=1; i<=N; i++) {
            if (map[1][i] <= K) answer++; // 배달 가능 지역
            // System.out.println("#"+i+" "+map[1][i]);
        }
    
        return answer;
    }
    
    private int getShortest(int N, int [][] map, boolean [] visit) {
        int idx = -1;
        
        for (int i=1; i<=N; i++) {
            if (visit[i] || map[1][i] == 0) continue;
            if (idx == -1) idx = i;
            else if (map[1][idx] > map[1][i]) idx = i; // 갱신
        }
        
        return idx;
    }
}
