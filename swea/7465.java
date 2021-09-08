
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	static int [][] graph = new int [101][101];
	static int N, M;
	static int [] visit = new int [101];
	static int size;
	
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();


		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			M = sc.nextInt();
			
			for (int i=1; i<=N; i++) visit[i] = 0; // -1이면 무리에 속하지 않았음 
			for (int i=1; i<=N; i++) {
				for (int j=1; j<=N; j++) {
					graph[i][j] = 0;
				}
			}
			int a, b;
			for (int i=0; i<M; i++) {
				a = sc.nextInt();
				b = sc.nextInt();
				
				graph[a][b] = 1;
				graph[b][a] = 1;
			}
			
			System.out.println("#"+test_case+" "+getCount());
		}
	}
	
	public static int getCount() {
		int count = 0;
		
		for (int i=1; i<=N; i++) {
			if (visit[i] == 0) {
				makeGroup(i);
				count++;
			}
		}
		
		return count;
	}

	// 아는 사람 싹 돌고 오
	public static void makeGroup(int start) {
		visit[start] = 1;
		
		for (int i=1; i<=N; i++) {
			if (graph[start][i] == 1 && visit[i] == 0) {
				makeGroup(i);
			}
		}
	}
}
