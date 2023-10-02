/*sy1.c程序文件代码*/
#include "seqlist.c"  //导入自定义类型及函数所在的文件seqlist.c，该文件与sy1.c存于同一目录�?
void  insertX(Seqlist* lp, datatype x);
void reverse(Seqlist* lp);
int count(Seqlist* lp, float y);
void  deleSex(Seqlist* lp, int sex);
int main() {
    Seqlist stu;  //定义stu为学生顺序表变量
    datatype x;  // x为存储一个学生元素的变量
    int c;
    char filename[20];  //filename为存储文件名的数�?
    /*创建一个包含学生学号、身高、性别的学生身高信息表stu并输出到屏幕，学生信息从records.txt文件读取*/
    initList(&stu);      //调用函数initList初始化顺序表stu
    createList(&stu);   // 调用函数createList创建学生表stu
    printf("\nsource list:\n");
    pntList(&stu);          //调用函数pntList打印学生表stu
    getchar();   //在执行程序能起到暂定的作用，按任意键继续
    /*从键盘输入一个身高值，统计高于该身高的学生个数并输出在屏幕*/
    printf("\nInput  a student height: \n");
    scanf("%f", &x.sg);
    c = count(&stu, x.sg);         //统计身高高于指定值的学生数存于c�?
    printf("\nThe higher height :%d\n", c);
    getchar();

    /*对已建立的学生身高信息表进行倒置，结果输出在屏幕�?*/
    reverse(&stu);       //倒置顺序�?
    printf("\nlist after reverse:\n");
    pntList(&stu);
    getchar();

    /*对学生信息表按学号从小到大排序，并把结果写入到数据文件中（result.txt�?*/
    sort_xh(&stu);   //调用函数sort_xh 对学生表stu按学号从小到大排�?
    printf("\nInput new file name to save: ");
    gets(filename);     //键盘输入文件名字符串存于filename数组�?
    save(&stu, filename);  //调用函数save把顺序表stu存于文件在filename�?

    /*从键盘输入一位学生信息插入到已排序的学生信息表中，保持学号有序；*/
    printf("\nInput a student information: \n");
    scanf("%d%f%d", &x.xh, &x.sg, &x.sex);
    insertX(&stu, x);                   //插入
    printf("\nlist after insert:\n");
    pntList(&stu);
    getchar();

    /*从键盘输入一个性别�?0为男生，1为女生），删除该性别的学�?*/
    printf("\nInput a student sex�?0为男生，1为女生）: \n");
    scanf("%d", &x.sex);
    deleSex(&stu, x.sex);        //删除
    printf("\nlist after delete:\n");
    pntList(&stu);
    return 0;
}

/*统计学生表中身高值高于y的学生数并返�?*/
int count(Seqlist* lp, float y) {
    int i, ct = 0;

    for (int i = 0; i < lp->last; i++) {
        if (lp->data[i].sg > y) {
            ct++;
        }
    }

    return ct;
}

/*对lp指向的顺序表进行倒置操作*/
void reverse(Seqlist* lp) {
    int i, k;
    datatype tmp;
    //通过前后数据元素交换的方式实现倒置
    for (i = 0, k = lp->last - 1; i < k; i++, k--) {
        tmp = lp->data[i];
        lp->data[i] = lp->data[k];
        lp->data[k] = tmp;
    }
}

/*在学号从小到大排序的学生表中插入值为x的学生仍保持学号的有序�?*/
void insertX(Seqlist* lp, datatype x) {
    int i;
    if (lp->last >= MAX) {
        printf("list is full"); return;
    }
    //在学号升序的顺序表中找插入位置后，插入x并使表长�?1

    for (i = 0; i < lp->last; i++) {
        if (lp->data[i].xh > x.xh) {
            break;
        }
    }

    for (int j = lp->last; j > i; j--) {
        lp->data[j] = lp->data[j - 1];
    }

    lp->data[i] = x;
}
/*删除性别为sex�?0为男生，1为女生）的学�?*/
void  deleSex(Seqlist* lp, int sex) {

    int deleted = 0, index = 0;

    for (index = 0; index < lp->last; index++) {
        if (!(lp->data[index].sex == sex)) {
            lp->data[deleted++] = lp->data[index];
        }
    }

    lp->last = deleted;

}