
#include <stdio.h>
#include <string.h>

#define STUDENTS 3
#define SUBJECTS 3

int main(void)
{
    const char *subjectName[SUBJECTS] = {"Math", "Phy", "Chem"};
    char name[STUDENTS][50];
    double score[STUDENTS][SUBJECTS];
    double sum[SUBJECTS] = {0};
    char label[80];
    int i, j;

    for (i = 0; i < STUDENTS; i++)
    {
        printf("Enter name of student %d: ", i + 1);
        scanf("%49s", name[i]);
        for (j = 0; j < SUBJECTS; j++)
        {
            printf("  %s score: ", subjectName[j]);
            scanf("%lf", &score[i][j]);
            sum[j] += score[i][j];
        }
    }

    printf("\n============================================================\n");
    printf("%-24s%12s%12s%12s\n", "Student (length)", "Math", "Phy", "Chem");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < STUDENTS; i++)
    {
        sprintf(label, "%s (%d)", name[i], (int)strlen(name[i]));
        printf("%-24s", label);
        for (j = 0; j < SUBJECTS; j++)
            printf("%12.2f", score[i][j]);
        printf("\n");
    }

    printf("------------------------------------------------------------\n");
    printf("%-24s", "Subject average");
    for (j = 0; j < SUBJECTS; j++)
        printf("%12.2f", sum[j] / STUDENTS);
    printf("\n============================================================\n");

    return 0;
}
