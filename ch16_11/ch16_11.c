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
    puts("�޴�");
    puts("1. �߰�");
    puts("2. Ž��");
    puts("3. ����");
}

int select_menu()
{
    int selected;
    printf("��ȣ�� �Է��Ͻÿ�: ");
    scanf("%d", &selected);

    return selected;
}

int add_book(BOOK library[], int count)
{
    printf("���� �̸�: ");
    gets(library[count].Title);
    fflush(stdin);

    printf("����: ");
    gets(library[count].Author);
    fflush(stdin);

    printf("���ǻ�: ");
    gets(library[count].Publisher);
    fflush(stdin);
}

int list_book(BOOK library[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("------------------------");
        printf("���� �̸�: %s\n", library[i].Title);
        printf("����: %s\n", library[i].Author);
        printf("���ǻ��: %s\n", library[i].Publisher);
    }
    printf("------------------------");

    return 1;
}
