#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MODE
// 0: ���� �̸��� ����ڰ� ���� �Է�
// 1: ���� �̸��� ����� �μ��� �Է�
#define MODE 0

FILE* try_to_open_file(const char* fname);

int main(int argc, char** argv)
{
    FILE* fp1;
    FILE* fp2;

    char fname1[FILENAME_MAX];
    char fname2[FILENAME_MAX];

    char ch1;
    char ch2;

#if MODE == 0
    printf("ù��° ���� �̸�: ");
    gets(fname1);

    printf("�ι�° ���� �̸�: ");
    gets(fname2);
#else
    if (argc < 3)
    {
        printf("����: %s ����1 ����2\n", argv[0]);
        exit(1);
    }

    strcpy(fname1, argv[1]);
    printf("ù��° ���� �̸�: %s\n", fname1);

    strcpy(fname2, argv[2]);
    printf("�ι�° ���� �̸�: %s\n", fname2);
#endif

    fp1 = try_to_open_file(fname1);
    fp2 = try_to_open_file(fname2);

    while (!feof(fp1) && !feof(fp2))
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2)
        {
            puts("�� ������ �ٸ��ϴ�.");
            exit(0);
        }
    }
    puts("�� ������ �����ϴ�.");

    fclose(fp1);
    fclose(fp2);

    return 0;
}

FILE* try_to_open_file(const char* fname)
{
    FILE* fp = fopen(fname, "r");
    if (!fp)
    {
        fprintf(stderr, "%s ������ �����ϴ�.\n", fname);
        exit(1);
    }

    return fp;
}
