#include "1_node.h"
/*
* @brief：初始化双向环链表
* @param
*   @arg  
*   @retval   头节点
*/
node_t *node_init(void)
{
	node_t *head = malloc(sizeof(node_t));
	SYSERR(head,==,NULL,"malloc err",NULL);
	head->before = head->next = head;
	head->data = NULL;
	return head;
}
/*
* @brief：头插
* @param
*   @arg  头指针
*   @arg  数据
*	@arg  拷贝的字节数
*   @retval  
*/
int node_hinstall(node_t *head,void *data,int size)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	node_t *p = malloc(sizeof(node_t));
	SYSERR(p,==,NULL,"malloc err",-2);
	p->data = malloc(size);
	if(p->data == NULL)
	{
		free(p);
		printf("malloc err\n");
		return -2;
	}
	memcpy(p->data,data,size);

	p->next = head->next;
	p->before = head;

	p->next->before = p;
	head->next = p;
	return  0;
}
/*
* @brief：尾插
* @param
*   @arg  头指针
*   @arg  数据
*	@arg  拷贝的字节数
*   @retval  
*/
int node_einstall(node_t *head,void *data,int size)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	node_t *p = malloc(sizeof(node_t));
	SYSERR(p,==,NULL,"malloc err",-2);
	p->data = malloc(size);
	if(p->data == NULL)
	{
		free(p);
		printf("malloc err\n");
		return -2;
	}
	memcpy(p->data,data,size);
	p->next = head;
	p->before = head->before;

	p->before->next = p;
	head->before = p;
	return 0;

}
/*
* @brief：头插
* @param
*   @arg  头指针
*   @arg   显示函数指针
*   @retval  
*/
void node_show(node_t *head,showfun_t showfun)
{
	SYSERR(head->next,==,head,"is empty",;);
	node_t *p = head->next;
	while(p != head)
	{
		showfun(p->data);
		p = p->next;
	}
	return ;
}
/*
* @brief：头删
* @param
*   @arg  头指针
*   @retval  
*/
int node_hdelete(node_t *head)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	SYSERR(head->next,==,head,"head is empty",-2);
	node_t *p = head->next;
	head->next = p->next;
	p->next->before = head;

	free(p->data);
	free(p);
	return  0;
}
/*
* @brief：尾部删除
* @param
*   @arg  头指针
*   @retval  
*/
int node_edelete(node_t *head)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	SYSERR(head->next,==,head,"head is empty",-2);
	node_t *p = head->before;
	p->before->next = head;
	head->before = p->before;

	free(p->data);
	free(p);
	return  0;
}
/*
* @brief：查找
* @param
*   @arg  头指针
*   @arg  数据
*	@arg  比较函数指针
*   @retval  
*/
node_t *node_find(node_t *head,void *data,cmpfun_t cmpfun)
{
	SYSERR(head,==,NULL,"head is NULL",NULL);
	SYSERR(head->next,==,head,"head is empty",NULL);
	node_t *p = head->next;
	while((p != head) && (p->data != NULL))
	{
		if(cmpfun(p->data,data)==0)
			return p;
		p = p->next;
	}
	printf("not found\n");
	return NULL;
}
/*
* @brief：查找删除
* @param
*   @arg  头指针
*   @arg  数据
*	@arg  比较函数指针
*   @retval  
*/
int node_find_delete(node_t *head,void *data,cmpfun_t cmpfun)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	SYSERR(head->next,==,head,"head is empty",-2);
	node_t *p = node_find(head,data,cmpfun);
	SYSERR(p,==,NULL,"not fount",-3);
	node_t *q = p->before;

	q->next = p->next;
	p->next->before = q;

	free(p->data);
	free(p);
	return  0;
}
/*
* @brief：更新
* @param
*   @arg  头指针
*   @arg  旧数据
*   @arg  新数据
*	@arg  拷贝的字节数
*   @arg  比较函数指针
*   @retval  
*/
int node_update(node_t *head,void *olddata,void *newdata,int size,cmpfun_t cmpfun)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	SYSERR(head->next,==,head,"head is empty",-2);
	node_t *p = node_find(head,olddata,cmpfun);
	SYSERR(p,==,NULL,"not found",-3);
	memcpy(p->data,newdata,size);
	return 0;
}
/*
* @brief：冒泡排序
* @param
*   @arg  头指针
*   @arg  比较函数
*   @retval  
*/
int node_bubble_sort(node_t *head,cmpfun_t cmpfun)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	SYSERR(head->next,==,head,"head is empty",-2);
	node_t *i,*j,*end;
	int flag;
	void *temp;

	for(i=head->next,end = head; i->next!=head; i=i->next,end=end->before)
	{
		flag = 1;
		for(j=head->next; j->next!=end; j=j->next)
		{
			if(cmpfun(j->data,j->next->data)>0)
			{
				flag = 0;
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
		if(flag)
			break;
	}
	return 0;
}

/*
* @brief：选择排序
* @param
*   @arg  头指针
*   @arg  比较函数的指针
*   @retval  
*/
int node_select_sort(node_t *head,cmpfun_t cmpfun)
{
	SYSERR(head,==,NULL,"head is NULL",-1);
	SYSERR(head->next,==,head,"head is empty",-2);
	node_t *i,*j,*min;
	void *temp;

	for(i=head->next; i->next!=head; i=i->next)
	{
		min = i;
		for(j=i->next; j!=head; j=j->next)
		{
			if(cmpfun(min->data,j->data)>0)
				min = j;
		}
		if(min != i)
		{
			temp = i->data;
			i->data = min->data;
			min->data = temp;
		}
	}
	return 0;
	
}
/*
* @brief：销毁链表
* @param
*   @arg  头指针
*   @retval  
*/
void node_destory(node_t **head)
{
	node_t *p = (*head)->next;
	//node_t *q = p;
	while(p != *head)
	{
		printf("p = %p\n",p);
		free(p->data);
		free(p);
		p = p->next;
	}
	free(*head);
	*head = NULL;
}
