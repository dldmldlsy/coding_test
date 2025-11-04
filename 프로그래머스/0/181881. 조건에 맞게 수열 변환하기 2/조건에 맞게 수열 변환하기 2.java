import java.util.Arrays;

class Solution {
    public int solution(int[] arr) {

        int copyarr[] = new int[arr.length];
        int count = 0;
        int result = 0;

      while(true){

          copyarr = arr.clone(); // 연산 수행전 이전 결과로 나온 배열을 복사해둠
          ++count;

          for(int i = 0; i < arr.length; ++i){ // 배열의 크기만큼 반복

              if(arr[i] >= 50 && (arr[i]%2 == 0)){ // 50보다 크거나 같은 짝수라면
                arr[i] = arr[i] / 2; //2로 나누고
            }
            else if(arr[i] < 50 && (arr[i]%2 == 1)){ // 50보다 작은 홀수라면 
                arr[i] = 2*arr[i] + 1; // 2를 곱하고 다시 1을 더합니다.
            }

        } //for문 종료

          if(Arrays.equals(copyarr, arr)){ // 이전 배열과 현재 배열의 내용이 같은지 비교
             result = count - 1;
             break;
          }

      } //while문 종료 

        return result;

    }
}