//#include"1_node.h"
//#include"student.h"
#include"menu.h"
int main()
{
    node_t  *head=loadstuInfo();
    //node_show(head,show);
    #if 1
    int issave=0;
    login_menu(head);
    printf("-----------------------\n");
    printf("1为保存，0为销毁\n");
    scanf("%d",&issave);
    if(issave==0)
    {
        destroynode_tList(&head);
        printf("已经销毁了\n");
        return  0;
    }
    savestuInfo(head);
    printf("已经保存到文件中了\n");
#endif
    //测试函数
    //node_show(head,show);
    //savestuInfo(head);
    #if 0
    node_t *temp=stupwdcheck(head);
    if(temp!=NULL)
    {
        show(temp->data);
    }
    
    stu_t student={2,"zhangsan","zhangsan",22,33,44,55,66,77,88};
    stu_t  student1={2,"lisi","hanhan",22,33,44,55,66,77,88};
    updatestu(head,1,&student,&student1);
    node_show(head,show);
   
    //addstu(head);
    //addstu(head);
    //delstu(head,1);
    stu_t  student={2,"zhangsan","zhangsan",22,33,44,55,66,77,88};
    node_t  *cid=getstut(head,1,student);
    //node_show(cid,show);
    show(cid->data);
    delstu_name(head,"zhangsan");
    node_show(head,show);
    #endif
}