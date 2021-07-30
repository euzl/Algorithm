import java.util.Scanner;
import java.util.Stack;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
//		System.setIn(new FileInputStream("res/input (11).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int size = sc.nextInt();
			String input = sc.next();	
			
			System.out.printf("#%d %d\n", test_case, calculate(convertToPost(input, size)));
		}
	}
	
	/*
	 *  후위표기식으로 변환 
	 */
	public static String convertToPost(String s, int size) {
		String result="";
		Stack<Character> stack = new Stack<>(); // 연산자 저장 
		char t;
		for (int i=0; i<size; i++) {
			t = s.charAt(i);
			if (t>='0' && t<='9') { // 숫자일 때 
				result += t;
			} else {
				if (t != '(') {
					while(!stack.isEmpty()) {
						if (stack.peek() == '(') { // 괄호처리 
							if (t == ')') stack.pop();
							break;
						}
						if (stack.peek() == '+' && t == '*') { // 자신보다 낮은 연산자가 나오면 stack에서 더이상 빼지 않음 
							break;
						}
						result += stack.peek(); stack.pop(); // stack의 연산자를 결과로 옮김 
					}
				}
				if (t==')') continue; // ')'는 stack에 넣지 않는다.
				stack.push(t);
			}
		}
		while(!stack.isEmpty()) { // stack에 남은 연산자 옮겨주기 
			result += stack.peek(); stack.pop();
		}
//		System.out.println(result);
		return result;
	}
	
	/*
	 *  후위표기식 계산하여 반환 
	 */
	public static int calculate(String s) {
		Stack<Integer> stack = new Stack<>(); // 숫자 저장
		int size = s.length();
		char t;
		int a, b;
		for (int i=0; i<size; i++) {
			t = s.charAt(i);
			if (t>='0' && t<='9') { // 숫자일 때 
				stack.add(Character.getNumericValue(t)); // 숫자로 변환해서 넣음 
			} else {
				// a-b || a*b 인데 stack에 a, b 순서로 들어갔기 때문에 반대로 꺼내준다.
				b = stack.peek(); stack.pop();
				a = stack.peek(); stack.pop();
				if (t == '*') {
					stack.push(a*b);
				} else if (t == '+') {
					stack.push(a+b);
				}
			}
		}
		
		return stack.peek();
	}
}
