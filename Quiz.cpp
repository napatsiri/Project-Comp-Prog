#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void student(vector<string> &q,vector<string> &a,vector<string> &b, vector<string> &c, vector<string> &d, vector<string> ans,int &numq){
	
	cout<<q[numq]<<"\n"<<a[numq]<<"\n"<<b[numq]<<"\n"<<c[numq]<<"\n"<<d[numq];
	cout<<"\n---------------------------------";
	cout<<"\nYour answer is (a/b/c/d) : ";
	string stu_ans;
	cin >> stu_ans;
	 
	cout<<"\nYour student ID is : ";
	string id;
	cin >> id;
	cout<<"\n---------------------------------\n";
	cout<<"Thank you for your answer.\n<3<3<3 Good luck <3<3<3\n";
	cout<<"---------------------------------\n";
	
	int count=0;
	string text; 
	ifstream find;
	find.open("StudentID_Ans.txt");
	
	while(getline(find,text))	if(text==id)	count++;
	
	if(count==0){
		ofstream writeid1("StudentID_Ans.txt",ios::app);	//all student file
		writeid1<<"\n"<<id;
		
		if(toUpperStr(stu_ans)==ans[numq]){
			ofstream writeid2("StudentID_Ans_correct.txt",ios::app);	//correct ans file
			writeid2<<"\n"<<id;
		}
	}
}



void librarian(vector<string> &q,vector<string> &a,vector<string> &b,vector<string> &c,vector<string> &d,vector<string> &ans){
	do{
        string command1;
        cout<<"READQ / READSID / EDIT / EXIT : ";
        cin>>command1;
        command1 = toUpperStr(command1);
        if(command1 == "EXIT") break;
        else if(command1 == "READQ") for(int i=0;i<q.size();i++)	cout<<i+1<<". "<<q[i]<<"\n"<<a[i]<<"\n"<<b[i]<<"\n"<<c[i]<<"\n"<<d[i]<<"\n"<<"Answer is : "<<ans[i]<<"\n"<<"---------------------------------\n";
        else if(command1 == "READSID"){
        	string sid; 
			ifstream read;
			read.open("StudentID_Ans_correct.txt");
			cout<< "---------------------------------\n";
			while(getline(read,sid))	cout<<sid<<"\n";
			cout<< "---------------------------------\n";
			do{
				string	delid;
				cout<<"Do you want to delete all student id in file? (yes/no): ";
				cin>>delid;
				delid=toUpperStr(delid);
				if(delid=="YES"){
					ofstream del1("StudentID_Ans.txt");
					del1<<"";
					ofstream del2("StudentID_Ans_correct.txt");
					del2<<"";
					cout<<"DELETED ALL STUDENT ID\n";
					break;
				}
				else if(delid=="NO")	break;
			}while(true);
			cout<< "---------------------------------\n";
		}
		else if(command1 == "EDIT"){
        	do{
        		string command2;
        		cout<<"ADD / EDIT / DELETE QUESTIONS or EXIT : ";
        		cin>>command2;
        		command2 = toUpperStr(command2);
        		if(command2 == "EXIT") break;
        		else if(command2 == "DELETE"){
					do{
        				int numofqd;
        				string confirmd;
        				cout<<"Please enter number of question : ";
						cin>>numofqd;
						cout<<"\nDelete question number "<<numofqd<<" (yes/no) : ";
						cin>>confirmd;
						confirmd = toUpperStr(confirmd);
						if(confirmd=="YES"){
							
							for(int i=numofqd-1;i<q.size();i++){
								if(i+1==q.size()){
									q.pop_back();
									a.pop_back();
									b.pop_back();
									c.pop_back();
									d.pop_back();
									ans.pop_back();
								}
								else{
									q[i]=q[i+1];
									a[i]=a[i+1];
									b[i]=b[i+1];
									c[i]=c[i+1];
									d[i]=d[i+1];
									ans[i]=ans[i+1];
								
								}
							}
							
							cout<<"\n---------------------------------\nShow quiz\n---------------------------------\n";
							for(int i=0;i<q.size();i++)	cout<<i+1<<". "<<q[i]<<"\n"<<a[i]<<"\n"<<b[i]<<"\n"<<c[i]<<"\n"<<d[i]<<"\nAnswer is : "<<ans[i]<<"\n"<<"---------------------------------\n";
												
							break;
						}
						else if(confirmd=="NO")	break;
						else{
            				cout << "---------------------------------\n";
            				cout << "Invalid command.\n";
            				cout << "---------------------------------\n";
        				}
    				}while(true);
				}
        		else if(command2 == "EDIT"){
        			do{
        				int numofqe;
        				string confirme;
        				cout<<"Please enter number of question : ";
						cin>>numofqe;
						cout<<"Delete question number "<<numofqe<<" (yes/no)";
						cin>>confirme;
						confirme = toUpperStr(confirme);
						if(confirme=="YES"){
							string newq,newa,newb,newc,newd,newans;
							cout<<"Enter new question : ";
							cin>>newq;
							cout<<"\nEnter new choice a. : ";
							cin>>newa;
							cout<<"\nEnter new choice b. : ";
							cin>>newb;
							cout<<"\nEnter new choice c. : ";
							cin>>newc;
							cout<<"\nEnter new choice d. : ";
							cin>>newd;
							cout<<"\nEnter new answer : ";
							cin>>newans;
							q[numofqe-1]=newq;
							a[numofqe-1]=newa;
							b[numofqe-1]=newb;
							c[numofqe-1]=newc;
							d[numofqe-1]=newd;
							ans[numofqe-1]=newans;	
							
							cout<<"\n---------------------------------\nShow quiz\n---------------------------------\n";
							for(int i=0;i<q.size();i++)	cout<<i+1<<". "<<q[i]<<"\n"<<a[i]<<"\n"<<b[i]<<"\n"<<c[i]<<"\n"<<d[i]<<"\nAnswer is : "<<ans[i]<<"\n"<<"---------------------------------\n";
												
							break;
						}
						else if(confirme=="NO")	break;
						else{
            				cout << "---------------------------------\n";
            				cout << "Invalid command.\n";
            				cout << "---------------------------------\n";
        				}
        			}while(true);
				}
				else if(command2 == "ADD"){
					string newq,newa,newb,newc,newd,newans;
					cin.ignore();
							cout<<"Enter new question : ";
							getline(cin,newq);						
							cout<<"Enter new choice a. : ";
							getline(cin,newa);							
							cout<<"Enter new choice b. : ";
							getline(cin,newb);						
							cout<<"Enter new choice c. : ";
							getline(cin,newc);							
							cout<<"Enter new choice d. : ";
							getline(cin,newd);						
							cout<<"Enter new answer : ";
							getline(cin,newans);
							
														
							newq=newq+" ";
							newa=" "+newa+" ";
							newb=" "+newb+" ";
							newc=" "+newc+" ";
							newd=" "+newd+" ";
						
							
							q.push_back(newq);
        					a.push_back(newa);
        					b.push_back(newb);
							c.push_back(newc);
							d.push_back(newd);
							ans.push_back(newans);
							
							cout<<"\n---------------------------------\nShow quiz\n---------------------------------\n";
							for(int i=0;i<q.size();i++)	cout<<i+1<<". "<<q[i]<<"\n"<<a[i]<<"\n"<<b[i]<<"\n"<<c[i]<<"\n"<<d[i]<<"\nAnswer is : "<<ans[i]<<"\n"<<"---------------------------------\n";
				}
        		else{
            		cout << "---------------------------------\n";
            		cout << "Invalid command.\n";
            		cout << "---------------------------------\n";
        		}
    		}while(true);
		}
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
}

void quiz(string user){
	srand(time(0));
	
	vector<string> questions;
	vector<string> choice_a;
	vector<string> choice_b;
	vector<string> choice_c;
	vector<string> choice_d;
	vector<string> qans;
	int numq;
	ifstream read;
	read.open("Question.txt");
	string textline;
    char format[] = "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%s";
    
    while(getline(read,textline)){
        char *q,*a,*b,*c,*d,*ans;
		q = new char[999];
		a = new char[999];
		b = new char[999];
		c = new char[999];
		d = new char[999];
		ans = new char[1];
		const char * ch = textline.c_str();
        sscanf(ch,format,q,a,b,c,d,ans);
        questions.push_back(q);
        choice_a.push_back(a);
        choice_b.push_back(b);
		choice_c.push_back(c);
		choice_d.push_back(d);
		qans.push_back(ans);
    }
	numq = rand()%questions.size();
	if(user=="student")		student(questions,choice_a,choice_b, choice_c, choice_d, qans,numq);
	else if(user=="librarian"){
		librarian(questions,choice_a,choice_b, choice_c, choice_d, qans);
		
		ofstream write("Question.txt");;
		for(int i=0;i<questions.size();i++){
			write<<questions[i]<<":"<<choice_a[i]<<":"<<choice_b[i]<<":"<<choice_c[i]<<":"<<choice_d[i]<<":"<<qans[i]<<"\n";
		} 
		
	}
}
