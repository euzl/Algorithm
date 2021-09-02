//package problemsolving; // 제출시 주석 

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
	static int size;
	public static void main(String args[]) throws Exception
	{
		//System.setIn(new FileInputStream("res/input (3).txt")); // 제출시 주석처리 


		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int K;
		String str;
		String [] SA; // Suffix Array 
		int [] LCP; // 접두어가 이전과 다르기 시작하는 index 
		for(int test_case = 1; test_case <= T; test_case++)
		{
			K = sc.nextInt();
			str = sc.next();
			size = str.length();
			SA = new String[size];
			LCP = new int[size];

			makeSA(SA, str);
			String result = makeLCP(LCP, SA, K);
			
			if (result.equals("")) {
				System.out.println("#"+test_case +" none");
			} else {
				System.out.println("#"+test_case +" " + result);
			}
			
		}
	}
	
	public static void makeSA(String [] SA, String str) {
		for (int i=0; i<size; i++) {
			SA[i] = str.substring(i, size);
		}
		Arrays.sort(SA); // 정렬 
	}
	
	public static String makeLCP(int [] LCP, String [] SA, int K) {
		int cnt = 0; // 누적개수 

		LCP[0] = 0;
		for (int i=0; i<size; i++) {
			if (i>0) {
				int length = Math.min(SA[i].length(), SA[i-1].length());
				for (int j=0; j<length; j++) {
					if (SA[i].charAt(j) == SA[i-1].charAt(j)) {
						LCP[i]++;
					} else {
						break;
					}
				}
			}
			cnt += SA[i].length() - LCP[i]; // 현재까지 정렬된 개수
//			System.out.println(cnt + " " + SA[i]);
			if (cnt >= K) {
				int end = SA[i].length()-(cnt-K);
//				System.out.println(SA[i].length()+" "+cnt +" "+K);
				return SA[i].substring(0, end);
			}
		}
		return ""; // K번째 문자열이 존재하지 않는다.
	}
	

}
