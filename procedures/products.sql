create or replace PROCEDURE spProductsInsert(
EC OUT INTEGER,
PC IN products.PRODUCTCODE%type,
PN IN products.PRODUCTNAME%type,
PD IN products.PRODUCTDESCRIPTION%type,
QIS IN products.QUANTITYINSTOCK%type,
BP IN products.BUYPRICE%type,
MP IN products.MARKETPRICE%type,
SI IN products.STOREID%type )
AS
BEGIN
        INSERT INTO products(productcode,productname,productdescription,quantityinstock,buyprice,marketprice,storeid)
        VALUES (PC,PN,PD,QIS,BP,MP,SI);
        
        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spProductsInsert;



create or replace PROCEDURE spProductsRead(
EC OUT INTEGER,
PC IN products.PRODUCTCODE%type,
PN OUT products.PRODUCTNAME%type,
PD OUT products.PRODUCTDESCRIPTION%type,
QIS OUT products.QUANTITYINSTOCK%type,
BP OUT products.BUYPRICE%type,
MP OUT products.MARKETPRICE%type,
SI OUT products.STOREID%type 
)
AS
sPN products.PRODUCTNAME%type;      sPD products.PRODUCTDESCRIPTION%type;
sQIS products.QUANTITYINSTOCK%type; sBP products.BUYPRICE%type;
sMP  products.MARKETPRICE%type;     sSI products.STOREID%type ;
BEGIN
       SELECT   PRODUCTNAME,        PRODUCTDESCRIPTION,
                QUANTITYINSTOCK,    BUYPRICE,
                MARKETPRICE,        STOREID
       INTO     sPN ,                sPD ,
                sQIS ,               sBP ,
                sMP ,                sSI 
	FROM products
	WHERE productcode=PC;

                PN:=sPN;            PD:=sPD;
                QIS:=sQIS;          BP:=sBP;
                MP:=sMP;            SI:=sSI;
                EC:=sql%rowcount;
                COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spProductsRead;







create or replace PROCEDURE spProductsUpdate(
EC OUT INTEGER,
PC IN products.PRODUCTCODE%type,
PN IN products.PRODUCTNAME%type,
PD IN products.PRODUCTDESCRIPTION%type,
QIS IN products.QUANTITYINSTOCK%type,
BP IN products.BUYPRICE%type,
MP IN products.MARKETPRICE%type,
SI IN products.STOREID%type )
AS
BEGIN
        UPDATE products
        SET productname=PN,
            productdescription=PD,
            quantityinstock=QIS,
            buyprice=BP,
            marketprice=MP,
            storeid=SI
        WHERE productcode=PC;
        
        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spProductsUpdate;








create or replace PROCEDURE spProductsDelete(
EC OUT INTEGER,
PC IN Products.productcode%type
)
AS
BEGIN
    DELETE FROM Products
    WHERE ProductCode = PC;
            
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spProductsDelete;







