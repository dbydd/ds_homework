#include "stdio.h"
#include "stdlib.h"
typedef struct {
    int xh;   /*ѧ��*/
    float sg; /*����*/
} STUDENTS;
int getRecs(STUDENTS s[]);
void sort(STUDENTS s[], int n);

int compare(STUDENTS* a, STUDENTS* b) {
    return (*a).sg >= (*b).sg;
}

int main() {

    STUDENTS stu[20];
    int n, i;
    n = getRecs(stu);
    // for (i = 0; i < n; i++) {
        // printf("%d %.2f\n", stu[i].xh, stu[i].sg);
    // }

    sort(stu, n);
    printf("\n���������\n");
    for (i = 0; i < n; i++) {
        printf("%d %.2f\n", stu[i].xh, stu[i].sg);
    }
    return 0;
}

void sort(STUDENTS a[], int n) {
    qsort(a, n, sizeof(STUDENTS), compare);
}



int getRecs(STUDENTS s[]) {
    FILE* fp = fopen("records.txt", "r");
    int i;
    for (i = 0; !feof(fp) && i < 20; i++) {
        fscanf(fp, "%d %f", &(s[i].xh), &(s[i].sg));
    }

    return i;
}


