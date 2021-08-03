import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	static char [] alpha = new char[101];
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (19).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N = sc.nextInt();
			int [][] tree = new int[N+1][2];
			input(tree, N, sc);
			
			System.out.printf("#%d ", test_case);
			inOrder(tree, 1);
			System.out.println();
		}
	}
	
	static void inOrder(int [][] tree, int cur) {
		child(tree, 0, cur);
		System.out.print(alpha[cur]);
		child(tree, 1, cur);
	}
	
	static void child(int [][] tree, int flag, int cur) {
		if (tree[cur][flag] == 0) return;
		inOrder(tree, tree[cur][flag]);
	}
	
	static void input(int [][] tree, int N, Scanner sc) {
		int a;
		String b;
		int i;
		
		// input 4개 
		for (i=1; i<N/2; i++) {
			a = sc.nextInt();
			b = sc.next();
			alpha[i] = b.charAt(0);
			a = sc.nextInt();
			tree[i][0] = a;
			a = sc.nextInt();
			tree[i][1] = a;
		}
		
		// input 개수가 변하는 지점 (N/2 || N/2+1)
		a = sc.nextInt();
		b = sc.next();
		alpha[i] = b.charAt(0);
		a = sc.nextInt();
		tree[i][0] = a;
		if (N%2==1) {
			a = sc.nextInt();
			tree[i][1] = a;
		}
		
		// input 2개 
		i++;
		for (; i<=N; i++) {
			a = sc.nextInt();
			b = sc.next();
			alpha[i] = b.charAt(0);
		}
	}
}
