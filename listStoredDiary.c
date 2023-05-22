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
    handle = _findfirst("./*.txt", &fd);  //���� ���� �� ��� ������ ã�´�.
    if (handle == -1)
        return;
    pr("\n%d�� %d���� �ۼ��Ͻ� �ϱ� ���\n\n", yy, mm);
    while (result != -1)
    {   
        ptr = strtok(fd.name, ".");
        pr("%s��\n", ptr);
        result = _findnext(handle, &fd);
    }
    _findclose(handle);
    chdir(wd);
}