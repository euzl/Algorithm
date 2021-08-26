import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Main {
	static int N;
	static int [][] map;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		map = new int[N][N];
		
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		if (map[N-1][N-1] == 1) {
			System.out.println(0);
			return;
		}
		
		System.out.println(BFS());
		
		
	}
	
	private static int BFS() {
		int count = 0;
		Queue<Cord> q = new LinkedList<>();
		q.add(new Cord(0, 1, -1)); // start
		
		Cord cur;
		int d; // -1 가로 0 대각 1 세로 
		int nr, nc;
		
		while(!q.isEmpty()) {
			cur = q.poll();
			d = cur.dir;
			
			// 대각선 
			nr = cur.r+1; nc = cur.c+1;
			if (nr<N && nc<N && map[cur.r][nc]==0 && map[nr][cur.c]==0 && map[nr][nc]==0) {
				if (nr == N-1 && nc == N-1) {
					count++;
				} else if (nr<N && nc<N) {
					q.add(new Cord(nr, nc, 0));
				}
			}

			// 세로 
			if (d >= 0) {
				nr = cur.r+1; nc=cur.c;
				if (nr == N-1 && nc == N-1) {
					count++;
				} else if (nr<N && nc<N && map[nr][nc]!=1) {
					q.add(new Cord(nr, nc, 1));
				}
			}
			
			// 가로 
			if (d <= 0) {
				nr = cur.r; nc=cur.c+1;
				if (nr == N-1 && nc == N-1) {
					count++;
				} else if (nr<N && nc<N && map[nr][nc]!=1) {
					q.add(new Cord(nr, nc, -1));
				}
			}
			
		}
		
		return count;
	}
	
	static class Cord {
		int r;
		int c;
		int dir;
		Cord(int r, int c, int dir) {
			this.r = r;
			this.c = c;
			this.dir = dir;
		}
	}
}
