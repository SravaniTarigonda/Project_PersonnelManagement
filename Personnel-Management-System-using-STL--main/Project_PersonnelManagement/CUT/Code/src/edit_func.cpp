/*****************************************************************************************
 *
 * FILE NAME   : edit_func.cpp
 *
 * DESCRPITION : This file defines the edit function in the employee menu 
 *               to perform edit operation on the employee database
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

/******************************************************************************************
 *
 * FUNCTION NAME  : editdata()
 *
 * DESCRIPTION    :  This function  edit the details of employee in the employee database by
 *                   validating the input
 *
 * RETURN         : NO RETURN
 *
 ****************************************************************************************/

void SALARY::editdata()
{
	int fg;
	int ed;
	string eid;
	int choice;
	string ch;
	if(empsal_list.empty())
	{
		cout<<"---List is empty---"<<endl;
	}
	else
	{
		while(1)
		{
			cout<<"  Enter the employee id to edit: ";
			cin>>eid;
			try
			{
				for(int i=0;i<eid.length();i++)
				{
					if(!isdigit(eid[i]))
					{
						throw eid;
					}
				}
			}
			catch (string n)
			{
				cout<<"\n\n Employee id should be a digit !!!!!!\n\n";
				continue;
			}

			ed=stoi(eid);
			break;
		}
		char n_name[20];
		char n_dept[10];
		char n_contact[15];
		int n_pr[6];
		string pr[6];
		for (std::list<SALARY>::iterator it = empsal_list.begin(); it != empsal_list.end(); ++it)
		{
			fg=0;
			if(it->emp_id==ed)
			{

				while(choice!=8)
				{
					cout<<"Which detail of Employee Id "<<ed<<" you want to change?"<<endl;
					cout<<"1. Name"<<endl<<"2. Department"<<endl<<"3. Contact Number"<<endl<<"4. Project 1"<<endl<<"5. Project 2"<<endl<<"6. Project 3"<<endl<<"7.Salary"<<endl<<"8.Exit"<<endl;
					while(1)
					{
						cout<<endl<<"Enter choice: "<<endl;
						cin>>ch;
						try
						{
							for(int i=0;i<ch.length();i++)
							{
								if(!isdigit(ch[i]))
								{
									throw ch;
								}
							}
						}
						catch (string z)
						{
							cout<<"\n---Choice should be a digit !!!!!\n";
							continue;
						}
						choice=stoi(ch);
						break;
					}

					switch(choice)
					{
						case 1:
							{
								while(1)
								{
									cout<<"Enter the new name for Employee ID "<<ed<<": "<<endl;
									cin>>n_name;
									try
									{
										for(int i=0;i<strlen(n_name);i++)
										{
											if(!isalpha(n_name[i]))
											{
												throw n_name;
											}
										}
									}
									catch(char *p)
									{
										cout<<"\n -----Name should not contain any digits!!!!!!\n\n";
										continue;
									}			     
									try
									{
										if(strlen(n_name)<3 || strlen(n_name)>20)
										{           
											throw n_name;
										}
									}
									catch(char *d)
									{            
										cout<<"\n\n ---Name should be more than 2 and less than 20!!! \n   TRY AGAIN !!!!!!!\n\n";
										continue;
									}
									break;
								}
								strcpy(it->emp_name,n_name);
								cout<<"----New name is "<<it->emp_name<<endl;
								break;
							}
						case 2:
							{
								while(1)
								{
									cout<<"Enter the new Department for Employee ID "<<ed<<": "<<endl;
									cin>>n_dept;
									try
									{
										for(int i=0;i<strlen(n_dept);i++)
										{  
											n_dept[i]=toupper(n_dept[i]);
										}

										if(n_dept=="IT" || n_dept=="HR" || n_dept=="SALES" || n_dept=="MARKETING")
										{
											break;
										}
										else
										{
											throw n_dept;
										}
									}
									catch(char *m)
									{
										cout<<"\n\n Department name should be either IT OR HR OR SALES OR MARKETING !!!!\n\n";
										continue;
									}

									break;
								}

								strcpy(it->dept,n_dept);
								cout<<"----New Department is "<<it->dept<<endl;
								break;

							}
						case 3:
							{
								cout<<"Enter the new contact for Employee ID "<<ed<<": "<<endl;
								cin.ignore(1,'\n');
								cin.getline(n_contact,15);
								try
								{
									for(int i=0;i<strlen(n_contact);i++)
									{
										if(!isdigit(n_contact[i]))
										{
											throw n_contact;
										}
									}
								}
								catch(char *r)
								{
									cout<<"\n -----Name should not contain any digits!!!!!!\n\n";
									continue;
								}	
								try
								{
									if(strlen(n_contact)!=10)
									{
										throw n_contact;
									}
								}
								catch(char *g)
								{
									cout<<"\n ----Mobile number should be 10 digits!!!!\n";
									continue;
								}
								strcpy(it->contact,n_contact);
								break;
							}
						case 4:
							{

								cout<<"Enter the Project 1 ID for Employee ID "<<ed<<": "<<endl;
								cin>>pr[0];
								try
								{
									for(int i=0;i<pr[0].length();i++)
									{
										if(!isdigit(pr[0][i]))
										{
											throw pr[0];
										}
									}
								}
								catch(string c)
								{
									cout<<"\n ----Project ID should only contain digits!!!!!!\n\n";
									continue;
								}
								n_pr[0]=stoi(pr[0]);
								int flag=0;				
								for (std::list<PROJECT>::iterator st = pr_list.begin(); st != pr_list.end(); ++st)
								{
									if(st->pr_id==n_pr[0])
									{
										flag=1;
										break;
									}
								}	
								if(flag==1)
								{
									if(it->project_counter==0)
									{
									it->project_counter++;
									}
									cout<<"\n\n ------Project Id exits!! -------\n\n";
									it->pr_no_prid[0]=n_pr[0];
								}
								else
								{
									cout<<"\n\n ------Project Id does not exits!! -------\n\n";
									break;
								}

								cout<<"Enter the no. of hours worked : ";
								cin>>pr[1];
								try
								{
									for(int i=0;i<pr[1].length();i++)
									{
										if(!isdigit(pr[1][i]))
										{
											throw pr[1];
										}
									}
								}
								catch(string d)
								{
									cout<<"\n ----Number of hours worked should be  digit!!!!!!\n\n";
									continue;
								}			     
								n_pr[1]=stoi(pr[1]);
								it->pr_no_hrs[0]=n_pr[1];
								break;
							}
						case 5:
							{
								cout<<"Enter the Project 2 ID for Employee ID "<<ed<<": "<<endl;
								cin>>pr[2];
								try
								{
									for(int i=0;i<pr[2].length();i++)
									{
										if(!isdigit(pr[2][i]))
										{
											throw pr[2];
										}
									}
								}
								catch(string b)
								{
									cout<<"\n ----Project ID should only contain digits!!!!!!\n\n";
									continue;
								}
								n_pr[2]=stoi(pr[2]);
								int flag=0;				
								for (std::list<PROJECT>::iterator st = pr_list.begin(); st != pr_list.end(); ++st)
								{
									if(st->pr_id==n_pr[2])
									{
										flag=1;
										break;
									}
								}	
								if(flag==1)
								{
									if(it->project_counter==1)
									{
									it->project_counter++;
									}
									cout<<"\n\n ------Project Id exits!! -------\n\n";
									it->pr_no_prid[1]=n_pr[2];
									
								}
								else
								{
									cout<<"\n\n ------Project Id does not exits!! -------\n\n";
									break;
								}

								cout<<"Enter the no. of hours worked : ";
								cin>>pr[3];
								try
								{
									for(int i=0;i<pr[3].length();i++)
									{
										if(!isdigit(pr[3][i]))
										{
											throw pr[3];
										}
									}
								}
								catch(string c)
								{
									cout<<"\n ----Number of working hours should be  digit!!!!!!\n\n";
									continue;
								}
								n_pr[3]=stoi(pr[3]);
								it->pr_no_hrs[1]=n_pr[3];
								break;
							}
						case 6:
							{
								cout<<"Enter the Project 3 ID for Employee ID "<<ed<<": "<<endl;
								cin>>pr[4];
								try
								{
									for(int i=0;i<pr[4].length();i++)
									{
										if(!isdigit(pr[4][i]))
										{
											throw pr[4];
										}
									}
								}
								catch(string a)
								{
									cout<<"\n ----Project ID should only contain digits!!!!!!\n\n";
									continue;
								}
								n_pr[4]=stoi(pr[4]);
								int flag=0;				  
								for (std::list<PROJECT>::iterator st = pr_list.begin(); st != pr_list.end(); ++st)
								{
									if(st->pr_id==n_pr[4])
									{
										flag=1;
										break;
									}
								}	
								if(flag==1)
								{
									if(it->project_counter==2)
									{
									it->project_counter++;
									}
									cout<<"\n\n ------Project Id  exits!! -------\n\n";
									it->pr_no_prid[2]=n_pr[4];
								}
								else
								{
									cout<<"\n\n ------Project Id does not exits!! -------\n\n";
									break;
								}

								cout<<"Enter the no. of hours worked : ";
								cin>>pr[5];
								try
								{
									for(int i=0;i<pr[5].length();i++)
									{
										if(!isdigit(pr[5][i]))
										{
											throw pr[5];
										}
									}
								}
								catch(string c)
								{
									cout<<"\n -NUmber of hours should be  digit!!!!!!\n\n";
									continue;
								}
								n_pr[5]=stoi(pr[5]);			     
								it->pr_no_hrs[2]=n_pr[5];
								break;
							}
						case 7:
							{
								double n_salary;
								string sal;
								while(1)
								{
									cout<<"Enter the new salary for Employee ID "<<ed<<": "<<endl;
									cin>>sal;
									try
									{
										for(int i=0;i<sal.length();i++)
										{
											if(!isdigit(sal[i]))
											{
												throw sal;
											}
										}
									}
									catch(string e)
									{
										cout<<"\n ---Salary should a number !!!\n";
										continue;
									}
									n_salary=stod(sal);
									if(n_salary<=0)
									{
										cout<<"\n ----Basic Salary should be greater than Rs. 10,000!!!\n";
										continue;
									}
									else if(n_salary<10000 || n_salary>200000)
									{
										cout<<"\n ----Salary should be in the range 10000 to 200000!!!!\n";
										continue;
									}
									else
										break;
								}

								it->salary=n_salary;
								cout<<"----New salary is "<<it->salary<<endl;
								break;
							}

						case 8: break;
						default:cout<<endl<<"----INVALID CHOICE----"<<endl;
					}
                                    break;
				}
			}
			else
			{
				fg=1;
			}

		}
		if(fg==1)
			cout<<"--This employee id doesn't exist!!!"<<endl;
	}
}








