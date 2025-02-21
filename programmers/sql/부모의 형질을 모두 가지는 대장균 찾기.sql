-- 부모의 형질을 모두 보유한 대장균의 ID(ID), 대장균의 형질(GENOTYPE), 
-- 부모 대장균의 형질(PARENT_GENOTYPE)을 출력하는 SQL 문을 작성해주세요.
-- 이때 결과는 ID에 대해 오름차순 정렬해주세요.
SELECT ed1.ID, ed1.GENOTYPE, ed2.GENOTYPE as PARENT_GENOTYPE
    FROM ECOLI_DATA ed1
    LEFT JOIN ECOLI_DATA ed2 ON ed1.PARENT_ID = ed2.ID
    WHERE ed1.GENOTYPE & ed2.GENOTYPE = ed2.GENOTYPE
    ORDER BY ed1.ID;