-- 부서별 평균 연봉 조회: 부서번호, 영문 부서명, 평균 영문(소수점 첫째에서 반올림), 평균연봉 기준 내림차순 정렬
-- 부서테이블 + 사원 테이블 join -> 부서로 그룹화해서 평균 연봉 계산 후 출력

SELECT HD.DEPT_ID, DEPT_NAME_EN, ROUND(AVG(HE.SAL)) AS AVG_SAL
FROM HR_DEPARTMENT AS HD
JOIN HR_EMPLOYEES AS HE 
ON HD.DEPT_ID = HE.DEPT_ID
GROUP BY HD.DEPT_ID
ORDER BY AVG_SAL DESC