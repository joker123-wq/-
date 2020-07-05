#ifndef	_1_NODE_H
#define _1_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYSERR(x,option,y,k,z) if((x)option(y))\
{\
	printf("%s:%s:%d:%s\n",__FILE__,__func__,__LINE__,k);\
	return z;\
}


typedef struct node
{
	void *data;
	struct node *next,*before;
}node_t;

node_t *node_init(void);
int node_hinstall(node_t *head,void *data,int size);
int node_einstall(node_t *head,void *data,int size);

typedef void(*showfun_t)(void *);
void node_show(node_t *head,showfun_t showfun);
int node_hdelete(node_t *head);
int node_edelete(node_t *head);

typedef int(*cmpfun_t)(void *,void *);
node_t *node_find(node_t *head,void *data,cmpfun_t cmpfun);
int node_find_delete(node_t *head,void *data,cmpfun_t cmpfun);
int node_update(node_t *head,void *olddata,void *newdata,int size,cmpfun_t cmpfun);

int node_bubble_sort(node_t *head,cmpfun_t cmpfun);
int node_select_sort(node_t *head,cmpfun_t cmpfun);

void node_destory(node_t **head);

#endif
