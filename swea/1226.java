import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	static final int SIZE = 16;
	static char [][] map = new char[SIZE][SIZE];
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (17).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		String input;
		Cord start = new Cord();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int t = sc.nextInt();
			for (int i=0; i<SIZE; i++) {
				input = sc.next();
				for (int j=0; j<SIZE; j++) {
					map[i][j] = input.charAt(j);
					if (map[i][j] == '2') start.set(i, j);
				}
			}
		
			System.out.printf("#%d %d\n", test_case, BFS(start)==true?1:0);
		}
	}
	
	/**
	 * 좌표 저장
	 */
	static class Cord {
		public int y;
		public int x;
		public Cord() {}
		public Cord(int y, int x) {this.y=y; this.x=x;}
		public void set(int y, int x) {this.y=y; this.x=x;}
	}
	
	public static boolean BFS(Cord start) {
		Queue<Cord> q = new LinkedList<>();
		q.add(start);
		
		int [] dy = {-1, 0, 1, 0};
		int [] dx = {0, -1, 0, 1};
		
		boolean [][] isVisited = new boolean[SIZE][SIZE];
		isVisited[start.y][start.x] = true;
		
		Cord cur = new Cord();
		int y, x, ny, nx;
		while(!q.isEmpty()) {
			cur = q.poll();
			y=cur.y; x=cur.x;
			
			for (int d=0; d<4; d++) {
				ny=y+dy[d]; nx=x+dx[d]; // 다음 좌표로 이동
				if (ny>=SIZE || ny<0 || nx>=SIZE || nx<0) continue; // out of map
				if (map[ny][nx] == '1' || isVisited[ny][nx]) continue; // already visited
				
				if (map[ny][nx] == '3') return true; // arrive at end
				
				q.add(new Cord(ny, nx));
				isVisited[ny][nx] = true;
			}
		}
		return false;
	}
}
