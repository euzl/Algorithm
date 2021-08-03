import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N = sc.nextInt();
			int [][] tree = new int[N+1][2]; // 1 left 2 right
			char [] oper = new char[N+1]; // save operator
			double [] num = new double[N+1]; // value of Node
			input(tree, num, oper, N, sc);
			
			System.out.printf("#%d %d\n", test_case, (int)calculate(tree, num, oper, 1));
		}
	}
	
	static double calculate(int [][] tree, double [] num, char [] oper, int cur) {
		if (isDigit(oper[cur])) return num[cur];
		
		double a = child(tree, num, oper, 0, cur);
		double b = child(tree, num, oper, 1, cur);
		
		if (oper[cur] == '/') return a/b;
		else if (oper[cur] == '*') return a*b;
		else if (oper[cur] == '+') return a+b;
		else return a-b;
	}
	
	static double child(int [][] tree, double [] num, char [] oper, int flag, int cur) {
		if (tree[cur][flag] == 0) return 1;
		return calculate(tree, num, oper, tree[cur][flag]);
	}
	
	static void input(int [][] tree, double [] num, char [] oper, int N, Scanner sc) {
		int a;
		String b;
		int i;
		
		for (i=1; i<=N; i++) {
			a = sc.nextInt();
			b = sc.next();
			if (!isDigit(b.charAt(0))) {
				oper[i] = b.charAt(0);
				tree[i][0] = sc.nextInt();
				tree[i][1] = sc.nextInt();
			} else {
				num[i] = Double.parseDouble(b);
			}
		}
	}
	
	static boolean isDigit(char t) {
		if (t=='/' || t=='+'||t=='-'||t=='*') return false;
		return true;
	}
}
