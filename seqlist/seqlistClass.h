const int MaxSize=100;
template <class DataType>
class SeqList
{
public:
	SeqList();      //�޲ι��캯��������һ���յ�˳���
	SeqList(DataType arr[],int n);   //�вι��캯��������һ������Ϊ n ��˳���
	~SeqList();
	int Length();   //��ȡ���Ա�ĳ���
	int Location(DataType x);   //��ȡԪ��ֵΪ x ��λ��
	DataType Get(int i);  //��ȡ i λ�õ�Ԫ��ֵ
	void Insert(int i, DataType x);  //�����������λ�� i ������ֵΪ x ��Ԫ��
	DataType Delete(int i);   //ɾ��������ɾ��λ�� i ����Ԫ�ز�����λ�� i ��Ԫ��ֵ
	void PrintList();  //���˳���ȫ��Ԫ��
	void PrintList(int m,int n);   //���Ԫ�ر���λ�� m ��λ�� n ��Ԫ�� (m <= n)
	void Change(int i,DataType x);  //����λ�� i ��Ԫ��ֵΪ x

private:
	DataType data[MaxSize];
	int length;
};