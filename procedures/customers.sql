

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

