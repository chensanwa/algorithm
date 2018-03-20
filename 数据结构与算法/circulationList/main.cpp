#include <iostream>
using namespace std;

struct Node
{
	long data;
	Node *left,*right;
};

class List
{
public:
	//~List();	//�����������ͷ��ڴ�
	List(long a[],long length);
	long getLength();	//��ȡ������
	bool insertInto(long _data,long location);	//��location����_data
	bool remove(long location);	//ɾ��λ��location��Ԫ��
	void display();	//��ӡ����
private:
	Node *head;
};

//List::~List()
//{
//	while(head->right!=head)
//	{
//		Node *p=head;
//		head=head->right;
//		((p->right)->right)->left=p;
//		p->right=(p->right)->right;
//		delete p;
//	}
//}


List::List(long a[],long length)
{
	//��ʼ������
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<"�ڴ治��!";
		return ;
	}
	head=p;
	p->data=a[0];
	p->left=p;
	p->right=p;
	for(long i=1;i<length;i++)
	{
		Node *node=new Node;
		node->data=a[i];
		node->right=p;
		node->left=p->left->right;
		p->left->right=node;
		p->left=node;
	}
}

long List::getLength()
{	//��ȡ������
	Node *p=head->right;
	if(p==head) return 0;
	long count=1;
	while(p!=head)
	{
		count++;
		p=p->right;
	}
	return count;
}

bool List::insertInto(long _data,long location)
{//��location����_data
	Node *p=head->right;
	long count=0;
	while(p!=head && count<=location-1)
	{
		p=p->right;
		count++;
	}
	if(p==head) return false;
	Node *node=new Node;
	node->data=_data;
	node->right=p->right;
	node->left=(p->right)->left;
	(p->right)->left=node;
	p->right=node;
	return true;
}

bool List::remove(long location)
{//ɾ��λ��location��Ԫ��
	Node *p=head->right;
	long count=1;
	while(p!=head && count<=location-1)
	{
		p=p->right;
		count++;
	}
	if(p==head) return false;
	((p->right)->right)->left=p;
	p->right=(p->right)->right;
	return true;
}

void List::display()
{	//��ӡ����
	Node *p=head->right;
	while(p!=head)
	{
		cout<<p->data<<" ";
		p=p->right;
	}
	cout<<endl;
}

int main ()
{
	long a[10]={1,2,3,4,5,6,7,8,9,10};
	List list(a,10);	//����List��Ķ���
	//for(long i=0;i<10;i++)
	//	list.insertInto(a[i],i+1);	//������Ԫ��ȫ������������
	cout<<"��ʼ������"<<endl<<endl; 
	list.display();	//��ӡ��������鿴�����Ƿ�ɹ�
	list.insertInto(11,5);	//��λ��5����11
	cout<<"���������"<<endl<<endl;
	list.display();	//��ӡ��������鿴�����Ƿ�ɹ�
	long location=5;
	list.remove(location);	//ɾ��locationλ�õ�Ԫ��
	cout<<"ɾ��������"<<endl<<endl;
	list.display();	//��ӡ��������鿴�����Ƿ�ɹ�
	return 0;
}
