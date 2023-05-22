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
    for(int i = 0;  i < 4; i++)
        last_word->book[i] = (char*)malloc(sizeof(char));
    last_word->word = (char*)malloc(sizeof(char));

    pr("불러오고 싶은 연도, 월, 일을 띄어서 입력해주세요(ex.2014 01 05): ");
    sc("%d %d %d", &stored->year, &stored->mon, &stored->day);
    sprintf(path, "%s%d/%d/", PATH, stored->year, stored->mon);
    while(getchar()!='\n');

    if (access(path, 0) == 0)
        chdir(path);
    else
        printf("\n=> 찾으시는 일기가 존재하지 않습니다.\n");

    sprintf(file_name, "%d.txt", stored->day);
    fp = fopen(file_name, "r");
    if (fp == NULL)
        return;
    else
    {  
        fscanf(fp, "%s %d %d %s\n", last_word->book[1], &last_word->verse, &last_word->chp, &last_word->word);
        if(feof(fp)) return;
        fscanf(fp, "%s", stored->contents);
    }
    chdir(wd);
    return 1;
} // 묵상한 말씀 불러오는 기능 추가.