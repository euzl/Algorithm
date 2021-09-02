package problemsolving;

import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	static final int MAX = 10001; // 10000 + 1
	static int [] parent = new int[MAX]; // 0 : 부모없음 
	static int [][] child = new int[MAX][2]; // 0 : 자식없음 
	static int count;
	static boolean isFind;
	public static void main(String args[]) throws Exception
	{
		// System.setIn(new FileInputStream("res/input.txt"));


		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int V, E, N1, N2;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			V = sc.nextInt();
			E = sc.nextInt();
			N1 = sc.nextInt();
			N2 = sc.nextInt();
			
			init(V);
			
			int p, c;
			for (int i=0; i<E; i++) {
				p = sc.nextInt();
				c = sc.nextInt();
				parent[c] = p;
				if (child[p][0]==0) child[p][0] = c;
				else child[p][1] = c;
			}
			
			System.out.printf("#%d %d %d\n", test_case, search(N1, 0, N2), count);
		}
	}
	
	public static void init(int V) {
		count = 0;
		isFind = false;
		
		for (int i=1; i<=V; i++) {
			parent[i] = 0;
			child[i][0] = 0;
			child[i][1] = 0;
		}
	}
	
	public static int search(int start, int skipChild, int target) {
		// 자식 다돌고 (서브트리 카운트++)
		DFS(start, skipChild, target);
		
		// 못찾았으면 부모호출 
		if (!isFind) return search(parent[start], start, target);
		else return start;
	}
	
	public static void DFS(int start, int skipChild, int target) {
		if (start == skipChild) return;
		count++;
		for (int i=0; i<2; i++) {
			if (child[start][i] == 0) continue;
			if (child[start][i] == target) isFind = true;
			DFS(child[start][i], skipChild, target);
		}
	}
}
