create or replace PROCEDURE spSaleDetailsInsert(
EC OUT INTEGER,
DI IN SALEDETAILS.DETAILID%type,
SAI IN SALEDETAILS.SALESID%type,
PID IN SALEDETAILS.PRODUCTID%type,
QO IN SALEDETAILS.QUANTITYORDER%type,
PE IN SALEDETAILS.PRICEEACH%type
)
AS
BEGIN
        INSERT INTO SALEDETAILS(detailid,salesid,productid,quantityorder,priceeach)
        VALUES (DI,SAI,PID,QO,PE);
               
        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSaleDetailsInsert;
--===========================================================

create or replace PROCEDURE spSaleDetailsRead(
EC OUT INTEGER,
DI IN SALEDETAILS.DETAILID%type,
SAI OUT SALEDETAILS.SALESID%type,
PID OUT SALEDETAILS.PRODUCTID%type,
QO OUT SALEDETAILS.QUANTITYORDER%type,
PE OUT SALEDETAILS.PRICEEACH%type
)
AS
s_SAI SALEDETAILS.SALESID%type;
s_PID SALEDETAILS.PRODUCTID%type;
s_QO SALEDETAILS.QUANTITYORDER%type;
s_PE SALEDETAILS.PRICEEACH%type;

BEGIN

       SELECT   SALESID,PRODUCTID,QUANTITYORDER,PRICEEACH
        INTO       s_SAI,s_PID,    s_QO,               s_PE
        FROM SALEDETAILS
        WHERE detailid=DI;
    SAI:=s_SAI;
    PID:=s_PID;
    QO:=s_QO;
    PE:=s_PE;
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSaleDetailsRead;

--===========================================================

create or replace PROCEDURE spSaleDetailsUpdate(
EC OUT INTEGER,
DI IN SALEDETAILS.DETAILID%type,
SAI IN SALEDETAILS.SALESID%type,
PID IN SALEDETAILS.PRODUCTID%type,
QO IN SALEDETAILS.QUANTITYORDER%type,
PE IN SALEDETAILS.PRICEEACH%type
)
AS
BEGIN
    UPDATE SALEDETAILS
        SET SALESID=SAI,
            PRODUCTID = PID, 
            QUANTITYORDER =QO,
            PRICEEACH = PE
        WHERE detailid=DI;
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSaleDetailsUpdate;


--===========================================================

create or replace PROCEDURE spSaleDetailsDelete(
EC OUT INTEGER,
DI IN SALEDETAILS.DETAILID%type
)
AS
BEGIN

    DELETE FROM SALEDETAILS
    WHERE DETAILID = DI;
    
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSaleDetailsDelete;
--===========================================================

