-- 코드를 작성해주세요
-- 1. 평가정보에서 2022년 상반기 점수가장 큰 점수인 사원들의 사번, 점수 추출한 테이블과  
-- 2. 사원 정보 조인해서  
-- 3. 점수, 사번, 성명 직책, 이메일 출력
-- 4. 가장 높은 점수의 사원이 여러명일 경우는?
SELECT SUM(SCORE) AS SCORE, HE.EMP_NO, HE.EMP_NAME, HE.POSITION, HE.EMAIL
FROM HR_EMPLOYEES AS HE
JOIN HR_GRADE AS HG
ON HE.EMP_NO = HG.EMP_NO
GROUP BY HE.EMP_NO, YEAR
HAVING YEAR = 2022
ORDER BY SCORE DESC 
LIMIT 1;
