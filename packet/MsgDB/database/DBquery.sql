-- 유저 추가
INSERT INTO PersonalInfo values ('user_name', 'user_id', 'user_passwd');

-- id를 통한 유저 정보 조회
SELECT name, id, passwd
FROM PersonalInfo
where id = 'user_id';

-- 유저 리스트 조회
SELECT id
FROM PersonalInfo;

-- 메세지 추가
INSERT INTO Msg values ('id', 'opp_id', 'text_msg', 'timestamp');

-- 두 사람의 통신 기록 출력
SELECT id, opp_id, text_msg
FROM Msg
where (id = 'id' and opp_id = 'opp_id')
      or (id = 'opp_id' and opp_id = 'id')
ORDER BY msg_time;