#include "BibleDiary.h"

int loadStoredDiary(Diary *stored, Bible *last_word)
{
    FILE *fp;
    int date[3];
    char path[15], dir[15], day[5];
    char* ptr;
    path[0] = '\0';
    dir[0] = '\0';
    day[0] = '\0';
    strcat(dir, PATH);
    char *wd = getcwd(NULL, 0);

    pr("불러오고 싶은 연도, 월, 일을 띄어서 입력해주세요(ex.2014-01-05): ");
    sc("%s", path);

    for(int i = 0; i < 10; i++)
    {
        ptr = strstr(path, "-");
        if(ptr)
            strncpy(ptr, "/", 1);
    }   
    strncpy(day, path+7, 2);
    strcat(dir, path);
    dir[strlen(dir)-1] = '\0';
    dir[strlen(dir)-2] = '\0';
    dir[strlen(dir)-3] = '\0';

    if (access(dir, 0) == 0)
        chdir(dir);
    else
        printf("\n=> 찾으시는 일기가 존재하지 않습니다.\n");

    strcat(day, ".txt");
    fp = fopen(day, "r");
    if (fp == NULL)
        return;
    else
    {   
        int i = 0;
        ptr = strtok(path, "/");
        date[i] = atoi(ptr);
        while(path != NULL)
        {
            i++;
            ptr = strtok(NULL, "/");
            date[i] = atoi(ptr);
        }
        fscanf(fp, "%s", &stored->contents);
        if(feof(fp)) return;
    }
    chdir(wd);
} // 묵상한 말씀 불러오는 기능 추가.