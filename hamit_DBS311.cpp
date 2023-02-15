

#include <iostream>
#include<iomanip>
#include <occi.h>
#include<limits>


//To connect and work with databases in Oracle server, we use the <occi.h> header file or library
using oracle::occi::Environment;
using oracle::occi::Connection;

using namespace oracle::occi;
using namespace std;

struct Store
{
	  int m_storeId{};
	  string m_storeName{};
	  string m_phone{};
	  string m_email{};
	  string m_location{};

};
struct Employee
{

	  int m_employeeId{};
	  string m_lastName{};
	  string m_firstName{};
	  string m_extension{};
	  string m_email{};
	  int m_storeId{};
	  int m_reportsto{};
	  string m_jobTite{};

};
struct Customer
{

	  int m_customerId{};
	  string m_lastName{};
	  string m_firstName{};
	  string m_phone{};
	  string m_add1{};
	  string m_add2{};
	  string m_city{};
	  string m_state{};
	  string m_postalCode{};
	  string m_country{};
	  int m_employeedRepId{};

};
struct Product
{
	  string productcode{};
	  string productname{};
	  string productdescription{};
	  int quant{};
	  double buyprice{};
	  double marketprice{};
	  int storeid{};
};
void insertStore(Connection* conn);
void updateStore(Connection* conn);
void deleteStore(Connection* conn);
void readStore(Connection* conn);

void readEmployee(Connection* conn);
void insertEmployee(Connection* conn);
void updateEmployee(Connection* conn);
void deleteEmployee(Connection* conn);

void readCustomer(Connection* conn);
void insertCustomer(Connection* conn);
void updateCustomer(Connection* conn);
void deleteCustomer(Connection* conn);

void readProducts(Connection* conn);
void insertProducts(Connection* conn);
void updateProducts(Connection* conn);
void deleteProducts(Connection* conn);

void displayStores(Connection* conn);
void displayEmployees(Connection* conn);
void displayCustomers(Connection* conn);
void displayProducts(Connection* conn);

int main(void)
{
	  //OCCI VARIABLES
	  Environment* env = nullptr;
	  Connection* conn = nullptr;

	  // USER VARIABLES
	  string str;
	  string usr = "dbs311_222zc48";	  // this is your login assigned to you 
	  string pass = "11452277";   // this is your password assigned to you 
	  string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	  try {
			int option{ 0 };
			bool flag{ true };
			cout << "======================================" << endl;
			cout << "|       WELCOME TO VAUGHAN MILLS      |" << endl;
			cout << "======================================" << endl;

			env = Environment::createEnvironment(Environment::DEFAULT);
			conn = env->createConnection(usr, pass, srv);
			while (flag)
			{
				  cout << "**************************************" << endl;
				  cout << "PLEASE CHOOSE YOUR OPTION:" << endl;
				  cout << "**************************************" << endl;
				  cout << "1 STORES" << endl;
				  cout << "2 EMPLOYEES" << endl;
				  cout << "3 CUSTOMERS" << endl;
				  cout << "4 PRODUCTS" << endl;
				  cout << "0 Exit" << endl;
				  cout << "**************************************" << endl<<">";
				  cin >> option;
				  switch (option)
				  {

				  case 1:
						displayStores(conn);
						break;
				  case 2:
						displayEmployees(conn);
						break;
				  case 3:
						displayCustomers(conn);
						break;
				  case 4:
						displayProducts(conn);
						break;
				  case 0:
						cout << "Thanks for Visiting!!" << endl;
						cout << "**************************************" << endl;
						flag = false;
						break;
				  default:
						cout << "Wrong input\n";
						cout << "**************************************" << endl;
						break;
				  }
			}



	  }
	  catch (SQLException& sqlExcp)
	  {
			cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	  }
	  return 0;
}

void displayStores(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();
	  cout << "======================================" << endl;
	  cout << "|               STORES               |" << endl;
	  cout << "======================================" << endl;
	  ResultSet* rs = stmt->executeQuery("SELECT * FROM stores");

	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "STOREID";
	  cout.width(20);
	  cout << "STORENAME ";
	  cout.width(20);
	  cout << " PHONE ";
	  cout.width(30);
	  cout << "EMAIL";
	  cout.width(30);
	  cout << "LOCATION" << endl;

	  while (rs->next()) {
			int storeId = rs->getInt(1);  
			string storeName = rs->getString(2); 
			string phone = rs->getString(3); 
			string email = rs->getString(4);
			string location = rs->getString(5);
			cout.width(20);
			cout.setf(ios::left);
			cout << storeId;
			cout.width(20);
			cout << storeName;
			cout.width(20);
			cout << phone;
			cout.width(30);
			cout << email;
			cout.width(30);
			cout << location << endl;
	  }
	  conn->terminateStatement(stmt);				 
	  cout << "**************************************" << endl;


	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Insert New Store" << endl;
			cout << "2. Update an existing store" << endl;
			cout << "3. Delete an existing Store(MAY REQUIRE PERMISSION)" << endl;
			cout << "4. Vist a specific Store" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertStore(conn);
				  break;
			case 2:
				  updateStore(conn);
				  break;
			case 3:
				  deleteStore(conn);
				  break;
			case 4:
				  readStore(conn);
				  break;
			case 0:
				  cout << "See you soon!!\n";
				  cout << "**************************************" << endl;
				  flag = false;
				  break;
			default:
				  cout << "Wrong input!!\n";
				  cout << "**************************************" << endl;
				  break;
			}
	  }

}
void displayEmployees(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();

	  cout << "======================================" << endl;
	  cout << "|              EMPLOYEES             |" << endl;
	  cout << "======================================" << endl;
	  ResultSet* rs2 = stmt->executeQuery("SELECT * FROM employees");


	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "EMPLOYEENUMBER";
	  cout.width(20);
	  cout << "LASTNAME";
	  cout.width(20);
	  cout << "FIRSTNAME";
	  cout.width(20);
	  cout << "EXTENSION";
	  cout.width(40);
	  cout << "EMAIL";
	  cout.width(20);
	  cout << "STOREID";
	  cout.width(20);
	  cout << "REPORTSTO";
	  cout.width(20);
	  cout << "JOBTITLE" << endl;
	  while (rs2->next()) {
			int employeeId = rs2->getInt(1);
			string lastName = rs2->getString(2);
			string firstName = rs2->getString(3);
			string extension = rs2->getString(4);
			string email = rs2->getString(5);
			int storeId = rs2->getInt(6);
			int reportsTo = rs2->getInt(7);
			string jobTitle = rs2->getString(8);
			cout.width(20);
			cout.setf(ios::left);
			cout << employeeId;
			cout.width(20);
			cout << lastName;
			cout.width(20);
			cout << firstName;
			cout.width(20);
			cout << extension;
			cout.width(40);
			cout << email;
			cout.width(20);
			cout << storeId;
			cout.width(20);
			cout << reportsTo;
			cout.width(20);
			cout << jobTitle << endl;

	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;

	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Insert New Employee" << endl;
			cout << "2. Update an existing Employee" << endl;
			cout << "3. Delete an existing Employee(MAY REQUIRE PERMISSION)" << endl;
			cout << "4. Extract a specific Employee" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertEmployee(conn);
				  break;
			case 2:
				  updateEmployee(conn);
				  break;
			case 3:
				  deleteEmployee(conn);
				  break;
			case 4:
				  readEmployee(conn);
				  break;
			case 0:
				  cout << "See you soon!!\n";
				  cout << "**************************************" << endl;
				  flag = false;
				  break;
			default:
				  cout << "Wrong input!!\n";
				  cout << "**************************************" << endl;
				  break;
			}
	  }



}
void displayCustomers(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();
	  cout << "======================================" << endl;
	  cout << "|             CUSTOMERS              |" << endl;
	  cout << "======================================" << endl;
	  ResultSet* rs3 = stmt->executeQuery("SELECT * FROM customers");



	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "CUSTOMERNUMBER";
	  cout.width(20);
	  cout << "CONTACTLASTNAME";
	  cout.width(20);
	  cout << "CONTACTFIRSTNAME";
	  cout.width(20);
	  cout << "PHONE";
	  cout.width(30);
	  cout << "ADDRESSLINE1";
	  cout.width(14);
	  cout << "ADDRESSLINE2";
	  cout.width(20);
	  cout << "CITY";
	  cout.width(10);
	  cout << "STATE";
	  cout.width(14);
	  cout << "POSTAL CODE";
	  cout.width(20);
	  cout << "COUNTRY";
	  cout.width(20);
	  cout << "SALESREPEMPLOYEENUMBER" << endl;
	  while (rs3->next()) {
			int customerNumber = rs3->getInt(1);
			string lastName = rs3->getString(2);
			string firstName = rs3->getString(3);
			string phone = rs3->getString(4);
			string address_1 = rs3->getString(5);
			string address_2 = rs3->getString(6);
			string city = rs3->getString(7);
			string state = rs3->getString(8);
			string country = rs3->getString(9);
			string postalCode = rs3->getString(10);
			int salesRep = rs3->getInt(11);
			cout.width(20);
			cout.setf(ios::left);
			cout << customerNumber;
			cout.width(20);
			cout << lastName;
			cout.width(20);
			cout << firstName;
			cout.width(20);
			cout << phone;
			cout.width(30);
			cout << address_1;
			cout.width(14);
			cout << address_2;
			cout.width(20);
			cout << city;
			cout.width(10);
			cout << state;
			cout.width(14);
			cout << country;
			cout.width(20);
			cout << postalCode;
			cout.width(20);
			cout << salesRep << endl;

	  }
	  cout << "**************************************" << endl;
	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Insert New Customer" << endl;
			cout << "2. Update an existing Customer" << endl;
			cout << "3. Delete an existing Customer(MAY REQUIRE PERMISSION)" << endl;
			cout << "4. Extract a specific Customer" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertCustomer(conn);
				  break;
			case 2:
				  updateCustomer(conn);
				  break;
			case 3:
				  deleteCustomer(conn);
				  break;
			case 4:
				  readCustomer(conn);
				  break;
			case 0:
				  cout << "See you soon!!\n\n";
				  cout << "**************************************" << endl;
				  flag = false;
				  break;
			default:
				  cout << "Wrong input!!\n\n";
				  cout << "**************************************" << endl;
				  break;
			}
	  }

}
void displayProducts(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();

	  cout << "======================================" << endl;
	  cout << "|              PRODUCTS              |" << endl;
	  cout << "======================================" << endl;
	  ResultSet* rs4 = stmt->executeQuery("SELECT * FROM products");
	  cout.width(20);
	  cout << left << "PRODUCTCODE";
	  cout.width(20);
	  cout << "PRODUCTNAME";
	  cout.width(40);
	  cout << "PRODUCTDESCRIPTION";
	  cout.width(20);
	  cout << "QUANTITYINSTOCK";
	  cout.width(20);
	  cout << "BUYPRICE";
	  cout.width(20);
	  cout << "MARKETPRICE";
	  cout.width(20);
	  cout << "STOREID" << endl;
	  while (rs4->next()) {
			string PRODUCTCODE = rs4->getString(1);
			string PRODUCTNAME = rs4->getString(2);
			string PRODUCTDESCRIPTION = rs4->getString(3);
			int QUANTITYINSTOCK = rs4->getInt(4);
			double BUYPRICE = rs4->getDouble(5);
			double MARKETPRICE = rs4->getDouble(6);
			int STOREID = rs4->getInt(7);

			cout.width(20);
			cout.setf(ios::left);
			cout << PRODUCTCODE;
			cout.width(20);
			cout << PRODUCTNAME;
			cout.width(40);
			cout << PRODUCTDESCRIPTION;
			cout.width(20);
			cout << QUANTITYINSTOCK;
			cout.width(20);
			cout << fixed << setprecision(2) << BUYPRICE;
			cout.width(20);
			cout << fixed << setprecision(2) << MARKETPRICE;
			cout.width(20);
			cout << STOREID << endl;
	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;

	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Insert a New Product" << endl;
			cout << "2. Update an existing Product" << endl;
			cout << "3. Delete an existing Product(MAY REQUIRE PERMISSION)" << endl;
			cout << "4. Extract a specific Product" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertProducts(conn);
				  break;
			case 2:
				  updateProducts(conn);
				  break;
			case 3:
				  deleteProducts(conn);
				  break;
			case 4:
				  readProducts(conn);
				  break;
			case 0:
				  cout << "See you soon!!\n\n";
				  cout << "**************************************" << endl;
				  flag = false;
				  break;
			default:
				  cout << "Wrong input!!\n\n";
				  cout << "**************************************" << endl;
				  break;
			}
	  }

}

void insertStore(Connection* conn)
{
	  Store store{};
	  int err = 0;

	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;
	  cout << "Please enter STORE ID!!" << endl;
	  cin >> store.m_storeId;
	  cin.ignore();
	  cout << "Please enter the STORE NAME!!" << endl;
	  getline(cin, store.m_storeName, '\n');
	  cout << "Please enter the Store's PHONE NUMBER!!" << endl;
	  getline(cin, store.m_phone, '\n');
	  cout << "Please enter the Store's EMAIL!!" << endl;
	  getline(cin, store.m_email, '\n');
	  cout << "Please enter the Store's LOCATION!!" << endl;
	  getline(cin, store.m_location, '\n');


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spStoreInsert(:1,:2,:3,:4,:5,:6); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setNumber(2, store.m_storeId);
	  stmt->setString(3, store.m_storeName);
	  stmt->setString(4, store.m_phone);
	  stmt->setString(5, store.m_email);
	  stmt->setString(6, store.m_location);

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: NEW STORE INSERTED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: NEW STORE COULDN'T BE INSERTED. THE STORE ID ENTERED MAY ALREADY EXIST!!\n\n";
	  }
	  cout << "**************************************" << endl;
	  conn->terminateStatement(stmt);


}
void updateStore(Connection* conn)
{
	  Store store{};
	  int err = 0;
	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;
	  cout << "Please enter STORE ID!!" << endl;
	  cin >> store.m_storeId;
	  cin.ignore();
	  cout << "Please enter the STORE NAME!!" << endl;
	  getline(cin, store.m_storeName, '\n');
	  cout << "Please enter the Store's PHONE NUMBER!!" << endl;
	  getline(cin, store.m_phone, '\n');
	  cout << "Please enter the Store's EMAIL!!" << endl;
	  getline(cin, store.m_email, '\n');
	  cout << "Please enter the Store's LOCATION!!" << endl;
	  getline(cin, store.m_location, '\n');


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spStoreUpdate(:1,:2,:3,:4,:5,:6); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setNumber(2, store.m_storeId);
	  stmt->setString(3, store.m_storeName);
	  stmt->setString(4, store.m_phone);
	  stmt->setString(5, store.m_email);
	  stmt->setString(6, store.m_location);

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: STORE UPDATED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: STORE COULDN'T BE UPDATED. THE STORE ID ENTERED MAY NOT EXIST!!\n\n";
	  }
	  cout << "**************************************" << endl;
	  conn->terminateStatement(stmt);


}
void deleteStore(Connection* conn)
{
	  Store store{};
	  int err = 0;

	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "Please enter STORE ID!!" << endl;
	  cin >> store.m_storeId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spStoreDelete(:1,:2); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setNumber(2, store.m_storeId);
	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: STORE DELETED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: PERMISSION DENIED.\n STORE COULDN'T BE DELETED.\n\n";
	  }
	  conn->terminateStatement(stmt);


}
void readStore(Connection* conn)
{
	  Store store{};
	  int err = 0;
	  int storeId{};
	  string storeName{};
	  string phone{};
	  string email{};
	  string location{};

	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;
	  cout << "Please enter STORE ID!!" << endl;
	  cin >> store.m_storeId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spStoreSelect(:1,:2,:3,:4,:5,:6); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setInt(2, store.m_storeId);
	  stmt->registerOutParam(3, Type::OCCISTRING, sizeof(store.m_storeName));
	  stmt->registerOutParam(4, Type::OCCISTRING, sizeof(store.m_phone));
	  stmt->registerOutParam(5, Type::OCCISTRING, sizeof(store.m_email));
	  stmt->registerOutParam(6, Type::OCCISTRING, sizeof(store.m_location));


	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  storeId = store.m_storeId;
	  storeName = stmt->getString(3);
	  phone = stmt->getString(4);
	  email = stmt->getString(5);
	  location = stmt->getString(6);

	  if (err > 0)
	  {
			cout << "\nSUCCESS: RETRIEVING YOUR STORE.\n\n";
			cout.width(20);
			cout.setf(ios::left);
			cout << "STOREID";
			cout.width(20);
			cout << "STORENAME ";
			cout.width(20);
			cout << " PHONE ";
			cout.width(30);
			cout << "EMAIL";
			cout.width(30);
			cout << "LOCATION" << endl;
			cout.width(20);
			cout.setf(ios::left);
			cout << storeId;
			cout.width(20);
			cout << storeName;
			cout.width(20);
			cout << phone;
			cout.width(30);
			cout << email;
			cout.width(30);
			cout << location << endl;
	  }
	  else
	  {
			cout << "\nERROR: STORE COULDN'T BE RETRIEVED. THE STORE ID ENTERED MAY NOT EXIST!!\n\n";
	  }
	  cout << "**************************************" << endl;
	  conn->terminateStatement(stmt);


}

void insertEmployee(Connection* conn)
{
	  Employee emp{};
	  int err = 0;

	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;
	  cout << "Please enter EMPLOYEE ID!!" << endl;
	  cin >> emp.m_employeeId;
	  cin.ignore();
	  cout << "Please enter the Employee's FIRST NAME!!" << endl;
	  getline(cin, emp.m_firstName, '\n');
	  cout << "Please enter the Employee's LAST NAME!!" << endl;
	  getline(cin, emp.m_lastName, '\n');
	  cout << "Please enter the Employee's EXTENSION!!" << endl;
	  getline(cin, emp.m_extension, '\n');
	  cout << "Please enter the Employee's EMAIL!!" << endl;
	  getline(cin, emp.m_email, '\n');
	  cout << "Please enter the Employee's STORE ID!!" << endl;
	  cin >> emp.m_storeId;
	  cin.ignore();
	  cout << "Please enter the Employee's MANAGER ID!!" << endl;
	  cin >> emp.m_reportsto;
	  cin.ignore();
	  cout << "Please enter the Employee's JOB TITLE!!" << endl;
	  getline(cin, emp.m_jobTite, '\n');



	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spEmployeeInsert(:1,:2,:3,:4,:5,:6,:7,:8,:9); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setNumber(2, emp.m_employeeId);
	  stmt->setString(3, emp.m_firstName);
	  stmt->setString(4, emp.m_lastName);
	  stmt->setString(5, emp.m_extension);
	  stmt->setString(6, emp.m_email);
	  stmt->setNumber(7, emp.m_storeId);
	  stmt->setNumber(8, emp.m_reportsto);
	  stmt->setString(9, emp.m_jobTite);

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: NEW EMPLOYEE INSERTED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: NEW EMPLOYEE COULDN'T BE INSERTED. THE EMPLOYEE ID MAY ALREADY EXIST!!\n\n";
	  }
	  cout << "**************************************" << endl;
	  conn->terminateStatement(stmt);


}
void updateEmployee(Connection* conn)
{
	  Employee emp{};
	  int err = 0;

	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;
	  cout << "Please enter EMPLOYEE ID!!" << endl;
	  cin >> emp.m_employeeId;
	  cin.ignore();
	  cout << "Please enter the Employee's FIRST NAME!!" << endl;
	  getline(cin, emp.m_firstName, '\n');
	  cout << "Please enter the Employee's LAST NAME!!" << endl;
	  getline(cin, emp.m_lastName, '\n');
	  cout << "Please enter the Employee's EXTENSION!!" << endl;
	  getline(cin, emp.m_extension, '\n');
	  cout << "Please enter the Employee's EMAIL!!" << endl;
	  getline(cin, emp.m_email, '\n');
	  cout << "Please enter the Employee's STORE ID!!" << endl;
	  cin >> emp.m_storeId;
	  cin.ignore();
	  cout << "Please enter the Employee's MANAGER ID!!" << endl;
	  cin >> emp.m_reportsto;
	  cin.ignore();
	  cout << "Please enter the Employee's JOB TITLE!!" << endl;
	  getline(cin, emp.m_jobTite, '\n');



	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spEmployeeUpdate(:1,:2,:3,:4,:5,:6,:7,:8,:9); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setNumber(2, emp.m_employeeId);
	  stmt->setString(3, emp.m_firstName);
	  stmt->setString(4, emp.m_lastName);
	  stmt->setString(5, emp.m_extension);
	  stmt->setString(6, emp.m_email);
	  stmt->setNumber(7, emp.m_storeId);
	  stmt->setNumber(8, emp.m_reportsto);
	  stmt->setString(9, emp.m_jobTite);

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: EMPLOYEE UPDATED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: EMPLOYEE COULDN'T BE UPDATED. THE EMPLOYEE ID ENTERED MAY NOT EXIST!!\n\n";
	  }
	  conn->terminateStatement(stmt);

	  cout << "**************************************" << endl;


}
void deleteEmployee(Connection* conn)
{
	  Employee emp{};
	  int err = 0;

	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "Please enter EMPLOYEE ID!!" << endl;
	  cin >> emp.m_employeeId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spEmployeeDelete(:1,:2); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setNumber(2, emp.m_employeeId);
	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: EMPLOYEE DELETED\n\n";
	  }
	  else
	  {
			cout << "\nERROR: EMPLOYEE COULDN'T BE DELETED. PERMISSION DENIED!!\n\n";
	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;


}
void readEmployee(Connection* conn)
{
	  Employee emp{};
	  int err = 0;


	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;
	  cout << "Please enter EMPLOYEE ID!!" << endl;
	  cin >> emp.m_employeeId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spEmployeeSelect(:1,:2,:3,:4,:5,:6,:7,:8,:9); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setInt(2, emp.m_employeeId);
	  stmt->registerOutParam(3, Type::OCCISTRING, sizeof(emp.m_lastName));
	  stmt->registerOutParam(4, Type::OCCISTRING, sizeof(emp.m_firstName));
	  stmt->registerOutParam(5, Type::OCCISTRING, sizeof(emp.m_extension));
	  stmt->registerOutParam(6, Type::OCCISTRING, sizeof(emp.m_email));
	  stmt->registerOutParam(7, Type::OCCIINT, sizeof(emp.m_storeId));
	  stmt->registerOutParam(8, Type::OCCIINT, sizeof(emp.m_reportsto));
	  stmt->registerOutParam(9, Type::OCCISTRING, sizeof(emp.m_jobTite));

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  int employeeId = emp.m_employeeId;
	  string lastName = stmt->getString(3);
	  string firstName = stmt->getString(4);
	  string extension = stmt->getString(5);;
	  string email = stmt->getString(6);
	  int storeId = stmt->getInt(7);
	  int reportsto = stmt->getInt(8);
	  string jobTitle = stmt->getString(9);;

	  if (err > 0)
	  {
			cout.width(20);
			cout.setf(ios::left);
			cout << "EMPLOYEENUMBER";
			cout.width(20);
			cout << "LASTNAME";
			cout.width(20);
			cout << "FIRSTNAME";
			cout.width(20);
			cout << "EXTENSION";
			cout.width(40);
			cout << "EMAIL";
			cout.width(20);
			cout << "STOREID";
			cout.width(20);
			cout << "REPORTSTO";
			cout.width(20);
			cout << "JOBTITLE" << endl;

			cout.width(20);
			cout.setf(ios::left);
			cout << employeeId;
			cout.width(20);
			cout << lastName;
			cout.width(20);
			cout << firstName;
			cout.width(20);
			cout << extension;
			cout.width(40);
			cout << email;
			cout.width(20);
			cout << storeId;
			cout.width(20);
			cout << reportsto;
			cout.width(20);
			cout << jobTitle << endl;
	  }
	  else
	  {
			cout << "\nERROR: COULDN'T READ EMPLOYEE. THE EMPLOYEE ID ENTERED MAY NOT EXIST!!\n\n";
	  }
	  conn->terminateStatement(stmt);

	  cout << "**************************************" << endl;

}

void insertCustomer(Connection* conn)
{
	  Customer customer{};
	  int err = 0;

	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;
	  cout << "Please enter CUSTOMER ID!!" << endl;
	  cin >> customer.m_customerId;
	  cin.ignore();
	  cout << "Please enter the Customer's FIRST NAME!!" << endl;
	  getline(cin, customer.m_firstName, '\n');
	  cout << "Please enter the Customer's LAST NAME!!" << endl;
	  getline(cin, customer.m_lastName, '\n');
	  cout << "Please enter the Customer's PHONE!!" << endl;
	  getline(cin, customer.m_phone, '\n');
	  cout << "Please enter the Customer's ADDRESS LINE 1!!" << endl;
	  getline(cin, customer.m_add1, '\n');
	  cout << "Please enter the Customer's ADDRESS LINE 2!!" << endl;
	  getline(cin, customer.m_add2, '\n');
	  cout << "Please enter the Customer's CITY!!" << endl;
	  getline(cin, customer.m_city, '\n');
	  cout << "Please enter the Customer's STATE!!" << endl;
	  getline(cin, customer.m_state, '\n');
	  cout << "Please enter the Customer's POSTAL CODE!!" << endl;
	  getline(cin, customer.m_postalCode, '\n');
	  cout << "Please enter the Customer's COUNTRY!!" << endl;
	  getline(cin, customer.m_country, '\n');
	  cout << "Please enter the Customer's EMPLOYEE REPRESENTATIVE ID" << endl;
	  cin >> customer.m_employeedRepId;
	  cin.ignore();

	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spCustomerInsert(:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setInt(2, customer.m_customerId);
	  stmt->setString(3, customer.m_lastName);
	  stmt->setString(4, customer.m_firstName);
	  stmt->setString(5, customer.m_phone);
	  stmt->setString(6, customer.m_add1);
	  stmt->setString(7, customer.m_add2);
	  stmt->setString(8, customer.m_city);
	  stmt->setString(9, customer.m_state);
	  stmt->setString(10, customer.m_postalCode);
	  stmt->setString(11, customer.m_country);
	  stmt->setInt(12, customer.m_employeedRepId);

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: NEW CUSTOMER INSERTED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: NEW CUSTOMER COULDN'T BE INSERTED. THE CUSTOMER ID MAY ALREADY EXIST!!\n\n";
	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;


}
void updateCustomer(Connection* conn)
{
	  Customer customer{};
	  int err = 0;

	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;
	  cout << "Please enter CUSTOMER ID!!" << endl;
	  cin >> customer.m_customerId;
	  cin.ignore();
	  cout << "Please enter the Customer's FIRST NAME!!" << endl;
	  getline(cin, customer.m_firstName, '\n');
	  cout << "Please enter the Customer's LAST NAME!!" << endl;
	  getline(cin, customer.m_lastName, '\n');
	  cout << "Please enter the Customer's PHONE!!" << endl;
	  getline(cin, customer.m_phone, '\n');
	  cout << "Please enter the Customer's ADDRESS LINE 1!!" << endl;
	  getline(cin, customer.m_add1, '\n');
	  cout << "Please enter the Customer's ADDRESS LINE 2!!" << endl;
	  getline(cin, customer.m_add2, '\n');
	  cout << "Please enter the Customer's CITY!!" << endl;
	  getline(cin, customer.m_city, '\n');
	  cout << "Please enter the Customer's STATE!!" << endl;
	  getline(cin, customer.m_state, '\n');
	  cout << "Please enter the Customer's POSTAL CODE!!" << endl;
	  getline(cin, customer.m_postalCode, '\n');
	  cout << "Please enter the Customer's COUNTRY!!" << endl;
	  getline(cin, customer.m_country, '\n');
	  cout << "Please enter the Customer's EMPLOYEE REPRESENTATIVE ID" << endl;
	  cin >> customer.m_employeedRepId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spCustomerUpdate(:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setInt(2, customer.m_customerId);
	  stmt->setString(3, customer.m_lastName);
	  stmt->setString(4, customer.m_firstName);
	  stmt->setString(5, customer.m_phone);
	  stmt->setString(6, customer.m_add1);
	  stmt->setString(7, customer.m_add2);
	  stmt->setString(8, customer.m_city);
	  stmt->setString(9, customer.m_state);
	  stmt->setString(10, customer.m_postalCode);
	  stmt->setString(11, customer.m_country);
	  stmt->setInt(12, customer.m_employeedRepId);

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: CUSTOMER UPDATED.\n\n";
	  }
	  else
	  {
			cout << "\nERROR: CUSTOMER COULDN'T BE UPDATED. THE CUSTOMER ID ENTERED MAY NOT EXIST!!\n\n";
	  }
	  cout << "**************************************" << endl;
	  conn->terminateStatement(stmt);
}
void deleteCustomer(Connection* conn)
{
	  Customer customer{};
	  int err = 0;

	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "Please enter CUSTOMER ID!!" << endl;
	  cin >> customer.m_customerId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spCustomerDelete(:1,:2); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setInt(2, customer.m_customerId);
	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  if (err > 0)
	  {
			cout << "\nSUCCESS: CUSTOMER DELETED\n\n";
	  }
	  else
	  {
			cout << "\nERROR: CUSTOMER COULDN'T BE DELETED. PERMISSION DENIED!!\n\n";
	  }
	  cout << "**************************************" << endl;
	  conn->terminateStatement(stmt);


}
void readCustomer(Connection* conn)
{
	  Customer customer{};
	  int err = 0;

	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;
	  cout << "Please enter CUSTOMER ID!!" << endl;
	  cin >> customer.m_customerId;
	  cin.ignore();


	  Statement* stmt = conn->createStatement();
	  stmt->setSQL("BEGIN spCustomerSelect(:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12); END;");
	  stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
	  stmt->setInt(2, customer.m_customerId);
	  stmt->registerOutParam(3, Type::OCCISTRING, sizeof(customer.m_lastName));
	  stmt->registerOutParam(4, Type::OCCISTRING, sizeof(customer.m_firstName));
	  stmt->registerOutParam(5, Type::OCCISTRING, sizeof(customer.m_phone));
	  stmt->registerOutParam(6, Type::OCCISTRING, sizeof(customer.m_add1));
	  stmt->registerOutParam(7, Type::OCCISTRING, sizeof(customer.m_add2));
	  stmt->registerOutParam(8, Type::OCCISTRING, sizeof(customer.m_city));
	  stmt->registerOutParam(9, Type::OCCISTRING, sizeof(customer.m_state));
	  stmt->registerOutParam(10, Type::OCCISTRING, sizeof(customer.m_postalCode));
	  stmt->registerOutParam(11, Type::OCCISTRING, sizeof(customer.m_country));
	  stmt->registerOutParam(12, Type::OCCIINT, sizeof(customer.m_employeedRepId));

	  stmt->executeUpdate();
	  err = stmt->getInt(1);
	  int customerNumber = customer.m_customerId;
	  string lastName = stmt->getString(3);
	  string firstName = stmt->getString(4);
	  string phone = stmt->getString(5);
	  string address_1 = stmt->getString(6);
	  string address_2 = stmt->getString(7);
	  string city = stmt->getString(8);
	  string state = stmt->getString(9);
	  string country = stmt->getString(10);
	  string postalCode = stmt->getString(11);
	  int salesRep = stmt->getInt(12);


	  if (err > 0)
	  {
			cout.width(20);
			cout.setf(ios::left);
			cout << "CUSTOMERNUMBER";
			cout.width(20);
			cout << "CONTACTLASTNAME";
			cout.width(20);
			cout << "CONTACTFIRSTNAME";
			cout.width(20);
			cout << "PHONE";
			cout.width(30);
			cout << "ADDRESSLINE1";
			cout.width(14);
			cout << "ADDRESSLINE2";
			cout.width(20);
			cout << "CITY";
			cout.width(10);
			cout << "STATE";
			cout.width(14);
			cout << "POSTAL CODE";
			cout.width(20);
			cout << "COUNTRY";
			cout.width(20);
			cout << "SALESREPEMPLOYEENUMBER" << endl;
			cout.width(20);
			cout.setf(ios::left);
			cout << customerNumber;
			cout.width(20);
			cout << lastName;
			cout.width(20);
			cout << firstName;
			cout.width(20);
			cout << phone;
			cout.width(30);
			cout << address_1;
			cout.width(14);
			cout << address_2;
			cout.width(20);
			cout << city;
			cout.width(10);
			cout << state;
			cout.width(14);
			cout << country;
			cout.width(20);
			cout << postalCode;
			cout.width(20);
			cout << salesRep << endl;

	  }
	  else
	  {
			cout << "\nERROR: COULDN'T READ CUSTOMER. THE CUSTOMER ID ENTERED MAY NOT EXIST!!\n\n";
	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;


}

void insertProducts(Connection* conn)
{
	  Product prod;
	  int err = 0;
	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;
	  cout << "Enter productcode : ";
	  cin >> prod.productcode;
	  cout << "Enter productname : ";
	  cin >> prod.productname;
	  cout << "Enter productdescription : ";
	  cin >> prod.productdescription;
	  cout << "Enter Quantity in stock : ";
	  cin >> prod.quant;
	  cin.ignore();
	  cout << "Enter buyprice : ";
	  cin >> prod.buyprice;
	  cin.ignore();
	  cout << "Enter marketprice : ";
	  cin >> prod.marketprice;
	  cin.ignore();

	  cout << "Enter storeid : ";
	  cin >> prod.storeid;
	  cin.ignore();

	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spProductsInsert(:1,:2,:3,:4,:5,:6,:7,:8);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, prod.productcode);
			stmt->setString(3, prod.productname);
			stmt->setString(4, prod.productdescription);
			stmt->setInt(5, prod.quant);
			stmt->setDouble(6, prod.buyprice);
			stmt->setDouble(7, prod.marketprice);
			stmt->setInt(8, prod.storeid);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			if (err > 0)
				  cout << "\nSUCCESS: New Product inserted.\n\n";
			else
				  cout << "\nERROR: Product might already exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void readProducts(Connection* conn)
{
	  Product prod;
	  int err = 0;
	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;
	  cout << "Enter productcode : ";
	  cin >> prod.productcode;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spProductsRead(:1,:2,:3,:4,:5,:6,:7,:8);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, prod.productcode);
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(prod.productname));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(prod.productdescription));
			stmt->registerOutParam(5, Type::OCCIINT, sizeof(prod.quant));
			stmt->registerOutParam(6, Type::OCCIDOUBLE, sizeof(prod.buyprice));
			stmt->registerOutParam(7, Type::OCCIDOUBLE, sizeof(prod.marketprice));
			stmt->registerOutParam(8, Type::OCCIINT, sizeof(prod.storeid));


			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
			{
				  cout << "\nSUCCESS: product read.\n\n";
				  cout << "======================================" << endl;
				  cout << "|              PRODUCTS              |" << endl;
				  cout << "======================================" << endl;
				  cout.width(20);
				  cout << "PRODUCTCODE";
				  cout.width(20);
				  cout << "PRODUCTNAME";
				  cout.width(40);
				  cout << "PRODUCTDESCRIPTION";
				  cout.width(20);
				  cout << "QUANTITYINSTOCK";
				  cout.width(20);
				  cout << "BUYPRICE";
				  cout.width(20);
				  cout << "MARKETPRICE";
				  cout.width(20);
				  cout << "STOREID" << endl;
				  string PRODUCTCODE = prod.productcode;
				  string PRODUCTNAME = stmt->getString(3);
				  string PRODUCTDESCRIPTION = stmt->getString(4);
				  int QUANTITYINSTOCK = stmt->getInt(5);
				  double BUYPRICE = stmt->getDouble(6);
				  double MARKETPRICE = stmt->getDouble(7);
				  int STOREID = stmt->getInt(8);

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << PRODUCTCODE;
				  cout.width(20);
				  cout << PRODUCTNAME;
				  cout.width(40);
				  cout << PRODUCTDESCRIPTION;
				  cout.width(20);
				  cout << QUANTITYINSTOCK;
				  cout.width(20);
				  cout << fixed << setprecision(2) << BUYPRICE;
				  cout.width(20);
				  cout << fixed << setprecision(2) << MARKETPRICE;
				  cout.width(20);
				  cout << STOREID << endl;
			}
			else
				  cout << "\nERROR: product might not exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void updateProducts(Connection* conn)
{
	  Product prod;
	  int err = 0;
	  cin.clear();
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;
	  cout << "Enter productcode : ";
	  cin >> prod.productcode;
	  cout << "Enter productname : ";
	  cin >> prod.productname;
	  cout << "Enter productdescription : ";
	  cin >> prod.productdescription;
	  cout << "Enter Quantity in stock : ";
	  cin >> prod.quant;
	  cin.ignore();
	  cout << "Enter buyprice : ";
	  cin >> prod.buyprice;
	  cin.ignore();
	  cout << "Enter marketprice : ";
	  cin >> prod.marketprice;
	  cin.ignore();

	  cout << "Enter storeid : ";
	  cin >> prod.storeid;
	  cin.ignore();

	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spProductsUpdate(:1,:2,:3,:4,:5,:6,:7,:8);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, prod.productcode);
			stmt->setString(3, prod.productname);
			stmt->setString(4, prod.productdescription);
			stmt->setInt(5, prod.quant);
			stmt->setDouble(6, prod.buyprice);
			stmt->setDouble(7, prod.marketprice);
			stmt->setInt(8, prod.storeid);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: Sale updated.\n\n";
			else
				  cout << "\nERROR:Sale not updated.\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void deleteProducts(Connection* conn)
{
	  Product prod;
	  int err = 0;
	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "enter productcode : ";
	  cin >> prod.productcode;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spProductsDelete(:1,:2);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, prod.productcode);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: product deleted.\n\n";
			else
				  cout << "\nERROR: Product not deleted. PERMISSION REQUIRED\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
