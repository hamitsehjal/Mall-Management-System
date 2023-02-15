


--STORES TABLE

create or replace PROCEDURE spStoreInsert(
err_Code OUT INTEGER,
m_storeid IN stores.storeid%type,
m_name IN stores.storename%type,
m_phone IN stores.phone%type DEFAULT NULL,
m_email IN stores.email%type DEFAULT NULL,
m_location IN stores.store_location%type
) AS
BEGIN
    INSERT INTO stores(storeid,storename,phone,email,store_location)
    VALUES (m_storeid,m_name,m_phone,m_email,m_location);

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spStoreInsert;
--=======================================
SET SERVEROUTPUT ON;
DECLARE
    err_Code INTEGER;
BEGIN
    spStoreInsert(err_Code,100621,'LifeWear','+1 945 366 1234','Life@gmail.com','West Wing');
END;

--=======================================
create or replace PROCEDURE spStoreUpdate(
err_Code OUT INTEGER,
m_storeid IN stores.storeid%type,
m_name IN stores.storename%type,
m_phone IN stores.phone%type,
m_email IN stores.email%type,
m_location IN stores.store_location%type
) AS
BEGIN
    UPDATE stores
        SET storeid=m_storeid,
            storename=m_name,
            phone=m_phone,
            email=m_email,
            store_location=m_location
        WHERE storeid=m_storeid;

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spStoreUpdate;
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spStoreUpdate(err_Code,100621,'Life Gear','+1 945 366 1234','LifeGear@gmail.com','East Wing');
END;
--=======================================
create or replace PROCEDURE spStoreDelete(
err_Code OUT INTEGER,
m_storeid IN stores.storeid%type
) AS
BEGIN
    DELETE FROM stores
    WHERE storeid=m_storeid;

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spStoreDelete;
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spStoreDelete(err_Code,100621);
END;
--=======================================
create or replace PROCEDURE spStoreSelect(
err_Code OUT INTEGER,
m_storeid IN stores.storeid%type,
m_name OUT stores.storename%type,
m_phone OUT stores.phone%type,
m_email OUT stores.email%type,
m_location OUT stores.store_location%type) AS

s_storeid stores.storeid%type;
s_name  stores.storename%type;
s_phone stores.phone%type;
s_email  stores.email%type;
s_location  stores.store_location%type;

BEGIN
    SELECT storename,phone,email,store_location
    INTO s_name,s_phone,s_email,s_location
    FROM stores
    WHERE storeid=m_storeid;

    err_code:=SQL%ROWCOUNT;
    m_name:=s_name;
    m_phone:=s_phone;
    m_email:=s_email;
    m_location:=s_location;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spStoreSelect;
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spStoreSelect(err_Code,100621);
END;

--=======================================



















--EMPLOYEES table

create or replace PROCEDURE spEmployeeInsert(
err_Code OUT INTEGER,
m_employeenumber IN employees.employeenumber%type,
m_lName IN employees.lastname%type,
m_fName IN employees.firstname%type,
m_extension IN employees.extension%type,
m_email IN employees.email%type,
m_storeid IN employees.storeid%type DEFAULT NULL,
m_reportsto IN employees.reportsto%type,
m_title IN employees.jobtitle%type
) AS
BEGIN
    INSERT INTO employees(employeenumber,lastname,firstname,extension,email,storeid,reportsto,jobtitle)
    VALUES (m_employeenumber,m_lName,m_fName,m_extension,m_email,m_storeid,m_reportsto,m_title);

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spEmployeeInsert;

--=======================================

DECLARE
    err_Code INTEGER;
BEGIN
    spEmployeeInsert(err_Code,1033,'Thomas','Arnold','x9333','AroTho@classicmodelcars.com',124578,1166,'Sales Rep');
END;

--=======================================


create or replace PROCEDURE spEmployeeUpdate(
err_Code OUT INTEGER,
m_employeenumber IN employees.employeenumber%type,
m_lName IN employees.lastname%type,
m_fName IN employees.firstname%type,
m_extension IN employees.extension%type,
m_email IN employees.email%type,
m_storeid IN employees.storeid%type DEFAULT NULL,
m_reportsto IN employees.reportsto%type,
m_title IN employees.jobtitle%type
) AS
BEGIN
    UPDATE employees
        SET lastname=m_lName,
            firstname=m_fName,
            extension=m_extension,email=m_email,
            storeid=m_storeid,
            reportsto=m_reportsto,
            jobtitle=m_title
        WHERE employeenumber=m_employeenumber;

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spEmployeeUpdate;
--=======================================

DECLARE
    err_Code INTEGER;
BEGIN
    spEmployeeUpdate(err_Code,1033,'Thomas','Arnold','x9333','Arnold@classicmodelcars.com',124578,1166,'Sales Manager');

--=======================================

create or replace PROCEDURE spEmployeeDelete(
err_Code OUT INTEGER,
m_employeenumber IN employees.employeenumber%type
) AS
BEGIN
    DELETE FROM employees
    WHERE employeenumber=m_employeenumber;

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spEmployeeDelete;
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spEmployeeUpdate(err_Code,1033,'Thomas','Arnold','x9333','Arnold@classicmodelcars.com',124578,1166,'Sales Manager');
END;

--=======================================


create or replace PROCEDURE spEmployeeSelect(
err_Code OUT INTEGER,
m_employeenumber IN employees.employeenumber%type,
m_lName OUT employees.lastname%type,
m_fName OUT employees.firstname%type,
m_extension OUT employees.extension%type,
m_email OUT employees.email%type,
m_storeid OUT employees.storeid%type ,
m_reportsto OUT employees.reportsto%type,
m_title OUT employees.jobtitle%type) AS

s_lName employees.lastname%type;
s_fName employees.firstname%type;
s_extension employees.extension%type;
s_email employees.email%type;
s_storeid employees.storeid%type;
s_reportsto employees.reportsto%type;
s_title employees.jobtitle%type;

BEGIN
    SELECT lastname,firstname,extension,email,storeid,reportsto,jobtitle
    INTO s_lName,s_fName,s_extension,s_email,s_storeid,s_reportsto,s_title
    FROM employees
    WHERE employeenumber=m_employeenumber;

    err_code:=SQL%ROWCOUNT;
    m_lName:=s_lName;
    m_fName:=s_fName;
    m_extension:=s_extension;
    m_email:=s_email;
    m_storeid:=s_storeid;
    m_reportsto:=s_reportsto;
    m_title:=s_title;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spEmployeeSelect;
--=======================================
DECLARE
    err_Code INTEGER;
    m_lName employees.lastname%type;
    m_fName employees.firstname%type;
    m_extension employees.extension%type;
    m_email employees.email%type;
    m_storeid employees.storeid%type;
    m_reportsto employees.reportsto%type;
    m_title employees.jobtitle%type;
BEGIN
    spEmployeeSelect(err_Code,1033,m_lName,m_fName,m_extension,m_email,m_storeid,m_reportsto,m_title);
END;

--=======================================
DECLARE
    err_Code INTEGER;
    m_lName employees.lastname%type;
    m_fName employees.firstname%type;
    m_extension employees.extension%type;
    m_email employees.email%type;
    m_storeid employees.storeid%type;
    m_reportsto employees.reportsto%type;
    m_title employees.jobtitle%type;
BEGIN
    spEmployeeSelect(err_Code,1033,m_lName,m_fName,m_extension,m_email,m_storeid,m_reportsto,m_title);
END;

--=======================================





















--CUSTOMERS table

create or replace PROCEDURE spCustomerInsert(
err_Code OUT INTEGER,
m_customernumber IN customers.customernumber%type,
m_lName IN customers.contactlastname%type,
m_fName IN customers.contactfirstname%type,
m_phone IN customers.phone%type,
m_add1 IN customers.addressline1%type,
m_add2 IN customers.addressline2%type DEFAULT NULL,
m_city IN customers.city%type,
m_state IN customers.c_state%type DEFAULT NULL,
m_postal IN customers.postalcode%type DEFAULT NULL,
m_country IN customers.country%type,
m_employeeid IN customers.salesrepemployeenumber%type DEFAULT NULL
) AS
BEGIN
    INSERT INTO customers(customernumber,contactlastname,contactfirstname,phone,addressline1,addressline2,city,c_state,postalcode,country,salesrepemployeenumber)
    VALUES (m_customernumber,m_lName,m_fName,m_phone,m_add1,m_add2,m_city,m_state,m_postal,m_country,m_employeeid);

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spCustomerInsert;
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spCustomerInsert(err_Code,190,'Yolo','Morgan',	'+1 950 222 3333',' 35 penine Street','San Francisco','CA','943343','USA',	1076);
END;

--=======================================

CREATE OR REPLACE PROCEDURE spCustomerUpdate(
err_Code OUT INTEGER,
m_customernumber IN customers.customernumber%type,
m_lName IN customers.contactlastname%type,
m_fName IN customers.contactfirstname%type,
m_phone IN customers.phone%type,
m_add1 IN customers.addressline1%type,
m_add2 IN customers.addressline2%type DEFAULT NULL,
m_city IN customers.city%type,
m_state IN customers.c_state%type DEFAULT NULL,
m_postal IN customers.postalcode%type DEFAULT NULL,
m_country IN customers.country%type,
m_employeeid IN customers.salesrepemployeenumber%type DEFAULT NULL
) AS
BEGIN
    UPDATE customers
        SET contactlastname=m_lName,
            contactfirstname=m_fName,
            phone=m_phone,
            addressline1=m_add1,
            addressline2=m_add2,
            city=m_city,
            c_state=m_state,
            postalcode=m_postal,
            country=m_country,
            salesrepemployeenumber=m_employeeid
        WHERE customernumber=m_customernumber;
    
    err_code:=SQL%ROWCOUNT;
    COMMIT;
    
    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spCustomerUpdate;

--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spCustomerUpdate(err_Code,190,'Yolo','Mairn',	'+1 950 222 3333',' 54 penine Street','San Francisco','CA','33433','USA',	1076);
END;

--=======================================
create or replace PROCEDURE spCustomerDelete(
err_Code OUT INTEGER,
m_customernumber IN customers.customernumber%type
) AS
BEGIN
    DELETE FROM customers
    WHERE customernumber=m_customernumber;

    err_code:=SQL%ROWCOUNT;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spCustomerDelete;
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spCustomerDelete(err_Code,190);
END;

--=======================================

create or replace PROCEDURE spCustomerSelect(
err_Code OUT INTEGER,
m_customernumber IN OUT customers.customernumber%type,
m_lName OUT customers.contactlastname%type,
m_fName OUT customers.contactfirstname%type,
m_phone OUT customers.phone%type,
m_add1 OUT customers.addressline1%type,
m_add2 OUT customers.addressline2%type,
m_city OUT customers.city%type,
m_state OUT customers.c_state%type,
m_postal OUT customers.postalcode%type,
m_country OUT customers.country%type,
m_employeeid OUT customers.salesrepemployeenumber%type)
AS

s_lName customers.contactlastname%type;
s_fName customers.contactfirstname%type;
s_phone customers.phone%type;
s_add1 customers.addressline1%type;
s_add2 customers.addressline2%type;
s_city customers.city%type;
s_state customers.c_state%type;
s_postal customers.postalcode%type;
s_country customers.country%type;
s_employeeid customers.salesrepemployeenumber%type;
BEGIN
    SELECT contactlastname,contactfirstname,phone,addressline1,addressline2,city,c_state,postalcode,country,salesrepemployeenumber
    INTO s_lName,s_fName,s_phone,s_add1,s_add2,s_city,s_state,s_postal,s_country,s_employeeid
    FROM customers
    WHERE customernumber=m_customernumber;

    err_code:=SQL%ROWCOUNT;
    m_lName:=s_lName;
    m_fName:=s_fName;
    m_phone:=s_phone;
    m_add1:=s_add1;
    m_add2:=s_add1;
    m_city:=s_city;
    m_state:=s_state;
    m_postal:=s_postal;
    m_country:=s_country;
    m_employeeid:=s_employeeid;
    COMMIT;

    EXCEPTION
        WHEN OTHERS
            THEN err_code:=-1;

END spCustomerSelect;
--=======================================
DECLARE
err_Code INTEGER;
s_lName customers.contactlastname%type;
s_fName customers.contactfirstname%type;
s_phone customers.phone%type;
s_add1 customers.addressline1%type;
s_add2 customers.addressline2%type;
s_city customers.city%type;
s_state customers.c_state%type;
s_postal customers.postalcode%type;
s_country customers.country%type;
s_employeeid customers.salesrepemployeenumber%type;
BEGIN
    spCustomerSelect(err_Code,1033,s_lName,s_fName,s_phone,s_add1,s_add2,s_city,s_state,s_postal,s_country,s_employeeid);

--=======================================





















--PRODUCTS table

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
--=======================================
EXAMPLE NON-SAVE PROCEDURAL CODE:
DECLARE
    err_Code INTEGER;
BEGIN
    spProductsInsert(err_Code,'ABC500','ps5','Playstation 5',2,500,1700,124578);
END;

--=======================================

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
--=======================================
DECLARE
err_Code INTEGER;
sPN products.PRODUCTNAME%type;      sPD products.PRODUCTDESCRIPTION%type;
sQIS products.QUANTITYINSTOCK%type; sBP products.BUYPRICE%type;
sMP  products.MARKETPRICE%type;     sSI products.STOREID%type ;
BEGIN
   spProductsRead(err_Code,'ABC500',sPN ,sPD , sQIS , sBP , sMP ,  sSI );
END;

--=======================================

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
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spProductsUpdate(err_Code,'ABC500','PS 5','Playstation 5 dulex edition',4,700,2700,124578);
END;

--=======================================

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
--=======================================
DECLARE
    err_Code INTEGER;
BEGIN
    spProductsDelete(err_Code,'ABC500');
END;

--=======================================
--=========================================================================================================
create or replace procedure printStores
AS
eStoreid Stores.Storeid%type;
eStorename Stores.Storename%type;
ePhone Stores.Phone%type;
eEmail Stores.Phone%type;
eSTORE_LOCATION Stores.STORE_LOCATION%type;
CURSOR sCursor IS
SELECT * FROM Stores;
BEGIN
OPEN sCursor;
dbms_output.put_line('********************************************STORES********************************************');
dbms_output.put_line('Storeid            Storename                  Phone                        Email                     store location');
dbms_output.put_line('*************************************************************************************************');

LOOP
FETCH sCursor into eStoreid, eStorename,ePhone,eEmail,eSTORE_LOCATION;
EXIT WHEN sCursor%notfound;
dbms_output.put_line(eStoreid || '            ' || eStorename || '            ' || ePhone|| '            '||eEmail|| '            '||eSTORE_LOCATION);
END LOOP;
CLOSE sCursor;
END;
--=========================================================================================================
create or replace procedure printCustomers
AS
eCUSTOMERNUMBER CUSTOMERS.CUSTOMERNUMBER%type;
eCONTACTLASTNAME CUSTOMERS.CONTACTLASTNAME%type;
eCONTACTFIRSTNAME CUSTOMERS.CONTACTFIRSTNAME%type;
ePHONE CUSTOMERS.PHONE%type;
eADDRESSLINE1  CUSTOMERS.ADDRESSLINE1%type;
eADDRESSLINE2 CUSTOMERS.ADDRESSLINE2%type;
eCITY CUSTOMERS.CITY%type;
eSTATE CUSTOMERS.C_STATE%type;
ePOSTALCODE CUSTOMERS.POSTALCODE%type;
eCOUNTRY CUSTOMERS.COUNTRY%type;
eSALESREPEMPLOYEENUMBER CUSTOMERS.SALESREPEMPLOYEENUMBER%type;
CURSOR sCursor IS
SELECT * FROM CUSTOMERS;
BEGIN
OPEN sCursor;
dbms_output.put_line('**********************************************************************CUSTOMERS**********************************************************************');
dbms_output.put_line('CUSTOMERNUMBER                     CONTACTLASTNAME                      PHONE                       CONTACTFIRSTNAME               ADDRESSLINE1                  ADDRESSLINE2             CITY             
C_STATE             POSTALCODE             COUNTRY             SALESREPEMPLOYEENUMBER');
dbms_output.put_line('**********************************************************************************************************************************************************');
LOOP
FETCH sCursor into eCUSTOMERNUMBER, eCONTACTLASTNAME,eCONTACTFIRSTNAME,ePHONE,eADDRESSLINE1,eADDRESSLINE2,eCITY,eSTATE,ePOSTALCODE,eCOUNTRY,eSALESREPEMPLOYEENUMBER;
EXIT WHEN sCursor%notfound;
dbms_output.put_line(eCUSTOMERNUMBER||'                   '||eCONTACTLASTNAME||'                   '||eCONTACTFIRSTNAME||'                 '||ePHONE||'                '||eADDRESSLINE1||'                   '||eADDRESSLINE2||' 
'||eCITY||'                   '||eSTATE||'                  '||ePOSTALCODE||'                   '||eCOUNTRY||'                   '||eSALESREPEMPLOYEENUMBER);
END LOOP;
CLOSE sCursor;
END;

--=========================================================================================================
create or replace procedure printEmployees
AS
eEMPLOYEENUMBER EMPLOYEES.EMPLOYEENUMBER%type;
eLASTNAME EMPLOYEES.LASTNAME%type;
eFIRSTNAME EMPLOYEES.FIRSTNAME%type;
eEXTENSION EMPLOYEES.EXTENSION%type;
eEMAIL  EMPLOYEES.EMAIL%type;
eSTOREID EMPLOYEES.STOREID%type;
eREPORTSTO  EMPLOYEES.REPORTSTO%type;
eJOBTITLE EMPLOYEES.JOBTITLE%type;
CURSOR sCursor IS
SELECT * FROM EMPLOYEES;
BEGIN
OPEN sCursor;
dbms_output.put_line('********************************************EMPLOYEES********************************************');
dbms_output.put_line('EMPLOYEENUMBER                     LASTNAME                       FIRSTNAME               EXTENSION                  EMAIL             STOREID                  REPORTSTO             JOBTITLE');
dbms_output.put_line('*****************************************************************************************************');

LOOP
FETCH sCursor into eEMPLOYEENUMBER, eLASTNAME,eFIRSTNAME,eEXTENSION,eEMAIL,eSTOREID,eREPORTSTO,eJOBTITLE;
EXIT WHEN sCursor%notfound;
dbms_output.put_line(eEMPLOYEENUMBER||'                   '||eLASTNAME||'                   '||eFIRSTNAME||'                   '||eEXTENSION||'                   '||eEMAIL||'                   '||eSTOREID||'                   '||eREPORTSTO||'                     '||eJOBTITLE);
END LOOP;
CLOSE sCursor;
END;

create or replace procedure printProducts
AS
ePRODUCTCODE Products.PRODUCTCODE%type;
ePRODUCTNAME Products.PRODUCTNAME%type;
ePRODUCTDESCRIPTION Products.PRODUCTDESCRIPTION%type;
eQUANTITYINSTOCK Products.QUANTITYINSTOCK%type;
eBUYPRICE Products.BUYPRICE%type;
eMARKETPRICE Products.MARKETPRICE%type;
eSTOREID Products.STOREID%type;
CURSOR sCursor IS
SELECT * FROM Products;
BEGIN
OPEN sCursor;
dbms_output.put_line('********************************************PRODUCTS********************************************');
dbms_output.put_line('PRODUCTCODE             PRODUCTNAME             PRODUCTDESCRIPTION                       QUANTITYINSTOCK            BUYPRICE                     MARKETPRICE                     eSTOREID');
dbms_output.put_line('*********************************************************************************************************************************************************************');

LOOP
FETCH sCursor into ePRODUCTCODE, ePRODUCTNAME,ePRODUCTDESCRIPTION,
eQUANTITYINSTOCK,eBUYPRICE,eMARKETPRICE,eSTOREID;
EXIT WHEN sCursor%notfound;
dbms_output.put_line(ePRODUCTCODE || '            ' || ePRODUCTNAME || '            ' || ePRODUCTDESCRIPTION|| '                                 '||eQUANTITYINSTOCK|| '            '||eBUYPRICE|| '            '||eMARKETPRICE|| '            '||eSTOREID);
END LOOP;
CLOSE sCursor;
END;
