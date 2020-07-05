#ifndef  _MENU_H
#define  _MENU_H
#include<unistd.h>
#include"1_node.h"
#include"student.h"
#include<stdlib.h>
#define LOOPCOUNT 3	//错误次数
#define ADMINNAME "admin"	//管理员用户名
#define ADMINPASS "admin"	//管理员密码


int login_menu(node_t *stulist);	//程序主界面
int admin_menu(node_t *stulist);	//管理员操作菜单
int welcomeadmin_menu(node_t *stulist);	    //管理员登陆界面

int stu_menu(node_t *stulist);				//学生操作菜单
int welcomestu_menu(node_t *stulist);					//学生登陆界面

int addstu_menu(node_t *stulist);			//添加学生菜单
int deletestu_menu(node_t *stulist);		//删除学生菜单
int updatestu_menu(node_t *stulist);		//修改学生菜单
int showstu_menu(node_t *stulist);		//显示学生菜单
int findstu_menu(node_t *stulist);			//查找学生菜单
int sort_menu(node_t *stulist);    //排序学生菜单
int showstu(node_t *stulist);

#endif