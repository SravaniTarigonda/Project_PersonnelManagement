
/*****************************************************************************************
 *
 * FILE NAME   : proj_func.cpp
 *
 * DESCRPITION : This file defines the functions in the project menu 
 *               to perform various operations in the project database
 *
 * REVISION    :
 *
 * 	DATE		NAME		REASON
 *
 *       ----           -------         ------
 *
 *******************************************************************************************/

#include<iostream>
#include<cstring>
#include <string.h>
#include<ctype.h>
#include <list>
#include <fstream>
using namespace std;
using std::left;


/******************************************************************************************
 *
 * FUNCTION NAME  : getdata()
 *
 * DESCRIPTION    : This function  writes the contents in to the project database by
 *                  validating the input
 *
 * RETURN         : No Returns 
 *
 ****************************************************************************************/

void PROJECT:: getdata()
{
	int id=2000;
	if(pr_list.empty()) //Checking whether project list is empty or not
	{
		id=2000;
	}
	else
	{
		for(PROJECT it:pr_list) //Runs a loop through the entire project list
		{
			if(id<it.pr_id)
				id=it.pr_id;
		}
	}

	id+=1; // Incrementing id according to if condition
	pr_obj.pr_id=id;
	cout<<endl<<endl<<"You are entering the details for Project Id: "<<pr_obj.pr_id<<endl;
	while(1)
	{
		cout<<endl<<endl<<"Enter the project name : "<<setw(40);
		cin.ignore(1,'\n');
		cin.getline(pr_name,20);
		try
		{
		if(strlen(pr_name)<3 || strlen(pr_name)>20) //Checking the length of the project name
		{
			throw pr_name;
		}
		}
		catch(char *a)
		{
			cout<<endl<<endl<<"\n ---Project name should be more than 2 letters and less than 20---\n";
			continue;
		}
		
         	break;
	}
	while(1)
	{
		string mem;
		cout<<endl<<endl<<"Enter no. of people working on this project: "<<setw(40);
		cin>>mem;
		try
		{
		for(int i=0;i<mem.length();i++)
		{
			if(!isdigit(mem[i])) //Checking for alphabets in the mem variable as no. of  team members can only be a digit
			{
				throw mem;
			}
		}
		}
		catch (string c)
		{
			cout<<endl<<"---Number of members should be an integer---\n";
			continue;
		}
			team_mem=stoi(mem); //Converting string into integer
			try
			{
			if(team_mem<1 || team_mem>15) //checking the number of team members
			{
				throw team_mem;
			}
			}
			catch (int d)
			{
				cout<<"\n---Team members should be atleast more than 1 and atmost less than 15---\n";
				continue;
			}
				break;
		}	
	}

/* This function displays the project details in project database*/

void PROJECT :: view()
{
	cout<<endl<<setw(30)<<pr_id<<setw(30)<<pr_name<<setw(30)<<team_mem<<setw(30)<<endl;
}

/******************************************************************************************
 *
 * FUNCTION NAME  : edit()
 *
 * DESCRIPTION    :  This function  edit the details of project in the project database by
 *                   validating the input
 *
 * RETURN         : NO RETURN
 *
 ****************************************************************************************/

void PROJECT :: edit()
{
	int pro_id;
	string id2;
	int ch;
	int flag=0;
	char new_name[20];
	string new_mem;
	while(1)
	{
	cout<<"\n  Enter the project id to edit :  ";
	cin>>id2;
	try
	{
		for(int i=0;i<id2.length();i++)
		{
			if(!isdigit(id2[i]))
			{
				throw id2;
			}
		}
	}
	catch (string e)
	{
		cout<<"\n\n Project ID should be a digit !!!!!\n\n";
		continue;
	}
	pro_id=stoi(id2);
	break;
	}
	if(pr_list.empty())
	{
		cout<<"\n ----project list id empty--- \n";
		exit(0);
	}
	string ch1;
	for (std::list<PROJECT>::iterator it = pr_list.begin(); it != pr_list.end(); ++it)
	{
		if(it->pr_id==pro_id)
		{
			while(ch!=3)
			{
				cout<<"\nEnter which detail you want to edit with the project id"<<pro_id<<endl;
				cout<<"1. Project Name\n 2.Number of team members working on it\n 3.Exit"<<endl;
				cin>>ch1;
				try
				{
				for(int i=0;i<ch1.length();i++)
				{
					if(!isdigit(ch1[i]))
					{
						throw ch1;
					}
				}
				}
				catch(string f)
				{
					cout<<"\n ---choice should a digit--- \n";
					continue;
				}
					ch=stoi(ch1);
					switch(ch)
					{
						case 1:
							{
							while(1)
							{
								cout<<"Enter the new name for project id "<<pro_id<<": "<<endl;
								//cin.ignore(1,'\n');
								cin>>new_name;
								try
								{
									if(strlen(new_name)<3 || strlen(new_name)>20)
									{
										throw new_name;
									}
								}
								catch(char *a)
								{
									cout<<"\n ---Project name should be more than 2 letters and less than 20---\n";
									continue;
								}
							
							strcpy(it->pr_name,new_name); //Updating Project name for the given project id
							cout<<"---New name is "<<it->pr_name<<"---"<<endl;
							break;
							}
							break;
							}
						case 2:  
							{
									int team_mem1;
								while(1)
								{
									cout<<"Enter the new team members for Project ID "<<pro_id<<": "<<endl;
									cin>>new_mem;
										try
										{
											for(int i=0;i<new_mem.length();i++)
											{
												if(!isdigit(new_mem[i]))
												{
													throw new_mem;
												}
											}
										}
										catch (string c)
										{
											cout<<"\n ---Number of members should be an integer---\n";
											continue;
										}
								                team_mem1=stoi(new_mem);
										try
										{
											if(team_mem1<1 || team_mem1>15)
											{
												throw team_mem1;
											}
										}
										catch (int d)
										{
											cout<<"\n---Team members should be atleast more than 1 and atmost less than 15---\n";
											continue;
										}
								it->team_mem=team_mem1;
								cout<<"----New no. of team members are "<<it->team_mem<<"---"<<endl;
								break;
								}
								break;
							}
						case 3:
							break;
						default:
							cout<<"\n---Please  enter a valid choice---\n";
							continue;
					}
					break;	
				}

				flag=1;
				break;
			}
		}
	if(flag==1)
	{
		cout<<"\n******** Succesfully edited **********\n";
	}
	else
	{
		cout<<"\n---Project with the project id "<<pro_id<<" does not exist---\n";
	}
}

/******************************************************************************************
 *
 * FUNCTION NAME  : del_project()
 *
 * DESCRIPTION    : This function  delete the details of project in the project database
 *
 * RETURN         : NO RETURN
 *
 ****************************************************************************************/

void PROJECT::del_project()
{
	int p_id;
	string p1_id;
	while(1)
	{
	cout<<"Enter the project id to delete: "; 
	cin>>p1_id;
	try
	{
		for(int i=0;i<p1_id.length();i++)
		{
			if(!isdigit(p1_id[i]))
			{
				throw p1_id;
			}
		}
	}
	catch (string q)
	{
		cout<<"\n\n  ---Project Id should be a digit---\n\n";
		continue;
	}
        p_id=stoi(p1_id);
	break;
       }
	if(pr_list.empty())
	{
		cout<<"\n ---Project list is empty---\n";
		exit(0);
	}
	int flag=0;
	for (std::list<PROJECT>::iterator it = pr_list.begin(); it != pr_list.end(); ++it)
	{
		if(it->pr_id==p_id)
		{
			it = pr_list.erase(it);
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"\n ******* Succesfully deleted *******\n";
	}
	else
	{
		cout<<"\nProject with the project id "<<p_id<<" does not exist!!!!\n";
	}
}


/* This project_query displays the highest team members in the project*/

void PROJECT :: project_query()
{
	if(pr_list.empty())
	{
		cout<<"   ---List is empty---  "<<endl;
	}
	else
	{
		std::list<PROJECT>::iterator st;
		st= pr_list.begin();
		int highest_no;
		highest_no=st->team_mem;
		for(PROJECT st:pr_list)
		{
			if(highest_no<=st.team_mem)
			{
				highest_no=st.team_mem;
			}

		}

	cout<<"------------------------------------------------------------------------------------"<<endl;
	cout<<setw(25)<<left<<"Project Id"<<setw(20)<<left<<"Name"<<setw(10)<<left<<"Team Members"<<endl;
	cout<<"------------------------------------------------------------------------------------"<<endl;
	for(PROJECT st:pr_list)
	{
		if(st.team_mem==highest_no)
		{
			cout<<endl<<setw(25)<<left<<st.pr_id<<setw(25)<<left<<st.pr_name<<setw(10)<<left<<st.team_mem <<endl;
		}
	}
	cout<<"------------------------------------------------------------------------------------"<<endl;
	}

}


