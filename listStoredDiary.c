#include "BibleDiary.h"

typedef struct _finddata_t SEARCH;

void listStoredDiary(int yy, int mm)
{
    SEARCH fd;
    long handle;
    int result = 1;
    char path[15];
    char* ptr;
    path[0] = '\0';
    char *wd = getcwd(NULL, 0);

    sprintf(path, "%s%d/%d/", PATH, yy, mm);
    handle = _findfirst(path, &fd);  //현재 폴더 내 모든 파일을 찾는다.
 
    if (handle == -1)
    {
        printf("\n아무 파일도 존재하지 않습니다.\n");
        return;
    }
    int count = 1;
    while (result != -1)
    {
        printf("%d번 파일: %s\n", count, fd.name);
        count++;
        result = _findnext(handle, &fd);
    }
    _findclose(handle);
}