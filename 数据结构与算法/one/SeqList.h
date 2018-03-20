#define MAXSIZE 100
template <class dataType> 
class SeqList
{
public:
	SeqList(){};
	SeqList(dataType arr[],int _length);	//�вι��캯��������һ������Ϊ n ��˳���
	bool insert(int location,dataType _date);	//��locationλ�ò�������_data
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

//��locationλ�ò�������_data
template <class dataType>
bool SeqList<dataType>::insert(int location,dataType _data)	
{	
	if(MAXSIZE==length)
		return false;
	else if(location<1 || location>length)
		return false;
	for(int i=length;i>=location;i--)
		data[i]=data[i-1];
	data[location-1]=_data;
	length++;
	return true;
}

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