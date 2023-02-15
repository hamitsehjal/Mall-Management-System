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













