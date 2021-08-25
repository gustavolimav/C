#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

    int entradas, i, flag = 1, save;

    scanf("%d", &entradas);

    int array[entradas];

    for(i = 0; i < entradas; i++) {
        scanf("%d", &array[i]);
    }

   while (flag != 0) {
        flag = 0;
        for(i = 0; i < entradas; i++) {
            if (i != 0) {
                if (save > array[i]) {
                    array[i-1] = array[i];
                    array[i] = save;
                    flag = 1;
                }
            }
            save = array[i];
        }
    }

    for(i = 0; i < entradas; i++) {
        printf("[%d]", array[i]);
    }
    return 0;
}
