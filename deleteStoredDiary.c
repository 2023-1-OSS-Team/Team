#include "BibleDiary.h"

int deleteStoredDiary(int yy, int mm, int dd)
{
    char *year, *mon, *day;
    char path[15];
    path[0] = '\0';
    char *wd = getcwd(NULL, 0);
    sprintf(path, "%s%d/%d/%d.txt", PATH, yy, mm, dd);

    if (remove(path) == 0)
        pr("\n=> 일기가 정상적으로 삭제되었습니다.\n");
    else
    {
        pr("\n=> 찾으시는 일기가 존재하지 않습니다.\n");
        return 0;
    }
    chdir(wd);
    return 1;
}