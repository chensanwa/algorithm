#include <iostream>
#include "linked.h"
using namespace std;
int main ()
{
	int arr[10],location=5,data=8,n=10;
	for(int i=0;i<10;i++)
		arr[i]=i+1;
	Linked<int> linked(arr,n);
	linked.display();	//�������
	cout<<endl<<"���������"<<endl;
	linked.insert(location,data);	//��location����data
	linked.display();
	cout<<endl<<"ɾ��������"<<endl;
	linked.remove(location+2);	//ɾ��λ��location+2��Ԫ��
	linked.display();
	return 0;
}