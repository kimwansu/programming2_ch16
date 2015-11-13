#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MODE
// 0: 파일 이름을 사용자가 직접 입력
// 1: 파일 이름을 명령행 인수로 입력
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
    printf("첫번째 파일 이름: ");
    gets(fname1);

    printf("두번째 파일 이름: ");
    gets(fname2);
#else
    if (argc < 3)
    {
        printf("사용법: %s 파일1 파일2\n", argv[0]);
        exit(1);
    }

    strcpy(fname1, argv[1]);
    printf("첫번째 파일 이름: %s\n", fname1);

    strcpy(fname2, argv[2]);
    printf("두번째 파일 이름: %s\n", fname2);
#endif

    fp1 = try_to_open_file(fname1);
    fp2 = try_to_open_file(fname2);

    while (!feof(fp1) && !feof(fp2))
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2)
        {
            puts("두 파일은 다릅니다.");
            exit(0);
        }
    }
    puts("두 파일은 같습니다.");

    fclose(fp1);
    fclose(fp2);

    return 0;
}

FILE* try_to_open_file(const char* fname)
{
    FILE* fp = fopen(fname, "r");
    if (!fp)
    {
        fprintf(stderr, "%s 파일이 없습니다.\n", fname);
        exit(1);
    }

    return fp;
}
