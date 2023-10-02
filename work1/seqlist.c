#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct
{
    int xh;   /*学号*/
    float sg; /*身高*/
    int sex;  /*性别，0为男生，1为女生*/
} datatype;

typedef struct
{
    datatype data[MAX]; /*存放顺序表元素的数组*/
    int  last;      /*表示data中实际存放元素个数*/
} Seqlist;

void initList(Seqlist  *lp);/*置一个空表*/
void createList(Seqlist  *lp);/*建一个学生顺序表*/
void sort_xh(Seqlist  *lp);/*按学号排序*/
void pntList(Seqlist  *lp);/*输出学生表*/
void save(Seqlist  *lp,char strname[]);/*保存学生顺序表到指定文件*/

/*置一个空表*/
void initList(Seqlist  *lp)
{
    lp->last=0;
}

/*建一个学生顺序表*/
void createList(Seqlist  *lp)
{
    FILE *fp;
    datatype stu;
    if((fp=fopen("records.txt","r"))==NULL)
    {
        printf("can not open read file !\n");
        exit(1);      /*返回OS,该函数定义在stdlib.h中*/
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d%f%d",&stu.xh,&stu.sg,&stu.sex);
        lp->data[lp->last]=stu;
        lp->last++;
    }
    fclose(fp);
}


/*按学号排序*/
void sort_xh(Seqlist  *lp)
{
    int i,j,k;
    datatype stu;
    for(i=0; i<lp->last-1; i++)
    {
        k=i;
        for(j=i+1; j<lp->last; j++)
            if(lp->data[j].xh<lp->data[k].xh )
                k=j;
        if(k!=i)
        {
            stu=lp->data[k];
            lp->data[k]=lp->data[i];
            lp->data[i]=stu;
        }
    }
}

/*输出学生顺序表*/
void pntList(Seqlist  *lp)
{
    int i;
    for(i=0; i<lp->last ; i++)
        printf("%2d: %.2f %d\n",lp->data [i].xh,lp->data [i].sg,lp->data[i].sex);
}

/*保存学生顺序表到指定文件*/
void save(Seqlist  *lp,char strname[])
{
    FILE *fp;
    int i;
    if((fp=fopen(strname,"w"))==NULL)
    {
        printf("can not open write file !\n");
        exit(1);      /*返回OS*/
    }
    for(i=0; i<lp->last ; i++)
    {
        fprintf(fp,"%2d %5.2f %2d\n",lp->data[i].xh,lp->data[i].sg,lp->data[i].sex);
    }

    fclose(fp);
}
