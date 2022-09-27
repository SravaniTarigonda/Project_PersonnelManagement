/********************************************************************************************
 * * FILE NAME           : personnel.hpp
 *
 * * DESCRIPTION         : This file consists of function declarations used in various functions
 *
 * * REVISION HISTORY    :
 *
 *	DATE		NAME		REASON
 *
 *	------          ------          -------
 *
 *******************************************************************************************/
#ifndef H_PERSONNEL
#define H_PERSONNEL
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int employee();
int project();
int emp_salary_list();
int query();
int payreport();
int emp_with_3_proj_report();
int addemp();
int editemp();
int delemp();
int viewemp();
int addproj();
int editproj();
int delproj();
int viewproj();
int view_emp_record();

struct emp_details
{
	int employee_id;
	char employee_name[20];
	char department[10];
	double basic_salary;
	char contact_number[15];
	int project_id[3];
	int no_hrs[3];
	int pr_count;
	double incentive;
	double epfdeduct;
	double income_deduct;
	double total_salary;
}empdetail;

/******************************************************************************************
 * CLASS NAME  : EMPLOYEE
 *
 * DESCRIPTION : This is the base class and consists of various variable
 *               initializations used in the employee function
 *
 * RETURN      : ---
 *
 *****************************************************************************************/               

class EMPLOYEE
{
	protected:
		int emp_id;
		char emp_name[20];
		char dept[10];
		double salary;
		char contact[15];
	public:
		EMPLOYEE()
		{
			int emp_id=100;
			double salary= 0;
		}
		void getdata();
};

/***********************************************************************************************************
 * CLASS NAME  : EMPLOYEE_PROJECT
 *
 * DESCRIPTION : This is the derived class and inheriting from the base class EMPLOYEE
 *               and  consists of various variable initializations used in the project function
 *
 * RETURN      : ----
 * 
 ***********************************************************************************************************/		 

class EMPLOYEE_PROJECT:public EMPLOYEE
{
	protected:
		int pr_no_prid[3];
		int pr_no_hrs[3];
		int project_counter;
	public:
		EMPLOYEE_PROJECT()
		{
			project_counter=0;
		}
};
/***********************************************************************************************************
 * CLASS NAME  : SALARY
 *
 * DESCRIPTION : This is the multi level derived class and inheriting from the  class EMPLOYEE_PROJECT 
 *               and  consists of various variable initializations used in the employee function
 *
 * RETURN      : ----
 * 
 **********************************************************************************************************/		 

class SALARY: public EMPLOYEE_PROJECT
{
	protected:
		double pr_bonus;
		double epf;
		double income_tax;
		double fi_salary;
	public:
		SALARY()
		{
			double epf=0;
			double income_tax=0;
			double fi_salary=0;
		}
		void calc_fi_salary();
		void add_employee();
		void view1();
		void view_employee();
		void editdata();
		void deldata();
		void salary_view();
		void view_emp_record();
		void emp_list_with_3_projects();
		void employee_file_to_list();
		void list_to_employee_file();
};

/******************************************************************************************
 * CLASS NAME  : PROJECT
 *
 * DESCRIPTION : This is the base class and consists of various variable
 *                initializations used in the project function
 *
 * RETURN      : ---
 *
 ******************************************************************************************/

struct temp
{
	char project_name[20];
	int t_members;
	int project_id;
}tmp;

class PROJECT
{
	protected:
		char pr_name[20];
	public:
		int team_mem;
		int pr_id;
		void getdata();
		void view();
		void edit();
		void del_project();
		void project_query();
		void project_file_to_list();
		void list_to_project_file();
};

list <SALARY> empsal_list;// Salary list Declaration
SALARY obj;
list <PROJECT> pr_list;
PROJECT pr_obj;





#endif
