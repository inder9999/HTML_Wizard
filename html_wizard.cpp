#include<bits/stdc++.h>
#include<stdio.h>
#include<sys/stat.h>

using namespace std;

const char * choose_color() {
	int color_choice;
	cout<<"    1.Red    2.Blue    3.Green    4.Yellow\n    Choose : ";
	cin>>color_choice;
	switch(color_choice) {
		case 1: return "red";
		case 2: return "blue";
		case 3: return "green";
		case 4: return "yellow";
		default: return "black";
	}
}
 void strcat(char *s,char c) {
	int i;
	for(i=0;s[i]!='\0';i++);
	s[i]=c;
	s[i+1]='\0';
	return;
}

int getid();

class profile
{
	static int s;
	int id;
	char title[100],file_name[100],folder[100];
	char body[1000000],body2[1000];
public:
	void get()
	{
		char c;
		id = getid();
		system("cls");
		cout<<"\n\n    ID : "<<id<<"\n";
		cin.get(c);
		cout<<"    File Name : ";
		cin.getline(file_name,100);
		strcpy(folder,file_name);
		strcat(file_name,".html");
		cout<<"    Title : ";
		cin.getline(title,100);
		int i=0;
		strcpy(body,"<html><head><title>");
		strcat(body,title);
		strcat(body,"</title><body>");

		strcpy(body2,"<body style=\"");
		while(i!=10) {
			system("cls");
			cout<<"\n\n    1.Add heading                           2.Create paragraph\n";
			cout<<"    3.Insert image                          4.Create hyperlink\n";
			cout<<"    5.Add Horizontal rule                   6.Add Marquee text\n";
			cout<<"    7.Add background image                  8.Add background color\n";
			cout<<"    9.Preview                               10.Create file\n    Choice : ";
			cin>>i;
			cout<<"\n";
			switch(i)
			{
				case 1: {
					cin.get(c);
					char head[100],col1[10],s;
					cout<<"    Enter Heading : ";
					cin.getline(head,100);
					cout<<"    Enter Heading size (1-7): ";
					cin>>s;
					strcpy(col1,choose_color());
					strcat(body,"<h");
					strcat(body,s);
					strcat(body," style=\"color:");
					strcat(body,col1);
					strcat(body,"\">");
					strcat(body,head);
					strcat(body,"</h1>");
					break;
				}


				case 2: {
					cin.get(c);
					char para[10000],col2[10];
					cout<<"    Enter Text : ";
					cin.getline(para,10000);
					strcpy(col2,choose_color());
					strcat(body,"<p style=\"color:");
					strcat(body,col2);
					strcat(body,"\">");
					strcat(body,para);
					strcat(body,"</p><br>");
					break;
				}


				case 3: {
					cin.get(c);
					char loc3[100];
					cout<<"    Enter Location : ";
					cin.getline(loc3,100);
					strcat(body,"<img src=\"");
					strcat(body,loc3);
					strcat(body,"\" onerror=\"this.style.display='none'\" style=\"max-width:70vw; max-height:70vh\"><br>");
					break;
				}


				case 4: {
					cin.get(c);
					char url[100],link[100];
					cout<<"    Link Title : ";
					cin.getline(link,100);
					cout<<"    Enter URL : ";
					cin.getline(url,100);
					strcat(body,"<a href=\"");
					strcat(body,url);
					strcat(body,"\">");
					strcat(body,link);
					strcat(body,"</a><br>");
					break;
				}


				case 5: {
					int h,v;
					cout<<"    Number of Horizontal Rules : ";
					cin>>h;
					for(int i=0;i<h;i++) {
						strcat(body,"<hr>");
					}
					break;
				}


				case 6: {
					cin.get(c);
					char mar[100],col6[100];
					cout<<"    Enter Text : ";
					cin.getline(mar,100);
					strcpy(col6,choose_color());
					strcat(body,"<marquee style=\"color:");
					strcat(body,col6);
					strcat(body,"\">");
					strcat(body,mar);
					strcat(body,"</marquee>");
					break;
				}


				case 7: {
					cin.get(c);
					char bgi[100];
					cout<<"    Enter Location of Background Image : ";
					cin.getline(bgi,100);
					strcat(body2,"background-image: url('");
					strcat(body2,bgi);
					strcat(body2,"'); background-size: cover; ");
					break;
				}


				case 8: {
					cin.get(c);
					char bgc[100];
					strcpy(bgc,choose_color());
					strcat(body2,"    background-color:");
					strcat(body2,bgc);
					strcat(body2,"; ");
					break;
				}


				case 9: {
					ofstream temp;
					temp.open("pre.html");
					temp<<body<<"</body>"<<body2<<"\"></body></head></html>";
					temp.close();
					system("pre.html");
					cout<<"\n\n    Press any Key to continue\n\n";
					cin.get(c);
					cin.get(c);
					remove("pre.html");
					break;
				}
			}
		}
		strcat(body2,"\"></body>");
		strcat(body,"</body>");
		strcat(body,body2);
		strcat(body,"</head></html>");
		return;
	}
	int ret_id () {
		return id;
	}
	char* ret_folder() {
		return folder;
	}
	char* ret_file() {
		return file_name;
	}
	void open_file() {
        char loc[100];
        strcpy(loc,"\"");
        strcat(loc,file_name);
        strcat(loc,"\"");
        system(loc);
        return;
	}
	static int size() {
		return s;
	}
	static void inc() {
		s++;
	}
	static void dec() {
		s--;
	}
	void create_file();
	static void assign_size();
};

int profile::s = 0;

void profile::assign_size() {
	fstream f;
	f.open("users.dat" , ios::in | ios::binary);
	if(!f) s=0;
	int t=0;
	profile p;
	while(f.read((char*)&p,sizeof(p))) {
		t++;
	}
	s=t;
}


void profile::create_file()
{
	ofstream file;
	file.open(file_name);
	file<<body;
	cout<<"    FILE CREATED !\n";
	file.close();
	return;
}

int getid() {
	fstream f;
	f.open("users.dat" , ios::in | ios:: binary);
	if(!f)
		return 1;
	int id=1;
	profile p;
	while(f.read((char*)&p,sizeof(p))) {
		if(id != p.ret_id())
			return id;
		id++;
	}
	return id;
}



void main_menu() {
	system("cls");
	cout<<"\n\n    HTML WIZARD";
	cout<<"\n\n    1. Create new File\n    2. Display Existing Files\n";
	cout<<"    3. Open File\n    4. Remove File\n    5. Exit\n\n    Enter Choice : ";
}

int main() {
	profile::assign_size();
	while(true){
		fstream file;
		char cc;
		int choice;
		profile p;
		main_menu();
		cin>>choice;
		switch(choice) {
			case 1: {
				p.get();
				p.create_file();
				profile::inc();
				cin.get(cc);
				cin.get(cc);
				file.open("users.dat", ios::app | ios::binary);
				file.write((char*)&p,sizeof(p));
				file.close();
				break;
			}

			case 2: {
				cout<<"\n";
				file.open("users.dat", ios::in | ios::binary);
				if(!file || profile::size() == 0) {
					cout<<"    No Data Present\n";
					cin.get(cc);
					cin.get(cc);
					break;
				}
				else {
					while(file.read((char*)&p,sizeof(p))) {
						cout<<"    "<<p.ret_id()<<". "<<p.ret_folder()<<"\n";
					}
				}
				cout<<"    Count : "<<profile::size()<<"\n";
				cin.get(cc);
				cin.get(cc);
				file.close();
				break;
			}

			case 3: {
				int idx,flag=0;
				cout<<"\n";
				cout<<"    Enter ID : ";
				cin>>idx;
				file.open("users.dat",ios::in | ios::binary);
				while(file.read((char*)&p,sizeof(p))) {
					if(p.ret_id() == idx) {
						//system(p.ret_file());
						p.open_file();
						flag=1;
					}
				}
				if(flag==0) {
                    cout<<"    ID not Present\n";
                    cin.get(cc);
                    cin.get(cc);
				}
				file.close();
				break;
			}

			case 4: {
				int idd,flag=0;
				cout<<"\n";
				cout<<"    Enter ID to Delete : ";
				cin>>idd;
				fstream temp;
				file.open("users.dat" , ios::in | ios::binary);
				temp.open("temp.dat" , ios::out | ios::binary);
				while(file.read((char*)&p,sizeof(p))) {
					if(p.ret_id() == idd) {
						cout<<"    "<<p.ret_file()<<" Deleted\n";
						flag=1;
						remove(p.ret_file());
						profile::dec();
					}
					else {
						temp.write((char*)&p,sizeof(p));
					}
				}
				if(flag == 0) {
					cout<<"    ID not Present\n";
				}
				temp.close();
				file.close();
				remove("users.dat");
				rename("temp.dat" , "users.dat");
				cin.get(cc);
				cin.get(cc);
				break;
			}


			case 5: {
				cout<<"    Bye";
				cin.get(cc);
				cin.get(cc);
				exit(1);
			}
		}
	}
	return 0;
}
