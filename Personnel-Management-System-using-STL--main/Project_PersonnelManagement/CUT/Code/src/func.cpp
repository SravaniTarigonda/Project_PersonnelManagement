/*****************************************************************************************
 *
 * FILE NAME   : func.cpp
 *
 * DESCRPITION : This file defines the functions in the employee menu 
 *               to perform various operations in the employee database
 *
 * REVISION    :
 *
 * 	DATE		NAME		REASON
 *
 *       ----           -------         ------
 *
 ******************************************************************************************/       

#include<iostream>
#include<iomanip>
#include <list>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <mutex>
#include <thread>
#include "methods.cpp"
#include "edit_func.cpp"
#include "proj_func.cpp"
using namespace std;
using std::left;



/******************************************************************************************
 *
 * FUNCTION NAME  : getdata()
 *
 * DESCRIPTION    :  This function  writes the contents in to the employee database by
 *                 validating the input
 *
 * RETURN         : No Returns 
 *
 ****************************************************************************************/

void EMPLOYEE::getdata()
{
	int id=100;
	if(empsal_list.empty())//checking whether the employee list is present or not 
	{
		id=100;
	}
	else
	{
		for(SALARY it:empsal_list)
		{
			if(id<it.emp_id)
				id=it.emp_id;
		}
	}

	id+=1;
	obj.emp_id=id;
	cout<<"\n\nYou are entering the details for Employee Id: "<<obj.emp_id<<endl<<endl;

	while(1)
	{
		cout<<endl<<endl<<"\n  Enter the employee name - ";
		cin.ignore(1,'\n');
		cin.getline(emp_name,20);
		try
		{
			if(strlen(emp_name)<3 || strlen(emp_name)>20)//checking the length  of the employee name 
			{
				throw emp_name;
			}
		}
		catch(char *e)
		{
			cout<<"\n\n ---Name should be more than 2 and less than 20--- \n   TRY AGAIN !!!!!!!\n\n";
			continue;
		}
		try
		{
			for(int i=0;i<strlen(emp_name);i++)
			{
				if(!isalpha(emp_name[i]))//checking the name only consists of alphabets
				{
					throw emp_name;
				}
			}
		}
		catch(char *i)
		{
			cout<<"\n\n---Name should only consists of alphabets---\n   TRY AGAIN !!!!!!!\n\n";
			continue;
		}

		break;
	}		
	while(1)
	{
			cout<<endl<<"\n---Please enter department only  as IT Or HR or SALES or MARKETING --\n"<<endl;
		cout<<endl<<endl<<"  Enter Department- ";
		cin>>dept;
		for(int i=0;i<strlen(dept);i++)
		{
			dept[i]=toupper(dept[i]);//converting the input from the user in to upper case
		}
		if((strcmp(dept,"IT")==0) || (strcmp(dept,"HR")==0) || (strcmp(dept,"SALES")==0) || (strcmp(dept,"MARKETING")==0))
		{
			break;
		}
		else
		{
			cout<<"\n---Department should be either IT Or HR or SALES or MARKETING --\n";//checking the department name should be either IT OR HR OR SALES OR MARKETING
			continue;
		}
	}
	while(1)
	{
		cout<<endl<<endl<<"  Enter Contact Number- ";
		cin>>contact;
		try
		{
			if(strlen(contact)!=10)//checking the length of the contact entered
			{
				throw contact;
			}
		}
		catch(char *g)
		{
			cout<<"\n ----Mobile number should be 10 digits---\n";
			continue;
		}
		try
		{
			for(int i=0;i<strlen(contact);i++)
			{
				if(!isdigit(contact[i]))//checking the entered input is a digit or not
				{
					throw contact;
				}
			}
		}
		catch(char *f)
		{
			cout<<"\n ---Mobile number should only consists of digits---\n";
			continue;
		}
		break;
	}
	}






/******************************************************************************************
 *
 * FUNCTION NAME  : add_employee()
 *
 * DESCRIPTION    : This function  add project details to the employee in the employee database by
 *                  validating the input
 *
 * RETURN         : No Returns 
 *
 ******************************************************************************************/

void SALARY::add_employee()
{
	getdata();
	string yn;
	int fg=0;
	int proj_id;
	string proj_id1;
	int w_hrs;
	while(1)
	{
	        string salary1;
		cout<<endl<<endl<<"  Enter the Employee's CTC - ";
		cin>>salary1;
		try
		{
			for(int i=0;i<salary1.length();i++)
			{
				if(!isdigit(salary1[i]))//checking the entered input is a digit or not
				{
					throw salary1;
				}
			}
		}
		catch(string e)
		{
			cout<<"\n ---Salary should a number---\n";
			continue;
		}
		ctc=stod(salary1);
		if(ctc<=0)//checking salary should not be zero
		{
			cout<<"\n ----CTC should be greater than Rs. 100,000---\n";
			continue;
		}
		else if(ctc<100000 || salary>2000000)//checking that salary should be in a range
		{
			cout<<"\n ----CTC should be in the range 100,000 to 20,00,000---\n";
			continue;
		}
		else
			break;
	}

	cout<<endl<<endl<<"  Do you wish to add project for the employee?"<<endl;
	while(1)
	{
		cout<<endl<<"---Enter yes or no---"<<endl;
		cout<<endl<<"Your choice: ";
		cin>>yn;
		try
		{
			for(int i=0;i<yn.length();i++)
			{
				if(isdigit(yn[i]))//checking that entered choice should not be a digit
				{
					throw yn;
				}
			}
		}
		catch(string x)
		{
			cout<<"\n---Choice should be either yes or no .It cannot be a digit---\n";
			continue;
		}
		try
		{
			if((yn!="yes") && (yn!="no"))//checking whether the entered choice is yes or no 
			{
				fg=1;
				throw yn;
			}
		}
		catch (string y)
		{
			if(fg==1)
			{
				cout<<"\n\n ---Choice should be either yes or no ---\n\n";
				continue;
			}
		}
		break;
	}
	project_counter=0;
	int ch=0;
	while(ch==0)
	{       
		if(yn=="yes" && project_counter<3)//checking the entered choice is yes and project_counter should less than 3
		{
			while(1)
			{
				cout<<" Enter the project id: ";
				cin>>proj_id1;
				try
				{
					for(int i=0;i<proj_id1.length();i++)
					{
						if(!isdigit(proj_id1[i]))//checking the entered project id is a digit or not
						{
							throw proj_id1;
						}
					}
				}
				catch (string c)
				{
					cout<<"\n\n Project ID should be an integer !!!!\n\n";
					continue;
				}
				proj_id=stoi(proj_id1);
				break;
			}
			if(pr_list.empty())//checking the project list is empty or not
			{
				cout<<"----Your Database currently have no projects----"<<endl;
				break;
			}
			else
			{
				int flag;
				for (std::list<PROJECT>::iterator it = pr_list.begin(); it != pr_list.end(); ++it)
				{
					flag=0;
					string w_hrs1;
					if(it->pr_id==proj_id)//checking the project id matches with the id in the list or not
					{
						if(it->team_mem==15)
						{
							cout<<"---This Project already have 15 members---"<<endl;
							break;
						}
						else
						{
							while(1)
							{
								cout<<" Enter the no. of hours employee worked on this project: ";
								cin>>w_hrs1;
								try
								{
									for(int i=0;i<w_hrs1.length();i++)
									{
										if(!isdigit(w_hrs1[i]))//checking the number of hours entered is a digit or not
										{
											throw w_hrs1;
										}
									}
								}
								catch (string c)
								{
									cout<<"\n\n ---Number of working hours should be an integer---\n\n";
									continue;
								}
								w_hrs=stoi(w_hrs1);
								break;
							}
						}
						if(project_counter==0)
						{
							pr_no_prid[0]=proj_id;
							pr_no_hrs[0]=w_hrs;
						}
						else if(project_counter==1)
						{
							pr_no_prid[1]=proj_id;
							pr_no_hrs[1]=w_hrs;
						}
						else 
						{
							pr_no_prid[2]=proj_id;
							pr_no_hrs[2]=w_hrs;
						}
						project_counter++;//incrementing the project counter
						it->team_mem++;
						break;
					}	
					else
					{
						flag=1;
						continue;
					}
				}
				if(flag==1)
					cout<<"---This project id doesn't exists in the list---"<<endl;
			}
			while(1)
			{
				string choice;
				cout<<"---Press 0 to continue adding projects for the employee OR any other number to return to menu---"<<endl;
				cin>>choice;
				try
				{
					for(int i=0;i<choice.length();i++)
					{
						if(!isdigit(choice[i]))//checking the choice is a digit or not
						{
							throw choice;
						}
					}
				}
				catch (string y)
				{
					cout<<"\n ---choice should be digit---\n";
					continue;
				}
				ch=stoi(choice);
				break;
			}
			if(ch==0)
			{
				continue;
			}
			else if(ch>0)
			{
				break;
			}
			else
			{
				break;
			}

		}
		else if(project_counter>=3)//checking the value of the project_counter
		{
			cout<<endl<<endl<<"---This employee already have 3 Projects. Cannot assign any more projects---"<<endl;
			break;
		}
		else
		{
			project_counter=0;
			break;
		}


	}
}




/* View the employee details in horizontal table*/
void SALARY::view_employee()
{
	cout<<endl<<setw(25)<<left<<emp_id<<setw(25)<<left<<emp_name<<setw(20)<<left<<dept<<setw(20)<<left<<contact<<setw(20)<<left<<project_counter<<endl;

}




/* View the employee record for the given employee id*/

void SALARY::view_emp_project_detail()
{
	cout<<endl<<"Employee Id: "<<emp_id<<endl<<"Employee Name: "<<emp_name<<endl;
	cout<<endl<<"Department: "<<dept<<endl<<"Contact Number: "<<contact<<endl;
	cout<<endl<<"CTC: "<<ctc<<endl;
	cout<<endl<<"No. of Projects: "<<project_counter<<endl;
	if(project_counter==0)
	{
		cout<<"Not assigned at any project yet"<<endl;
	}
	else if(project_counter==1)
	{
		cout<<endl<<"Project 1 ID: "<<setw(10)<<pr_no_prid[0]<<"   "<<"No. of hours worked on project 1: "<<setw(5)<<pr_no_hrs[0]<<endl;
	}
	else if(project_counter==2)
	{
		cout<<endl<<"Project 1 ID: "<<setw(10)<<pr_no_prid[0]<<"   "<<"No. of hours worked on project 1: "<<setw(5)<<pr_no_hrs[0]<<endl;
		cout<<endl<<"Project 2 ID: "<<setw(10)<<pr_no_prid[1]<<"   "<<"No. of hours worked on project 2: "<<setw(5)<<pr_no_hrs[1]<<endl;
	}
	else
	{
		cout<<endl<<"Project 1 ID: "<<setw(10)<<pr_no_prid[0]<<"   "<<"No. of hours worked on project 1: "<<setw(5)<<pr_no_hrs[0]<<endl;
		cout<<endl<<"Project 2 ID: "<<setw(10)<<pr_no_prid[1]<<"   "<<"No. of hours worked on project 2: "<<setw(5)<<pr_no_hrs[1]<<endl;
		cout<<endl<<"Project 3 ID: "<<setw(10)<<pr_no_prid[2]<<"   "<<"No. of hours worked on project 3: "<<setw(5)<<pr_no_hrs[2]<<endl;
	}
}



/*View the employee project report for the particular employee by entering the employee id*/

void SALARY :: view_emp_record()
{
	if(empsal_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{
		int ed;
		while(1)
		{	
			string eid1;
			cout<<"Enter the employee id to see the project details: ";
			cin>>eid1;
			try
			{
				for(int i=0;i<eid1.length();i++)
				{
					if(!isdigit(eid1[i]))
					{
						throw eid1;
					}
				}
			}
			catch(string h)
			{
				cout<<"\n\n Employee ID should be an integer !!!!!\n\n";
				continue;
			}
			ed=stoi(eid1);
			break;
		}
		int flag;
		for(SALARY st:empsal_list)
		{
			flag=0;
			if(ed==st.emp_id)
			{
				cout<<"------------------------------------------------------------"<<endl;
				st.view_emp_project_detail();
				cout<<"------------------------------------------------------------"<<endl;
				break;
			}
			else
			{
				flag=1;
				continue;
			}
		}
		if(flag==1)
			cout<<"This id doesn't exists"<<endl;
	}
}



/*View the employees working on 3 projects at a time from the employee list*/

void SALARY :: emp_list_with_3_projects()
{
	if(empsal_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{
		int flag;
		for(SALARY st:empsal_list)
		{
			flag=0;
			if(st.project_counter==3)
			{
				cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<setw(25)<<left<<"Employee Id"<<setw(20)<<left<<"Name"<<setw(20)<<left<<"Department"<<setw(20)<<left<<"Contact Number"<<setw(20)<<left<<"No. of Projects"<<endl;
				cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
				st.view_employee();
				cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
				break;
			}
			else
			{
				flag=1;
				continue;
			}
		}
		if(flag==1)
			cout<<"No employee is currently working on 3 Projects."<<endl;

	}
}



/******************************************************************************************
 *
 * FUNCTION NAME  : deldata()
 *
 * DESCRIPTION    :  This function deletes the employee details from the employee database
 *
 * RETURN         : No Returns 
 *
 ****************************************************************************************/

void SALARY::deldata()
{
	int ed;
	int flag;
	if(empsal_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else{
		while(1)
		{
			string ed1;
			cout<<"Enter the employee id to delete: ";
			cin>>ed1;
			try
			{
				for(int i=0;i<ed1.length();i++)
				{
					if(!isdigit(ed1[i]))
					{
						throw ed1;
					}
				}
			}
			catch (string e)
			{
				cout<<"\n\n Employee id should be an integer !!!!!\n\n";
				continue;
			}
			ed=stoi(ed1);
			break;
		}
		for (std::list<SALARY>::iterator it = empsal_list.begin(); it != empsal_list.end(); ++it)
		{
			flag=0;
			if(it->emp_id==ed)
			{
				if(it->project_counter==0)
				{
					it = empsal_list.erase(it);
					cout<<"**Deleted Successfully**"<<endl;
				}
				else
					cout<<"\n   This employee has some projects . It cannot be removed\n";
				break;
			}
			else
			{
				flag=1;
				continue;
			}
		}
		if(flag==1)
			cout<<"This employee id doesn't exists!!!!"<<endl;
	}
}




/*  View the final salary of all the employees after adding the bonus and deducting the incentives and income tax in the base salary*/

void SALARY::salary_view()
{
	if(empsal_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{
		int working_days=23;
		double gross_salary;
		double sal;
			cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(20)<<left<<"Employee Id"<<setw(20)<<left<<"Name"<<setw(20)<<left<<"Basic Salary"<<setw(20)<<left<<"Incentives"<<setw(20)<<left<<"EPF"<<setw(20)<<"Income Tax"<<setw(20)<<left<<"Total Salary"<<endl;
			cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		for (std::list<SALARY>::iterator it = empsal_list.begin(); it != empsal_list.end(); ++it)
		{
			gross_salary=it->ctc;
			sal=(gross_salary/12);
			it->salary=sal;
			if(it->project_counter==0)
				it->pr_bonus=0;
			else
			{
				it->pr_bonus = double ((45 * 9 * working_days) + (it->pr_no_hrs[0]*10) + (it->pr_no_hrs[1]*10) + (it->pr_no_hrs[2]*10));
			}

			double bonus =it->pr_bonus;
			it->epf = (sal*8.5)/100;
			it->income_tax = (sal*15)/100;
			it->fi_salary = (sal+bonus) - it->income_tax - it->epf;
			cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<setw(20)<<left<<it->emp_id<<setw(20)<<left<<it->emp_name<<setw(20)<<left<<it->salary<<setw(20)<<left<<it->pr_bonus<<setw(20)<<left<<it->epf<<setw(20)<<it->income_tax<<setw(20)<<left<<it->fi_salary<<endl;
			cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		}
	}
}



/* View the final salary of an employee in  the list by entering the employee id */

void SALARY::calc_fi_salary()
{
	string eid3;

	int ed;
	if(empsal_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{
		double sal;
		double gross_salary;
		int flag;
		int working_days=23;

		while(1)
		{
			cout<<"Enter the employee id : ";
			cin>>eid3;
			try
			{
				for(int i=0;i<eid3.length();i++)
				{
					if(!isdigit(eid3[i]))
					{
						throw eid3;
					}
				}
			}
			catch(string h)
			{
				cout<<"\n\n Employee ID should be an integer !!!!!\n\n";
				continue;
			}
			ed=stoi(eid3);
			cout<<ed<<endl;
			break;
		}
		for (std::list<SALARY>::iterator it = empsal_list.begin(); it != empsal_list.end(); ++it)
		{

			if(it->emp_id==ed)
			{
				flag=0;
				gross_salary=it->ctc;
				sal=(gross_salary/12);
				it->salary=sal;
				if(it->project_counter==0)
					it->pr_bonus=0;
				else
				{
					it->pr_bonus = double ((45 * 9 * 23) + (it->pr_no_hrs[0]*10) + (it->pr_no_hrs[1]*10) + (it->pr_no_hrs[2]*10));
				}

				double bonus =it->pr_bonus;
				it->epf = (sal*8.5)/100;
				it->income_tax = (sal*15)/100;
				it->fi_salary = (sal+bonus) - it->income_tax - it->epf;
				cout<<"--------------------------------------------------------------------------------------------------"<<endl;
				cout<<"             MARSPRO ORGANISATION "<<endl;
				cout<<"             Pay Slip for employee "<<it->emp_name<<endl;
				cout<<"--------------------------------------------------------------------------------------------------"<<endl;
				cout<<setw(20)<<left<<"Basic Salary"<<setw(20)<<left<<"Incentives"<<"   ||  "<<setw(20)<<left<<"EPF"<<setw(20)<<"Income Tax"<<endl;
				cout<<setw(20)<<left<<it->salary<<setw(20)<<left<<it->pr_bonus<<"   ||  "<<setw(20)<<left<<it->epf<<setw(20)<<it->income_tax<<endl;
				cout<<endl<<endl<<"Total Salary ="<<it->fi_salary<<endl<<endl;
				cout<<"--------------------------------------------------------------------------------------------------"<<endl;
				break;

			}
			else
			{
				flag=1;
				continue;
			}
		}
		if(flag==1)
			cout<<"This employee id doesn't exists!!!!"<<endl;

	}
}

