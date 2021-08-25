#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int n, int arr[]) {
	int i, j, save;

	for (i = 1; i < n; i++) {
		save = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > save) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = save; 
	}
}

void selectionsort(int n, int arr[]) { 
	int i, j, aux, min;

	for (i = 0; i < (n-1) ; i++) {
		min = i;
		for (j = (i + 1); j < n ; j++) {
			if (arr[j] < arr[min]) {
				min = j;
		}
	}
		aux = arr[i]; 
		arr[i] = arr[min]; 
		arr[min] = aux;
	}
}

void bubblesort(int n, int arr[]) {
	int aux;

	for (int i = (n-1); i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}
	}

	return;
}

int main(void)
{

	int n = 0, a, b;
	FILE *input;


	printf("1 - Insertion Sort\n");
	printf("2 - Selection Sort\n");
	printf("3 - Bubble Sort\n");

	scanf("%d", &b);

	printf("1 - 1000\n");
	printf("2 - 5000\n");
	printf("3 - 10000\n");
	printf("4 - 20000\n");
	printf("5 - 50000\n");
	printf("6 - 75000\n");
	printf("7 - 100000\n");

	scanf("%d", &a);

	if (a == 1) {
		input = fopen("1000.txt", "r");
		n = 1000;
	}

	if (a == 2) {
		input = fopen("5000.txt", "r");
		n = 5000;
	}

	if (a == 3) {
		input = fopen("10000.txt", "r");
		n = 10000;
	}

	if (a == 4) {
		input = fopen("20000.txt", "r");
		n = 20000;
	}

	if (a == 5) {
		input = fopen("50000.txt", "r");
		n = 50000;
	}

	if (a == 6) {
		input = fopen("75000.txt", "r");
		n = 75000;
	}

	if (a == 7) {
		input = fopen("100000.txt", "r");
		n = 100000;
	}

	int arr[n];
	int i = 0;

	while (!feof(input)) {
		fscanf(input, "%d", &arr[i]);
		i++;
	}

	clock_t start, end;
	
	if (b == 1) {
		start = clock();
		insertionsort(n, arr);
		end = clock();
	} else if (b == 2) {
		start = clock();
		selectionsort(n, arr);
		end = clock();
	} else if (b == 3) {
		start = clock();
		bubblesort(n, arr);
		end = clock();
	}
	

	double time = (end - start) * 1000.0 / CLOCKS_PER_SEC;

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nTEMPO: %g ms.\n", time);

	return 0;
}
