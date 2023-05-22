#include "BibleDiary.h"

void saveDiary(Diary today, Bible word)
{
    FILE *fp;
    char path[20];
    char make_diary[10];
    char make_diary[0] = '\0';
    makeFolder(today, path);
    char *wd = getcwd(NULL, 0);
    // ���� ������ ����, fopen�� ��θ� ���� string variable path �����ϰ� makeFolder �Լ� �ҷ��ͼ� ./��/���� ���丮 ����
    // ������ �����ϰ� �ٽ� ������ ��η� ���ƿ��� ���Ͽ� 
    chdir(path);
    sprintf(make_diary, "%d.txt", today.day);
    fp = fopen(make_diary, "wt");
    if (today.year == -1 || today.mon == -1 || today.day == -1)
        return;
    fprintf(fp, "%s %d %d %s\n", word.book, word.verse, word.chp, word.word);
    fprintf(fp, "%s", today.contents);
    fclose(fp);
    pr("=> ������ �Ϸ�Ǿ����ϴ�.\n");
    chdir(wd);
} // ���󸻾� ���� // ���๮�� ���� // �ϱ� ���� // load�� ���� �ҷ��;� ��.
