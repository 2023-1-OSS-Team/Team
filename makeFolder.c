#include "BibleDiary.h"

void makeFolder(Diary today)
{   
    char folder_year[5], folder_mon[3];
    folder_year[0] = '\0';
    folder_mon[0] = '\0';
    // today�� year, mon�� string���� ��ȯ�� ������ array�� ���������� path�� ������ array�� �����ϰ� ù index �ʱ�ȭ.
    sprintf(folder_year, "%d", today.year);
    sprintf(folder_mon, "%d", today.mon);
    if(mkdir(folder_year) == 0)
    {   
        chdir(folder_year);
        mkdir(folder_mon);
        chdir(folder_mon);
    }
}
//���� �� �ȸ�������� �ϳ��ϳ� ����� ������ �غ���.