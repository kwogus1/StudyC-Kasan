-- SQL (Structured Query Language)
/* 주석인건가? */

-- 1. SELECT 쿼리 (조회)
-- 기본 쿼리
SELECT *
	from contact;
   
-- 기본 쿼리(위와 같음)
SELECT Id, name, phonenum, email, addr
FROM ems.contact;
    
-- 데이커가 몇개 조회쿼리
SELECT COUNT(*)
FROM contact;

-- 데이터를 원하는 컬럼만 조회
SELECT name, phonenum, email
FROM contact;

-- 원하는 결과만 조회
SELECT *
FROM contact
WHERE id = 2; -- PK 조회가 일반적

--
SELECT *
FROM contact
WHERE name = '홍길동'; -- DB에서는 같은지 비교 =

-- 2. INSERT 쿼리
INSERT INTO contact
(name, phonenum, email, addr) 
VALUES
('홍길순', '010-1111-8888', 'hds@daum.net', '횡성');

-- NULL값 제외
INSERT INTO contact
(name) VALUES ('손흥민'); -- 데이터 입력불가
-- 컬럼값이 NOT NULL인 것은 모두 입력되어야 함
INSERT INTO contact
(name, phonenum) VALUES ('손흥민', '010-7878-9090');

-- 컬럼이 4개인데 4개다 데이터를 넣겠다고 하면
INSERT INTO contact 
(name, phonenum, email, addr)
VALUES
('이동욱', '010-6868-5656', 'Idw@gamil.com', '서울');

-- 3. UPDATE 쿼리 (데이터 수정)
-- 홍길동 id = 1. phonenum = 010-0000-9999 --> 010-7777-6648
UPDATE contact SET
phonenum = '010-7777-6648'
WHERE id = 1;

 -- 컬럼이 1개이상 변경
 UPDATE contact SET
 phonenum = '010-2222-3333', -- 쉼표 필수
 email = 'gdhong@yahoo.com'
 WHERE id = 1; -- where절 없으면 절대안됨
 
-- 4. DELETE 삭제쿼리
DELETE FROM contact
WHERE id = 4; -- where절 없으면 절대안됨