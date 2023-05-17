#include "BibleDiary.h"

void saveLedger(Diary today)
{
    FILE *fp;
    char path[20];
    makeFolder(today, path);
    char *wd = getcwd(NULL, 0);
    // 파일 포인터 선언, fopen의 경로를 담을 string variable path 선언하고 makeFolder 함수 불러와서 ./년/월의 디렉토리 형성
    // 파일을 저장하고 다시 원래의 경로로 돌아오기 위하여 
    char dd[10];
    char dd[0] = '\0';
    chdir(path);
    sprintf(dd, "%d", today.day);
    strcat(dd, ".txt");
    fp = fopen(dd, "wt");
    if (today.year == -1 || today.mon == -1 || today.day == -1)
        return;
    fprintf(fp, "%s", today.contents);
    fclose(fp);
    pr("=> 저장이 완료되었습니다.\n");
    chdir(wd);
}
