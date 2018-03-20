#include <iostream>
using namespace std;
#define MAX_VERTEX_NUM 50	// �����������
// �ߣ�����
typedef struct ArcNode {
	int vertex;				// �����򡣼������ڶ��������е��±ꡣ
	struct ArcNode* next;	// ����ָ����һ���ߣ�������
}ArcNode;
// ����
typedef struct VexNode {
	const char* name;			// ʹ��һ���ַ�����Ϊ���㱣���ֵ��Ҳ������Ϊ�Ƕ�������֡�
	struct ArcNode* firstarc;	// ָ���һ���ߣ�����
}VexNode;
// ͼ��ʹ���ڽӱ�洢
typedef struct Graph {
	VexNode vexlist[MAX_VERTEX_NUM];	// �����
	int length;							// ��������
}Graph;
void DepthFirstSearch(Graph* pGraph);
void InitGraph(Graph* pGraph);
void DeleteGraph(Graph* pGraph);
int visited[MAX_VERTEX_NUM];	// ������ʱ�־���顣0 ��ʾδ���ʣ����� 0 ��ʾ���ʵ��Ⱥ����

int main()
{
	Graph graph;
	int i;
	InitGraph(&graph); // ��ʼ��ͼ
	// ��ʼ�����ʱ�־����
	for(i=0; i<graph.length; i++)
		visited[i] = 0;
	// �����������
	DepthFirstSearch(&graph);
	// ����ͼ
	DeleteGraph(&graph);
	return 0;
}
void DepthFirstSearch(Graph* pGraph)
{
	ArcNode* Stack[MAX_VERTEX_NUM];		// ջ��
	int top = 0;						// ջ����0 ��ʾ��ջ

	ArcNode* pArcNode;		// �ߣ������ڵ�ָ��
	int i, v;				// ������š��� 0 ��ʼ������
	int nVisitCount = 0;	// ���ʼ�������
	int f[7] = {0,0,0,0,0,0,0};
	for(i=0;nVisitCount<7;){
		v=i;
		if(f[v] == 0) {
			printf("%s ",pGraph->vexlist[v].name);
			f[v]=1;	
		}else{
			pArcNode = Stack[top-1];
			top--;
			printf("%s ",pGraph->vexlist[pArcNode->vertex].name);
			pArcNode = pGraph->vexlist[pArcNode->vertex].firstarc;
			while (pArcNode != NULL) {
				if (f[pArcNode->vertex] != 1) {
					Stack[top] = pArcNode;
					top++;v++;
					f[pArcNode->vertex] = 1;					
				}
				pArcNode = pArcNode->next;
			}
		}			
		pArcNode = pGraph->vexlist[v].firstarc;
		while(pArcNode != NULL && f[pArcNode->vertex]!=1){
			Stack[top] = pArcNode;
			top++;v++;
			f[pArcNode->vertex]=1;
			pArcNode = pArcNode->next;
		}
		nVisitCount++;
	}	
	return;
}
typedef struct VertexArrayEntry {
	const char* name;				// �������ơ�NULL ��ʾ�������н�����
	int VexIndex[MAX_VERTEX_NUM];	// ��ö����ڽӵĶ������С�-1 ��ʾ���н�����
}VertexArrayEntry;
const VertexArrayEntry VertexArray[] = {
	{ "V0", {2, 5, 6, 1, -1}	},
	{ "V1", {3, 6, 4, 2, -1}	},
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
���ܣ�����ͼ
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
