#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *lChild,*rChild;
};

class BinaryTree
{
public:
	BinaryTree(int arr[],int count);	//������arr��Ԫ�س�ʼ�������������ɵ�����ȫ��������
	void display();	//	�������
private:
	Node *base;		//����
	int nodeCount;		//�ڵ����
};

BinaryTree::BinaryTree(int arr[],int count)
{//������arr��Ԫ�س�ʼ�������������ɵ�����ȫ��������
	Node *first=new Node;
	if(first==NULL)
	{
		cout<<"�ڴ治�㣡";
		return ;
	}
	delete first;
	nodeCount=count;
	Node *tree=new Node[nodeCount];
	for(int i=1;i<=nodeCount;i++)
	{
		(tree+i-1)->data=arr[i-1];
		if(i*2<=nodeCount)
			(tree+i-1)->lChild=(tree+2*i-1);
		else (tree+i-1)->lChild=NULL;
		if(i*2+1<=nodeCount)
			(tree+i-1)->rChild=(tree+2*i);
		else (tree+i-1)->rChild=NULL;
	}
	base=tree;
}

void BinaryTree::display()
{	//�������
	Node *p=base;
	Node *stack[100]; //����ջ
	int top=-1;	//ջ��
	while(p || top>=0)
	{
		while(p)
		{
			cout<<p->data<<endl;
			if(p->rChild)
				stack[++top]=p->rChild;
			p=p->lChild;
		}
		if(top>=0) p=stack[top--];
	}
}

int main()
{
	int arr[10];
	cout<<"���ڳ�ʼ��������������Ԫ�أ�"<<endl<<endl;
	for(int i=0;i<10;i++)
	{
		arr[i]=i*i;
		cout<<arr[i]<<"  ";
    }
	BinaryTree myTree(arr,10);
	cout<<endl<<"���������������"<<endl<<endl;
	myTree.display();
	return 0;
}
