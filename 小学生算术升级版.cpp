#include<iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include<fstream>
using namespace std;
class Student
{
public:
Student(){}
void expression();
void again();
};
static int num=0,a,b,d,c,e,sum,result;
void Student::expression()
{
cout<<"\n\n\n\t\t\tѧ������10��\n\n\n\n";
for(int i=0;i<10;i++)
{
cout<<"��"<<i+1<<"��\n";
c=rand()%4+1;
switch(c)
{
case 1:
{
 srand(time( NULL ) );
 a=rand()%100+1;
 b=rand()%100+1;
 e=rand()%100+1;
 d=a+b*e;
 cout<<a<<" + "<<b<<"*"<<e<<" = ";
 }
 break;
case 2:
 {
 srand(time( NULL ) );
 a=rand()%100+1;
 b=rand()%100+1;
 e=rand()%100+1;
 if(a<b)
 {
 d=a;
 a=b;
 b=d;
 }
 d=a*b-e;
 cout<<a<<" * "<<b<<"-"<<e<<" = ";
  }
 break;
 case 3:
  {

 a=rand()%8+1;       
 b=rand()%8+1;
 e=rand()%8+1;
 if(a>b)
 {
 d=a;
 a=b;
 b=d;
 }
 d=a*b+e;
 cout<<a<<" * "<<b<<"+"<<e<<" = ";
 }
break;
case 4:
 {
   srand(time( NULL ) );
a=rand()%9+1;
b=rand()%9+1;
e=rand()%9+1;
a=(a/b)*b;
d=a/b;
cout<<a<<" / "<<b<<"+"<<e<<" = ";
 }

break;
}
cin>>result;
if(result!=d)
{
cout<<"error!\n";
ofstream outfile("���⼯.txt",ios::app);
if(!outfile)
{
cerr<<"open error!"<<endl;
exit(1);
}
outfile<<a;
switch(c)
{
case 1:outfile<<"+";break;
case 2:outfile<<"-";break;
case 3:outfile<<"*";break;
case 4:outfile<<"/";break;      
}
outfile<<b;
outfile<<endl;
outfile<<d;
outfile<<endl;
outfile.close();
}
else
{
cout<<"right!\n";
num++;
}
}
cout<<"\t\t\t����� "<<num<<" ����\n";
}
void Student::again()
{
char ch,c;
cout<<"\t\t\t�Ƿ���������(��y/Y���������������)\n";
cin>>ch;
if(num!=10)
{
  
    if(ch=='Y'||ch=='y')
    {
ifstream infile("���⼯.txt",ios::in);
    while(!(infile>>a>>c>>b>>d).eof()) 
    {
    cout<<a<<c<<b<<" = ";
    cin>>result;
    if(result==d)
    {
    cout<<"right!\n";
    }
    else
    cout<<"error!\n";

    }
    cout<<"\t\t\t���Խ���\n";
    infile.close();
    }
    else
cout<<"\t\t\t���Խ���\n";
}
else
cout<<"\t\t\t�������\n";
}
int main()
{
Student stu;
cout<<"\t\t^^*^^*^^*^^*^^��ӭ����ѧ������ϵͳ^^*^^*^^*^^*^^*^^\n\n\n\n";
cout<<"^^^^^^^^^^^^^^�״β���ѡ��y/Y,���Թ�ѡ��n/N^^^^^^^^^^^^^^^^^\n";
char ch;
cin>>ch; 
if(ch=='N'||ch=='n')
stu.again();
if(ch=='Y'||ch=='y')
{
 stu.expression();
 stu.again();
}
return 0;
}