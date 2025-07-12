import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int frameSize = sc.nextInt(); // 사진틀 개수
        int k = sc.nextInt();         // 총 추천 수
        int[] recommend = new int[k];
        for (int i = 0; i < k; i++) recommend[i] = sc.nextInt();

        List<Integer> frame = new ArrayList<>();
        int[] recCount = new int[101]; // 추천 횟수 저장용

        for (int i = 0; i < k; i++) {
            int student = recommend[i];

            if (frame.contains(student)) {
                recCount[student]++;
                continue;
            }

            if (frame.size() < frameSize) {
                frame.add(student);
                recCount[student] = 1;
            } else {
                // 가장 추천 수 낮고 먼저 들어온 학생 찾기
                int minCount = Integer.MAX_VALUE;
                int toRemove = -1;
                for (int s : frame) {
                    if (recCount[s] < minCount) {
                        minCount = recCount[s];
                        toRemove = s;
                    }
                }
                frame.remove(Integer.valueOf(toRemove));
                recCount[toRemove] = 0;

                frame.add(student);
                recCount[student] = 1;
            }
        }

        Collections.sort(frame);
        for (int s : frame) {
            System.out.print(s + " ");
        }
    }
}
