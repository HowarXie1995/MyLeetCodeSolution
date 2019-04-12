#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

/*hashtable��ʵ��*/

//����Node
typedef struct Node
{
	int val;				//���ֵ
	struct Node* next;
}Node;

//����Set
typedef struct Set
{
	int bucket;		//���Set���������
	struct Node ** table;		//��Ź���Node��ָ��
}Set;

//��ʼ��Set
//������Set����ָ��,�����������С��һ��
//����ֵ����ʼ���õ�Set
void SetInit(Set *s, int size)
{
	s->bucket = size;
	s->table = (Node **)malloc(sizeof(Node*) * s->bucket);
	memset(s->table, 0, sizeof(Node*) * s->bucket);
}

//����Set
//������Set���͵�ָ�룬���������ֵ
//����ֵ��bool����
int insertSet(Set *s, int val)
{
	int idx = val > 0 ? val : -val;		//��ֵ��Ϊ��
	idx %= s->bucket;
	Node * node = s->table[idx];
	while (node != NULL)		//����ռ䱻ռ��
	{
		if (node->val == val)	//��������ֵ���
		{
			return false;
		}
		//��������ƶ�
		node = node->next;
	}
	node = (Node *)malloc(sizeof(Node));		//�½�
	//ʹ��ǰ�巨������
	node->val = val;
	node->next = s->table[idx];		
	s->table[idx] = node;

	return true;	
}
//�ͷ�Set
void releseSet(Set *s)
{
	int i;
	for (i = 0; i < s->bucket; ++i)
	{
		Node *p = s->table[i];
		while(p)
		{ 
			Node *pre = p;
			p = p->next;
			free(pre);
			pre = NULL;
		}
		free(p);
	}
	free(s->table);
	s->table = NULL;
	s->bucket = 0;
}


int containsDuplicate(int* nums, int numsSize) 
{
	//1���ж�numsSize�Ƿ�С�ڵ���1 ������false	
	if (numsSize <= 1) return false;
	//2������Set����ʼ��Set����numsSize�����ֵ�����ϣSet
	Set set;
	SetInit(&set, numsSize / 2);
	int i;
	for (i = 0; i < numsSize; ++i)
	{
		//�岻����˵�����ظ��ģ�ֱ�ӷ���
		if ( !( insertSet(&set, nums[i]) ) )
		{
			releseSet(&set);
			return true;
		}
		//��Ľ�ȥ˵��û�ظ���
	}

	releseSet(&set);
	return false;
}


int main()
{
	int nums[] = { 1,2,3,4,5, 1};
	int flag = containsDuplicate(nums, 6);
	printf("%d\r\n", flag);
	system("pause\r\n");


	return 0;
}