#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct {
     int xh;   /*ѧ��*/
     float sg; /*���*/
     int sex;  /*�Ա�0Ϊ������1ΪŮ��*/
} datatype;
typedef struct{
     datatype data[MAX]; /*���˳���Ԫ�ص�����*/
     int  last;      /*��ʾdata��ʵ�ʴ��Ԫ�ظ���*/
}Seqlist;

void initList(Seqlist  *lp);/*��һ���ձ�*/
void createList(Seqlist  *lp);/*��һ��ѧ��˳���*/
void sort_xh(Seqlist  *lp);/*��ѧ������*/
void pntList(Seqlist  *lp);/*���ѧ����*/
void save(Seqlist  *lp,char strname[]);/*����ѧ��˳���ָ���ļ�*/

int main()
{
    Seqlist slt;
    FILE*f=fopen("records.txt","w");
    fprintf(f,"2 1.58 1\n4 1.81 0\n8 1.74 0\n5 1.68 0\n9 1.75 0\n1 1.64 1\n7 1.55 1\n6 1.72 1");
    fclose(f);
    /*�����������������ĿҪ��*/
    initList(&slt);
    createList(&slt);
    pntList(&slt);

    return 0;
}

/*��һ���ձ�*/
void initList(Seqlist  *lp)
{   lp->last=0; }

/*��һ��ѧ��˳���*/
void createList(Seqlist  *lp)
{
	FILE *fp;
	int xh;
	float sg;
	int sex;

	if((fp=fopen("records.txt","r"))==NULL)
	{
		printf("can not open read file !\n");
		exit(1);      /*����OS,�ú���������stdlib.h��*/
	}
	while(!feof(fp))
	{	fscanf(fp,"%d%f%d",&xh,&sg,&sex);
		lp->data[lp->last].xh=xh;
		lp->data[lp->last].sg=sg;
		lp->data[lp->last].sex=sex;
		lp->last++;
	}
	fclose(fp);
}

/*��ѧ������*/
void sort_xh(Seqlist  *lp)
{	int i,j,k;
	datatype st;

	for(i=0;i<lp->last-1;i++)
	{k=i;
	 for(j=i+1;j<lp->last;j++)
		 if(lp->data[j].xh<lp->data[k].xh )
			 k=j;
	 if(k!=i)
		 {st=lp->data[k];
		 lp->data[k]=lp->data[i];
		 lp->data[i]=st;}
	}
}

/*���ѧ��˳���*/
void pntList(Seqlist  *lp)
{ int i;
  for(i=0;i<lp->last ;i++)
	  printf("%2d: %.2f %d\n",lp->data [i].xh,lp->data [i].sg,lp->data[i].sex);
}

/*����ѧ��˳���ָ���ļ�*/
void save(Seqlist  *lp,char strname[])
{	FILE *fp;
	int i;
	if((fp=fopen(strname,"w"))==NULL)
	{
	  printf("can not open write file !\n");
	  exit(1);      /*����OS*/
	}
	for(i=0;i<lp->last ;i++)
	{
		fprintf(fp,"%2d %5.2f %2d\n",lp->data[i].xh,lp->data[i].sg,lp->data[i].sex);
	}

	fclose(fp);
}



