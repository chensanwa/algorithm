#include <iostream>
#include "SeqList.h"
using namespace std;
int main ()
{
	int arr[10],location=5,data=8,length=10;
	for(int i=0;i<length;i++)	//��ʼ������
		arr[i]=i+1;
	SeqList<int> list(arr,10);
	list.display();	//������Ա�
	list.remove(location+1);	//ɾ������location+1λ�õ�Ԫ��
	list.display();
	//list.remove(data-5);	//ɾ������Ԫ��ֵΪdata-5��Ԫ��
	//list.display();
	return 0;
}