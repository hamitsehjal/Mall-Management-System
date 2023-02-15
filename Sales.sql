create or replace PROCEDURE spSalesInsert(
EC OUT INTEGER,
SAI IN sales.SALESID%type,
STI IN sales.STOREID%type,
CN IN sales.CUSTOMERID%type,
D IN sales.PURCHASEDATE%type
)
AS
BEGIN

        INSERT INTO sales(salesid,storeid,customerid,purchasedate)
        VALUES (SAI, STI,CN,D);

        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSalesInsert;

create or replace PROCEDURE spSalesRead(
EC OUT INTEGER,
SAI IN sales.SALESID%type,
STI OUT sales.STOREID%type,
CI OUT sales.CUSTOMERID%type,
D OUT sales.PURCHASEDATE%type
)
AS
s_STI  sales.STOREID%type;
s_CI sales.CUSTOMERID%type;
s_D  sales.PURCHASEDATE%type;
BEGIN

    SELECT STOREID,CUSTOMERID,PURCHASEDATE
    INTO s_STI,s_CI,s_D
	FROM Sales
	WHERE salesid = SAI;  
 
    STI:=s_STI;
    CI:=s_CI;
    D:=s_D;

    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSalesRead;



create or replace PROCEDURE spSalesUpdate(
EC OUT INTEGER,
SAI IN sales.SALESID%type,
STI IN sales.STOREID%type,
CI IN sales.CUSTOMERID%type,
D IN sales.PURCHASEDATE%type
)
AS
BEGIN
    UPDATE Sales
    SET STOREID = STI, CUSTOMERID = CI, PURCHASEDATE = D
    WHERE SALESID =SAI;
EC:=sql%rowcount;
COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSalesUpdate;




create or replace PROCEDURE spSalesDelete(
EC OUT INTEGER,
SI IN Sales.SalesID%type
)
AS
BEGIN

    DELETE FROM Sales
    WHERE SalesID = SI;
        
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spSalesDelete;













