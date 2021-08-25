#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *a, int *b, int beg1, int beg2, int n) {
	int i = beg1, j = beg2, k = beg1;

	while (i < beg2 && j < (beg1 + n)) {
		if (a[i] <= a[j]) { 
			b[k] = a[i];
			i++;
			k++;
		} else { 
			b[k] = a[j];
			j++;
			k++;
		}
	}

	while (i < beg2) {
		b[k] = a[i];
		k++;
		i++;
	}

	while (j < (beg1 + n)) {
		b[k] = a[j];
		k++;
		j++;
	}
	
	for (int s = beg1; s < (beg1 + n); s++) {
		a[s] = b[s];
	}
}

void mergesort(int *a, int *b, int beg, int end) {
	if (end != beg) {
		mergesort(a, b, beg, ((beg + end) / 2));
		mergesort(a, b, ((beg + end) / 2) + 1, end);
		merge(a, b, beg, ((beg + end) / 2) + 1, end - beg + 1);
	} 
}

void myswitch(int arr[], int i, int j) {
	int aux;

	aux = arr[i]; 
	arr[i] = arr[j]; 
	arr[j] = aux;
}

void max_heapify(int size, int arr[], int i) {
	int largest;
	int l = 2*i;
	int r = (2*i) + 1;

	if ((l < size) && (arr[l] > arr[i])) {
		largest = l;
	} else {
		largest = i;
	}

	if ((r < size) && (arr[r] > arr[largest])) {
		largest = r;
	}

	if (largest != i) {
		myswitch(arr, i, largest);
		max_heapify(size, arr, largest);
	}
}

void build_max_heap(int arr[], int n) {
	for (int i = (n/2) - 1; i >= 0; i--) {
		max_heapify(n, arr, i);
	}
}

void heapsort(int n, int arr[]) {
	build_max_heap(arr, n);

	for (int i = (n-1); i >= 0; i--) {
		myswitch(arr, 0, i);
		max_heapify(i, arr, 0);
	}
}

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
	printf("4 - Heap Sort\n");
	printf("5 - Merge Sort\n");

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

	int *arr, *arrb;

	arr = (int*)malloc(n * sizeof(int));
	arrb = (int*)malloc(n * sizeof(int));

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
	} else if (b == 4) {
		start = clock();
		heapsort(n, arr);
		end = clock();
	} else if (b == 5) {
		start = clock();
		mergesort(arr, arrb, 0, (n-1));
		end = clock();
	}

	double time = (end - start) * 1000.0 / CLOCKS_PER_SEC;

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nTEMPO: %g ms.\n", time);

	return 0;
}
