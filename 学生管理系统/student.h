#ifndef  _STUDNET_H
#define  _STUDENT_H
#include"1_node.h"
//int stuid=2;
typedef struct student	//学生结构体定义
{
	int cid;	//学生学号定义
	char name[32];	//学生姓名
	char pass[16];	//学生密码
	int age;	//学生年龄
	int gmath;	//学生数学成绩
	int glang;	//C语言成绩
	int gphil;	//语文成绩
	int gsum;	//总分
	int order;	//排序
	int classid;		//班号
}stu_t;
/*修改*/
int updatestu(node_t *head,int mode,void * olddata,void * newdata);	//修改学生数据函数
int changestu(node_t *head);
int cha_passstu(node_t *head);

void show(void *data);//显示函数
/*比较*/
int cmp_stu_cid(void *data1,void *data2);	//比较学生学号函数
int cmp_stu_name(void *data1,void *data2);//比较学生名字函数
int cmp_stu_gmath(void *data1,void *data2);//比较学生数学成绩函数
int cmp_stu_glang(void *data1,void *data2);//比较学生C语言成绩函数
int cmp_stu_gphil(void *data1,void *data2);//比较学生语文成绩函数
int cmp_stu_sum(void *data1,void *data2);//比较学生总分函数
int cmp_stu_order(void *data1,void *data2);//比较学生序号函数
int cmp_stu_classid(void *data1,void *data2);//比较学生班号函数
/*文件操作*/
node_t * loadstuInfo();//初始化,将文件中的数据写入链表中并插入
int	savestuInfo(node_t * head);//写数据到文件

node_t *stupwdcheck(node_t * head);//检查密码和学号
/* 添加 */
node_t* addstu(node_t * stulist);//输入数据添加
/*  删除   */
int	delstu(node_t * head,const int id); //根据学号删除
int	delstu_name(node_t * head,const char *name);//根据名字删除
int	delstu_class(node_t * head,int classid);//根据班级删除
/* 销毁  */
void	destroynode_tList(node_t ** stulist);//销毁整个链表
/*查找*/
//2、	如果mode为1,调用find_vdlist()按学号从链表中查找学生，返回单个学生
//3、	如果mode为2,调用find_vdlist()按姓名从链表中查找学生，调用create_dlist()新建链表，每查出一个学生则插入到新链表，返回新链表。
//4、	如果mode为3,调用find_vdlist()按班级从链表中查找学生，调用create_dlist()新建链表，每查出一个学生则插入到新链表，返回新链表。
node_t * getstut(node_t * head, int mode,stu_t  *student);//函数功能；按mode从学生节点中获取数据
node_t *stupoint(node_t * stulist, int id) ;//根据学号查找
/*排序*/
int sturank(node_t * head, int mode) ;//排序
#endif