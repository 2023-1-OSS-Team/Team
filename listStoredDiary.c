#include "BibleDiary.h"

typedef struct _finddata_t SEARCH;

void listStoredDiary(int yy, int mm)
{
    char path[15];
    path[0] = '\0';
    char *wd = getcwd(NULL, 0);
    char *ptr;

    sprintf(path, "%d/%d/", yy, mm);
    chdir(path);
    SEARCH fd;
    long handle;
    int result = 1;
    handle = _findfirst("./*.txt", &fd);  //현재 폴더 내 모든 파일을 찾는다.
    if (handle == -1)
        return;
    pr("\n%d년 %d월에 작성하신 일기 목록\n\n", yy, mm);
    while (result != -1)
    {   
        ptr = strtok(fd.name, ".");
        pr("%s일\n", ptr);
        result = _findnext(handle, &fd);
    }
    _findclose(handle);
    chdir(wd);
}