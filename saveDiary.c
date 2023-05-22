#include "BibleDiary.h"

void saveLedger(Diary today, Bible word)
{
    FILE *fp;
    char path[20];
    char make_diary[10];
    char make_diary[0] = '\0';
    makeFolder(today, path);
    char *wd = getcwd(NULL, 0);
    // 파일 포인터 선언, fopen의 경로를 담을 string variable path 선언하고 makeFolder 함수 불러와서 ./년/월의 디렉토리 형성
    // 파일을 저장하고 다시 원래의 경로로 돌아오기 위하여 
    chdir(path);
    sprintf(make_diary, "%d.txt", today.day);
    fp = fopen(make_diary, "wt");
    if (today.year == -1 || today.mon == -1 || today.day == -1)
        return;
    fprintf(fp, "%s %d %d\n %s\n", word.book[1], word.verse, word.chp, word.word);
    fprintf(fp, "%s", today.contents);
    fclose(fp);
    pr("=> 저장이 완료되었습니다.\n");
    chdir(wd);
} // 묵상말씀 저장 // 개행문자 저장 // 일기 저장 // load할 때도 불러와야 함.
