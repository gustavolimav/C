// SPDX-License-Identifier: GPL-3.0
#include <stdio.h>

static int left(int i, int j, int lines, int coluns, int arr[lines][coluns]);
static int rigth(int i, int j, int lines, int coluns, int arr[lines][coluns]);

int up(int i, int j, int lines, int coluns, int arr[lines][coluns])
{
	int answer = 1;

	arr[i][j] = 1;
	i--;
	if (i == (lines - 1) && j == (coluns - 1))
		return 0;
	if (arr[i][j] == 0)
		if (arr[i][j + 1] == 0) {
			answer = rigth(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i][j - 1] == 0) {
			answer = left(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i - 1][j] == 0) {
			answer = up(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
	return answer;
}

int down(int i, int j, int lines, int coluns, int arr[lines][coluns])
{
	int answer = 1;

	arr[i][j] = 1;
	i++;
	if (i == (lines - 1) && j == (coluns - 1))
		return 0;

	if (arr[i][j] == 0) {
		if (arr[i + 1][j] == 0 && i != lines - 1) {
			answer = down(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i][j + 1] == 0 && j != coluns - 1) {
			answer = rigth(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i][j - 1] == 0 && j != 0) {
			answer = left(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
	}
	return answer;
}

int rigth(int i, int j, int lines, int coluns, int arr[lines][coluns])
{
	int answer = 1;

	arr[i][j] = 1;
	j++;

	if (i == (lines - 1) && j == (coluns - 1))
		return 0;
	if (arr[i][j] == 0) {
		if (arr[i + 1][j] == 0 && i != lines - 1) {
			answer = down(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i][j + 1] == 0 && j != coluns - 1) {
			answer = rigth(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i - 1][j] == 0 && i != 0) {
			answer = up(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
	}
	return answer;
}

int left(int i, int j, int lines, int coluns, int arr[lines][coluns])
{
	int answer = 1;

	arr[i][j] = 1;
	j--;

	if (i == (lines - 1) && j == (coluns - 1))
		return 0;

	if (arr[i][j] == 0) {
		if (arr[i + 1][j] == 0 && i != lines - 1) {
			answer = down(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i][j - 1] == 0 && j != 0) {
			answer = left(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
		if (arr[i - 1][j] == 0 && i != 0) {
			answer = up(i, j, lines, coluns, arr);
			if (answer == 0)
				return 0;
		}
	}
	return answer;
}

int maze(int i, int j, int lines, int coluns, int arr[lines][coluns])
{
	int answer;

	if (arr[i + 1][j] == 0 && i != lines - 1) {
		answer = down(i, j, lines, coluns, arr);
		if (answer == 0)
			return 0;
	}
	if (arr[i][j + 1] == 0 && j != coluns - 1) {
		answer = rigth(i, j, lines, coluns, arr);
		if (answer == 0)
			return 0;
	}
	return 1;
}

int verificar_tamanho(const char arr[])
{
	int i = 0;

	while (arr[i] != '\0')
		i++;
	return i;
}

int linhas(FILE *fp)
{
	char text[200];
	int liness = 0, i;

	fread(&text, sizeof(char), 200, fp);

	for (i = 0; i < verificar_tamanho(text); i++) {
		if (text[i] == '\n')
			liness++;
	}
	return liness + 1;
}

int colunas(FILE *fp)
{
	char text[200];
	int colunas = 0, i;

	fread(&text, sizeof(char), 200, fp);

	for (i = 0; i < verificar_tamanho(text); i++) {
		if (text[i] == '\n')
			return (colunas + 1) / 2;

		colunas++;
	}
}

int main(int argc, const char *argv[])
{
	int i, j;
	int a, b, lines, coluns;

	FILE *fp;

	fp = fopen(argv[1], "r");
	lines = linhas(fp);
	fseek(fp, 0, SEEK_SET);
	coluns = colunas(fp);
	fseek(fp, 0, SEEK_SET);

	int matriz[lines][coluns];

	while (!feof(fp)) {
		for (i = 0; i < lines; i++) {
			for (j = 0; j < coluns; j++)
				fscanf(fp, "%d", &matriz[i][j]);
		}
	}
	fclose(fp);
	a = maze(0, 0, lines, coluns, matriz);
	if (a == 1)
		printf("False\n");
	else
		printf("True\n");

	return 0;
}
