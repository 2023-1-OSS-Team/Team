#include "BibleDiary.h"

int deleteStoredDiary(int yy, int mm, int dd)
{
    char path[15], file_name[10];
    path[0] = '\0';
    file_name[0] = '\0';
    char *wd = getcwd(NULL, 0);
    sprintf(file_name, "%d.txt", dd);
    sprintf(path, "%d/%d", yy, mm);
    chdir(path);
    if (remove(file_name) == 0)
    {
        pr("\n=> 일기가 정상적으로 삭제되었습니다.\n");
        chdir("../");
        sprintf(path, "./%d", mm);
        _rmdir(path);
        chdir("../");
        sprintf(path, "./%d", yy);
        _rmdir(path);
    }  
    else
    {
        pr("\n=> 찾으시는 일기가 존재하지 않습니다.\n");
        return -1;
    }
    chdir(wd);
    return 1;
}