#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "1.h"


int main(int argc, char const *argv[])
{
	struct stu *head = NULL;
	char m;
	menu();
	while(1)
	{
		printf("请输入命令:");
		m=getchar();
		getchar();
		switch (m)
		{
		case 'H':
			menu();
			break;
		case 'T':
			head=Type(head);
			break;
		case 'A':
			Average(head);
			break;
		case 'L':
			List(head);
			break;
		case 'P':
			Sort(head);
			break;
		case 'S':
			printf("请输入要查询的学生学号:");
			long n;
			scanf("%ld",&n);
			getchar();
			Search(head,n);
			break;
		case 'C':
			system("clear");
			break;
		case 'Q':
			return 0;
			break;
		default:
			printf("输入不合法\n");
			break;
		}
	}
	return 0;
}