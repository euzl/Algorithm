
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	// 좌 상 우 하 
	static int [] dr = {0, -1, 0, 1};
	static int [] dc = {-1, 0, 1, 0};
	static List<Integer> [] pipe = new List[8];
	
	static int [][] map = new int [50][50];
	static int count;
	
	static int N, M, R, C, L;
	public static void main(String args[]) throws Exception
	{
		pipe[0] = Arrays.asList();
		pipe[1] = Arrays.asList(0, 1, 2, 3);
		pipe[2] = Arrays.asList(1,3);
		pipe[3] = Arrays.asList(0,2);
		pipe[4] = Arrays.asList(1,2);
		pipe[5] = Arrays.asList(2,3);
		pipe[6] = Arrays.asList(0,3);
		pipe[7] = Arrays.asList(0,1);
		
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();


		for(int test_case = 1; test_case <= T; test_case++)
		{
			count = 0;
			N = sc.nextInt();
			M = sc.nextInt();
			R = sc.nextInt();
			C = sc.nextInt();
			L = sc.nextInt();
			
			for (int i=0; i<N; i++) {
				for (int j=0; j<M; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			BFS();
			System.out.println("#"+test_case+" "+count);
		}
	}
	
	public static void BFS() {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(R, C, 1));
		
		Pair cur;
		int nr, nc;
		while(!q.isEmpty()) {
			cur = q.poll();
			
			if (cur.t > L) return;
			if (map[cur.r][cur.c] == 0) continue; // already visit
			
			for (int d : pipe[map[cur.r][cur.c]]) {
				nr = cur.r + dr[d];
				nc = cur.c + dc[d];
				
				if (nr<0||nr>=N||nc<0||nc>=M) continue;
				if (map[nr][nc] == 0) continue;
				if (pipe[map[nr][nc]].contains((d+2)%4)) {
					q.add(new Pair(nr, nc, cur.t+1));
				}
			}
			
			map[cur.r][cur.c]= 0;
			count++;
//			System.out.printf("(%d, %d) ", cur.r, cur.c);
		}
	}
	
	static class Pair {
		int r; int c; int t;
		Pair(int r, int c, int t) {this.r = r; this.c = c; this.t = t;}
	}
}
