import java.util.Stack;

/**
 * 괄호 짝 검사  
 */
public class Solution2 {
	public static void main(String[] args) {
		System.out.println(check("()()((()))"));
		System.out.println(check("((()((((()()((()())((())))))"));
	}
	public static boolean check(String input) {
		Stack<Character> stack = new Stack<>();
		int size = input.length();
		for (int i=0; i<size; i++) {
			if (input.charAt(i) == '(') {
				stack.push('(');
			} else {
				if (stack.peek() == '(') stack.pop();
				else return false;
			}
		}
		if (stack.empty()) return true;
		return false;
	}
}
