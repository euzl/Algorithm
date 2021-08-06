
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	static class Pair {
		int x;
		int y;
		int h; // height
		Pair() {}
		Pair(int x, int y, int h) {this.x=x; this.y=y; this.h=h;}
	}

	
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, -1, 0, 1};
	
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt(); 
		int n;
		for(int test_case = 1; test_case <= T; test_case++)
		{				
			n = sc.nextInt();
			
			int [][] map = new int[n][n];
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					// Load map
					map[i][j] = sc.nextInt();
				}
			}
			
			int max = -1;
			int roomNumber = 10000;
			int temp;
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					temp = BFS(i, j, map, n);
					if (temp > max) {
						max = temp;
						roomNumber = map[i][j];
					} else if (temp == max && map[i][j]<roomNumber) {
						max = temp;
						roomNumber = map[i][j];
					}
				}
			}
 			
			System.out.printf("#%d %d %d\n", test_case, roomNumber, max);
		}
	}
	
	static int BFS(int r, int c, int [][] map, int n) {
		int cnt=1;
		
		int nr, nc;
		boolean isPromising = false;
		while(true) {
			isPromising = false;
			for (int d=0; d<4; d++) {
				nr = r+dr[d];
				nc = c+dc[d];
				
				if(nr<0||nr>=n||nc<0||nc>=n) continue;

				if (map[nr][nc]-map[r][c] == 1) {
					cnt++;
					r = nr;
					c = nc;
					isPromising = true;
					break;
				}
			}
			if (!isPromising) break;
		}
		
		
		return cnt;
	}

}
