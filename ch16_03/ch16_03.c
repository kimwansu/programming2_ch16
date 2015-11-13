#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 4096

FILE* try_to_open_file(const char* fname, const char* mode);

int main()
{
    FILE* rfp;
    FILE* wfp;

    char rfname[FILENAME_MAX];
    char wfname[FILENAME_MAX];

    int read;
    char buf[BUFLEN];

    printf("원본 파일 이름: ");
    gets(rfname);

    printf("복사 파일 이름: ");
    gets(wfname);

    rfp = try_to_open_file(rfname, "rb");
    wfp = try_to_open_file(wfname, "wb");

    while ((read = fread(buf, sizeof(char), BUFLEN, rfp)))
    {
        fwrite(buf, sizeof(char), read, wfp);
    }

    fclose(rfp);
    fclose(wfp);

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
