#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *lChild,*rChild;
};

class HuffmanTree
{
public:
	HuffmanTree(int arr[],int count);	//���캯��,count��ʾ������,arr����Ԫ�ؼ�Ϊ���Ԫ��ֵ
	void display();	//���������������
private:
	Node *base;	//����
	int nodeCount;	//������
};

bool cmp(Node a,Node b)
{
	return a.data>b.data;
}

HuffmanTree::HuffmanTree(int arr[],int count)
{//���캯��,count��ʾ������,arr����Ԫ�ؼ�Ϊ���Ԫ��ֵ
	nodeCount=count;
	Node *p=new Node;
	if(p==NULL)
	{
		cout<<"�ڴ治��";
		return ;
	}
	delete p;
	sort(arr,arr+count);	//���������������
	Node tree[100];
	int len=count;	//����tree�ĳ���
	for(int i=0;i<len;i++)
		(tree+i)->data=arr[i];
	while(len>1)
	{
		sort(tree,tree+len,cmp);
		Node *p=new Node;
		p->lChild=(tree+len-2);
		p->rChild=(tree+len-1);
		p->data=(tree+len-2)->data+(tree+len-1)->data;

		cout<<p->data<<"     ";	//���Ԫ��ֵ����֤����������
		cout<<"lChild:"<<p->lChild->data<<"  ";
		cout<<"rChild:"<<p->rChild->data<<endl<<endl;

		(tree+len-2)->data=p->data;
		(tree+len-2)->lChild=p->lChild;
		(tree+len-2)->rChild=p->rChild;
		len--;	
	}
	base=&tree[0];
}

//void HuffmanTree::display()
//{	//�������
//	Node *p=base;
//	Node *stack[100]; //����ջ
//	int top=-1;	//ջ��
//	while(p!=NULL || top>=0)
//	{
//		while(p!=NULL)
//		{
//			cout<<(p->data)<<endl;
//			//cout<<"**"<<endl;
//			if(p->rChild)
//				stack[++top]=p->rChild;
//			p=p->lChild;
//		}
//		if(top>=0) p=stack[top--];
//	}
//}

int main ()
{
	int arr[10];
	for(int i=0;i<10;i++)
		arr[i]=i;
	HuffmanTree myHuffman(arr,10);
	//myHuffman.display();
	return 0;
}