
import java.util.ArrayList;
import java.util.Scanner;

import java.io.FileInputStream;


class Solution
{		
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		
		int [] price = new int[4]; // 1day 1month 3month 1year
		int [] plan = new int[13];
		int [] dp = new int[13]; // 최소요금 저장 

		for(int test_case = 1; test_case <= T; test_case++)
		{
			for (int i=0; i<4; i++) price[i] = sc.nextInt();
			for (int i=1; i<=12; i++) plan[i] = sc.nextInt();
			
			int min = price[3];
			

			int temp;
			for (int i=1; i<=12; i++) {
				if (i<3) {
					dp[i] = dp[i-1] + Math.min(plan[i]*price[0], price[1]);
				} else {
					dp[i] = Math.min(dp[i-1]+Math.min(plan[i]*price[0], price[1]), dp[i-3]+price[2]);
					
					if (i>9) {
						temp = dp[i];
						for (int j=i+1; j<13; j++) {
							temp += dp[j];
						}
						min = Math.min(min, temp);
					}
				}
			}
			System.out.printf("#%d %d\n", test_case, min);
		}
	}
}
