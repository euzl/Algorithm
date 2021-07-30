import java.util.Scanner;
import java.util.Stack;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
//		System.setIn(new FileInputStream("res/input (13).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int size = sc.nextInt();
			String input = sc.next();
			
			System.out.printf("#%d %s\n", test_case, getPassword(input, size));
		}
	}
	
	public static String getPassword(String input, int size) {
		Stack<Character> stack = new Stack<>();
		for (int i=0; i<size; i++) {
			if (stack.isEmpty()) {
				stack.push(input.charAt(i));
				continue;
			}
			if (stack.peek() == input.charAt(i)) {
				stack.pop();
			} else {
				stack.push(input.charAt(i));
			}
		}
		String result = "";
		while(!stack.isEmpty()) {
			result = stack.peek() + result;
			stack.pop();
		}
		return result;
	}
}
