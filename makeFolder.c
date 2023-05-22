#include "BibleDiary.h"

int makeFolder(Diary today, char* path[])
{   
    //char *wd = getcwd(NULL); 
    path[0] = '\0';
    // today의 year, mon을 string으로 변환해 저장할 array와 최종적으로 path를 저장할 array를 선언하고 첫 index 초기화.
    sprintf(path, "%s%d/%d/", PATH, today.year, today.mon);
    if(mkdir(path) == 0)
    {
        strcat(path, "/");
        return 1;
    }
    else return -1;
}
//폴더 잘 안만들어지면 하나하나 만드는 식으로 해보기.