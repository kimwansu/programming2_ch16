#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_MAX 80
#define AUTHOR_MAX 80
#define PUBLISHER_MAX 80

#define ADDBOOK 1
#define LISTBOOK 2
#define QUIT 3

typedef struct {
    char Title[TITLE_MAX];
    char Author[AUTHOR_MAX];
    char Publisher[PUBLISHER_MAX];
} BOOK;

void print_menu();
int select_menu();
int add_book(BOOK library[], int count);
int list_book(BOOK library[], int count);

int main()
{
    BOOK library[30];
    int selmenu;
    int count = 0;

    while (1)
    {
        print_menu();
        selmenu = select_menu();
        switch (selmenu)
        {
        case ADDBOOK:
            add_book(library, count);
            break;
        case LISTBOOK:
            count += list_book(library, count);
            break;
        case QUIT:
            exit(0);
            break;
        }
    }

    return 0;
}

void print_menu()
{
    puts("메뉴");
    puts("1. 추가");
    puts("2. 탐색");
    puts("3. 종료");
}

int select_menu()
{
    int selected;
    printf("번호를 입력하시오: ");
    scanf("%d", &selected);

    return selected;
}

int add_book(BOOK library[], int count)
{
    printf("도서 이름: ");
    gets(library[count].Title);
    fflush(stdin);

    printf("저자: ");
    gets(library[count].Author);
    fflush(stdin);

    printf("출판사: ");
    gets(library[count].Publisher);
    fflush(stdin);
}

int list_book(BOOK library[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("------------------------");
        printf("도서 이름: %s\n", library[i].Title);
        printf("저자: %s\n", library[i].Author);
        printf("출판사명: %s\n", library[i].Publisher);
    }
    printf("------------------------");

    return 1;
}
