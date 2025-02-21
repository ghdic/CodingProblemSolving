SELECT COUNT() as FISH_COUNT
FROM FISH_INFO
WHERE YEAR(TIME) = '2021'

-- DATE_FORMAT(시간데이터, "%Y-%m-%d") 시간->문자열 변환
-- STR_TO_DATE('20141201', '%Y%M%D')
-- split("1924/07/24", "/")[0] -- 한번에 잘라서 배열에 담음
-- SUBSTRING_INDEX(문자열, 구분자, 구분자의 index) -- 순차적으로 자름