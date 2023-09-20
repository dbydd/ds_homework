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

double getAvg(int a[], int n) {

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	return sum / n;
}

int getIndex(int a[], int n, double x) {
	int index = 0;
	double err = abs([0] - x);
	for (int i = 1; i < n; i++) {
		double temp = abs(a[i] - x);
		if (temp < err) {
			err = temp;
			index = i;
		}

	}

	return index;
}
