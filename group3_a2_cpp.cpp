/*
Full Name - Hamit Sehjal
Student ID - 139238208
Mail - hsehjal@myseneca.ca


Full Name - Alen Thomas
Student ID - 156632200
Mail - athomas110@myseneca.ca
*/

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
struct Expense
{
	  string expenseid{};
	  int storeid{};
	  double rent{};
	  double maintenance{};
	  double utilities{};
	  string expensedate{};
};
struct Sales
{
	  int SALESID{};
	  int STOREID{};
	  int CUSTOMERID{};
	  string PURCHASEDATE{};
};
struct Payment
{
	  int paymentId{};
	  int customerId{};
	  string paymentDate{};
	  double amount{};
	  string paymentType{};
};
struct SaleDetail
{
	  string detailId{};
	  int salesId{};
	  string productId{};
	  int quantityOrdered{};
	  double priceEach{};
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

void readExpense(Connection* conn);
void insertExpense(Connection* conn);
void updateExpense(Connection* conn);
void deleteExpense(Connection* conn);

void readSales(Connection* conn);
void insertSales(Connection* conn);
void updateSales(Connection* conn);
void deleteSales(Connection* conn);

void readSaleDetail(Connection* conn);
void insertSaleDetail(Connection* conn);
void updateSaleDetail(Connection* conn);
void deleteSaleDetail(Connection* conn);

void readPayment(Connection* conn);
void insertPayment(Connection* conn);
void updatePayment(Connection* conn);
void deletePayment(Connection* conn);

void displayStores(Connection* conn);
void displayEmployees(Connection* conn);
void displayCustomers(Connection* conn);
void displayProducts(Connection* conn);
void displaySales(Connection* conn);
void displayExpense(Connection* conn);
void displayPayment(Connection* conn);
void displaySaleDetail(Connection* conn);

int main(void)
{
	  //OCCI VARIABLES
	  Environment* env = nullptr;
	  Connection* conn = nullptr;

	   // info of Alen Thomas :
	  string str;
	  string usr = "dbs311_222zc16";	  // this is your login assigned to you
	  string pass = "33411063";   // this is your password assigned to you
	  string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	  /*
	  //Hamit Sehjal's info

	  string str;
	  string usr = "dbs311_222zc48";	  // this is your login assigned to you
	  string pass = "11452277";   // this is your password assigned to you
	  string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	  */


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
				  cout << "5 MONTHLY EXPENSES" << endl;
				  cout << "6 SALES" << endl;
				  cout << "7 SALES DETAIL" << endl;
				  cout << "8 PAYMENTS" << endl;
				  cout << "0 Exit" << endl;
				  cout << "**************************************" << endl << ">";
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
				  case 5:
						displayExpense(conn);
						break;
				  case 6:
						displaySales(conn);
						break;
				  case 7:
						displaySaleDetail(conn);
						break;
				  case 8:
						displayPayment(conn);
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
void displaySales(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();
	  cout << "======================================" << endl;
	  cout << "|                SALES               |" << endl;
	  cout << "======================================" << endl;
	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "SALESID";
	  cout.width(20);
	  cout << "STOREID";
	  cout.width(20);
	  cout << "CUSTOMERNUBER";
	  cout.width(20);
	  cout << "DATE" << endl;


	  ResultSet* rs6 = stmt->executeQuery("SELECT * FROM SALES");
	  while (rs6->next())
	  {
			int SALESID = rs6->getInt(1);
			int STOREID = rs6->getInt(2);
			int CUSTOMERNUBER = rs6->getInt(3);
			string DATE = rs6->getString(4);

			cout.width(20);
			cout.setf(ios::left);
			cout << SALESID;
			cout.width(20);
			cout << STOREID;
			cout.width(20);
			cout << CUSTOMERNUBER;
			cout.width(20);
			cout << DATE << endl;
	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;

	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Insert a New Sale" << endl;
			cout << "2. Update an existing Sale" << endl;
			cout << "3. Delete an existing Sale" << endl;
			cout << "4. Extract a specific Sale" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertSales(conn);
				  break;
			case 2:
				  updateSales(conn);
				  break;
			case 3:
				  deleteSales(conn);
				  break;
			case 4:
				  readSales(conn);
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
void displayExpense(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();

	  cout << "======================================" << endl;
	  cout << "|          MONTHLY EXPENSES          |" << endl;
	  cout << "======================================" << endl;
	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "EXPENSE ID";
	  cout.width(20);
	  cout << "STOREID";
	  cout.width(20);
	  cout << "RENT";
	  cout.width(20);
	  cout << "MAINTANENCE";
	  cout.width(20);
	  cout << "UTILITIES";
	  cout.width(20);
	  cout << "EXPENSE DATE" << endl;
	  ResultSet* rs5 = stmt->executeQuery("SELECT * FROM monthlyexpenses");
	  while (rs5->next())
	  {
			string expense = rs5->getString(1);
			int STOREID = rs5->getInt(2);
			double RENT = rs5->getDouble(3);
			double MAINTANENCE = rs5->getDouble(4);
			double UTILITIES = rs5->getDouble(5);
			string expenseDate = rs5->getString(6);

			cout.width(20);
			cout.setf(ios::left);
			cout << expense;
			cout.width(20);
			cout << STOREID;
			cout.width(20);
			cout << fixed << setprecision(2) << RENT;
			cout.width(20);
			cout << fixed << setprecision(2) << MAINTANENCE;
			cout.width(20);
			cout << fixed << setprecision(2) << UTILITIES;
			cout.width(20);
			cout << expenseDate << endl;
	  }

	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;

	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Insert a New Expense" << endl;
			cout << "2. Update an existing Expense" << endl;
			cout << "3. Delete an existing Expense" << endl;
			cout << "4. Extract a specific Expense" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertExpense(conn);
				  break;
			case 2:
				  updateExpense(conn);
				  break;
			case 3:
				  deleteExpense(conn);
				  break;
			case 4:
				  readExpense(conn);
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
void displayPayment(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();

	  cout << "======================================" << endl;
	  cout << "|              PAYMENTS              |" << endl;
	  cout << "======================================" << endl;
	  ResultSet* rs8 = stmt->executeQuery("SELECT * FROM payments");

	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "PAYMENTID";
	  cout.width(20);
	  cout << "CUSTOMERID";
	  cout.width(20);
	  cout << "PAYMENTDATE";
	  cout.width(20);
	  cout << "AMOUNT";
	  cout.width(20);
	  cout << "PAYMENTTYPE" << endl;

	  while (rs8->next()) {
			int paymentId = rs8->getInt(1);
			int custNumber = rs8->getInt(2);
			string date = rs8->getString(3);
			double amount = rs8->getDouble(4);
			string paymentType = rs8->getString(5);
			cout.width(20);
			cout.setf(ios::left);
			cout << paymentId;
			cout.width(20);
			cout << custNumber;
			cout.width(20);
			cout << date;
			cout.width(20);
			cout << fixed << setprecision(2) << amount;
			cout.width(20);
			cout << paymentType << endl;
			cout.unsetf(ios::right);


	  }

	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;

	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Record a New Payment" << endl;
			cout << "2. Update an existing Payment" << endl;
			cout << "3. Delete an existing Payment" << endl;
			cout << "4. Extract a specific Payment" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertPayment(conn);
				  break;
			case 2:
				  updatePayment(conn);
				  break;
			case 3:
				  deletePayment(conn);
				  break;
			case 4:
				  readPayment(conn);
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
void displaySaleDetail(Connection* conn)
{
	  int option{ 0 };
	  bool flag{ true };
	  Statement* stmt = conn->createStatement();

	  cout << "======================================" << endl;
	  cout << "|            SALEDETAILS             |" << endl;
	  cout << "======================================" << endl;
	  cout.width(20);
	  cout.setf(ios::left);
	  cout << "SALE DETAIL ID";
	  cout.width(20);
	  cout << "SALESID";
	  cout.width(20);
	  cout << "PRODUCTID";
	  cout.width(20);
	  cout << "QUANTITYORDERED";
	  cout.width(20);
	  cout << "PRICEEACH" << endl;
	  ResultSet* rs7 = stmt->executeQuery("SELECT * FROM saledetails");
	  while (rs7->next())
	  {
			string DETAILID = rs7->getString(1);
			int SALESID = rs7->getInt(2);
			string PRODUCTID = rs7->getString(3);
			int QUANTITYORDERED = rs7->getInt(4);
			double PRICEEACH = rs7->getDouble(5);
			cout.width(20);
			cout.setf(ios::left);
			cout << DETAILID;
			cout.width(20);
			cout << SALESID;
			cout.width(20);
			cout << PRODUCTID;
			cout.width(20);
			cout << QUANTITYORDERED;
			cout.width(20);
			cout << fixed << setprecision(2) << PRICEEACH << endl;

	  }
	  conn->terminateStatement(stmt);
	  cout << "**************************************" << endl;

	  while (flag)
	  {

			cout << "\nDo you want to make any changes!!!" << endl;
			cout << "1. Record a SaleDetail" << endl;
			cout << "2. Update an existing SaleDetail" << endl;
			cout << "3. Delete an existing SaleDetail" << endl;
			cout << "4. Extract a specific SaleDetail" << endl;
			cout << "0. You want to Exit!!" << endl;
			cin >> option;

			switch (option)
			{
			case 1:
				  insertSaleDetail(conn);
				  break;
			case 2:
				  updateSaleDetail(conn);
				  break;
			case 3:
				  deleteSaleDetail(conn);
				  break;
			case 4:
				  readSaleDetail(conn);
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
			if (err > 0)
				  cout << "\nSUCCESS: Product updated.\n\n";
			else
				  cout << "\nERROR:Product not updated.\n\n";
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

void insertExpense(Connection* conn)
{
	  Expense exp;
	  int err = 0;
	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;

	  cout << "Enter expenseid : ";
	  cin >> exp.expenseid;
	  cout << "Enter storeid : ";
	  cin >> exp.storeid;
	  cout << "Enter rent : ";
	  cin >> exp.rent;
	  cout << "Enter maintenance : ";
	  cin >> exp.maintenance;
	  cout << "Enter utilities : ";
	  cin >> exp.utilities;
	  cout << "Enter expensedate : ";
	  cin >> exp.expensedate;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spMonthlyExpensesInsert(:1,:2,:3,:4,:5,:6,:7);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setNumber(2, exp.storeid);
			stmt->setDouble(3, exp.rent);
			stmt->setDouble(4, exp.maintenance);
			stmt->setDouble(5, exp.utilities);
			stmt->setString(6, exp.expensedate);
			stmt->setString(7, exp.expenseid);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: New Expense inserted.\n\n";
			else
				  cout << "\nERROR: Expense might already exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void readExpense(Connection* conn)
{
	  Expense exp;
	  int err = 0;
	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;

	  cout << "Enter expenseid : ";
	  cin >> exp.expenseid;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spMonthlyExpensesRead(:1,:2,:3,:4,:5,:6,:7);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, exp.expenseid);
			stmt->registerOutParam(3, Type::OCCIINT, sizeof(exp.storeid));
			stmt->registerOutParam(4, Type::OCCIDOUBLE, sizeof(exp.rent));
			stmt->registerOutParam(5, Type::OCCIDOUBLE, sizeof(exp.maintenance));
			stmt->registerOutParam(6, Type::OCCIDOUBLE, sizeof(exp.utilities));
			stmt->registerOutParam(7, Type::OCCISTRING, sizeof(exp.expensedate));
			stmt->executeUpdate();

			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err >= 0)
			{
				  cout << "\nSUCCESS: Expenses read.\n\n";
				  cout << "======================================" << endl;
				  cout << "|          MONTHLY EXPENSES          |" << endl;
				  cout << "======================================" << endl;
				  cout.width(20);
				  cout.setf(ios::left);
				  cout << "EXPENSEID";
				  cout.width(20);
				  cout << "STOREID";
				  cout.width(20);
				  cout << "RENT";
				  cout.width(20);
				  cout << "MAINTANENCE";
				  cout.width(20);
				  cout << "EXPENSEDATE";
				  cout.width(20);
				  cout << "UTILITIES" << endl;

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << stmt->getString(2);
				  cout.width(20);
				  cout << fixed << stmt->getInt(3);
				  cout.width(20);
				  cout << fixed << setprecision(2) << stmt->getDouble(4);
				  cout.width(20);
				  cout << fixed << setprecision(2) << stmt->getDouble(5);
				  cout.width(20);
				  cout << fixed << setprecision(2) << stmt->getDouble(6);
				  cout.width(20);
				  cout << fixed << setprecision(2) << stmt->getString(7) << endl;
			}
			// 7647546
			else
				  cout << "\nERROR: Expense might not exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void updateExpense(Connection* conn)
{
	  Expense exp;
	  int err = 0;
	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;

	  cout << "Enter expenseid : ";
	  cin >> exp.expenseid;
	  cout << "Enter storeid : ";
	  cin >> exp.storeid;
	  cout << "Enter rent : ";
	  cin >> exp.rent;
	  cout << "Enter maintenance : ";
	  cin >> exp.maintenance;
	  cout << "Enter utilities : ";
	  cin >> exp.utilities;
	  cout << "Enter expensedate : ";
	  cin >> exp.expensedate;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spMonthlyExpensesUpdate(:1,:2,:3,:4,:5,:6,:7);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setNumber(2, exp.storeid);
			stmt->setDouble(3, exp.rent);
			stmt->setDouble(4, exp.maintenance);
			stmt->setDouble(5, exp.utilities);
			stmt->setString(6, exp.expensedate);
			stmt->setString(7, exp.expenseid);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: Expense updated.\n\n";
			else
				  cout << "\nERROR: Expense not updated.\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void deleteExpense(Connection* conn)
{
	  Expense exp;
	  int err = 0;
	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "enter expenseid : ";
	  cin >> exp.expenseid;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spMonthlyExpensesDelete(:1,:2);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, exp.expenseid);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: Expense deleted.\n\n";
			else
				  cout << "\nERROR: Expense not deleted\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
//
void insertSales(Connection* conn)
{
	  Sales sale;
	  int err = 0;
	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;
	  cout << "Enter SalesID : ";
	  cin >> sale.SALESID;
	  cout << "Enter STOREID : ";
	  cin >> sale.STOREID;
	  cout << "Enter CUSTOMERID : ";
	  cin >> sale.CUSTOMERID;
	  cout << "Enter PURCHASEDATE : ";
	  cin >> sale.PURCHASEDATE;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSalesInsert(:1,:2,:3,:4,:5);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setNumber(2, sale.SALESID);
			stmt->setNumber(3, sale.STOREID);
			stmt->setNumber(4, sale.CUSTOMERID);
			stmt->setString(5, sale.PURCHASEDATE);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			if (err > 0)
				  cout << "\nSUCCESS: New sale inserted.\n\n";
			else
				  cout << "\nERROR: Sale might already exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void readSales(Connection* conn)
{
	  Sales sale;
	  int err = 0;
	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;
	  cout << "Enter SalesID : ";
	  cin >> sale.SALESID;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSalesRead(:1,:2,:3,:4,:5);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setInt(2, sale.SALESID);
			stmt->registerOutParam(3, Type::OCCIINT, sizeof(sale.STOREID));
			stmt->registerOutParam(4, Type::OCCIINT, sizeof(sale.CUSTOMERID));
			stmt->registerOutParam(5, Type::OCCISTRING, sizeof(sale.PURCHASEDATE));
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
			{
				  cout << "\nSUCCESS: Sales read.\n\n";
				  cout << "======================================" << endl;
				  cout << "|            SALESDETAILS            |" << endl;
				  cout << "======================================" << endl;
				  cout.width(20);
				  cout.setf(ios::left);
				  cout << "SALESID";
				  cout.width(20);
				  cout << "STOREID";
				  cout.width(20);
				  cout << "CUSTOMERID";
				  cout.width(20);
				  cout << "PURCHASEDATE" << endl;

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << stmt->getInt(2);
				  cout.width(20);
				  cout << fixed << stmt->getInt(3);
				  cout.width(20);
				  cout << fixed << stmt->getInt(4);
				  cout.width(20);
				  cout << fixed << stmt->getString(5) << endl;
			}
			else
				  cout << "\nERROR: Sales might not exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void updateSales(Connection* conn)
{
	  Sales sale;
	  int err = 0;
	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;
	  cout << "Enter SALESID : ";
	  cin >> sale.SALESID;
	  cout << "Update STOREID : ";
	  cin >> sale.STOREID;
	  cout << "Update CUSTOMERID : ";
	  cin >> sale.CUSTOMERID;
	  cout << "Update PURCHASEDATE : ";
	  cin >> sale.PURCHASEDATE;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSalesUpdate(:1,:2,:3,:4,:5);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setNumber(2, sale.SALESID);
			stmt->setNumber(3, sale.STOREID);
			stmt->setNumber(4, sale.CUSTOMERID);
			stmt->setString(5, sale.PURCHASEDATE);
			stmt->executeUpdate();
			err = stmt->getInt(1);
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
void deleteSales(Connection* conn)
{
	  Sales sale;
	  int err = 0;
	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "enter SalesID : ";
	  cin >> sale.SALESID;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSalesDelete(:1,:2);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setNumber(2, sale.SALESID);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			if (err > 0)
				  cout << "\nSUCCESS: Sales deleted.\n\n";
			else
				  cout << "\nERROR: Sales not deleted\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
//
void insertSaleDetail(Connection* conn)
{
	  SaleDetail detail;
	  int err = 0;

	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;

	  cout << "Enter SaleDetail id : ";
	  cin >> detail.detailId;
	  cout << "Enter Sales id : ";
	  cin >> detail.salesId;
	  cout << "Enter Product id: ";
	  cin >> detail.productId;
	  cout << "Enter Quantity Ordered: ";
	  cin >> detail.quantityOrdered;
	  cout << "Enter Price Each: ";
	  cin >> detail.priceEach;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSaleDetailsInsert(:1,:2,:3,:4,:5,:6);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, detail.detailId);
			stmt->setInt(3, detail.salesId);
			stmt->setString(4, detail.productId);
			stmt->setInt(5, detail.quantityOrdered);
			stmt->setDouble(6, detail.priceEach);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: New SaleDetail inserted.\n\n";
			else
				  cout << "\nERROR: SaleDetail might already exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void readSaleDetail(Connection* conn)
{
	  SaleDetail detail;
	  int err = 0;
	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;

	  cout << "Enter SaleDetail id : ";
	  cin >> detail.detailId;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSaleDetailsRead(:1,:2,:3,:4,:5,:6);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, detail.detailId);
			stmt->registerOutParam(3, Type::OCCIINT, sizeof(detail.salesId));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(detail.productId));
			stmt->registerOutParam(5, Type::OCCIINT, sizeof(detail.quantityOrdered));
			stmt->registerOutParam(6, Type::OCCIDOUBLE, sizeof(detail.priceEach));
			stmt->executeUpdate();

			err = stmt->getInt(1);
			string d_Id = stmt->getString(2);
			int s_Id = stmt->getInt(3);
			string p_Id = stmt->getString(4);
			int quantity = stmt->getInt(5);
			double price = stmt->getDouble(6);

			//cout << "error code i.e., rowcount " << err;
			if (err >= 0)
			{
				  cout << "\nSUCCESS: SaleDetails read.\n\n";

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << "SALE DETAIL ID";
				  cout.width(20);
				  cout << "SALES ID";
				  cout.width(20);
				  cout << "PRODUCT ID";
				  cout.width(20);
				  cout << "QUANTITY";
				  cout.width(20);
				  cout << "PRICE" << endl;

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << d_Id;
				  cout.width(20);
				  cout << s_Id;
				  cout.width(20);
				  cout << p_Id;
				  cout.width(20);
				  cout << quantity;
				  cout.width(20);
				  cout << fixed << setprecision(2) << price << endl;
				  cout.unsetf(ios::right);
			}
			else
				  cout << "\nERROR: SaleDetail might not exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void updateSaleDetail(Connection* conn)
{
	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;

	  SaleDetail detail;
	  int err = 0;
	  cout << "Enter Detail id : ";
	  cin >> detail.detailId;
	  cout << "Enter Sales id : ";
	  cin >> detail.salesId;
	  cout << "Enter Product id: ";
	  cin >> detail.productId;
	  cout << "Enter Quantity Ordered: ";
	  cin >> detail.quantityOrdered;
	  cout << "Enter Price Each: ";
	  cin >> detail.priceEach;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSaleDetailsUpdate(:1,:2,:3,:4,:5,:6);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, detail.detailId);
			stmt->setInt(3, detail.salesId);
			stmt->setString(4, detail.productId);
			stmt->setInt(5, detail.quantityOrdered);
			stmt->setDouble(6, detail.priceEach);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: SaleDetail updated.\n\n";
			else
				  cout << "\nERROR: SaleDetail not updated.\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void deleteSaleDetail(Connection* conn)
{
	  SaleDetail detail;
	  int err = 0;
	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "Enter SaleDetail id : ";
	  cin >> detail.detailId;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spSaleDetailsDelete(:1,:2);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setString(2, detail.detailId);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: SaleDetail deleted.\n\n";
			else
				  cout << "\nERROR: SaleDetail not deleted\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
//
void insertPayment(Connection* conn)
{
	  Payment pay;
	  int err = 0;
	  cout << "*** PROCESS OF INSERTION STARTS ***" << endl;

	  cout << "Enter Payment id : ";
	  cin >> pay.paymentId;
	  cout << "Enter Customer id : ";
	  cin >> pay.customerId;
	  cout << "Enter Payment Date: ";
	  cin >> pay.paymentDate;
	  cout << "Enter Amount: ";
	  cin >> pay.amount;
	  cout << "Enter Payment Type: ";
	  cin >> pay.paymentType;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spPaymentsInsert(:1,:2,:3,:4,:5,:6);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setInt(2, pay.paymentId);
			stmt->setInt(3, pay.customerId);
			stmt->setDouble(4, pay.amount);
			stmt->setString(5, pay.paymentType);
			stmt->setString(6, pay.paymentDate);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: New Payment inserted.\n\n";
			else
				  cout << "\nERROR: Payment might already exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void readPayment(Connection* conn)
{
	  Payment pay;
	  int err = 0;
	  cout << "*** PROCESS OF READING DATA STARTS ***" << endl;

	  cout << "Enter Payment id : ";
	  cin >> pay.paymentId;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spPaymentsRead(:1,:2,:3,:4,:5,:6);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setInt(2, pay.paymentId);
			stmt->registerOutParam(3, Type::OCCIINT, sizeof(pay.customerId));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(pay.paymentDate));
			stmt->registerOutParam(5, Type::OCCIDOUBLE, sizeof(pay.amount));
			stmt->registerOutParam(6, Type::OCCISTRING, sizeof(pay.paymentType));
			stmt->executeUpdate();

			err = stmt->getInt(1);
			int paymentId = stmt->getInt(2);
			int custNumber = stmt->getInt(3);
			string date = stmt->getString(4);
			double amount = stmt->getDouble(5);
			string paymentType = stmt->getString(6);

			if (err >= 0)
			{
				  cout << "\nSUCCESS: Payments read.\n\n";

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << "PAYMENTID";
				  cout.width(20);
				  cout << "CUSTOMERID";
				  cout.width(20);
				  cout << "PAYMENTDATE";
				  cout.width(20);
				  cout << "AMOUNT";
				  cout.width(20);
				  cout << "PAYMENTTYPE" << endl;

				  cout.width(20);
				  cout.setf(ios::left);
				  cout << paymentId;
				  cout.width(20);
				  cout << custNumber;
				  cout.width(20);
				  cout << date;
				  cout.width(20);
				  cout << fixed << setprecision(2) << amount;
				  cout.width(20);
				  cout << paymentType << endl;
				  cout.unsetf(ios::right);
			}
			else
				  cout << "\nERROR: Payment might not exist\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void updatePayment(Connection* conn)
{
	  Payment pay;
	  int err = 0;
	  cout << "*** PROCESS OF UPDATION STARTS ***" << endl;
	  cout << "Enter Payment id : ";
	  cin >> pay.paymentId;
	  cout << "Enter Customer id : ";
	  cin >> pay.customerId;
	  cout << "Enter Payment Date: ";
	  cin >> pay.paymentDate;
	  cout << "Enter Amount: ";
	  cin >> pay.amount;
	  cout << "Enter Payment Type: ";
	  cin >> pay.paymentType;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spPaymentsUpdate(:1,:2,:3,:4,:5,:6);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setInt(2, pay.paymentId);
			stmt->setInt(3, pay.customerId);
			stmt->setDouble(4, pay.amount);
			stmt->setString(5, pay.paymentType);
			stmt->setString(6, pay.paymentDate);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: Payment updated.\n\n";
			else
				  cout << "\nERROR: Payment not updated.\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
void deletePayment(Connection* conn)
{
	  Payment pay;
	  int err = 0;
	  cout << "*** PROCESS OF DELETION STARTS ***" << endl;
	  cout << "Enter Payment id : ";
	  cin >> pay.paymentId;
	  cout << endl;
	  try
	  {
			Statement* stmt = conn->createStatement();
			stmt->setSQL("BEGIN spPaymentsDelete(:1,:2);END;");
			stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
			stmt->setInt(2, pay.paymentId);
			stmt->executeUpdate();
			err = stmt->getInt(1);
			//cout << "error code i.e., rowcount " << err;
			if (err > 0)
				  cout << "\nSUCCESS: Payment deleted.\n\n";
			else
				  cout << "\nERROR: Payment not deleted\n\n";
			cout << "**************************************" << endl;
			conn->terminateStatement(stmt);
	  }
	  catch (SQLException& sqlExcp)
	  {
			std::cout << sqlExcp.getErrorCode() << ": "
				  << sqlExcp.getMessage();
	  }
}
