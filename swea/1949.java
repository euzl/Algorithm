package problemsolving;


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
	
	static int k=0;
	static int n=0;
	static int [][] map = new int[8][8];
	static boolean [][] isVisited = new boolean [8][8];
	
	static int maxLength = 0;
	
	static int [] dx = {-1, 0, 1, 0};
	static int [] dy = {0, -1, 0, 1};
	
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/sample_input (1).txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt(); 
		
		for(int test_case = 1; test_case <= T; test_case++)
		{				
			n = sc.nextInt();
			k = sc.nextInt();
			
			int max=0;
			map = new int[n][n];
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					// Load map
					map[i][j] = sc.nextInt();
					if (map[i][j] > max) max = map[i][j];
					
					// init visited
					isVisited[i][j] = false;
				}
			}
			
			// 가장 높은곳에서부터 등산로 탐색 
			maxLength = 0;
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (map[i][j] == max) {
						DFS(new Pair(i, j, map[i][j]), false, 1);
					}
				}
			}
 			
			System.out.printf("#%d %d\n", test_case, maxLength);
		}
	}
	

	static void DFS(Pair start, boolean isCutted, int length) {
		int nx, ny;
		isVisited[start.x][start.y] = true;
		if (length > maxLength) maxLength = length;
		
		for (int d=0; d<4; d++) {
			nx = start.x+dx[d];
			ny = start.y+dy[d];
			
			if(nx<0||nx>=n||ny<0||ny>=n||isVisited[nx][ny]) continue;
			
			isVisited[nx][ny] = true;
			
			if (map[nx][ny] < start.h) {
				DFS(new Pair(nx, ny, map[nx][ny]), isCutted, length+1);
			}
			else {
				if (isCutted == false && (map[nx][ny]-start.h)<k && start.h>=1) {DFS(new Pair(nx, ny, start.h-1), true, length+1);
				
				}
			}
			
			isVisited[nx][ny] = false;
		}
		
		isVisited[start.x][start.y] = false;
		
	}
	
	static void printArray(int n, int [][] map) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				System.out.printf("%d ", map[i][j]);
			}
			System.out.println();
		}
	}
}
