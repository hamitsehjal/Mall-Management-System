create or replace PROCEDURE spPaymentsInsert(
EC OUT INTEGER,
PID IN PAYMENTS.PAYMENTID%type,
CID IN PAYMENTS.CUSTOMERID%type,
A IN PAYMENTS.AMOUNT%type,
PT IN PAYMENTS.PAYMENTTYPE%type,
PD IN PAYMENTS.PAYMENTDATE%type
)
AS
BEGIN
        INSERT INTO PAYMENTS(PAYMENTID,CUSTOMERID,AMOUNT,PAYMENTTYPE,PAYMENTDATE)
        VALUES (PID, CID,A,PT,PD);
        
        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spPaymentsInsert;
--=============================================================
create or replace PROCEDURE spPaymentsRead(
EC OUT INTEGER,
PID  IN PAYMENTS.PAYMENTID%type,
CID OUT PAYMENTS.CUSTOMERID%type,
A OUT PAYMENTS.AMOUNT%type,
PT OUT PAYMENTS.PAYMENTTYPE%type,
PD OUT PAYMENTS.PAYMENTDATE%type
)
AS
s_CID PAYMENTS.CUSTOMERID%type;
s_A  PAYMENTS.AMOUNT%type;
s_PT PAYMENTS.PAYMENTTYPE%type;
s_PD PAYMENTS.PAYMENTDATE%type;
BEGIN
        SELECT CUSTOMERID,AMOUNT,PAYMENTTYPE,PAYMENTDATE
        INTO s_CID,s_A ,s_PT,s_PD
        FROM PAYMENTS
        WHERE PAYMENTID = PID;  
    CID:=s_CID;
    A:=s_A;
    PT:=s_PT;
    PD:=s_PD;
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spPaymentsRead;


--===========================================================

create or replace PROCEDURE spPaymentsUpdate(
EC OUT INTEGER,
PID IN PAYMENTS.PAYMENTID%type,
CID IN PAYMENTS.CUSTOMERID%type,
A IN PAYMENTS.AMOUNT%type,
PT IN PAYMENTS.PAYMENTTYPE%type,
PD IN PAYMENTS.PAYMENTDATE%type
)
AS
BEGIN
    UPDATE PAYMENTS
    SET CUSTOMERID = CID, AMOUNT = A,PAYMENTTYPE=PT,PAYMENTDATE=PD
    WHERE PAYMENTID =PID;
    
    EC:=sql%rowcount;
    COMMIT;
    EXCEPTION 
        when others
        then EC:=-1;
END spPaymentsUpdate;



--===========================================================

create or replace PROCEDURE spPaymentsDelete(
EC OUT INTEGER,
PID IN PAYMENTS.PAYMENTID%type
)
AS
BEGIN
    DELETE FROM PAYMENTS
    WHERE
    PAYMENTID = PID;
        
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spPaymentsDelete;