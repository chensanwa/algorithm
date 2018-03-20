#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_QUEUE_LENGTH 64 	// ������󳤶�
#define MAX_VERTEX_NUM 50	// �����������
// ���ζ���
typedef struct Queue{
	int buffer[MAX_QUEUE_LENGTH];	// ���л�����
	int begin;		// ��ʼλ��
	int end;		// ����λ��
	int length;		// ���г���
}Queue;
void InitQueue(Queue* pQ);
int EnQueue(Queue* pQ, int Elem);
int DeQueue(Queue* pQ);
int QueueEmpty(Queue* pQ);
// �ߣ�����
typedef struct ArcNode {
	int vertex;				// �����򡣼������ڶ��������е��±ꡣ
	struct ArcNode* next;	// ����ָ����һ���ߣ�������
}ArcNode;

// ����
typedef struct VexNode {
	const char* name;			// ʹ��һ���ַ�����Ϊ���㱣���ֵ��Ҳ������Ϊ�Ƕ�������֡�
	struct ArcNode* firstarc;	// ָ���һ���ߣ�������
}VexNode;

// ͼ��ʹ���ڽӱ�洢
typedef struct Graph {
	VexNode vexlist[MAX_VERTEX_NUM];	// �����
	int length;							// ��������
}Graph;

void BreadthFirstSearch(Graph* pGraph);
void InitGraph(Graph* pGraph);
void DeleteGraph(Graph* pGraph);
int visited[MAX_VERTEX_NUM];	// ������ʱ�־���顣0 ��ʾδ���ʣ����� 0 ��ʾ���ʵ��Ⱥ����
Queue queue;	// ����

int main()
{
	Graph graph;
	int i;
	// ��ʼ��ͼ
	InitGraph(&graph);
	// ��ʼ������
	InitQueue(&queue);
	// ��ʼ�����ʱ�־����
	for(i=0; i<graph.length; i++)
		visited[i] = 0;
	// �����������
	BreadthFirstSearch(&graph);
	// ����ͼ
	DeleteGraph(&graph);
	return 0;
}

/*
���ܣ�
	�������������

������
	pGraph -- ͼָ��
*/
void BreadthFirstSearch(Graph* pGraph)
{
	ArcNode* pArcNode;		// �ߣ������ڵ�ָ��
	int i, v;				// ������š��� 0 ��ʼ������
	int nVisitCount = 0;	// ���ʼ�������
	ArcNode* Stack[MAX_VERTEX_NUM];
	int top = 0;
	v = 0;
	for (i = 0;nVisitCount < 7;) {
		if (visited[i] == 0) {
			printf("%s ", pGraph->vexlist[i].name);
			visited[i] = 1;
			nVisitCount++;
			pArcNode = pGraph->vexlist[i].firstarc;
			while (pArcNode != NULL) {
				if (visited[pArcNode->vertex] == 0) {
					Stack[top] = pArcNode;
					visited[pArcNode->vertex] = 1;
					top++;
					pArcNode = pArcNode->next;
				}
			}
		}else{
			pArcNode = Stack[v];
			v++;
			printf("%s ", pGraph->vexlist[pArcNode->vertex].name);
			visited[pArcNode->vertex] = 1;
			nVisitCount++;
			pArcNode = pGraph->vexlist[pArcNode->vertex].firstarc;
			while (pArcNode != NULL) {
				if (visited[pArcNode->vertex] == 0) {
					Stack[top] = pArcNode;
					visited[pArcNode->vertex] = 1;
					top++;					
				}
				pArcNode = pArcNode->next;
			}
		}
	}
	return;
}

/*
���ܣ�
	ʹ�ø��������ݳ�ʼ��ͼ���ڽӱ�

������
	pGraph -- ͼָ��
*/
typedef struct VertexArrayEntry {
	const char* name;				// �������ơ�NULL ��ʾ�������н�����
	int VexIndex[MAX_VERTEX_NUM];	// ��ö����ڽӵĶ������С�-1 ��ʾ���н�����
}VertexArrayEntry;
const VertexArrayEntry VertexArray[] = {
	{ "V0", {2, 5, 1, -1}		},
	{ "V1", {3, 6, 2, -1}		},
	{ "V2", {0, 3, 6, 1, -1}	},
	{ "V3", {1, 2, 4, -1}		},
	{ "V4", {1, 3, -1}			},
	{ "V5", {0, 6, -1}			},
	{ "V6", {2, 5, 0, -1}		},
	{ NULL 						}	// ������־
};
void InitGraph(Graph* pGraph)
{
	int i, j;
	ArcNode** pArcNodePtr;	// ָ��ָ���ָ��	
	// ����ͼ�е�����
	pGraph->length = 0;
	// ʹ�ø��������ݳ�ʼ��ͼ���ڽӱ�
	for(i=0; i<MAX_VERTEX_NUM ;i++)
	{
		if(NULL == VertexArray[i].name)
			break;		
		pGraph->vexlist[i].name = VertexArray[i].name;
		pArcNodePtr = &pGraph->vexlist[i].firstarc;
		for(j=0; j<MAX_VERTEX_NUM; j++)
		{
			if(-1 == VertexArray[i].VexIndex[j])
			{
				*pArcNodePtr = NULL;
				break;
			}		
			*pArcNodePtr = (ArcNode*)malloc(sizeof(ArcNode));
			(*pArcNodePtr)->vertex = VertexArray[i].VexIndex[j];
			pArcNodePtr = &(*pArcNodePtr)->next;
		}	
		pGraph->length++;
	}
}
/*
���ܣ�
	����ͼ

������
	pGraph -- ͼָ��
*/
void DeleteGraph(Graph* pGraph)
{
	int i;
	ArcNode* pArcNode;
	
	for(i=0; i<pGraph->length; i++)
	{
		while(pGraph->vexlist[i].firstarc != NULL)
		{
			pArcNode = pGraph->vexlist[i].firstarc;
			pGraph->vexlist[i].firstarc = pArcNode->next;
			free(pArcNode);
		}
	}
	pGraph->length = 0;
}

/*
���ܣ�
	��ʼ�����С�

������
	pQ -- ����ָ��
*/
void InitQueue(Queue* pQ)
{
	pQ->begin = pQ->end = 0;
	pQ->length = 0;
}
/*
���ܣ�
	��Ԫ�ز����β��

������
	pQ -- ����ָ��
	Elem -- ��ӵ�Ԫ��
  
����ֵ��
	�������ɹ��������Ԫ�ص�ֵ��
	�������ʧ�ܷ��� -1��
*/
int EnQueue(Queue* pQ, int Elem)
{
	// �����������ʧ�ܡ�
	if(MAX_QUEUE_LENGTH == pQ->length)
		return -1;
		
	pQ->buffer[pQ->end] = Elem;
	pQ->end = (pQ->end + 1) % MAX_QUEUE_LENGTH;
	pQ->length++;
	
	return Elem;
}

/*
���ܣ�
	������Ԫ�س���

������
	pQ -- ����ָ��
  
����ֵ��
	������ӳɹ����س���Ԫ�ص�ֵ��
	�������ʧ�ܷ��� -1��
*/
int DeQueue(Queue* pQ)
{
	int Elem;
	// ���пգ�����ʧ��
	if(QueueEmpty(pQ))
		return -1;
	Elem = pQ->buffer[pQ->begin];
	pQ->begin = (pQ->begin + 1) % MAX_QUEUE_LENGTH;
	pQ->length--;
	return Elem;
}

/*
���ܣ�
	�ж϶����Ƿ�Ϊ�ա�

������
	pQ -- ����ָ��
  
����ֵ��
	������пշ��� 1���棩
	������зǿշ��� 0���٣�
*/
int QueueEmpty(Queue* pQ)
{
	return 0 == pQ->length ? 1 : 0;
}


