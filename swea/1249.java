
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	static int N;
	static int [][] map = new int [100][100];
	static int [][] p = new int [100][100];
	
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, -1, 0, 1};
	
	static final int MAX = 987654321;

	public static void main(String args[]) throws Exception
	{

		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		String line;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			
			for (int i=0; i<N; i++) {
				line = sc.next();
				for (int j=0; j<N; j++) {
					map[i][j] = line.charAt(j)-'0';
					p[i][j] = MAX; //init
				}
			}
			p[0][0] = 0;

			BFS();
			
			System.out.printf("#%d %d\n", test_case, p[N-1][N-1]);
		}
	}
	
	public static void BFS() {
		Queue<Cord> q = new LinkedList<>();
		q.add(new Cord(0, 0));
		
		Cord cur;
		int nr, nc, price;
		while(!q.isEmpty()) {
			cur = q.poll();
			
			for (int d=0; d<4; d++) {
				nr = cur.r+dr[d];
				nc = cur.c+dc[d];
				if (nr<0||nr>=N||nc<0||nc>=N) continue;
				
				price = p[cur.r][cur.c] + map[nr][nc];
				if (p[nr][nc] > price) {
					p[nr][nc] = price;
					q.add(new Cord(nr, nc));
				}
			}
		}
	}

	static class Cord{
		int r;
		int c;
		Cord(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
}
