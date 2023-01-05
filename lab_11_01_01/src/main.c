#include "my_snprintf.h"

int compare_strings(char *s1, int len1, char *s2, int len2)
{
    printf("%s in comparison 1\n", s1);
    printf("%s in comparison 2\n", s2);
    if (len1 != len2)
        return EXIT_FAILURE;
    
    for (int i = 0; i < len1; i++)
    {
        if (*s1++ != *s2++)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    // char s1[100], s2[100], s3[100], s4[100];
    // short int num = 325;
    // int res1, res2, res3, res4;
    // res1 = my_snprintf(s1, 100, "You have %hd apples (%c).", num, 'a');
    // res2 = snprintf(s2, 100, "You have %hd apples (%c).", num, 'a');
    // res3 = my_snprintf(s3, 100, "You have %hx apples (%c).", num, 'e');
    // res4 = snprintf(s4, 100, "You have %hx apples (%c).", num, 'e');

    // printf("%s (%d)\n%s (%d)\n\n%s (%d)\n%s (%d)\n", s1, res1, s2, res2, s3, res3, s4, res4);

    char s5[5], s6[5];

    int buf = 5;

    int res5 = my_snprintf(s5, buf, "Hello, world! %d\n", 100);
    int res6 = snprintf(s6, buf, "Hello, world! %d\n", 100);

    printf("\n%s (%d)\n%s (%d)\n", s5, res5, s6, res6);

    // char s7[16], s8[16];
    // num = 0;

    // int res7 = my_snprintf(s7, 16, "%d", num);
    // int res8 = snprintf(s8, 16, "%d", num);

    // printf("\n%s (%d)\n%s (%d)\n", s7, res7, s8, res8);

    // char s9[1], s10[1];
    // int size = 1;

    // int res9 = my_snprintf(s9, size, "asfdasfwqfasf");
    // int res10 = snprintf(s10, size, "asfdasfwqfasf");

    // printf("\n%s (%d)\n%s (%d)\n", s9, res9, s10, res10);

    // char s1[100];
    // char s2[100];
    // char s3[100];
    // char s4[100];

    // int num;
    // scanf("%d", &num);

    // my_snprintf(s1, 100, "I have %x apples.", num);
    // printf("%s - my_snprintf for %%x\n", s1);
    // snprintf(s2, 100, "I have %x apples.", num);
    // printf("%s - snprintf for %%x\n\n", s2);

    // my_snprintf(s3, 100, "You got %d pears.", num);
    // printf("%s - my_snprintf for %%d\n", s3);
    // snprintf(s4, 100, "You got %d pears.", num);
    // printf("%s - snprintf for %%d\n\n", s4);

    // char s5[5], s6[5];

    // my_snprintf(s5, 5, "Hello, world! %d\n", 100);
    // snprintf(s6, 5, "Hello, world! %d\n", 100);
    // printf("%s - my\n", s5);
    // printf("%s - std\n", s6);
}