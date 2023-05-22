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

    pr("Ȯ���ϰ� ���� ����, ���� �� �Է����ּ���(ex.2014-01): ");
    sc("%s", path);

    for(int i = 0; i < 10; i++)
    {
        ptr = strstr(path, "-");
        if(ptr)
            strncpy(ptr, "/", 1);
    } 
    strcat(dir, path);  
    handle = _findfirst(dir, &fd);  //���� ���� �� ��� ������ ã�´�.
 
    if (handle == -1)
    {
        printf("\n�ƹ� ���ϵ� �������� �ʽ��ϴ�.\n");
        return;
    }
    int count = 1;
    while (result != -1)
    {
        printf("%d�� ����: %s\n", count, fd.name);
        count++;
        result = _findnext(handle, &fd);
    }
    _findclose(handle);
    return;
}