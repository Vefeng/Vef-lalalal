#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "1.h"
#define LEN sizeof(struct stu)
struct stu
{
	long num;//学号
	int yw;
	int sx;
	int yy;
	float ave;
	struct stu *next;
};

int stutotle=0;
void menu()
{
	printf("    ******************************************\n");
	printf("      *       学生成绩管理系统——帮助菜单   *\n");
	printf("    ******************************************\n");
	printf("      *          H = 显示帮助菜单          *\n");
	printf("      *          T = 学生成绩录入          *\n");
	printf("      *          A = 计算学生平均分        *\n");
	printf("      *          L = 列出成绩表            *\n");
	printf("      *          P = 按平时成绩由高到低排序*\n");
	printf("      *          S = 按学号查询学生成绩    *\n");
	printf("      *          C = 清屏                  *\n");
	printf("      *          Q = 退出系统              *\n");
	printf("    ******************************************\n");
	printf("      * Copyright <C> 2024.07.09 By 魏一锋 *\n");
	printf("    ******************************************\n");

}
struct stu *Type(struct stu *head)
{
	struct stu *p=NULL;
	int n;
    printf("请输入学生人数：");
	scanf("%d",&n);
	printf("请输入%d名学生的三门成绩:\n",n);
	printf("  学号 语文 数学 英语\n");
    for(int i=0;i<n;i++)
    {
        p=(struct stu *)malloc(LEN);
        if(p==NULL)
        {
            printf("No enough memory to allocate!\n");
            exit(0);
        }
		printf("%d:",i+1);
        scanf("%ld",&p->num);
		scanf("%d",&p->yw);
		scanf("%d",&p->sx);
		scanf("%d",&p->yy);
		p->ave=0;
        if(head==NULL)
        {
            head=p;
            p->next=NULL;
        }
        else
        {
            p->next=head;
            head=p;
        }
	stutotle++;
    }
	getchar();
    return(head);
}
void List(struct stu *head)
{
	struct stu *p=NULL;
	p=head;
	if(head!=NULL)
	{
		printf("学生成绩如下：\n");
		//printf("\t%-12s%-12s%-12s%-12s%-12s\n","学号","语文","数学","英语","平均");
		printf("\t学号\t语文\t数学\t英语\t平均\n");
		for(int i=0;i<stutotle;i++)
		{
			printf("%d",i+1);
			printf("\t%ld",p->num);
			printf("\t%d",p->yw);
			printf("\t%d",p->sx);
			printf("\t%d",p->yy);
			printf("\t%.2f\n",p->ave);
			p=p->next;
		}
	}
	else 
		printf("成绩表为空！请先使用命令T录入学生成绩\n");

}
void Average(struct stu *head)
{
	struct stu *p=NULL;
	p=head;
	if(head!=NULL)
	{
		for(int i=0;i<stutotle;i++)
		{
			p->ave=(p->sx+p->yw+p->yy)/3.0;
			p=p->next;
		}
		printf("平均分以计算。请使用命令L查看。\n");
	}
	else 
		printf("成绩表为空！请先使用命令T录入学生成绩\n");
}
void Sort(struct stu *head)
{
	struct stu *p=head;
	struct stu *q=p->next;
	struct stu *k=NULL;
	if(head!=NULL)
	{
		for(int i=0;i<stutotle&&p!=NULL;i++)
		{
			k=p;
			//printf ("1\n");
			for(int j=0;j<stutotle-i-1&&q!=NULL;j++)
			{
				if(k->ave<q->ave)k=q;
				q=q->next;
			}
			if(k!=p)
				Move(k,p);
			p=p->next;

		}
		printf("完成排序。请使用命令L查看。\n");
	}
	else 
		printf("成绩表为空！请先使用命令T录入学生成绩\n");
}
void Move(struct stu *p,struct stu *q)
{
	int test;
	float test2;
	test=q->num;
	q->num=p->num;
	p->num=test;
	test=q->yw;
	q->yw=p->yw;
	p->yw=test;
	test=q->sx;
	q->sx=p->sx;
	p->sx=test;
	test=q->yy;
	q->yy=p->yy;
	p->yy=test;
	test2=q->ave;
	q->ave=p->ave;
	p->ave=test2;
}
void Search(struct stu *head,long n)
{
	struct stu *p=NULL;
    p=head;
	for(int i=0;i<stutotle;i++)
	{
		if(p->num==n)
		{
			printf("\t学号\t语文\t数学\t英语\t平均\n");
			printf("\t%ld",p->num);
			printf("\t%d",p->yw);
			printf("\t%d",p->sx);
			printf("\t%d",p->yy);
			printf("\t%.2f\n",p->ave);
			break;
		}
		else p=p->next;
		
	}
	
}