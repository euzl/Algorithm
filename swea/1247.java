import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	

	static int N;
	static Cord [] list; // 0 office, 1 home, 2~N+2 : customer
	static int minDistance=987654321;
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{	
			minDistance = 987654321;
			N = sc.nextInt();
			list = new Cord[N+2];
			int r, c;
			for (int i=0; i<N+2; i++) {
				r = sc.nextInt();
				c = sc.nextInt();
				list[i] = new Cord(r, c);
			}
			
			DFS(list[0], 0, 0);
			
			System.out.printf("#%d %d\n", test_case, minDistance);
		}
	}
	
	public static void DFS(Cord cur, int distance, int depth) {
		if (depth == N) {
			getMinDistance(cur, distance);
			return;
		} else {
			int newDistance;
			for (int i=2; i<N+2; i++) {
				if (list[i].isVisit) continue;
				
				newDistance = distance + Math.abs(cur.r-list[i].r) + Math.abs(cur.c-list[i].c);
				list[i].isVisit = true;
				DFS(list[i], newDistance, depth+1);
				list[i].isVisit = false;
			}
		}
	}
	
	public static void getMinDistance(Cord last, int distance) {
		distance += Math.abs(list[1].r - last.r) + Math.abs(list[1].c - last.c);
		if (distance < minDistance) {
			minDistance = distance;
		}
	}
	
	static class Cord {
		int r;
		int c;
		boolean isVisit;
		Cord(int r, int c) {
			this.r = r;
			this.c = c;
			this.isVisit = false;
		}
		
	}
	
}
