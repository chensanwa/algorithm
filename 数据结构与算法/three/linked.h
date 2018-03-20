template <class dataType>
struct Node
{
	dataType data;
	Node<dataType> *next;
};

template <class dataType>
class Linked
{
public:
	Linked();
	Linked(dataType arr[],int _length);	
	~Linked();
	bool insert(int location,dataType _data);	//��location����_data
	bool remove(int location);	//ɾ��locationλ�õ�Ԫ��
	//bool remove(dataType _data);	//ɾ��Ԫ��ֵΪ_data��Ԫ��
	void display();	//�������
private:
	Node<dataType> *first;
};

template<class dataType>
Linked<dataType>::Linked()
{
	first=new Node;
	first->=NULL;
}

//���캯��(ͷ�巨)
template<class dataType>
Linked<dataType>::Linked(dataType arr[],int _length)
{
	first=new Node<dataType>;
	first->next=NULL;
	for(int i=0;i<_length;i++)
	{
		Node<dataType> *f;
		f=new Node<dataType>;
		f->data=arr[i];
		f->next=first->next;
		first->next=f;
	}
}

//��������
template<class dataType>
Linked<dataType>::~Linked()
{
	while(first!=NULL)
	{
		Node<dataType> *f;
		f=first;
		first=first->next;
		delete f;
	}
}

//��location����_data
template <class dataType>
bool Linked<dataType>::insert(int location,dataType _data)
{
	Node<dataType> *f=new Node<dataType>;
	f=first->next;
	int m=1;
	while(m!=location && f!=NULL)
	{
		if(m==location-1)
		{
			Node<dataType> *a=new Node<dataType>;
			a->data=_data;
			a->next=f->next;
			f->next=a;
			return true;
		}
		f=f->next;
		m++;
	}
	return false;
}

//ɾ��locationλ�õ�Ԫ��
template <class dataType>
bool Linked<dataType>::remove(int location)
{
	Node<dataType> *f;
	f=first;
	int m=0;
	while(m!=location-1 && f!=NULL)
	{
		f=f->next;
		m++;
		if(m==location-2)
		{
			Node<dataType> *a;
			a=f->next;
			f->next=(f->next)->next;
			delete a;
			return true;
		}
	}
	return false;
}

//�������
template<class dataType>
void Linked<dataType>::display()
{
	if(first==NULL) return;
	Node<dataType> *f;
	f=first->next;
	cout<<"��������Ϊ��"<<endl;
	while(f!=NULL)
	{
		cout<<f->data<<" ";
		f=f->next;
	}
	cout<<endl;
}