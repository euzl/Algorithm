import java.util.Scanner;
import java.util.Stack;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (8).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int size = sc.nextInt();
			String input = sc.next();
			
			
			System.out.printf("#%d %d\n", test_case, check(input, size)?1:0);
		}
	}
	public static boolean check(String input, int size) {
		Stack<Character> stack = new Stack<>();
		for (int i=0; i<size; i++) {
			if (isOpen(input.charAt(i))) {
				stack.push(input.charAt(i));
			} else {
				if (isClose(input.charAt(i), stack.peek())) stack.pop();
				else return false;
			}
		}
		if (stack.empty()) return true;
		return false;
	}
	
	public static boolean isOpen(char input) {
		if (input == '{' || input == '[' || input == '(' || input == '<') return true;
		else return false;
	}
	
	public static boolean isClose(char input, char top) {
		if (input == '}' && top == '{') return true;
		else if (input == ']' && top == '[') return true;
		else if (input == ')' && top == '(') return true;
		else if (input == '>' && top == '<') return true;
		else return false;
	}
}
