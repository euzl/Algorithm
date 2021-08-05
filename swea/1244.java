package problemsolving;

import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{	
	static int changeCnt=0;
	static int cnt=0;

	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		String numStr;
		for(int test_case = 1; test_case <= T; test_case++)
		{	
			changeCnt = 0;
			numStr = sc.next();
			cnt = sc.nextInt();
			int [] num = new int[6];
			for (int i=0; i<numStr.length(); i++) {
				num[i] = numStr.charAt(i) - '0';
			}
				
			change(num, 0, numStr.length());
			System.out.printf("#%d ", test_case);
			for (int i=0; i<numStr.length(); i++) System.out.print(num[i]);
			
			System.out.println();
		}
	}
	
	public static void change(int [] num, int start, int end) {
		int lidx = end-1, sidx=-1;
		int max = -1;
		
		for (int i=end-1; i>=start; i--) {
			if (num[i] > max) {
				lidx=i;
				max=num[i];
			}
		}
		
		int min = max;
		
		for (int i=start; i<lidx; i++ ) {
			if (num[i] < max) {
				sidx = i;
				min=num[i];
				break;
			}
		}
				
		if (sidx > -1) {
			// 작은 수가 가장 큰 수보다 앞에 있는 경우
			num[lidx] = min;
			num[sidx] = max;
			changeCnt++;
			if (sidx>0 && num[sidx]==num[sidx-1]) changeCnt--;
			
			if (changeCnt == cnt) return;
			
			change(num, sidx+1, end);
		} else if (lidx == end-1) {
			// 정렬이 이미 완료된 경우
			// case 1: 중복되는 수가 있는 경우 바로 끝
			for (int i=1; i<end; i++) {
				if (num[i] == num[i-1]) return;
			}
			
			// case 2: 남은 횟수만큼 맨 뒤에 두 자리 바꿔주기 
			while (changeCnt < cnt) {
				int temp = num[lidx];
				num[lidx] = num[lidx-1];
				num[lidx-1] = temp;
				changeCnt++;
			}
		} else {
			// 가장 큰 수가 작은 수보다 앞에 있는 경우 
			change(num, lidx+1, end);
		}
	}
}
