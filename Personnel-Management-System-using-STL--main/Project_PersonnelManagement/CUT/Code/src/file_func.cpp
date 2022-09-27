/*******************************************************
* * FILE NAME   : file_func.cpp
*
* * DESCRIPTION : This file consists of file_to_list and list_to_file
* 		  operations for employee and project details
*
* * REVISION 	: 
*
* 	DATE		NAME		REASON
*
* 	----		----		------
*
********************************************************/  

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "func.cpp"
using namespace  std;


/*******************************************************
* * FUNCTION NAME   : employee_file_to_list
*
* * DESCRIPTION     : This function creates or open an existing Employee file and 
* 		      read data from file to list  
*
* * RETURN 	    :  ------
*
*
********************************************************/  

void SALARY::employee_file_to_list()
{
	ifstream emp_file("Employee");
	if(emp_file)
	{
		emp_file.read((char *) &empdetail,sizeof(emp_details));
		SALARY sal_obj; 
		while(!emp_file.eof())
		{
			sal_obj.emp_id = empdetail.employee_id;
			strcpy(sal_obj.emp_name , empdetail.employee_name);
			strcpy(sal_obj.dept , empdetail.department);
			sal_obj.salary = empdetail.basic_salary;
			strcpy(sal_obj.contact , empdetail.contact_number);

			sal_obj.pr_no_prid[0] = empdetail.project_id[0];
			sal_obj.pr_no_prid[1] = empdetail.project_id[1];
			sal_obj.pr_no_prid[2] = empdetail.project_id[2];

			sal_obj.pr_no_hrs[0] = empdetail.no_hrs[0];
			sal_obj.pr_no_hrs[1] = empdetail.no_hrs[1];
			sal_obj.pr_no_hrs[2] = empdetail.no_hrs[2];

			sal_obj.project_counter = empdetail.pr_count;
			sal_obj.ctc = empdetail.gross_salary;
			sal_obj.pr_bonus = empdetail.incentive;
			sal_obj.epf = empdetail.epfdeduct;
			sal_obj.income_tax = empdetail.income_deduct;
			sal_obj.fi_salary = empdetail.total_salary;
			empsal_list.push_back(sal_obj);

			emp_file.read((char *) &empdetail,sizeof(emp_details));
		}
		emp_file.close();
	}
}

/*******************************************************
* * FUNCTION NAME   : list_to_employee_file
*
* * DESCRIPTION     : This function writes the data into a employee_file from list
*
* * RETURN 	    :  ------
*
********************************************************/
void SALARY :: list_to_employee_file()
{
	fstream emp_file;
	if(!empsal_list.empty())
	{
		emp_file.open("Employee", ios::out);
		for(list<SALARY> :: iterator  it=empsal_list.begin(); it!=empsal_list.end();it++)
		{
			empdetail.employee_id = it->emp_id;
			strcpy( empdetail.employee_name , it->emp_name );
			strcpy( empdetail.department,it->dept );

			empdetail.basic_salary = it->salary;

			strcpy( empdetail.contact_number , it->contact );

			empdetail.project_id[0] = it->pr_no_prid[0];
			empdetail.project_id[1] = it->pr_no_prid[1];
			empdetail.project_id[2] = it->pr_no_prid[2];

			empdetail.no_hrs[0] = it->pr_no_hrs[0];
			empdetail.no_hrs[1] = it->pr_no_hrs[1];
			empdetail.no_hrs[2] = it->pr_no_hrs[2];

			empdetail.pr_count = it->project_counter;
			empdetail.gross_salary = it->ctc;
			empdetail.incentive = it->pr_bonus;
			empdetail.epfdeduct = it->epf;
			empdetail.income_deduct = it->income_tax;
			empdetail.total_salary = it->fi_salary;

			emp_file.write((char *) &empdetail , sizeof(emp_details));
		}
		emp_file.close();
	}
}




/*******************************************************
* * FUNCTION NAME   : project_file_to_list
*
* * DESCRIPTION     : This function creates or open an existing project file and 
* 		      read data from file to list  
*
* * RETURN 	    :  ------
*
********************************************************/
void PROJECT::project_file_to_list()
{
	ifstream project_file("Project");
	if(project_file)
	{
		project_file.read((char *) &projdetail,sizeof(pr_details));
		PROJECT obj; 
		while(!project_file.eof())
		{
			strcpy( obj.pr_name, projdetail.project_name );
			obj.team_mem = projdetail.t_members;
			obj.pr_id = projdetail.project_id;
			pr_list.push_back(obj);
			project_file.read((char *) &projdetail,sizeof(pr_details));
		}
		project_file.close();
	}
}


/*******************************************************
* * FUNCTION NAME   : list_to_project_file
*
* * DESCRIPTION     : This function writes the data into a project_file from list
*
* * RETURN 	    :  ------
*
********************************************************/

void PROJECT :: list_to_project_file()
{
	fstream project_file;
	if(!pr_list.empty())
	{
		project_file.open("Project", ios::out);
		for(list<PROJECT> :: iterator  it=pr_list.begin(); it!=pr_list.end();it++)
		{
			strcpy( projdetail.project_name, it->pr_name );
			projdetail.t_members = it->team_mem;
			projdetail.project_id = it->pr_id;
			project_file.write((char *) &projdetail , sizeof(pr_details));
		}
		project_file.close();
	}
}




