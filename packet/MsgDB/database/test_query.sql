-- 외래키 활성화
PRAGMA foreign_keys = 1;

-- 유저 3명 추가
INSERT INTO PersonalInfo values ('minwoo', 'qwer1', '1');
INSERT INTO PersonalInfo values ('minwoo2', 'qwer2', '12');
INSERT INTO PersonalInfo values ('minwoo3', 'qwer3', '123');

-- 유저 목록 조회
SELECT id
FROM PersonalInfo;

-- minwoo2 유저 정보 조회
SELECT name, id, passwd
FROM PersonalInfo
where id = 'qwer2';

-- 메세지 추가
INSERT INTO Msg values ('qwer1', 'qwer3', 'hi1', '2005-7-27 09:00:30.75');
INSERT INTO Msg values ('qwer3', 'qwer1', 'hi2', '2005-7-28 09:00:30.75');
INSERT INTO Msg values ('qwer1', 'qwer3', 'hi3', '2005-7-28 09:01:30.75');
INSERT INTO Msg values ('qwer1', 'qwer3', 'hi4', '2005-7-28 09:02:30.75');
INSERT INTO Msg values ('qwer1', 'qwer3', 'hi5', '2005-7-28 09:03:30.75');

-- 두 사람의 통신 기록 출력
SELECT id, opp_id, text_msg
FROM Msg
where (id = 'qwer1' and opp_id = 'qwer3')
      or (id = 'qwer3' and opp_id = 'qwer1')
ORDER BY msg_time;

-- 외래키 제약조건 확인
INSERT INTO Msg values ('qwer4', 'qwer3', 'hi2', '2005-7-28 09:00:30.75');
INSERT INTO Msg values ('qwer3', 'qwer5', 'hi2', '2005-7-28 09:00:30.75');

-- 테스트 테이블 초기화
delete from Msg;
delete from PersonalInfo;