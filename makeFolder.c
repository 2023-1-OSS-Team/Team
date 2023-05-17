#include "BibleDiary.h"

int makeFolder(Diary today, char* path[])
{
        char yy[10], mm[10];
        path[0] = '\0';
        yy[0] = '\0';
        mm[0] = '\0';
        // today의 year, mon을 string으로 변환해 저장할 array와 최종적으로 path를 저장할 array를 선언하고 첫 index 초기화.
        strcat(path, PATH);
        sprintf(yy, "%d", today.year);
        sprintf(mm, "%d", today.mon);
        strcat(path, yy);
        strcat(path, "/");
        strcat(path, mm);
        if(mkdir(path) == 0)
        {
            strcat(path, "/");
            return 1;
        }
        else return -1;
}