#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double getAvg(int a[], int n);
int getIndex(int a[], int n, double x);

int main() {
	int arr[10], n, i;
	double avg;
	n = 8;
	for (i = 0; i < n; i++)
		arr[i] = rand() % 10;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	avg = getAvg(arr, n);
	printf("avg=%lf\n", avg);

	i = getIndex(arr, n, avg);
	printf("minpos=%d,value=%d\n", i, arr[i]);
	return 0;
}

/// @brief 取平均值，返回结果为double类型
/// @param a 数组
/// @param n 数组元素个数
/// @return 平均值
double getAvg(int a[], int n) {

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	return sum / n;
}

/// @brief 获取 @param a 中最接近 @param x 的元素
/// @param a 输入数组
/// @param n 数组元素个数
/// @param x 带查找值
/// @return 查询到的元素下标
int getIndex(int a[], int n, double x) {
	int index = 0;
	double err = abs(a[0] - x);
	for (int i = 1; i < n; i++) {
		double temp = abs(a[i] - x);
		if (temp < err) {
			err = temp;
			index = i;
		}

	}

	return index;
}

1 7 4 0 9 4 8 8
avg = 5.125000
minpos = 1, value = 7
(base)
# 19920 @ dbydd_laptop in ~[13:25 : 41]
$