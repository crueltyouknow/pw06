/*вариант 18*/
#include <stdio.h>

#define MAX_LEN 1024

int main(void)
{
    char out[MAX_LEN];
    int len = 0;
    int count = 0;
    int c;

    printf("Введите текст (завершается символом #):\n");
    while ((c = getchar()) != EOF && c != '#') {
        if (c == 'o') {
            c = '0';
            count++;
        }
        if (len < MAX_LEN - 1) {
            out[len++] = (char)c;
        }
    }
    out[len] = '\0';

    printf("Текст после замены:\n%s\n", out);
    printf("Количество замен символа 'o' на '0': %d\n", count);

    /*
     * Для этого варианта классификация через <ctype.h> не требуется:
     * достаточно сравнения с конкретным символом 'o'. Считывание идет
     * до символа '#' (или до конца ввода EOF), а переменная c имеет тип int,
     * чтобы можно было отличить EOF от допустимых кодов символов.
     */
    return 0;
}
