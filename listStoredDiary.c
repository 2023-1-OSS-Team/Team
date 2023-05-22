#include "BibleDiary.h"

typedef struct _finddata_t SEARCH;

void listStoredDiary(int yy, int mm)
{
    SEARCH fd;
    long handle;
    int result = 1;
    char year[4], mon[2];
    char path[15], dir[15];
    char* ptr;
    path[0] = '\0';
    dir[0] = '\0';
    itoa(yy, year, 10);
    itoa(mm, mon, 10);
    strcat(dir, PATH);
    char *wd = getcwd(NULL, 0);

    pr("확인하고 싶은 연도, 월을 띄어서 입력해주세요(ex.2014-01): ");
    sc("%s", path);

    for(int i = 0; i < 10; i++)
    {
        ptr = strstr(path, "-");
        if(ptr)
            strncpy(ptr, "/", 1);
    } 
    strcat(dir, path);  
    handle = _findfirst(dir, &fd);  //현재 폴더 내 모든 파일을 찾는다.
 
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
    return;
}