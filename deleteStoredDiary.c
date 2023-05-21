#include "BibleDiary.h"

int deleteStoredDiary(int yy, int mm, int dd)
{
    char *year, *mon, *day;
    char path[15];
    itoa(yy, year, 10);
    itoa(mm, mon, 10);
    itoa(dd, day, 10);
    path[0] = '\0';
    char *wd = getcwd(NULL, 0);
    strcat(path, PATH);
    strcat(path, year);
    strcat(path, "/");
    strcat(path, mon);
    strcat(path, "/");
    strcat(path, day);
    strcat(path, ".txt");

    if (remove(path) == 0)
        printf("\n=> 일기가 정상적으로 삭제되었습니다.\n");
    else
    {
        printf("\n=> 찾으시는 일기가 존재하지 않습니다.\n");
        return 0;
    }
    chdir(wd);
    return 1;
}