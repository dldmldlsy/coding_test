-- 코드를 작성해주세요
SELECT FI.ID, FNI.FISH_NAME, FI.LENGTH
FROM FISH_INFO AS FI
JOIN FISH_NAME_INFO AS FNI
ON FI.FISH_TYPE = FNI.FISH_TYPE
WHERE (FI.FISH_TYPE, FI.LENGTH) IN (
                    SELECT FI.FISH_TYPE, MAX(FI.LENGTH)
                    FROM FISH_INFO AS FI
                    GROUP BY FI.FISH_TYPE
                  )
ORDER BY FI.ID