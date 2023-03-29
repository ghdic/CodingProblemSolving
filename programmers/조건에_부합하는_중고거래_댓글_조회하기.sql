select board.TITLE, reply.BOARD_ID, reply.REPLY_ID, reply.WRITER_ID, reply.CONTENTS, date_format(reply.CREATED_DATE, "%Y-%m-%d") as CREATED_DATE
from USED_GOODS_BOARD board, USED_GOODS_REPLY reply
where board.BOARD_ID = reply.BOARD_ID and DATE_FORMAT(board.CREATED_DATE, "%Y-%m") = '2022-10'
order by reply.CREATED_DATE, board.TITLE