package problemsolving; // 제출시 주석 

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

import java.io.FileInputStream;


class Solution
{		
	static int N;
	static int [] s = new int [100];
	static int [] e = new int [100];
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input (5).txt")); // 제출시 주석처리 


		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		int cnt;
		int a, b;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			init();

			cnt = 1;
			N = sc.nextInt();
			int start = 0, end = 0;
			for (int i=0; i<N; i++) {
				a = sc.nextInt();
				b = sc.nextInt();
				e[a] = b; // a의 끝은 b 
				s[b] = a; // b의 시작은 a
				
				if (start == 0) {
					start = a;
					end = b;
				}
			}
			
			// 나사 연결 
			while(true) {
				if (s[start] != 0) { // 앞에 연결 
					cnt++;
					start = s[start];
				} else if (e[end] != 0) { // 뒤에 연결 
					cnt++;
					end = e[end];
				} else {
					break;
				}
			}
			System.out.print("#" + test_case);
			
			for (int i=0; i<cnt; i++) {
				System.out.printf(" %d", start);
				System.out.printf(" %d", e[start]);
				start = e[start];
			}
			System.out.println();
		}
	}
	
	public static void init() {
		for (int i=0; i<100; i++) {
			s[i] = 0;
			e[i] = 0;
		}
	}
}
