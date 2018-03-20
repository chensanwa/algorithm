#define MAXSIZE 100
template <class dataType> 
class SeqList
{
public:
	SeqList(){};
	SeqList(dataType arr[],int _length);	//�вι��캯��������һ������Ϊ n ��˳���
	bool remove(int location);	//ɾ��λ��location��Ԫ��
	//bool remove(dataType _data);	//ɾ��ֵΪ_data��Ԫ��
	void display();	//��ӡ����
private:
	dataType data[MAXSIZE];
	int length;
};

template <class dataType>
SeqList<dataType>::SeqList(dataType arr[],int _length)
{
	if(_length<1 || _length>MAXSIZE)
		return;
	for(int i=0;i<_length;i++)
		data[i]=arr[i];
	length=_length;
}


//ɾ��λ��location��Ԫ��
template <class dataType>
bool SeqList<dataType>::remove(int location)
{
	if(location<1 || location>length)
		return false;
	for(int i=location-1;i<length-2;i++)
		data[i]=data[i+1];
	length--;
	return true;
}

//ɾ��ֵΪ_data��Ԫ��
//template <class dataType>
//bool SeqList<dataType>::remove(dataType _data)
//{
//	bool f=false;
//	for(int i=0;i<length;i++)
//	{
//		if(data[i]==_data)
//		{
//			f=true;
//			for(int j=i;i<length-2;i++)
//				data[j]=data[j+1];
//		}
//	}
//	return f;
//}

template <class dataType>
void SeqList<dataType>::display()
{
	cout<<"˳������ݣ�"<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl<<"���Ա��ȣ�"<<length<<endl;
}