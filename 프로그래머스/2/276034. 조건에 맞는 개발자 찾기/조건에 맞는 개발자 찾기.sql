-- 코드를 작성해주세요
SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
WHERE SKILL_CODE & (SELECT SUM(S.CODE)
                     FROM SKILLCODES S
                     WHERE S.NAME IN ('Python','C#')
                     )
ORDER BY ID