// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2015-2017, ARM Limited and Contributors. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char matrix[8][8];
struct rei {
	int Kj;
	int Ki;
};
void acharRei(struct rei *ponteiro)
{
		char posicao;
		int i, j, cont;

		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				scanf("%s", &matrix[i][j]);
				posicao = matrix[i][j];
				if (posicao == 'K') {
					ponteiro->Ki = i;
					ponteiro->Kj = j;
				}
			}
		}
}
int peao(struct rei *rei)
{
		char posicao, posicao2;
		int i, j;

		posicao = matrix[rei->Ki-1][rei->Kj-1];
		posicao2 = matrix[rei->Ki-1][rei->Kj+1];
		if (posicao == 'p') {
			printf("XEQUE");
			return 0;
		} else if (posicao2 == 'p') {
			printf("XEQUE");
			return 0;
		}
		return 1;
}

int torre(struct rei *rei)
{
		char posicao;
		int i, j, ki, kj;

		ki = rei->Ki;
		kj = rei->Kj;
		for (j = kj + 1; j < 8; j++) {
			posicao = matrix[ki][j];
			if (posicao == '-' || posicao == 't' || posicao == 'K') {
				if (posicao == 't') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		for (j = kj - 1; j >= 0; j--) {
			posicao = matrix[ki][j];
			if (posicao == '-' || posicao == 't' || posicao == 'K') {
				if (posicao == 't') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		for (i = ki + 1; i < 8; i++) {
			posicao = matrix[i][kj];
			if (posicao == '-' || posicao == 't' || posicao == 'K') {
				if (posicao == 't') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		for (i = ki - 1; i >= 0; i--) {
			posicao = matrix[i][kj];
			if (posicao == '-' || posicao == 't' || posicao == 'K') {
				if (posicao == 't') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}

}

int cavalo(struct rei *rei)
{
		char posicao;
		int ki, kj;

		ki = rei->Ki;
		kj = rei->Kj;
		posicao = matrix[ki-2][kj+1];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki-2][kj-1];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki-1][kj-2];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki-1][kj+2];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki+1][kj-2];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki+1][kj+2];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki+2][kj-1];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki+2][kj+1];
		if (posicao == 'c') {
			printf("XEQUE");
			return 0;
		}
		return 1;
}
int bispo(struct rei *rei)
{
		char posicao;
		int i, j, ki, kj;

		ki = rei->Ki;
		kj = rei->Kj;
		j = kj + 1;
		for (i = ki + 1; i < 8; i++) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'b') {
				if (posicao == 'b') {
					printf("XEQUE");
					return 0;
				}
				} else {
					break;
				}
				j += 1;
		}
		j = kj + 1;
		for (i = ki - 1; i >= 0; i--) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'b') {
				if (posicao == 'b') {
					printf("XEQUE");
					return 0;
				}
				} else {
					break;
				}
				j += 1;
		}
		j = kj - 1;
		for (i = ki - 1; i >= 0; i--) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'b') {
				if (posicao == 'b') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
			j -= 1;
		}
		j = kj - 1;
		for (i = ki + 1; i < 8; i++) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'b') {
				if (posicao == 'b') {
					printf("XEQUE");
					return 0;
				}
				} else {
					break;
				}
				j -= 1;
		}
		return 1;
}
int reii(struct rei *rei)
{
		char posicao;
		int i, j, ki, kj;

		ki = rei->Ki;
		kj = rei->Kj;
		for (i = 1; i <= 3; i++) {
			posicao = matrix[ki - 1][kj + 2 - i];
			if (posicao == 'k') {
				printf("XEQUE");
				return 0;
			}
		}
		for (i = 1; i <= 3; i++) {
			posicao = matrix[ki + 1][kj + 2 - i];
			if (posicao == 'k') {
				printf("XEQUE");
				return 0;
			}
		}
		posicao = matrix[ki][kj + 1];
		if (posicao == 'k') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki][kj - 1];
		if (posicao == 'k') {
			printf("XEQUE");
			return 0;
		}
		return 1;
}

int rainha(struct rei *rei)
{
		char posicao;
		int i, j, ki, kj;

		ki = rei->Ki;
		kj = rei->Kj;
		j = kj + 1;
		for (i = ki + 1; i < 8; i++) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
			j += 1;
		}
		j = kj + 1;
		for (i = ki - 1; i >= 0; i--) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
			j += 1;
		}
		j = kj - 1;
		for (i = ki - 1; i >= 0; i--) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
			j -= 1;
		}
		j = kj - 1;
		for (i = ki + 1; i < 8; i++) {
			posicao = matrix[i][j];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
			j -= 1;
		}
		for (j = kj + 1; j < 8; j++) {
			posicao = matrix[ki][j];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		for (j = kj - 1; j >= 0; j--) {
			posicao = matrix[ki][j];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		for (i = ki + 1; i < 8; i++) {
			posicao = matrix[i][kj];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		for (i = ki - 1; i >= 0; i--) {
			posicao = matrix[i][kj];
			if (posicao == '-' || posicao == 'q') {
				if (posicao == 'q') {
					printf("XEQUE");
					return 0;
				}
			} else {
				break;
			}
		}
		posicao = matrix[ki-1][kj+1];
		if (posicao == 'q') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki-1][kj-1];
		if (posicao == 'q') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki+1][kj+1];
		if (posicao == 'q') {
			printf("XEQUE");
			return 0;
		}
		posicao = matrix[ki+1][kj-1];
		if (posicao == 'q') {
			printf("XEQUE");
			return 0;
		}
		return 1;
}

int main(void)
{
		struct rei *rei;

		rei = malloc(sizeof(struct rei));
		acharRei(rei);
		if (peao(rei) == 0) {
			free(rei);
			return 0;
		} else if (torre(rei) == 0) {
			free(rei);
			return 0;
		} else if (reii(rei) == 0) {
			free(rei);
			return 0;
		} else if (cavalo(rei) == 0) {
			free(rei);
			return 0;
		} else if (bispo(rei) == 0) {
			free(rei);
			return 0;
		} else if (rainha(rei) == 0) {
			free(rei);
			return 0;
		}
		free(rei);
		printf("NAO XEQUE");
}
