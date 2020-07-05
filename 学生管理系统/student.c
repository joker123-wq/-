#include "student.h"
static int stuid=0;
int getsid()
{
    return  stuid++;
}
/*
* @brief：比较学生学号
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_cid(void *data1,void *data2)	
{
    return  ((stu_t *)data1)->cid-((stu_t *)data2)->cid;
}
/*
* @brief：比较学生姓名
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_name(void *data1,void *data2)//比较学生名字函数
{
   return  strcmp(((stu_t*)data1)->name,((stu_t *)data2)->name);   
}
/*
* @brief：比较学生数学成绩
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_gmath(void *data1,void *data2)
{
    return  ((stu_t *)data1)->gmath-((stu_t *)data2)->gmath;
}
/*
* @brief：比较学生c语言成绩
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_glang(void *data1,void *data2)
{
    return  ((stu_t *)data1)->glang-((stu_t *)data2)->glang;
}
/*
* @brief：比较学生语文成绩
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_gphil(void *data1,void *data2)
{
    return  ((stu_t *)data1)->gphil-((stu_t *)data2)->gphil;
}
/*
* @brief：比较学生总成绩
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_sum(void *data1,void *data2)
{
    return  ((stu_t *)data1)->gsum -((stu_t *)data2)->gsum;
}
/*
* @brief：比较学生序号
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_order(void *data1,void *data2)
{
    return  ((stu_t *)data1)->order-((stu_t *)data2)->order;
}
/*
* @brief：比较学生班级
* @param
*   @arg  void类型指针
*   @arg  void指针
*   @retval  比较值
*/
int cmp_stu_classid(void *data1,void *data2)
{
     return  ((stu_t *)data1)->classid-((stu_t *)data2)->classid;
}
/*
* @brief：显示函数
* @param
*   @arg  void类型指针
*   @retval  none
*/
void show(void *data)
{
    ((stu_t *)data)->gsum=((stu_t *)data)->gphil+((stu_t *)data)->gmath+((stu_t *)data)->glang;
    printf("\tname %s\tpass %s\n",((stu_t *)data)->name,((stu_t *)data)->pass);
    printf("age %d\tcid %d\tclassid %d\tglang %d\t\n",((stu_t *)data)->age,((stu_t *)data)->cid,((stu_t *)data)->classid,((stu_t *)data)->glang);
    printf("gmath %d\tgphil %d\tgsum %d\torder %d\n",((stu_t *)data)->gmath,((stu_t *)data)->gphil,((stu_t *)data)->gsum,((stu_t *)data)->order);
}
/*
* @brief：更新学生数据
* @param
*   @arg  头指针
*   @arg  方式
    @arg   旧数据（根据旧数据查找）
    @arg   新数据
*   @retval  
*/
int updatestu(node_t *head,int mode,void *olddata,void * newdata) 
{
    SYSERR(head,==,NULL,"is NULL",-1);
    //SYSERR(head->data,==,NULL,"is NULL",-1);
    node_t *temp=node_find(head,olddata,cmp_stu_cid);
    if(temp==NULL)
    return  -1;
    stu_t *  stu=temp->data;
    printf("输入1修改名字，输入2修改年龄，输入3修改c语言成绩,输入4为修改数学成绩，输入5为修改语文成绩，\
    输入6为修改班号，输入7为修改排序\n");
    switch (mode)
    {
        case 1:    //修改名字
            strcpy(stu->name,((stu_t *)newdata)->name);
             break;
        case 2:    //修改年龄
            stu->age=((stu_t *)newdata)->age;
            break;
        case 3:  //修改c语言成绩
            stu->glang=((stu_t *)newdata)->glang;
            break;
        case 4:  //修改数学成绩  
            stu->gmath=((stu_t *)newdata)->gmath;
            break;
        case 5:  //修改语文成绩
            stu->gphil=((stu_t *)newdata)->gphil;
            break;
        case 6:  
            stu->classid=((stu_t *)newdata)->classid;
            break;
        case 7:
            stu->order=((stu_t *)newdata)->order;
            break;
        default:
            printf("not choice\n");
            break;
        
    }
    //修改后展示
    //node_show(head,show);
    return  0;
}
/*
* @brief：将文件数据写入链表
* @param
*   @arg  none
    @retval  头指针
*/
node_t * loadstuInfo()
{
    node_t *head=node_init();
    FILE  *fp=fopen("student.txt","r");
    SYSERR(fp,==,NULL,"err",NULL);
    stu_t  student;
    while(fscanf(fp,"%d %s %s %d %d %d %d %d %d %d\n",&student.cid,student.name,student.pass,&student.age,  \
    &student.gmath,&student.gphil,&student.glang,&student.gsum,&student.order,&student.classid)!=EOF )
    {
        node_einstall(head,&student,sizeof(stu_t));
        bzero(&student,sizeof(stu_t));
    }
    //node_show(head,show);
    return  head;  
    fclose(fp);
}
/*
* @brief：写入文件数据
* @param
*   @arg  头指针
*   @retval  
*/
int	savestuInfo(node_t * head)
{
    SYSERR(head,==,NULL,"err",-1);
    FILE  *fp=fopen("student.txt","w");
    SYSERR(fp,==,NULL,"err",-1);
    node_t *temp=head->next;
    while(temp!=head)
    {
        stu_t  *student=(stu_t *)temp->data;
        fprintf(fp,"%d %s %s %d %d %d %d %d %d %d\n",student->cid,student->name,student->pass,student->age,  \
        student->gmath,student->gphil,student->glang,student->gsum,student->order,student->classid);
        temp=temp->next;
    }
    fclose(fp);
    return  0;
}
/*
* @brief：查看
* @param
*   @arg  
    @retval
*/
node_t *stupwdcheck(node_t * head)
{
    node_t *temp=head->next;
    int i=0,cid;
    char pass[128];
    for(i;i<3;i++)
    {
        printf("please input the cid and pass\n");
        scanf("%s %d",pass,&cid);
        while(temp!=head)
        {
            if((strcmp(pass,((stu_t *)(temp->data))->pass)==0)&&(((stu_t *)(temp->data))->cid==cid))
            {
                return  temp;
            }
            temp=temp->next;
        }
        printf("input wrong,you have 3 chance\n");
    }
    printf("not found\n");
    return  NULL;
}
/*
* @brief：输入添加数据
* @param
*   @arg  头指针
*   @retval node_t *的指针
*/
node_t* addstu(node_t * stulist)//输入数据添加
{
    SYSERR(stulist,==,NULL,"err",NULL);
    stu_t  student;
    printf("输入学生密码\n");
    scanf("%s",student.pass);
    printf("输入学生年龄\n");
    scanf("%d",&student.age);
    printf("输入学生姓名\n");
    scanf("%s",student.name);
    printf("输入学生班级\n");
    scanf("%d",&student.classid);
    printf("输入学生数学成绩\n");
    scanf("%d",&student.gmath);
    printf("输入学生c语言成绩\n");
    scanf("%d",&student.glang);
    printf("输入学生语文成绩\n");
    scanf("%d",&student.gphil);
   // printf("输入总分(等于成绩之和)\n");
   // scanf("%d",&student.gsum);
    printf("输入排序\n");
    scanf("%d",&student.order);
    //printf("输入学号\n");
    student.cid=getsid();
    node_einstall(stulist,&student,sizeof(stu_t));
    return  stulist;
}
/*
* @brief 删除学生
* @param
*   @arg  头指针
*   @arg  学号
*   @retval  
*/
int	delstu(node_t * head,const int id)
{
    SYSERR(head,==,NULL,"is NULL",-1);
    node_t *temp=head->next;
    while(temp!=head)
    {
        stu_t *student=(stu_t *)(temp->data);
        if(id==student->cid)
        {
            node_t *q = temp->before;
            q->next = temp->next;
            temp->next->before = q;
            free(temp->data);
            free(temp);
        }
        temp=temp->next;
    }
    return  0;
    //if()
    //printf("is not found\n");
}
/*
* @brief：销毁链表
* @param
*   @arg  头指针
*   @retval  none
*/
void	destroynode_tList(node_t ** stulist)
{
	SYSERR(*stulist,==,NULL,"is NULL",;);
	node_destory(stulist);
}
/*
* @brief：查找学生，多值查找
* @param
*   @arg  头指针
*   @arg  模式
*   @arg  查找的数据
*   @retval  头指针
*/
node_t * getstut(node_t * head, int mode,stu_t  *student)
{
    SYSERR(head,==,NULL,"is NULL",NULL);
    node_t *temp=head;
     node_t *cid=node_init();
    switch (mode)
    {
    case 1:
            temp=node_find(head,student,cmp_stu_cid);
            SYSERR(temp,==,NULL,"not found",NULL);
            show(temp->data);
            return  temp;
    case 2:
          
        while((temp=node_find(temp,student,cmp_stu_name)))
        {
            node_einstall(cid,temp->data,sizeof(stu_t));
        }
           // SYSERR(temp,==,NULL,"not found",NULL);
            node_show(cid,show);
            return  cid;
        break;
    case 3:
        while((temp=node_find(temp,student,cmp_stu_classid)))
        {
            node_einstall(cid,temp->data,sizeof(stu_t));
        }
           // SYSERR(temp,==,NULL,"not found",NULL);
            node_show(cid,show);
            return  cid;
        break;
    default:
        break;
    }
    return NULL;
}
/*
* @brief：排序(选择1是学生学号排序，选择2是总分排序，选择3是数学成绩排序，选择4是c语言成绩，选择5是语文成绩)
* @param
*   @arg  头指针
*   @arg  模式
*   @retval  
*/

int sturank(node_t * head, int mode) 
{
    SYSERR(head,==,NULL,"is NULL",-1);
    SYSERR(head->next,==,head,"is empty",-1);
    switch (mode)
    {
    case 1:
        node_bubble_sort(head,cmp_stu_cid);
        break;
    case 2:
        node_bubble_sort(head,cmp_stu_sum);
        break;
    case 3:
        node_bubble_sort(head,cmp_stu_gmath);
        break;
    case 4:
        node_bubble_sort(head,cmp_stu_glang);
        break;
    case 5:
        node_bubble_sort(head,cmp_stu_gphil);
        break;
    default:
        break;
    }
    return  0;
}
/*
* @brief：通过学号查找
* @param
*   @arg  头指针
*   @arg  学号
*   @retval  头指针
*/

node_t *stupoint(node_t * stulist, int id) 
{
    SYSERR(stulist,==,NULL,"is err",NULL);
    node_t *temp=stulist->next;
    while(temp!=stulist)
    {
        stu_t  *student=temp->data;
        if(student->cid==id)
        {
            return  temp;
        }
        temp=temp->next;
    }
    printf("is not found\n");
    return NULL;
}
/*
* @brief：根据姓名删除
* @param
*   @arg  头指针
*   @arg  名字
*   @retval  
*/

 int	delstu_name(node_t * head,const char *name)//根据名字删除
{
    SYSERR(head,==,NULL,"is NULL",-1);
    node_t *temp=head->next;
    while(temp!=head)
    {
        stu_t *student=(stu_t *)(temp->data);
        if(strcmp(student->name,name)==0)
        {
            node_t *q = temp->before;
            q->next = temp->next;
            temp->next->before = q;
            free(temp->data);
            free(temp);
        }
        temp=temp->next;
    }
    //if()
    //printf("is not found\n");
    return  0;
}
/*
* @brief：根据班级删除
* @param
*   @arg  头指针
*   @arg  班级
*   @retval  
*/

int	delstu_class(node_t * head,int classid)
{
    SYSERR(head,==,NULL,"is NULL",-1);
    node_t *temp=head->next;
    while(temp!=head)
    {
        stu_t *student=(stu_t *)(temp->data);
        if(student->classid==classid)
        {
            node_t *q = temp->before;
            q->next = temp->next;
            temp->next->before = q;
            free(temp->data);
            free(temp);
        }
        temp=temp->next;
    }
    //if()
    //printf("is not found\n");
    return  0;
}
/*
* @brief：修改学生姓名
* @param
*   @arg  头指针
*   @retval  
*/
int changestu(node_t *head)
{
    printf("请输入你要修改的名字");
    char name[123];
    scanf("%s",name);
    strcpy(((stu_t *)(head->data))->name,name);
    return  0;
}
/*
* @brief：修改学生密码
* @param
*   @arg  头指针
*   @retval  
*/
int cha_passstu(node_t *head)
{
    printf("请输入你要修改的密码");
    char pass[123];
    scanf("%s",pass);
    strcpy(((stu_t *)(head->data))->pass,pass);
    return  0;
}