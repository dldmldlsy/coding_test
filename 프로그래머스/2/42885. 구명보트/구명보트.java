import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        Arrays.sort(people); // 몸무게 오름차순 정렬
        int left = 0;
        int right = people.length - 1;
        int boats = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                // 둘이 같이 타기
                left++;
                right--;
            } else {
                // 무거운 사람 혼자 타기
                right--;
            }
            boats++; // 보트 1대 사용
        }

        return boats;
    }
}
