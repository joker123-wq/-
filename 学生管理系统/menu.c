#include"menu.h"
/*
* @brief：删除菜单
* @param
*   @arg  头指针
*   @retval  
*/
int deletestu_menu(node_t *stulist)
{
   SYSERR(stulist->next,==,stulist,"is empty",-1);
   int id,classid;
   char name[128]="";
   printf("输入你的选择\n");
   printf("输入1为按照学号删除\n");
   printf("输入2为按照姓名删除\n");
   printf("输入3为按照班级删除\n");
   int choose=-1;
   scanf("%d",&choose);
   switch (choose)
   {
   case 1:  
        printf("输入学号\n");
        scanf("%d",&id);
        delstu(stulist,id);
        node_show(stulist,show);
       break;
   case 2:
        printf("输入姓名\n");
        scanf("%s",name);
        delstu_name(stulist,name);
        node_show(stulist,show);
        break;
    case 3:
        printf("输入班级\n");
        scanf("%d",&classid);
        delstu_class(stulist,classid);
        node_show(stulist,show);
   default:
       printf("input err\n");
       
       break;
   }
    return  0;
}
/*
* @brief：添加菜单
* @param
*   @arg  头指针
*   @retval  
*/
int addstu_menu(node_t *stulist) //添加学生菜单
{
   node_t *temp=addstu(stulist);
    node_show(temp,show);
    return  0;
}
/*
* @brief：排序
* @param
*   @arg  头指针
*   @retval  
*/
int sort_menu(node_t *stulist) //排序
{
     SYSERR(stulist->next,==,stulist,"is empty",-1);
    int choose=-1;
    printf("选择1是学生学号排序，选择2是总分排序，选择3是数学成绩排序，选择4是c语言成绩，选择5是语文成绩\n");
    scanf("%d",&choose);
    sturank(stulist,choose);
    node_show(stulist,show);
    return  0;
}
/*
* @brief：更新信息
* @param
*   @arg  头指针
*   @retval  
*/
int updatestu_menu(node_t *stulist)//更新
{
    SYSERR(stulist->next,==,stulist,"is empty",-1);
    int choose=-1,id,math,chinese,c;
    printf("输入3修改c语言成绩,输入4为修改数学成绩，输入5为修改语文成绩\n");
    scanf("%d",&choose);
    printf("请输入你要修改的学生信息的学号\n");
    scanf("%d",&id);
    node_t *temp=stupoint(stulist,id);
    SYSERR(temp,==,NULL,"is NULL",-1);
    stu_t  *student=(stu_t *)temp->data;
    stu_t  *student1=student;
    printf("输入修改的语文、数学、c语言成绩\n");
    scanf("%d %d %d",&chinese,&math,&c);
    student1->gmath=math;
    student1->gphil=chinese;
    student->glang=c;
    updatestu(stulist,choose,student,student1);
    printf("-------update--------\n");
    node_show(stulist,show);
    return  0;
}
/*
* @brief：展示链表信息
* @param
*   @arg  头指针
*   @retval  
*/
int showstu_menu(node_t *stulist)
{
    node_show(stulist,show);
    return  0;
}
/*
* @brief：展示单个学生
* @param
*   @arg  头指针
*   @retval  
*/
int showstu(node_t *stulist)
{
    show(stulist->data);
    return  0;
}
/*
* @brief：查找菜单
* @param
*   @arg  头指针
*   @retval  
*/
int findstu_menu(node_t *stulist)
{
    SYSERR(stulist->next,==,stulist,"is empty",-1);
    printf("输入1为学号查找学生\n");
    printf("输入2为姓名查找学生\n");
    printf("输入3为班级查找学生\n");
    int mode=-1,id,classid;
    char name[128];
    scanf("%d",&mode);
    //node_t *temp=(node_t *)malloc(sizeof(node_t));
    printf("输入你要查找的学号，班级，姓名\n");
    scanf("%d %d %s",&id,&classid,name);
    stu_t student={2,"lisi","hanhan",22,33,44,55,66,77,88};
    student.cid=id;
    student.classid=classid;
    strcpy(student.name,name);
    getstut(stulist,mode,&student);
    return  0;
}
/*
* @brief：程序主界面
* @param
*   @arg  头指针
*   @retval  
*/
int login_menu(node_t *stulist)	//程序主界面
{
    int choose=-1;
    while(choose)
    {
        system("clear");
        printf("输入1，进入管理员登陆界面\n");
        printf("输入2，学生登陆\n");
        printf("输入0，退出\n");
        printf("请输入你的选择\n");
        scanf("%d",&choose);
        switch (choose)
        {
        case 0:
            break;
        case 1:
                welcomeadmin_menu(stulist);
            break;
        case  2:
                welcomestu_menu(stulist);
        default:
            printf("input is err\n");
            break;
        }
    }
    return  0;
}
//管理员登陆界面
/*
* @brief：管理员登陆界面
* @param
*   @arg  头指针
*   @retval  
*/
int welcomeadmin_menu(node_t *stulist)
{
    int cout=LOOPCOUNT;
    char name[128]="";
    char pass[128]="";
    while(cout--)
    {
        system("clear");
        printf("请管理员输入名字\n");
        scanf("%s",name);
        printf("请输入管理员密码\n");
        scanf("%s",pass);
        if((!strcmp(name,ADMINNAME))&&(!strcmp(pass,ADMINPASS)))
        {
            admin_menu(stulist);
        }
        printf("输入有误，请重新输入，还有%d次机会\n",cout);
        getchar();
        getchar();
    }
    return  0;
}
//学生登陆界面
/*
* @brief：管理员登陆界面
* @param
*   @arg  头指针
*   @retval  
*/
int   welcomestu_menu (node_t *stulist)
{
    int cout=LOOPCOUNT;
    int id=0;
    char pass[128]="";
    while(cout--)
    {
        system("clear");
        printf("请输入你要进入学生的学号\n");
        scanf("%d",&id);
        node_t *temp=stupoint(stulist,id);
        if(temp==NULL)
        {
            printf("not found,you will exit\n");
            getchar();
            getchar();
            break;
        }
        printf("请输入密码\n");
        scanf("%s",pass);
        if(strcmp((((stu_t *)temp->data)->pass),pass)==0)
        {
            stu_menu(temp);
        }
        printf("输入有误，请重新输入，还有%d次机会\n",cout);
        getchar();
        getchar();
    }
    return  0;
}
/*
* @brief：学生操纵界面
* @param
*   @arg  头指针
*   @retval  
*/
int admin_menu(node_t *stulist)
{
     int choose=-1;
     system("clear");
    while(choose)
    {
        system("clear");
        printf("输入你要操作的\n");
        printf("输入1是删除学生\n");
        printf("输入2是添加学生\n");
        printf("输入3是将学生进行排序\n");
        printf("输入4为修改学生数据\n");
        printf("输入5是查找学生\n");
        printf("输入6是查看学生\n");
        printf("输入0是退出\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 0:
                break;
            case  1:
                deletestu_menu(stulist);
                break;
            case 2:
                addstu_menu(stulist);
                break;
            case 3:
                sort_menu(stulist);
                break;
            case 4:
                updatestu_menu(stulist);
                break;
            case 5:
                findstu_menu(stulist);
                break;
            case 6:
                showstu_menu(stulist);
                break;
            default:
                printf("输入有误\n");
                break;
        }
        getchar();
        getchar();
    }
    return  0;
}
/*
* @brief：学生操作菜单
* @param
*   @arg  头指针
*   @retval  
*/
int stu_menu(node_t *stulist)				//学生操作菜单
{
    SYSERR(stulist,==,NULL,"is NULL",-1);
    int choose=-1;
    while(choose)
    {
        system("clear");
        printf("输入你的选择\n");
        printf("选择1为查看学生数据\n");
        printf("选择2为修改学生姓名\n");
        printf("选择3为修改学生密码\n");
        printf("选择0退出\n");
         scanf("%d",&choose);
        switch(choose)
        {
            case  1:
                showstu(stulist);
                break;
            case 2:
               changestu(stulist);
               showstu(stulist);
                break;
            case 3:
                cha_passstu(stulist);
                showstu(stulist);
                break;
            default:
                printf("输入有误\n");
                break;
        }
        getchar();
        getchar();
    }
    return  0;
}

