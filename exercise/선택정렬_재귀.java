package problemsolving;

/**
 * Slection sort 재귀 
 */
public class Solution3 {
	static final int [] arr = {6,4,5,8,2,7,3,1,10,9};
	static final int SIZE = 10;
	public static void main(String[] args) {
		sort();
		for (int i=0; i<SIZE; i++) {
			System.out.printf("%d ", arr[i]);
		}
	}
	
	public static int selection(int sIdx, int next) {
		if (arr[next] < arr[sIdx]) sIdx = next;
		
		if (next == SIZE-1) return sIdx;
		else return selection(sIdx, next+1);
	}
	
	public static void sort() {
		for (int i=0; i<SIZE-1; i++) {
			int idx = selection(i, i+1);
			swapByIndex(i, idx);
		}
	}
	
	public static void swapByIndex(int a, int b) {
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}
