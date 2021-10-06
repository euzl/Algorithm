import java.util.*;

class Solution {
    final int MULTI = 65536; // 결과에 곱할 수 
    HashSet<String> set = new HashSet<>(); // 여태 나왔던 문자 쌍 저장
    public int solution(String str1, String str2) {
        HashMap<String, Integer> map1 = new HashMap<>();
        HashMap<String, Integer> map2 = new HashMap<>();
        
        setMap(map1, str1);
        setMap(map2, str2);
        
        return getJacard(map1, map2);
    }
    
  // str1과 str2에 대해 map에 세팅
    public void setMap(HashMap<String, Integer> map, String str) {
        str = str.toUpperCase(); // 대,소문자 구분X
        int size = str.length();
        String temp;
        for (int i=0; i<size-1; i++) {
            if (str.charAt(i) < 'A' || str.charAt(i) > 'Z') continue;
            if (str.charAt(i+1) < 'A' || str.charAt(i+1) > 'Z') {
                i++;
                continue;
            }
            
            temp = String.valueOf(str.charAt(i))+String.valueOf(str.charAt(i+1));
            set.add(temp); // 나왔던 글자 쌍 저장 
            
            if (map.containsKey(temp)) map.put(temp, map.get(temp) + 1);
            else map.put(temp, 1);
        }
    }
    
  // 자카드 유사도 구하기
    public int getJacard(HashMap<String, Integer> map1, HashMap<String, Integer> map2) {
        if (set.isEmpty()) return MULTI;
        int minSet = 0;
        int maxSet = 0;
        int cnt1, cnt2;
        for (String key : set) {
            cnt1 = 0; cnt2 = 0;
            if (map1.containsKey(key)) cnt1 = map1.get(key);
            if (map2.containsKey(key)) cnt2 = map2.get(key);
            
            maxSet += Math.max(cnt1, cnt2);
            minSet += Math.min(cnt1, cnt2);
        }
        return minSet*MULTI/maxSet;
    }
}
