CREATE OR REPLACE PROCEDURE spStoreInsert(
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

CREATE OR REPLACE PROCEDURE spStoreUpdate(
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

-- DELETE PROCEDURE
CREATE OR REPLACE PROCEDURE spStoreDelete(
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

-- SELECT PROCEDURE
SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE spStoreSelect(
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


CREATE OR REPLACE PROCEDURE spEmployeeInsert(
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

-- update employee
CREATE OR REPLACE PROCEDURE spEmployeeUpdate(
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


-- DELETE PROCEDURE
CREATE OR REPLACE PROCEDURE spEmployeeDelete(
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

-- SELECT PROCEDURE
CREATE OR REPLACE PROCEDURE spEmployeeSelect(
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




CREATE OR REPLACE PROCEDURE spCustomerInsert(
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

-- update employee
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


-- DELETE PROCEDURE
CREATE OR REPLACE PROCEDURE spCustomerDelete(
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

-- SELECT PROCEDURE
CREATE OR REPLACE PROCEDURE spCustomerSelect(
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







create or replace PROCEDURE  spMonthlyExpensesInsert(
EC OUT INTEGER,
SI IN MonthlyExpenses.STOREID%type DEFAULT NULL,
R IN MonthlyExpenses.RENT%type,
M IN MonthlyExpenses.MAINTENANCE%type,
U IN MonthlyExpenses.UTILITIES%type,
D IN MonthlyExpenses.expensedate%type,
EID IN MonthlyExpenses.expenseID%type
)
AS
BEGIN
        INSERT INTO monthlyexpenses(STOREID,RENT,MAINTENANCE,UTILITIES,expensedate,expenseID)
        VALUES (SI,R,M,U,D,EID);
        
        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spMonthlyExpensesInsert;


create or replace PROCEDURE spMonthlyExpensesRead(
EC OUT INTEGER,
EID IN MonthlyExpenses.EXPENSEID%type,
SI OUT MonthlyExpenses.STOREID%type,
R OUT MonthlyExpenses.RENT%type,
M OUT MonthlyExpenses.MAINTENANCE%type,
U OUT MonthlyExpenses.UTILITIES%type,
D OUT MonthlyExpenses.EXPENSEDATE%type
)
AS
sSI  MonthlyExpenses.STOREID%type;
sR  MonthlyExpenses.RENT%type;
sM  MonthlyExpenses.MAINTENANCE%type;
sU  MonthlyExpenses.UTILITIES%type;
sD  MonthlyExpenses.EXPENSEDATE%type;
BEGIN
        SELECT STOREID,RENT,MAINTENANCE,UTILITIES,EXPENSEDATE
        INTO sSI,sR,sM,sU,sD
        FROM MonthlyExpenses
        WHERE EXPENSEID=EID;
        
        EC:=sql%rowcount;
        SI:=sSI;R:=sR;M:=sM;
        U:=sU;D:=sD;
        COMMIT;
        
EXCEPTION 
    when others
        then EC:=-1;
END spMonthlyExpensesRead;
-----------------------------------------------------










create or replace PROCEDURE  spMonthlyExpensesUpdate(
EC OUT INTEGER,
SI IN MonthlyExpenses.STOREID%type DEFAULT NULL,
R IN MonthlyExpenses.RENT%type,
M IN MonthlyExpenses.MAINTENANCE%type,
U IN MonthlyExpenses.UTILITIES%type,
D IN MonthlyExpenses.expensedate%type,
EID IN MonthlyExpenses.expenseID%type
)
AS
BEGIN
        UPDATE monthlyexpenses
        SET STOREID=SI,
            RENT=R,
            MAINTENANCE=M,
            UTILITIES=U,
            expensedate=D
        WHERE expenseID=EID;
        
        EC:=sql%rowcount;
        COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spMonthlyExpensesUpdate;









create or replace PROCEDURE spMonthlyExpensesDelete(
EC OUT INTEGER,
EID IN MonthlyExpenses.expenseID%type
)
AS
BEGIN
    DELETE FROM MonthlyExpenses
    WHERE EXPENSEID = EID;
        
    EC:=sql%rowcount;
    COMMIT;
EXCEPTION 
    when others
        then EC:=-1;
END spMonthlyExpensesDelete;













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
