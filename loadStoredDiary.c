#include "BibleDiary.h"

int loadStoredDiary(Diary *stored, Bible *last_word)
{
    FILE *fp;
    char path[15];
    char file_name[10];
    char *wd = getcwd(NULL, 0);
    path[0] = '\0';
    file_name[0] = '\0';
    stored->contents = (char *)malloc(sizeof(char));
    last_word->book = (char*)malloc(sizeof(char));

    while(getchar()!='\n');
    pr("�ҷ����� ���� ����, ��, ���� �� �Է����ּ���(ex.2014 01 05): ");
    sc("%d %d %d", &stored->year, &stored->mon, &stored->day);
    while(getchar()!='\n');
    sprintf(path, "%d/%d", stored->year, stored->mon);
    if (access(path, 0) == 0)
        chdir(path);
    else
        printf("\n=> ã���ô� �ϱⰡ �������� �ʽ��ϴ�.\n");

    sprintf(file_name, "%d.txt", stored->day);
    fp = fopen(file_name, "r");
    if (fp == NULL)
        return -1;
    else
    {  
        fscanf(fp, "%s %d %d", last_word->book, &last_word->verse, &last_word->chp);
        if(feof(fp)) return -1;
        fgets(last_word->word, 200, fp);
        fgets(stored->contents, 1000, fp);
    }
    chdir(wd);
    return 1;
} // ������ ���� �ҷ����� ��� �߰�.