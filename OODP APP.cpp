#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

class employees;
class books
{
	int book_id;		
	string name;
	string auth;
	int price;
public:
	void storebook();
	void search();
	void display();
	friend class employees;
};
class issues
{
	int book_id;
	string name;
	string i_date;
	string d_date;
	int cos_id;		
public:
	void new_iss();
	void view_iss();
};
class purchases
{
	int book_id;
	string name;
	int price;
	int cos_id;		
public:
	void new_ord();
	void view();
};
class employees:public books
{
	int emp_id;	
	string name;
	string addr_city;
	long int phn;
	long int salary;
public:
	void add();
	void add_emp();
	void display();
};
class customers
{
    int cos_id;	
	string name;
	string addr_city;
	long int phn;
public:
	void add_cos();
	void cos_display();
};

void books::display()
{
	ifstream fin;
	fin.open("BOOKS.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	do
	{
		fin.read((char*)this,sizeof(*this));
	}while(!fin.eof());
	fin.close();
}
void issues::new_iss()
{
	cout<<"Customer name: ";
	cin>>name;
	cout<<"Customer ID: ";
	cin>>cos_id;
	cout << "Enter the book name : ";
	cin >> name;
	cout<<"Issue Date : ";
	cin>>i_date;
	cout<<"Due Date : ";
	cin>>d_date;
	cout << "Book Issued!!";
	ofstream fout;
	fout.open("ISSUES.txt",ios::in|ios::binary);
	fout.write((char*)this,sizeof(*this));
}
void issues::view_iss()
{
	ifstream fin;
	fin.open("ISSUES.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	do
	{
		fin.read((char*)this,sizeof(*this));
	}while(!fin.eof());
	fin.close();
	
}
void purchases::new_ord()
{
	cout<<"Customer name: ";
	cin>>name;
	cout<<"Customer ID: ";
	cin>>cos_id;
	cout << "Enter the book name : ";
	cin >> name;
	cout<<"Cost: Rs.";
	cin>>price;
	cout << "New order Added!!";
	ofstream fout;
	fout.open("SALES.txt",ios::in|ios::binary);
	fout.write((char*)this,sizeof(*this));
}
void purchases::view()
{
	ifstream fin;
	fin.open("SALES.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	do
	{
		fin.read((char*)this,sizeof(*this));
	}while(!fin.eof());
	fin.close();
}
void employees::add()
{
	cout << "Enter the book Id : ";
	cin >> book_id;
	cout << "Enter the name of the book : " ;
	cin >> name;
	cout << "Enter the name of the author : ";
	cin >> auth;
	cout << "Enter the Price : ";
	cin >> price;
	ofstream fout;
	fout.open("BOOKS.txt",ios::in|ios::binary);
	fout.write((char*)this,sizeof(*this));
}
void employees::add_emp()
{
	cout << "Enter The details of new employees!!" <<endl <<endl;
	cout << "Enter The name of the employee : ";
	cin >> name;
	cout << "Enter the employee Id : ";
	cin >> emp_id;
	cout << "Enter the Address : " << endl;
	cin >> addr_city;
	cout << "Enter phone no.";
	cin >> phn;
	cout << "Enter the salary : ";
	cin >> salary;
	cout << endl << endl << "Employee Added Succesfully!" << endl;
	ofstream fout;
	fout.open("STAFF.txt",ios::in|ios::binary);
	fout.write((char*)this,sizeof(*this));
}
void employees::display()
{
	ifstream fin;
	fin.open("STAFF.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	do
	{
		fin.read((char*)this,sizeof(*this));
	}while(!fin.eof());
	fin.close();
}
void customers::add_cos()
{
	cout << "Enter the name of the Customer : ";
	cin >> name;
	cout << "Enter phone no. : ";
	cin >> phn;
	cout << "Enter address :" << endl;
	cin >> addr_city;
	cout << "Customer Added successfully" << endl;
	ofstream fout;
	fout.open("CUSTOMER.txt",ios::in|ios::binary);
	fout.write((char*)this,sizeof(*this));
}
void customers::cos_display()
{
	ifstream fin;
	fin.open("CUSTOMER.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	do
	{
		fin.read((char*)this,sizeof(*this));
	}while(!fin.eof());
	fin.close();
}

void book_menu();
void iss_menu();
void pur_menu();
void emp_menu();
void cos_menu();

inline void main_menu()
{
	int c;
	cout << "*************************************************" << endl;
	cout << "         LIBRARY MANGEMENT SYSTEM" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. BOOKS" << endl;
	cout << "   2. ISSUES" << endl;
	cout << "   3. PURCHASES" << endl;
	cout << "   4. EMPLOYEES" << endl;
	cout << "   5. CUSTOMERS" << endl;
	cout << "   6. EXIT" << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			system("cls");
			book_menu();
			getch();
			break;
		case 2:
			system("cls");
			iss_menu();
			getch();
			break;
		case 3:
			system("cls");
			pur_menu();
			getch();
			break;
		case 4:
			system("cls");
			emp_menu();
			getch();
			break;
		case 5:
			system("cls");
			cos_menu();
			getch();
			break;
		case 6:
			exit(1);
		default:
			system("cls");
			cout <<"\nInvalid input";
			getch();
			break;
	}
	return;
}

inline void book_menu()
{
	int c;
	books b;
	cout << "*************************************************" << endl;
	cout << "                  BOOK MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. DISPLAY ALL" << endl;
	cout << "   2. RETURN TO MAIN MENU" << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			b.display();
			break;
		case 2:
			return;
			break;
		default:
			cout <<"\nInvalid input";
			break;
	}
	return;
}
inline void iss_menu()
{
	int c;
	issues i;
	cout << "*************************************************" << endl;
	cout << "                ISSUES MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. New Issue" << endl;
	cout << "   2. View All Issues" << endl;
	cout << "   3. RETURN TO MAIN MENU" << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			i.new_iss();
			break;
		case 2:
			i.view_iss();
			break;
		case 3:
			return;
		default:
			cout <<"\nInvalid input";
			break;
	}
}
inline void pur_menu()
{
	int c;
	purchases p;
	cout << "*************************************************" << endl;
	cout << "                PURCHASES MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. New Order" << endl;
	cout << "   2. View All Purchase" << endl;
	cout << "   3. RETURN TO MAIN MENU" << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			p.new_ord();
			break;
		case 2:
			p.view();
			break;
		case 3:
			return;
		default:
			cout <<"\nInvalid input";
			break;
	}
}
inline void emp_menu()
{
	int c;
	employees e;
	cout << "*************************************************" << endl;
	cout << "                 EMPLOYEE MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. New Employee" << endl;
	cout << "   2. Add Book" << endl;
	cout << "   3. View All Employees" << endl;
	cout << "   4. RETURN TO MAIN MENU" << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			e.add_emp();
			break;
		case 2:
			e.add();
			break;
		case 3:
			e.display();
			break;
		case 4:
			return;
		default:
			cout <<"\nInvalid input";
			break;
	}
}
inline void cos_menu()
{
	int c;
	customers m;
	cout << "*************************************************" << endl;
	cout << "                 CUSTOMERS MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. New Customer" << endl;
	cout << "   2. View Customer" << endl;
	cout << "   3. RETURN TO MAIN MENU" << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			m.add_cos();
			break;
		case 2:
			m.cos_display();
			break;
		case 3:
			return;
		default:
			cout <<"\nInvalid input";
			break;
	}
}

int main()
{
	while(1)
	{
		system("cls");
		main_menu();
	}
	return 0;
}