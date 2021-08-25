#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void myswitch(int arr[], int i, int j) {
    int aux;

    aux = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = aux;
}

void max_heapify(int size, int arr[], int i) {
    int largest;
    int l = 2 * i;
    int r = (2 * i) + 1;

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

int main(void)
{

	int n = 0, a, b;
	FILE *input;

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
	
	start = clock();
	heapsort(n, arr);
	end = clock();
	

	double time = (end - start) * 1000.0 / CLOCKS_PER_SEC;

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nTEMPO: %g ms.\n", time);

	return 0;
}
