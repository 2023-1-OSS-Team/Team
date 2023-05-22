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
    handle = _findfirst(path, &fd);  //���� ���� �� ��� ������ ã�´�.
 
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
}