#include "linklist.c"
int count(LinkNode* head, float sg_fm, float sg_m);/*统计head为头指针的学生链表中身高达标人数并返回*/
void insertX(LinkNode* head, datatype x);/*在学号从小到大排序的学生链表中插入值为x的学生仍保持学号的有序性*/
int delList(LinkNode* head, float sg);/*删除head为头指针的学生链表中身高低于指定身高的所有学生结点，删除成功返回1，否则返回0*/
float avgList(LinkNode head);/*求head为头指针的学生链表中身高平均值*/

void main() {
    LinkNode* head = initList();
    int c, flag;
    float sg, sg_fm, sg_m;
    datatype x;/*建立与源数据文件同序的学生链表并输出；*/
    createList_2(head);
    printf("\n与数据文件同序的学生链表：\n");
    pntList(head); /*调用函数打印输出链表中信息*/
    getchar();/*统计学生链表中身高达标人数（男女生的身高达标值由键盘输入）并打印结果；*/
    printf("\n输入达标的女生、男生身高值：");
    scanf("%f%f", &sg_fm, &sg_m);
    c = count(head, sg_fm, sg_m);
    printf("\n达标学生人数为：%d", c);
    getchar();
    /*对学生链表按学号进行排序*/
    sort_xh(head);
    /*在学生链表中插入指定的学生元素后使链表仍按学号有序*/
    x.xh = 3;
    x.sg = 1.67;
    x.sex = 0;
    insertX(head, x);
    printf("\n new list after insert:\n");
    pntList(head);
    getchar();
    /*对学生链表进行倒置，结果输出到文件result.txt中；*/
    reverse(head);
    save(head, "result.txt");
    getchar();
    /*删除链表中身高低于指定值的所有学生结点;*/
    sg = 1.67;
    flag = delList(head, sg);
    if (flag)
        printf("\ndelete succeed!\n");
    else
        printf("\ndelete failed\n");
    printf("\n new list after delete:\n");
    pntList(head);
    getchar();
}


//统计学生链表中身高达标人数并返回(sg_fm女生身高达标值、sg_m男生身高达标值)
int count(LinkNode* head, float sg_fm, float sg_m) {
    int n = 0;
    for (LinkNode* p = head->next; p != NULL; p = p->next) {
        if (p->data.sex == 0) {
            if (p->data.sg >= sg_m) {
                n++;
            }
        }
        else {
            if (p->data.sg >= sg_fm) {
                n++;
            }
        }

    }
    return n;
}

//删除学生链表中身高低于指定身高(存于sg中)的所有学生结点，删除成功返回1，否则返回0
int delList(LinkNode* head, float sg) {
    LinkNode* position = head, * query = head->next;
    if (head->next == NULL) {
        return 0;
    }
    while (position->next != NULL) {
        if (query->data.sg < sg) {
            position->next = query->next;
            free(query);
            query = position->next;
        }
        else {
            position = position->next;
            query = query->next;
        }

    }
    return 1;
}


//在学号从小到大排序的学生链表中插入值为x的学生仍保持学号的有序性
void insertX(LinkNode* head, datatype x) {
    LinkNode* temp = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* p = head;
    for (;p->next != NULL; p = p->next) {
        if (p->next->data.xh > x.xh) {
            temp->data = x;
            temp->next = p->next;
            p->next = temp;
            return;
        }
    }

    p->next = temp;
    temp->next = NULL;
}

float avgList(LinkNode* n) {
    float sum = 0;
    int i = 0;
    for (LinkNode* p = n->next; p != NULL; p = p->next, i++) {
        sum += p->data.sg;
    }
    return sum / i;

}
