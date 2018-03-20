#include <iostream>
#include <cmath>
#include <iomanip>
#define EPS 1e-10
using namespace std;
int main ()
{
	double erfen(double (&f)(double),double l,double r); //�Էַ����� 
	double function(double x);        //����ԭ���� 
	double function_1dao(double x);   //ԭ������һ�׵����� 
	double l,r,m,flag=0;
	cin>>l>>r;
	m=function_1dao(l)*function_1dao(r);
	while(m<0)  //�ж������Ƿ񵥵� 
	{
		cout<<"����������Ч�����������룺";
		cin>>l>>r;
		m=function_1dao(l)*function_1dao(r);
	}
	m=function(l)*function(r);
	if(m>0)
	{
		cout<<"�޽⣡"<<endl;
	}
	else m=erfen(function,l,r);
	cout<<setiosflags(ios::fixed)<<setprecision(7)<<m<<endl;
	return 0;
 } 
double erfen(double (&f)(double),double l,double r)    //�Էַ����� 
{
	double c,m;
	do{
		c=(l+r)/2;
		if(f(c)*f(l)>0)
			l=c;
		else r=c;
	}while(abs(f(c))>EPS);
	return c; 
}
double function(double x)   //����ԭ����
{
	double f;
	f=x*x*x-7.7*x*x+19.2*x-15.3;
	return f;
}
double function_1dao(double x)   //ԭ������һ�׵����� 
{
	double f;
	f=3*x*x-2*7.7*x+19.2;
	return f;
}
