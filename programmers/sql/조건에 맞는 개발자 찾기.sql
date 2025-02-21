
SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS dev
WHERE dev.SKILL_CODE
    & (
        SELECT SUM(CODE) -- SUM쓰는건 좀히트네
        FROM SKILLCODES sc
        WHERE NAME in ("Python", "C#")
    )
ORDER BY dev.ID ASC;