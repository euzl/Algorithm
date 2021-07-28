import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/test_input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = 10;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int t=sc.nextInt();
			String find = sc.next();
			String target = sc.next();
			int targetSize = target.length();
			int count=0;
			ArrayList<Integer> targetIdx = new ArrayList<>();
			
			// 첫 단어가 일치할 때 인덱스 저장 
			for (int i=0; i<targetSize; i++) {
				if (target.charAt(i) == find.charAt(0)) targetIdx.add(i);
			}
			
			//위에서 찾은 인덱스를 기준으로 문자열이 일치하는지 체크 
			int findSize = find.length();
			for (int i : targetIdx) {
				for (int j=0; j<findSize; j++) {
					if (i+j >= targetSize) break;
					if (target.charAt(i+j) != find.charAt(j)) break;
					if (j==findSize-1) ++count;
				}
			}

			System.out.printf("#%d %d\n", test_case, count);
		}
	}
}
