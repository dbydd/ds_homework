#include "stdio.h"

#define  MAX  100
typedef  struct {
    int   data[MAX];
    int  last;
}SeqList;

void reverse(SeqList* list);
int append(SeqList* l, int i);

int main(int argc, char const* argv[]) {
    SeqList list;
    list.last = -1; //initialize

    //生成数据并填充
    for (int i = 0; i <= MAX && append(&list, i + 1) != -1; i++) {
        printf("%d ", i + 1);
    }

    //分割线
    printf("\n======================================================================================================================\n");

    reverse(&list);

    for (int i = 0; i < MAX; i++) {
        printf("%d ", list.data[i]);
    }



    return 0;
}

int append(SeqList* l, int i) {
    if (l->last >= MAX) {
        return -1;
    }

    if (l->last == -1) {
        l->last = 0;
    }
    l->data[l->last++] = i;

    return l->last - 1;
}

void reverse(SeqList* list) {
    int temp = 0;
    for (int i = 0; i < list->last / 2; i++) {
        temp = list->data[i];
        list->data[i] = list->data[list->last - 1 - i];
        list->data[list->last - 1 - i] = temp;
    }
}
