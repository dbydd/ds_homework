#include <stdio.h>
#include <stdlib.h>
/*������������*/
typedef struct {
     int xh;   /*ѧ��*/
     float sg; /*���*/
     int sex;  /*�Ա�0Ϊ������1ΪŮ��*/
} datatype;
typedef  struct node{
   datatype  data;            /*������*/
   struct  node  *next;         /*ָ����*/
} LinkNode;
/*����ͷ�ĵ�����Ļ������㺯��*/
LinkNode* initList();/*��һ���ձ���ͷ��㣩*/
void createList_2(LinkNode* head);/*����������*/
void sort_xh(LinkNode* head);/*����������*/
void pntList(LinkNode* head);/*��ӡ������*/

int main()
{
    LinkNode* first;
    FILE*f=fopen("records.txt","w");
    fprintf(f,"2 1.58 1\n4 1.81 0\n8 1.74 0\n5 1.68 0\n9 1.75 0\n1 1.64 1\n7 1.55 1\n6 1.72 1");
    fclose(f);
    /*�����������������ĿҪ��*/
    first = initList();
    createList_2(first);
    pntList(first);

    return 0;
}

/*��һ���ձ�*/
LinkNode* initList()
{  LinkNode* p;
   p=( LinkNode*)malloc(sizeof(LinkNode));
   p->next=NULL;
   return  p;
}

/*������������2*/
void createList_2(LinkNode* head)
{	FILE *fp;
	datatype stu;
	LinkNode* p, *rear;
	if((fp=fopen("records.txt","r"))==NULL)
	{ printf("can not open read file !");
	  exit(1) ;
	}
	rear=head;
	while(!feof(fp))
	{	fscanf(fp,"%d%f%d",&stu.xh, &stu.sg, &stu.sex);
		p=( LinkNode*)malloc(sizeof(LinkNode));
		p->data = stu;
		p->next=NULL;
		rear->next=p;
		rear=p;
	}
	fclose(fp);
}

/*����������*/
void sort_xh(LinkNode* head)
{
  LinkNode* q, *p, *u;
  p=head->next;
  head->next=NULL;/*����ԭ��ͷ��㽨�µĿձ�*/
  while(p)
  { q=p; /*qΪ������Ľ��*/
    p=p->next;/*��p��¼��̽��*/
    /*������������Ҳ���λ��*/
    u=head;
    while(u->next!=NULL)/*���Ҳ���λ��*/
    { if(u->next->data.xh > q->data.xh)
         break;
      u=u->next;
    }
    /*������u���ĺ���*/
    q->next=u->next;
    u->next=q;
  }
}

/*���������*/
void pntList(LinkNode* head)
{	LinkNode* p;
	p=head->next;
	while (p!=NULL)
	{printf("%2d: %.2f %d\n",p->data.xh,p->data.sg,p->data .sex);
	  p=p->next;
	}
}

