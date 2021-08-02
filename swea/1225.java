import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (16).txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int t = sc.nextInt();
			Queue<Integer> queue = new LinkedList<>();
			int temp;
			for (int i=0; i<8; i++) {
				temp = sc.nextInt();
				queue.offer(temp);
			}
			
			int i=1;
			while(true) {
				
				temp = queue.poll();
				temp -= i;
				if (temp <= 0) break;
				
				queue.offer(temp);
				
				i++;
				if (i>5) i=1;
			}
			queue.offer(0);
		
			System.out.printf("#%d", test_case);
			for (i=0; i<8; i++) {
				System.out.printf(" %d", queue.poll());
			}
			System.out.println();
		}
	}
}
