-- 코드를 입력하세요
SELECT d.DR_NAME, d.DR_ID, d.MCDP_CD, DATE_FORMAT(d.HIRE_YMD, '%Y-%m-%d')
from DOCTOR d
where d.mcdp_cd in ('CS', 'GS')
ORDER BY d.hire_ymd desc, d.dr_name