#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int xh;
	float sg;
	int sex;
} datatype;
typedef  struct node {
	datatype  data;
	struct  node* next;
} LinkNode;
LinkNode* initList();/*�?一�?空表（带头结点�??*/
void createList_1(LinkNode* head);/*创建单链�?*/
void createList_2(LinkNode* head);/*创建单链�?*/
void sort_xh(LinkNode* head);/*单链表排�?*/
void reverse(LinkNode* head);/*单链表倒置*/
void pntList(LinkNode* head);/*打印单链�?*/
void save(LinkNode* head, char strname[]);/*保存单链表到文件*/

LinkNode* initList() {
	LinkNode* p;
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->next = NULL;
	return p;
}

/*创建单链表方�?1*/
void createList_1(LinkNode* head) {
	FILE* fp;
	datatype stu;
	LinkNode* p;
	if ((fp = fopen("records.txt", "r")) == NULL) {
		printf("can not open read file !");
		exit(1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d%f%d", &stu.xh, &stu.sg, &stu.sex);
		p = (LinkNode*)malloc(sizeof(LinkNode));
		p->data = stu;
		p->next = head->next;
		head->next = p;
	}
	fclose(fp);
}

/*创建单链表方�?2*/
void createList_2(LinkNode* head) {
	FILE* fp;
	datatype stu;
	LinkNode* p, * rear;
	if ((fp = fopen("records.txt", "r")) == NULL) {
		printf("can not open read file !");
		exit(1);
	}
	rear = head;
	while (!feof(fp)) {
		fscanf(fp, "%d%f%d", &stu.xh, &stu.sg, &stu.sex);
		p = (LinkNode*)malloc(sizeof(LinkNode));
		p->data = stu;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	fclose(fp);
}

/*单链表排�?*/
void sort_xh(LinkNode* head) {
	LinkNode* q, * p, * u;
	p = head->next;
	head->next = NULL;/*利用原表头结点建新的空表*/
	while (p) {
		q = p; /*q为�??插入的结�?*/
		p = p->next;/*用p记录后继结点*/
		/*遍历新链表查找插入位�?*/
		u = head;
		while (u->next != NULL)/*查找插入位置*/
		{
			if (u->next->data.xh > q->data.xh)
				break;
			u = u->next;
		}
		/*插入在u结点的后�?*/
		q->next = u->next;
		u->next = q;
	}
}

/*单链表倒置*/
void reverse(LinkNode* head) {
	LinkNode* p, * r;
	p = head->next;
	head->next = NULL;
	while (p) {
		r = p;
		p = p->next;
		/*r指向结点头插到链�?*/
		r->next = head->next;
		head->next = r;
	}
}

/*输出单链�?*/
void pntList(LinkNode* head) {
	LinkNode* p;
	p = head->next;
	while (p != NULL) {
		printf("%2d: %.2f %d\n", p->data.xh, p->data.sg, p->data.sex);
		p = p->next;
	}
}

/*保存单链表到文件*/
void save(LinkNode* head, char strname[]) {
	FILE* fp;
	LinkNode* p;
	if ((fp = fopen(strname, "w")) == NULL) {
		printf("can not open write file !");
		exit(1);
	}
	p = head->next;
	while (p != NULL) {
		fprintf(fp, "%2d %5.2f %2d\n", p->data.xh, p->data.sg, p->data.sex);
		p = p->next;
	}
	fclose(fp);
}