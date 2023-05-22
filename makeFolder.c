#include "BibleDiary.h"

void makeFolder(Diary today)
{   
    char folder_year[5], folder_mon[3];
    folder_year[0] = '\0';
    folder_mon[0] = '\0';
    // today의 year, mon을 string으로 변환해 저장할 array와 최종적으로 path를 저장할 array를 선언하고 첫 index 초기화.
    sprintf(folder_year, "%d", today.year);
    sprintf(folder_mon, "%d", today.mon);
    if(mkdir(folder_year) == 0)
    {   
        chdir(folder_year);
        mkdir(folder_mon);
        chdir(folder_mon);
    }
}
//폴더 잘 안만들어지면 하나하나 만드는 식으로 해보기.