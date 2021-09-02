import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

import java.io.FileInputStream;

class Solution
{
	static int [] table = new int[12];
	static String [] num = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
	public static void main(String args[]) throws Exception
	{

		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int N;
		String tc;
		String input;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			for (int i=0; i<12; i++) table[i] = 0;
			tc = sc.next();
			N = sc.nextInt();
			
			for (int i=0; i<N; i++) {
				input = sc.next();
				table[getHash(input)]++;
			}
			
			System.out.println("#"+test_case);
			
			int cnt;
			for (int i=0; i<10; i++) {
				cnt = table[getHash(num[i])];
				for (int j=0; j<cnt; j++) {
					System.out.print(num[i] + " ");
				}
			}
			System.out.println();
		}
	}
	
	public static int getHash(String num) {
		int answer = 0;
		for (int i=0; i<3; i++) {
			answer += num.charAt(i)*(3-i);
		}
		return answer%13;
	}
}
