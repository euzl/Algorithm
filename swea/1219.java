import java.util.Scanner;
import java.util.Stack;
import java.io.FileInputStream;

class Solution
{
	static int [][] graph;
	static boolean isTrue;
	public static void main(String args[]) throws Exception
	{
//		System.setIn(new FileInputStream("res/input (10).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			graph = new int[100][2];
			isTrue = false;
			int t = sc.nextInt();
			int size = sc.nextInt();
			int start, dest;
			for (int i=0; i<size; i++) {
				start = sc.nextInt();
				dest = sc.nextInt();
				if (graph[start][0] == 0) graph[start][0] = dest;
				else graph[start][1] = dest;
			}
			
			move(0);
			
			System.out.printf("#%d %d\n", test_case, isTrue?1:0);
		}
	}
	
	static void move(int start) {
		if (graph[start][0] == 99 || graph[start][1] == 99) {
			isTrue = true;
			return;
		}
		if (!isTrue && graph[start][0] != 0) move(graph[start][0]);
		if (!isTrue && graph[start][1] != 0) move(graph[start][1]);
	}
}
