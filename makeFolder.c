#include "BibleDiary.h"

int makeFolder(Diary today, char* path)
{   
    //char *wd = getcwd(NULL); 
    path[0] = '\0';
    // today�� year, mon�� string���� ��ȯ�� ������ array�� ���������� path�� ������ array�� �����ϰ� ù index �ʱ�ȭ.
    sprintf(path, "%s%d/%d/", PATH, today.year, today.mon);
    if(mkdir(path) == 0)
    {
        strcat(path, "/");
        return 1;
    }
    else return -1;
}
//���� �� �ȸ�������� �ϳ��ϳ� ����� ������ �غ���.