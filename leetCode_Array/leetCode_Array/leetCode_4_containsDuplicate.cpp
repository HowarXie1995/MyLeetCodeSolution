#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

/*hashtable的实现*/

//设置Node
typedef struct Node
{
	int val;				//存放值
	struct Node* next;
}Node;

//设置Set
typedef struct Set
{
	int bucket;		//存放Set表里的容量
	struct Node ** table;		//存放管理Node的指针
}Set;

//初始化Set
//参数：Set类型指针,数组的容量大小的一半
//返回值：初始化好的Set
void SetInit(Set *s, int size)
{
	s->bucket = size;
	s->table = (Node **)malloc(sizeof(Node*) * s->bucket);
	memset(s->table, 0, sizeof(Node*) * s->bucket);
}

//加入Set
//参数：Set类型的指针，数组里面的值
//返回值：bool类型
int insertSet(Set *s, int val)
{
	int idx = val > 0 ? val : -val;		//把值变为正
	idx %= s->bucket;
	Node * node = s->table[idx];
	while (node != NULL)		//如果空间被占用
	{
		if (node->val == val)	//如果里面的值相等
		{
			return false;
		}
		//否则向后移动
		node = node->next;
	}
	node = (Node *)malloc(sizeof(Node));		//新建
	//使用前插法，插入
	node->val = val;
	node->next = s->table[idx];		
	s->table[idx] = node;

	return true;	
}
//释放Set
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
	//1、判断numsSize是否小于等于1 ，返回false	
	if (numsSize <= 1) return false;
	//2、创建Set，初始化Set，把numsSize里面的值插入哈希Set
	Set set;
	SetInit(&set, numsSize / 2);
	int i;
	for (i = 0; i < numsSize; ++i)
	{
		//插不进，说明有重复的，直接返回
		if ( !( insertSet(&set, nums[i]) ) )
		{
			releseSet(&set);
			return true;
		}
		//插的进去说明没重复的
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