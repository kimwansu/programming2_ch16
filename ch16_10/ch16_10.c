#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 512

FILE* try_to_open_file(const char* fname, const char* mode);

int main()
{
    FILE* fp;
    char fname[FILENAME_MAX];
    char buf[BUFLEN];
    int lineNo;

    printf("파일 이름: ");
    gets(fname);

    fp = try_to_open_file(fname, "r");
    for (lineNo = 1; !feof(fp); lineNo++)
    {
        buf[0] = '\0';
        fgets(buf, BUFLEN, fp);
        printf("%6d: %s", lineNo, buf);
    }
    putchar('\n');

    return 0;
}

FILE* try_to_open_file(const char* fname, const char* mode)
{
    FILE* fp = fopen(fname, mode);
    if (!fp)
    {
        fprintf(stderr, "%s 파일을 열 수 없습니다.\n", fname);
        exit(1);
    }

    return fp;
}
