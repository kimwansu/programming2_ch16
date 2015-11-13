#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[22];
    int Korean;
    int Math;
    int English;
} RESULT;

void make_output_filename(const char* in_filename, char* out_filename);
FILE* try_to_open_file(const char* fname, const char* mode);
double get_average(const RESULT* r);

int main(int argc, char** argv)
{
    char in_fname[FILENAME_MAX] = { '\0' };
    char out_fname[FILENAME_MAX] = { '\0' };
    FILE* rfp;
    FILE* wfp;

    RESULT result;
    double avg;
    
    if (argc < 2)
    {
        fprintf(stderr, "사용법: %s 입력파일\n", argv[0]);
        exit(1);
    }

    strcpy(in_fname, argv[1]);
    make_output_filename(in_fname, out_fname);

    rfp = try_to_open_file(in_fname, "r");
    wfp = try_to_open_file(out_fname, "w");
    
    // 맨 윗줄은 학생 이름과 과목 이름이 나오므로 생략
    fscanf(rfp, "%*s\t%*s\t%*s\t%*s\n");
    fprintf(wfp, "이름\t평균\n");
    while (!feof(rfp))
    {
        result.Name[0] = '\0';
        fscanf(rfp, "%s\t%d\t%d\t%d\n",
               &result.Name, &result.Korean, &result.Math, &result.English);
        avg = get_average(&result);
        fprintf(wfp, "%s\t%.02lf\n", result.Name, avg);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}

void make_output_filename(const char* in_filename, char* out_filename)
{
    // 확장자는 .txt라고 가정
    int len = strlen(in_filename);
    strncpy(out_filename, in_filename, len - 4);
    strcat(out_filename, "_avg.txt");
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


double get_average(const RESULT* r)
{
    int sum = 0;
    double avg;

    sum += r->Korean;
    sum += r->Math;
    sum += r->English;

    avg = sum / 3.0;
    return avg;
}
