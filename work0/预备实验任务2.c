#include "stdio.h"
#include "stdlib.h"

/// @brief 似乎是系统编码问题，源文件的非ascii字符产生了乱码
typedef struct {
    int xh;   /*ѧ��*/
    float sg; /*����*/
} STUDENTS;
int getRecs(STUDENTS s[]);
void sort(STUDENTS s[], int n);

/// @brief 比较函数，参见 sort 函数
int compare(STUDENTS* a, STUDENTS* b) {
    return (*a).sg >= (*b).sg;
}

int main() {

    STUDENTS stu[20];
    int n, i;
    n = getRecs(stu);
    for (i = 0; i < n; i++) {
        printf("%d %.2f\n", stu[i].xh, stu[i].sg);
    }

    sort(stu, n);
    printf("\n学号\t身高\n");
    for (i = 0; i < n; i++) {
        printf("%d %.2f\n", stu[i].xh, stu[i].sg);
    }
    return 0;
}

void sort(STUDENTS a[], int n) {
    //c std标准库自带的快速排序算法
    //参数格式为：输入数组，数组大小，数组元素类型大小，比较函数的函数指针
    qsort(a, n, sizeof(STUDENTS), compare);
}


/// @return 返回值为数据条目的数量
int getRecs(STUDENTS s[]) {
    //以只读打开文件
    FILE* fp = fopen("records.txt", "r");
    int i;
    //获取数据 当到达文件结尾或达到缓存数组上限时停止
    for (i = 0; !feof(fp) && i < 20; i++) {
        fscanf(fp, "%d %f", &(s[i].xh), &(s[i].sg));
    }

    return i;
}