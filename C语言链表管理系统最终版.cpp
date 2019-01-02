#include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
# define F "����.txt" 
 
typedef struct Student
{
	int lh;			//����¥
    int roomnum;	//���� 
    int bednum;		//��λ
    int num;		//ѧ�� 
    char name[20];	//���� 
    struct Student *next;
}Stu;
 
//�˵�
int menu_select()
{      
 	int a;
    do{
        system("cls");
        printf("\n\n        ----------------------ѧ���������ϵͳ----------------------\n");
        printf("\t\t 1. ���                      \n\n");
        printf("\t\t 2. ��ӡ                      \n\n");
        printf("\t\t 3. ����                      \n\n");
        printf("\t\t 4. ����                      \n\n");
        printf("\t\t 5. ����                      \n\n");
        printf("\t\t 6. �޸�                      \n\n");
        printf("\t\t 7. ɾ��                      \n\n");
        printf("\t\t 8. ����                      \n\n");
        printf("\t\t 9. ��ȡ                      \n\n");
		printf("\t\t 0. �˳�                      \n\n");
        printf("     -----------------------------------------------------------------\n");
        printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
        scanf("%d",&a);
    }while(a<0||a>9);
    return a;
}
 
//���
Student *input(int n)                  
{
	int i;
	Stu *head,*l,*r;
	if(n<=0)
	{
		return NULL;
	}
	l=(Stu *)malloc(sizeof(Stu));
	printf("\t\t����¥��:");
	scanf("%d",&l->lh);
	printf("\t\t�����:");                
	scanf("%d",&l->roomnum);
	printf("\t\t��λ��:");
	scanf("%d",&l->bednum);
	printf("\t\tѧ��:");
	scanf("%d",&l->num);
	printf("\t\t����:");
	scanf("%s",&l->name);
	printf("\n");
	head=l;
	for(i=1;i<n;i++)
	{
		r=(Stu *)malloc(sizeof(Stu));
		printf("\t\t����¥��:");
	    scanf("%d",&r->lh);
	    printf("\t\t�����:");                
	    scanf("%d",&r->roomnum);
	    printf("\t\t��λ��:");
	    scanf("%d",&r->bednum);
	    printf("\t\tѧ��:");
	    scanf("%d",&r->num);
	    printf("\t\t����:");
	    scanf("%s",&r->name);
	    printf("\n");
	    l->next=r;
	    l=r;
	    if(i==n-1)
		{
			l->next=NULL;	
		}
	}
	return head;
}
 
//���
void output(Stu *head)
{
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf(" ����¥��          �����               ��λ��               ");
	printf("          ѧ��              ����               \n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	Stu *p;
	p=head;
	if(head==NULL)
	{
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	}
	else
	{
		do
		{
			printf("%3d%20d%20d%30d%20s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);
			p=p->next;
		}while(p!=NULL);
	} 
}
//����
int sort_select(Stu *head)
{
	Stu *p,*q;
	int lh;
	int roomnum;
	int bednum;
	int num; 
	char name[20];
	    	system("cls");    
			for(p=head;p!=NULL;p=p->next)
			{
			    for(q=p->next;q!=NULL;q=q->next)
			    {
			        if(p->num>q->num)//�Ƚ�ѧ�� 
			        {
			            lh=q->lh;
			            roomnum=q->roomnum;
			            bednum=q->bednum;
			            num=q->num;
			            strcpy(name,q->name);
			            
		                q->lh=p->lh;
		                q->roomnum=p->roomnum;
			            q->bednum=p->bednum;
			            q->num=p->num;
			            strcpy(q->name,p->name);
			            
		                p->lh=lh;
		                p->roomnum=roomnum;
		                p->bednum=bednum;
		                p->num=num;
		                strcpy(p->name,name);
					}
			    }
			}
		    output(head);
	    	system("pause");
			return 1;
   
    	system("pause");
    	return 0;
	}

 
//����
void insert(Stu *head)
{
    Stu *p,*pnew;
    int m;
	pnew=(Stu *)malloc(sizeof(Stu));
    printf("\t\t����¥��:");
	scanf("%d",&pnew->lh);
	printf("\t\t�����:");                
	scanf("%d",&pnew->roomnum);
	printf("\t\t��λ��:");
	scanf("%d",&pnew->bednum);
	printf("\t\tѧ��:");
	scanf("%d",&pnew->num);
	printf("\t\t����:");
	scanf("%s",&pnew->name);
	printf("\n");
    printf("\t\t\t��������Ҫ�嵽��λ�ã�");
	scanf("%d",&m);
	p=head;
	for(int j=1;j<m&&p!=NULL;j++)
	{
	    p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}
 

//����
int find_select(Stu *head)
{
	Stu *p;
			system("cls");
			p=head;
			int f;
			printf("\n\t\t\tҪ���ҵ�ѧ��Ϊ��");
			scanf("%d",&f);
			printf(" ----------------------------------------------------------------------------------------");
			printf("---------------------------------------------------------------------------------------\n");
			printf(" ����¥��          �����               ��λ��          ");
			printf("                   ѧ��                 ����          \n");
			printf(" ----------------------------------------------------------------------------------------");
			printf("---------------------------------------------------------------------------------------\n");
			while(p!=NULL)
			{
				if(p->num==f)
					printf("%3d%20d%20d%30d%20s\n",p->lh,p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
			system("pause");
			return 1;

	}

//�޸�
void correct(Stu *head)
{
	int a;
	printf("\n\t\t\t�����뽫Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d",&a);
	Stu *p;
    p=head;
	while(p!=NULL)
    {
    	if(a==p->num)
    	{
			printf("\t\tҪ�޸ĵ�����¥��:");
		    scanf("%d",&p->lh);
		    printf("\t\tҪ�޸ĵķ����:");                
		    scanf("%d",&p->roomnum);
		    printf("\t\tҪ�޸ĵĴ�λ��:");
		    scanf("%d",&p->bednum);
		    printf("\t\tҪ�޸ĵ�ѧ��:");
		    scanf("%d",&p->num);
		    printf("\t\tҪ�޸ĵ�����:");
		    scanf("%s",&p->name);

		    printf("\n");
		}
        p=p->next;
    }
}
 
//ɾ��
Student *del(Stu *head)
{
	int x,y; 
	printf("\n\t\t\t1.ɾ��ĳ��ѧ����Ϣ");
	printf("\n\t\t\t2.ɾ��ȫ��ѧ����Ϣ\n");
	printf("\n\t\t\tѡ��1��2��");
    scanf("%d",&x);
    if(x==1)
    {
    	printf("\n\t\t\t�����뽫Ҫɾ��ѧ����λ�ã�");
    	scanf("%d",&y);
    	Stu *p,*q;
	    int i;
	    if(y-1==0)
	    {
			head=head->next;
		}
		else
		{
	    	p=head;
	    	for(i=1;i<y&&p->next!=NULL;i++)
			{
				p=p->next;
			}
			q=p->next;
			p->next=q->next;
		}
		printf("\n\t\t\tɾ���ɹ���\n");
		return head;
	}
	else if(x==2)
	{
		head=NULL;
		printf("\n\t\t\tɾ���ɹ���\n");
		return head;
	}
	else
	{
		printf("������󣬷������˵���\n");
		return head;
	}
}
 
//�����ļ� 
void write_file(Stu *head)
{
	FILE *fp;
	if((fp=fopen(F,"at+"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
	}
	Stu *p;
	p=head;
	while(p!=NULL)
	{
		fprintf(fp,"%d\t",p->lh);
		fprintf(fp,"%d\t",p->roomnum);
		fprintf(fp,"%d\t",p->bednum);
		fprintf(fp,"%d\t",p->num);
		fprintf(fp,"%s\t",p->name);
		p=p->next;
	}
	 
    fflush(fp);// ˢ�»���������������������д���ļ�
    fclose(fp);
}
 
//��ȡ�ļ� 
void read_file()
{

	printf("-----------------------------------------------------------------------------------------------------\n");
	printf(" ����¥��          �����               ��λ��               ");
	printf("          ѧ��                ����              \n");
	
	int lh;			//���� 
    int roomnum;	//����
    int bednum;		//��λ 
    int num;		//ѧ�� 
    char name[20];	//���� 
	FILE *fp;
	fp=fopen(F,"rt");
	while(fscanf(fp,"%d\t%d\t%d\t%d\t%s",&lh,&roomnum,&bednum,&num,&name)!=EOF)
	{
		printf("%3d%20d%20d%30d%20s\n",lh,roomnum,bednum,num,name);
	}
}
 
int main()          
{
	
	int n,m,x,y;
	Stu *head=NULL;
	Stu *pnew;
	for(;;)
	{
        switch(menu_select())
        {
            case 1:
            	system("cls");
            	printf("\n\n\t\t----------------------------\n\n");
				printf("\t\t\t����ѧ���ĸ�����");
				scanf("%d",&n);
				if(n<=0)
				{
					printf("\n\t\t\t��������ȷ������!");
					Sleep(500);
					break;
				}
				else
				{
					printf("\n\t\t\t����ѧ������\n\n");
	            	head=input(n);
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\n\t\t\t\t\t\t\t\t��ʾѧ������\n");
	            output(head);
	            system("pause");
	            break; 
            case 3:
			
					x=sort_select(head);
					getchar();

                break;
            case 4:
                system("cls");
                printf("\n\n\t\t-----------------------------------\n\n");
                printf("\t\t\t����Ҫ�����ѧ������Ϣ\n\n"); 
				insert(head);
				printf("\n\t\t����ɹ���\n");
				system("pause");
				break;               
            case 5:
            	system("cls");
				do
				{
					y=find_select(head);
				}while(y!=0);
                break;
            case 6:
            	system("cls");
                printf("\n\n\t\t-----------------------------------\n\n");
				correct(head);
				printf("\n\t\t\t�޸ĳɹ���\n");
                system("pause");
                break;
			case 7:
				system("cls");
                printf("\n\n\t\t-----------------------------------\n\n");
                head=del(head);
                system("pause");
                break;
			case 8:
				write_file(head);
				printf("\n\t\t\t����ɹ���\n");
				system("pause");
				break;
			case 9:
				printf("\n\t\t\t��ȡ�ɹ���\n");
				read_file();
				system("pause");
				break;
            case 0:
                printf("\n\t\t\t���˳�\n");
                exit(0);
        }
	}
}
