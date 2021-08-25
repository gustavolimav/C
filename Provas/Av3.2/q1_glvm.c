// SPDX-License-Identifier: GPL-3.0
#include <stdio.h>

char *concatenar_array(char arr[], char arr2[])
{
	int i, j;

	for (i = 0; i < 10000; ++i) {
		if (arr[i] == '\0')
			break;
	}
	for (j = 0; arr2[j] != '\0'; ++j, ++i)
		arr[i] = arr2[j];

	arr[i] = '\0';
	return arr;
}

int verificar_contem(const char P[], const char S[])
{
	int i = 0, j, k;

	for (i = 0; P[i] != '\0'; i++) {
		k = 0;
		for (j = i; P[j] != '\0' && S[k] != '\0' && P[j] == S[k]; j++)
			k++;
		if (S[k] == '\0')
			return i;
	}
	return -1;
}

int verificar_igualdade(const char arr[], const char semente[])
{
	int i = 0;

	while (arr[i] == semente[i] && arr[i] != '\0' && semente[i] != '\0')
		i++;

	if (arr[i] == '\0' && semente[i] == '\0')
		return 0;
	return 1;
}

int ver_tam(const char arr[])
{
	int i = 0;

	while (arr[i] != '\0')
		i++;

	return i;
}

int verificar(const char semente[], const char palavra[])
{
	char aux[1000], inicio[1000], fim[1000];
	int i, j = 0, x, y, a;

	x = verificar_contem(palavra, semente);
	if (x == -1)
		return 1;
	y = ver_tam(semente);
	x = x + y;
	for (i = x; i < (ver_tam(palavra)) || palavra[i] == '\0'; i++) {
		fim[j] = palavra[x];
		j++;
		x++;
	}
	j = 0;
	for (i = 0; i < verificar_contem(palavra, semente); i++) {
		inicio[j] = palavra[i];
		j++;
		if (i == verificar_contem(palavra, semente) - 1)
			inicio[j] = '\0';
	}

	concatenar_array(inicio, fim);

	if (verificar_igualdade(inicio, semente) == 0)
		return 0;
	a = verificar(semente, inicio);
	if (a == 0)
		return 0;
	else
		return 1;
}

int main(int argc, const char *argv[])
{
	int i;

	i = verificar(argv[1], argv[2]);
	if (i == 0)
		printf("True\n");
	else
		printf("False\n");
	return 0;
}
