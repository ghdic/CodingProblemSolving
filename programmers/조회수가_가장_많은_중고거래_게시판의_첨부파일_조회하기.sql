SELECT concat("/home/grep/src/", file.BOARD_ID, "/", file.FILE_ID, file.FILE_NAME, file.FILE_EXT) as FILE_PATH
FROM USED_GOODS_FILE file
where file.BOARD_ID = (SELECT BOARD_ID 
                       FROM USED_GOODS_BOARD
                      WHERE VIEWS = (SELECT max(VIEWS) FROM USED_GOODS_BOARD))
ORDER BY file.FILE_ID desc;