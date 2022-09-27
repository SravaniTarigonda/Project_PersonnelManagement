/******************************************************************************************************************
 * * FILE NAME        :  menu.cpp
 *
 * * DESCRIPTION      : This file consists of Employee menu and project menu for performing various operations
 *
 * * REVISION HISTORY : 
 *              
 * 	DATE		NAME		REASON
 *
 * 	-----           -------         -------
 *
 * ******************************************************************************************************************/

#include<iostream>
using namespace std;

/******************************************************************************************************************
 * * FUNCTION NAME : employee
 *
 * * DESCRIPTION   : This function display various functions in the employee function
 *
 * * RETURN        :  1. Add Employee
 *                    2. Edit Employee
 *                    3. View Employee
 *                    4. Delete Employee
 *                    5. Return to main menu
 *         
 ****************************************************************************************************************/

int employee()
{
system("read");
system("clear");
	string pass;
	cout<<"\n Enter password : ";
	cin>>pass;
	if(pass.compare("user@123")==0)
	{
		system("clear");
		int ech;
		string emp_ch;
		int(*choice1[4]) ()={add_employee,edit_employee,view_employee,del_employee};
		while(ech!=5)
		{
			cout<<"--------Employee Menu------------\n";
			cout<<"\n1. Add Employee\n2. Edit Employee\n3. View Employee\n4. Delete Employee\n5. Return to main menu\n"; //Employee Submenu
			while(1)
			{
				cout<<"Enter choice: ";
				cin>>emp_ch;
				try
				{
					for(int i=0;i<emp_ch.length();i++)
					{
						if(!isdigit(emp_ch[i]))  //Checking entered choice is digit or not
						{
							throw emp_ch;
						}
					}
				}
				catch(string b)
				{
					cout<<"\n\n!!!!!Choice should be a digit!!!! \n\n\n";
					continue;
				}
				ech=stoi(emp_ch); // converting the entered choice into integer
				if(ech>0 && ech<5)
				{
					choice1[ech-1] ();
				}
				else if(ech==5)
				{
					break;
				}
				else
				{
					cout<<endl<<"\n\n----INVALID CHOICE----\n\n"<<endl;	
				}

				break;

			}
		}
	}
	else
	{
		cout<<"\n\n------wrong password!!!!!!\n----TRY AGAIN---\n\n";

	}
	return EXIT_SUCCESS;
}

/******************************************************************************************************************
 * * FUNCTION NAME : project
 *
 * * DESCRIPTION   : This function displays various functions in the project function
 *
 * * RETURN        : 1. Add project
 *                   2. Edit project
 *                   3. View project
 *                   4. Delete project
 *                   5. Return to main menu
 *         
 ****************************************************************************************************************/

int project()
{
system("read");
system("clear");
	string pass;
	cout<<"\n Enter password : ";
	cin>>pass;
	if(pass.compare("user@456")==0)
	{
		system("clear");
		int pch=0;
		string proj_ch;
		int(*choice2[4]) ()={add_project,edit_project,view_project,del_project};
		while(pch!=5)
		{
			cout<<"--------project Menu------------\n";
			cout<<"\n1. Add project\n2. Edit project\n3. View project\n4. Delete project\n5. Return to main menu\n"; //Project Submenu
			while(1)
			{
				cout<<"\nEnter choice: ";
				cin>>proj_ch;
				try
				{
					for(int i=0;i<proj_ch.length();i++)
					{
						if(!isdigit(proj_ch[i])) //Checking entered choice is digit or not 
						{
							throw proj_ch;
						}
					}
				}
				catch(string c)
				{
					cout<<"\n\n!!!!!!! choice should be a digit !!!!!!\n\n\n";
					continue;
				}
				pch=stoi(proj_ch); // converting entered choice into integer
				if(pch>0 && pch<5)
				{
					choice2[pch-1] ();
				}
				else if(pch==5)
				{
					break;
				}
				else
				{
					cout<<endl<<"\n\n----INVALID CHOICE----\n\n"<<endl;	
				}
				break;
			}
		}
	}
	else
	{
		cout<<"\n\n******Wrong password!!!!!!\n\n------TRY AGAIN !!!!!!\n\n";
	}
	return EXIT_SUCCESS;
}
