#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define format "%d\n%s\n%f\n%f\n%f\n"
#define len sizeof(stu)
typedef struct student{
    int num;//学号
	char name[20];//姓名
	int studentclass;//班级
	int dorm;//宿舍号
    struct student *next;
}stu;
stu *head;
int n;
int Tips()
{
    int p;
    printf("<----------请选择功能---------->\n");
    printf("<----------1.输入-------->\n");
    printf("<----------2.删除-------->\n");
    printf("<----------3.查找-------->\n");
    printf("<----------4.保存-------->\n");
    printf("<----------5.加载-------->\n");
    printf("<----------6.显示-------->\n");
    printf("<----------0.退出------------------->\n");
    scanf("%d",&p);
    return p;

}


/*创建*/
stu * creat()
{
    stu *p1,*p2,*head;int i,k=1,sum;
    n=0;
    printf("输入学生信息的个数\n");
    scanf("%d",&sum);

    //head=0;
    for(i=0;i<sum;i++)
    {
        p1=(stu *)malloc(len);
        printf("输入第%d个学生的信息\n",k++);
        printf("\n 请输入学生的学号：");
        scanf("%ld",&p1->num);
		printf("\n 请输入学生的姓名:");
		scanf("%s", &p1->name);
		printf("\n 请输入学生的班级:");
		scanf("%d", &p1->studentclass);
		printf("\n 请输入学生的宿舍号:");
		scanf("%d", &p1->dorm); 
        n=n+1;
        if(n==1)
            head=p1;
        else
        p2->next=p1;
        p2=p1;
    }
    p2->next=0;
    return head;
}



/*删除*/
stu * del(stu * head,long num)
{
    stu *p1,*p2;
    if(head==0)
        printf("表空!\n");
    else
    {
        p1=head;
        while(p1->num!=num && p1->next!=0)
        {
            p2=p1;p1=p1->next;
        }
        if(p1->num==num)
        {
            if(p1==head)
            {
            head=p1->next;
            }
            else
            {
                p2->next=p1->next;

            }
            printf("删除学号:%ld成功\n",num);
            n=n-1;
       }
       else
            printf("没有%ld这个学号!\n",num);
    }
      return head;
}






/*插入改为查找*/
stu *insert(stu * head, stu * stud)
{
    stu *p1,*p2,*p0;
    p0=stud;p1=head;
    if(head==0)
    {
        head=p0;stud->next=0;
    }
    else
    {
        while(p1->num<p0->num && p1->next!=0)
        {
            p2=p1;p1=p1->next;
        }
        if(p1->num>=p0->num)
        {
            if(p1==head)
            {
                head=p0;
                p0->next=p1;
             }
            else
            {
                p2->next=p0;
                p0->next=p1;
            }

        }
        else
        {
            p1->next=p0,p0->next=0;
        }

    }
    n=n+1;
    return head;
}



int save(stu *p)
{
	FILE *fp;
	stu *head;
	head = p;//p为已经构建好的链表
	if ((fp = fopen("data.txt", "ab+")) == NULL)
	{
		printf("无法打开!\n");
		return -1;
	}
	while (p != NULL)
	{

		fwrite(p, sizeof(stu), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 1;
}//储存链表到文件


stu* read()
{
	FILE *fp;
	if ((fp = fopen("data.txt", "rb")) == NULL)
	{
		printf("无法读取\n");
		return NULL;
	}
	int sign;
	stu *s,*p,*head;
	
	head= (stu*)malloc(sizeof(stu));
	if (head == NULL)
	{
		printf("读取失败！内存空间申请不足！\n");
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0)
	{
		return NULL;
	}
	p = head;
	p->next = NULL;
	while (!feof(fp))
	{
		s = (stu*)malloc(sizeof(stu));
		fread(s, sizeof(stu), 1, fp);
		p->next = s;
		p = s;
		p->next = NULL;
	}
	fclose(fp);
	return head;
}//读取文件到链表






/*输出*/
void print(stu * head)
{
    stu * p;
    printf("此时的%d个学生信息是:\n",n);
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {
        printf("学号:%-10ld 姓名：%s 班级：%d 宿舍：%d\n",p->num,p->name,p->studentclass,p->dorm);
        p=p->next;
       }
    }
}




/*主函数*/
int main()
{
    stu * head=0,*stud;
    int m;
    long del_num;
    int i=1;

    while(i>0)
    {
        system("cls");
        i=Tips();
        switch(i)
        {
            case 1:
           {   system("cls");
               printf("开始输入学生信息:\n");
               head=creat();
               system("cls");
               print(head);
               printf("请输入0返回\n");
               scanf("%d",&m);
               while(m!=0)
               {
                   printf("请输入0返回\n");
                   scanf("%d",&m);
               }
               break;

           }
            case 2:
           { 
                system("cls");
                printf("输入要删除的学号:");
                scanf("%ld",&del_num);
                head=del(head,del_num);
                print(head);
                printf("请输入0返回\n");
                scanf("%d",&m);
                while(m!=0)
                {
                   printf("请输入0返回\n");
                   scanf("%d",&m);
                }
                break;
           }
            case 3:
            {
                system("cls");
                stud=(stu *)malloc(len);
                printf("\n 请输入学生的姓名:");
		    	scanf("%s", &stud->name);
		    	printf("\n 请输入学生的班级:");
		    	scanf("%s", &stud->studentclass);
	     		printf("\n 请输入学生的宿舍号:");
	     		scanf("%d", &stud->dorm);
                head=insert(head,stud);
                print(head);
                printf("请输入0返回\n");
                scanf("%d",&m);
                while(m!=0)
                {
                    printf("请输入0返回\n");
                    scanf("%d",&m);
                }
                break;
            }
            case 6:
            {   
                system("cls");
                print(head);
                printf("请输入0返回\n");
                scanf("%d",&m);
                while(m!=0)
                {
                    printf("请输入0返回\n");
                    scanf("%d",&m);
                }
                break;
            }
            case 4:{//保存 
            	system("cls");
            	save(head);
		           }
		    case 5:{//加载 
            	system("cls");
            	read( ); 
		           }
       }
    }
}
