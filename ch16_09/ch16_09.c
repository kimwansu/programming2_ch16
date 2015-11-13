#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 4096

FILE* try_to_open_file(const char* fname, const char* mode);
void copy_file(FILE* rfp, FILE* wfp);

int main(int argc, char** argv)
{
    FILE* rfp1;
    FILE* rfp2;
    FILE* wfp;

    char rfname1[FILENAME_MAX];
    char rfname2[FILENAME_MAX];
    char wfname[FILENAME_MAX];

    if (argc < 4)
    {
        fprintf(stderr, "����: %s �Է�����1 �Է�����2 �������", argv[0]);
        exit(1);
    }

    strcpy(rfname1, argv[1]);
    strcpy(rfname2, argv[2]);
    strcpy(wfname, argv[3]);

    wfp = try_to_open_file(wfname, "w");
    rfp1 = try_to_open_file(rfname1, "r");
    copy_file(rfp1, wfp);
    fclose(rfp1);
    
    rfp2 = try_to_open_file(rfname2, "r");
    copy_file(rfp2, wfp);
    fclose(rfp2);
    
    fclose(wfp);
    printf("%s�� %s�� ���Ͽ� %s�� �ۼ��Ͽ����ϴ�.\n",
           rfname1, rfname2, wfname);

    return 0;
}

FILE* try_to_open_file(const char* fname, const char* mode)
{
    FILE* fp = fopen(fname, mode);
    if (!fp)
    {
        fprintf(stderr, "%s ������ �� �� �����ϴ�.\n", fname);
        exit(1);
    }

    return fp;
}

void copy_file(FILE* rfp, FILE* wfp)
{
    char buf[BUFLEN];
    int read;

    while (fgets(buf, BUFLEN, rfp))
    {
        fputs(buf, wfp);
    }
}
