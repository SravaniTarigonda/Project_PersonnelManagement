/*****************************************************************************************
 *
 * FILE NAME   : methods.cpp
 *
 * DESCRPITION : This file has all the methods which are called in the main.cpp file.
 *
 * METHODS     : addemp, editemp, viewemp, delemp,addproj,editproj,viewproj,delproj,
 * 		 payreport,emp_with_3_proj_report,view_emp_rec,emp_salary_list,query
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
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

mutex accum_mutex;//declaring accumulator


/* This function calls the getdata1 function and pushes the info in to the employee list */

int add_employee()
{
	system("read");
	system("clear");
	int ch=0;
	while(ch==0)
	{
		obj.add_employee();
		empsal_list.push_back(obj); //Inserting the detail into the emp_sal list through the object obj
		while(1)
		{
			string ch1;
			int f2=0;
			cout<<endl<<" ---Enter 0 to continue adding employee details -"; //Press 0 to add another employee details and any other number to stop adding the details
			cin>>ch1;
			for(int i=0;i<ch1.length();i++)
			{
				if(!isdigit(ch1[i]))
				{
					f2=1;
					break;
				}
			}
			if(f2==1)
			{
				cout<<"\n\n choice should be a digit !!!!!!\n\n        TRY AGAIN        \n\n";
				continue;
			}
			else
			{
				ch=stoi(ch1);
				break;
			}
		}
	}
	return EXIT_SUCCESS;

}

/* This function calls the view_employee function and displays the employee list */
int view_employee()
{
	system("read");
	system("clear");
	if(empsal_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{
		cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<setw(25)<<left<<"Employee Id"<<setw(20)<<left<<"Name"<<setw(20)<<left<<"Department"<<setw(20)<<left<<"Contact Number"<<setw(20)<<left<<"No. of Projects"<<endl;
		cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
		for(SALARY st:empsal_list)
		{
			st.view_employee();	
		}
		cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
	}
	return EXIT_SUCCESS;

}

/* This function calls the editdata function and edits the details in theemployee list */

int edit_employee()
{
	system("read");
	system("clear");
	obj.editdata();
	return EXIT_SUCCESS;
}

/* This function calls the deldata function and deletes the details in the employee list */

int del_employee()
{
	system("read");
	system("clear");
	obj.deldata();
	return EXIT_SUCCESS;
}

/* This function calls the calc_fi_salary function and displays the salary for all the employee in  employee list */

int payreport()


{
	system("read");
	system("clear");

	accum_mutex.lock(); //Locking thread
	obj.calc_fi_salary();

	accum_mutex.unlock(); //Unlocking thread
	return EXIT_SUCCESS;
}

/* This function calls the emp_list_with_3_projects function and displays the list of employees working on 3 projects in  the employee list */

int emp_with_3_proj_report()
{
	system("read");
	system("clear");
	obj.emp_list_with_3_projects();
	return EXIT_SUCCESS;
}

/* This function calls the view_emp_record function and displays the employee details along with number of projects */

int view_emp_record()
{
	system("read");
	system("clear");
	accum_mutex.lock(); //Locking thread

	if(empsal_list.empty())
	{
		cout<<"Your employee database doesn't have any records."<<endl;
	}
	else
	{
		obj.view_emp_record();

	}
	accum_mutex.unlock(); //Unlocking thread
	return EXIT_SUCCESS;
}

/* This function calls the salary_view function and displays the details of salary */ 

int emp_salary_list()
{
	system("read");
	system("clear");
	obj.salary_view();
	return EXIT_SUCCESS;
}



/* This function calls the getdata function and pushes the info in to the project list */

int add_project()
{
	system("read");
	system("clear");
	int ch=0;
	string choice;
	int flag=0;
	while(ch==0)
	{
		pr_obj.getdata(); //Calling getdata member function to take input from the user
		pr_list.push_back(pr_obj); //Pushing the details of project through object
		while(1)
		{
			cout<<endl<<"---Press 0 to continue OR any other number to return to menu---"<<endl;
			cout<<endl<<"Your choice: ";
			cin>>choice;
			try
			{
				for(int i=0;i<choice.length();i++)
				{
					if(!isdigit(choice[i])) //Checking whether choice is a digit or not
					{
						throw choice;
					}
				}
			}
			catch (string x)
			{
				cout<<"\n ---choice should be digit !!!\n";
				continue;
			}
			ch=stoi(choice);
			if(ch==0)
			{
				pr_obj.getdata();
				pr_list.push_back(pr_obj);
				continue;
			}
			else
			{
				break;
			}
			break;
		}
	}
	system("read");
	system("clear");
	return EXIT_SUCCESS;
}


/* This function calls the viewproj function and displays the project list */

int view_project()
{
	system("read");
	system("clear");
	if(pr_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{

		cout<<"------------------------------------------------------------------------------------"<<endl;
		cout<<setw(30)<<left<<"Project Id"<<setw(30)<<left<<"Name"<<setw(30)<<left<<"Team Members"<<endl;
		cout<<"------------------------------------------------------------------------------------"<<endl;
		for(PROJECT st:pr_list)
		{
			st.view();
		}
		cout<<"------------------------------------------------------------------------------------"<<endl;
	}
	return EXIT_SUCCESS;
}

/* This function calls the edit function and edits the details in the project list */

int edit_project()
{
	system("read");
	system("clear");
	if(pr_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{

		pr_obj.edit();  //calling edit member function of class PROJECT with its object
	}
	return EXIT_SUCCESS;
}


/* This function calls the del_proj function and deletes the details in the project list */

int del_project()
{
	system("read");
	system("clear");
	if(pr_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{

		pr_obj.del_project();
	}
	return EXIT_SUCCESS;
}

/* This function calls the project_query function and displays the top project */

int query()
{
	system("read");
	system("clear");
	if(pr_list.empty())
	{
		cout<<"   ---List is empty----"<<endl;
	}
	else
	{

		pr_obj.project_query();
	}
	return EXIT_SUCCESS;
}
