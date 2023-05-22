#include "BibleDiary.h"

int deleteStoredDiary(int yy, int mm, int dd)
{
    char *year, *mon, *day;
    char path[15];
    path[0] = '\0';
    char *wd = getcwd(NULL, 0);
    sprintf(path, "%s%d/%d/%d.txt", PATH, yy, mm, dd);

    if (remove(path) == 0)
        pr("\n=> �ϱⰡ ���������� �����Ǿ����ϴ�.\n");
    else
    {
        pr("\n=> ã���ô� �ϱⰡ �������� �ʽ��ϴ�.\n");
        return 0;
    }
    chdir(wd);
    return 1;
}