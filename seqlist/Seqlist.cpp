#include "seqlistClass.h"
#include <iostream>
using namespace std;

//�޲ι��캯��������һ���յ�˳���
template <class DataType> 
SeqList<DataType>::SeqList()
{
	length=0;
} 

//�вι��캯��������һ������Ϊ n ��˳���
template <class DataType>
SeqList<DataType>::SeqList(DataType arr[],int n) 
{
	if(n<1 || n>MaxSize)
		throw "�����Ƿ�";
	for(int i=0;i<n;i++)
		data[i]=arr[i];
	length=n;
}

//��������
template <class DataType>
SeqList<DataType>::~SeqList(){ }

//��ȡ���Ա�ĳ���
template <class DataType>
int SeqList<DataType>::Length()   
{
	return length;
}

//��ȡԪ��ֵΪ x ��λ��
template <class DataType>
int SeqList<DataType>::Location(DataType x) 
{
	for(int i=0;i<length;i++)
		if(data[i]==x) return i+1;
	return -1;
}

//��ȡ i λ�õ�Ԫ��ֵ
template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if(i<0 || i>length) throw "���ݷǷ�";
	else return data[i];
}

//�����������λ�� i ������ֵΪ x ��Ԫ��
template <class DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
	if(length==MaxSize) throw "����";
	if(i<0 || i>length+1) throw "���ݷǷ�";
	for(int j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;
}

//ɾ��������ɾ��λ�� i ����Ԫ�ز�����λ�� i ��Ԫ��ֵ
template <class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if(length==0) throw "����";
	if(i<0 || i>length) throw "���ݷǷ�";
	DataType x;
	x=data[i-1];
	for(int j=i-1;j<length;j++)
		data[j]=data[j+1];
	length--;
	return x;
}

//���˳���ȫ��Ԫ��
template <class DataType>
void SeqList<DataType>::PrintList()
{
	if(length==0)
	{
		cout<<"���Ա�Ϊ�ա���";
		return ;
	}
	for(int i=0;i<length;i++)
	{
		cout<<data[i]<<" ";
	}
}

//���Ԫ�ر���λ�� m ��λ�� n ��Ԫ��(Ҫ�� m <= n)
template <class DataType>
void SeqList<DataType>::PrintList(int m,int n)
{
	if((m<1 || m>length) && (n<1 || n>length) && m>n)
		throw "���ݷǷ�";
	for(int i=m-1;i<n;i++)
		cout<<data[i]<<" "; 
}

//����λ�� i ��Ԫ��ֵΪ x
template <class DataType>
void SeqList<DataType>::Change(int i,DataType x)
{
	if(i<1 || i>length)
		throw "���ݷǷ�";
	data[i-1]=x;
}