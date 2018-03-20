#include <iostream>
#include <string>
#define MaxSize 100
using namespace std;

class String
{
public:
	String(string str,int _length);	//��ʼ��
	bool insertInto(char data,int location);	//��locationλ�ò�������data
	void display();	//��ӡȫ������
private:
	char arr[MaxSize];
	int length;
};

String::String(string str,int _length)
{
	for(int i=0;i<_length;i++)
		arr[i]=str.at(i);
	length=_length;
}

bool String::insertInto(char data,int location)
{//��locationλ�ò�������data
	if(location<1 || location>length+1 || length==MaxSize)
		return false;
	for(int i=length;i>=location;i--)
		arr[i]=arr[i-1];
	arr[location-1]=data;
	length++;
	return true;
}

void String::display()
{
	for(int i=0;i<length;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main ()
{
	string str;
	cout<<"������һ���ַ�����"<<endl<<endl; 
	cin>>str;
	String test(str,str.size());
	cout<<"����ַ���˳��ṹ���ַ�����"<<endl<<endl;
	test.display();
	test.insertInto('A',5);	//��λ��5�����ַ���A��
	cout<<"ִ�в����������ַ�����"<<endl<<endl;
	test.display();
	return 0;
}
