-- 코드를 입력하세요
SELECT FW.WAREHOUSE_ID, FW.WAREHOUSE_NAME, FW.ADDRESS, COALESCE(FW.FREEZER_YN, 'N')
FROM FOOD_WAREHOUSE AS FW
WHERE FW.WAREHOUSE_NAME LIKE '%경기%'
ORDER BY FW.WAREHOUSE_ID
;