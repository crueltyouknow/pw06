/*вариант 25*/
#include <stdio.h>

#define BITS 64

/* пропуск остатка строки ввода после ошибки */
static void skip_line(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void)
{
    int choice;
    int running = 1;
    unsigned int v;
    int r;

    while (running) {
        printf("\n=== Конвертер систем счисления ===\n");
        printf("1. dec -> hex\n");
        printf("2. dec -> oct\n");
        printf("3. dec -> bin\n");
        printf("4. hex -> dec\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");

        r = scanf("%d", &choice);
        if (r == EOF) {
            break;                          /* конец ввода */
        }
        if (r != 1) {
            skip_line();
            printf("Ошибка: введите номер пункта меню\n");
            continue;                       /* пропуск некорректного ввода */
        }

        switch (choice) {
        case 1:
            printf("Введите десятичное число: ");
            if (scanf("%u", &v) != 1) {
                skip_line();
                printf("Ошибка: нужно целое неотрицательное число\n");
                break;
            }
            printf("HEX: %X\n", v);
            break;
        case 2:
            printf("Введите десятичное число: ");
            if (scanf("%u", &v) != 1) {
                skip_line();
                printf("Ошибка: нужно целое неотрицательное число\n");
                break;
            }
            printf("OCT: %o\n", v);
            break;
        case 3:
            printf("Введите десятичное число: ");
            if (scanf("%u", &v) != 1) {
                skip_line();
                printf("Ошибка: нужно целое неотрицательное число\n");
                break;
            } else {
                char bits[BITS + 1];
                int len = 0;
                int k;

                if (v == 0) {
                    bits[len++] = '0';
                }
                while (v > 0 && len < BITS) {
                    bits[len++] = (char)('0' + (v % 2));
                    v /= 2;
                }
                printf("BIN: ");
                for (k = len - 1; k >= 0; k--) {
                    putchar(bits[k]);
                }
                putchar('\n');
            }
            break;
        case 4:
            printf("Введите шестнадцатеричное число: ");
            if (scanf("%x", &v) != 1) {
                skip_line();
                printf("Ошибка: нужно шестнадцатеричное число\n");
                break;
            }
            printf("DEC: %u\n", v);
            break;
        case 0:
            running = 0;
            break;
        default:
            printf("Ошибка: пункта %d нет в меню\n", choice);
            continue;
        }
    }

    printf("Работа завершена.\n");

    /*
     * Что будет, если забыть break в одной из меток case: управление не
     * выйдет из switch, а "провалится" (fall-through) в следующую метку, и
     * ее операторы тоже выполнятся. Например, без break в case 1 после
     * вывода HEX программа продолжила бы выполнять case 2 и запросила бы
     * число еще раз для вывода OCT.
     */
    return 0;
}
