#include "BibleDiary.h"

void saveDiary(Diary today, Bible word)
{
    FILE *fp;
    char path[20];
    char make_diary[10];
    char *wd = getcwd(NULL, 0); 
    make_diary[0] = '\0';
    makeFolder(today);
    // ���� ������ ����, fopen�� ��θ� ���� string variable path �����ϰ� makeFolder �Լ� �ҷ��ͼ� ./��/���� ���丮 ����
    // ������ �����ϰ� �ٽ� ������ ��η� ���ƿ��� ���Ͽ� 
    sprintf(make_diary, "%d.txt", today.day);
    fp = fopen(make_diary, "wt");
    fprintf(fp, "%s %d %d %s", word.book, word.verse, word.chp, word.word);
    fprintf(fp, "%s", today.contents);
    fclose(fp);
    pr("=> ������ �Ϸ�Ǿ����ϴ�.\n");
    chdir(wd);
    pr("���� ��δ�: %s\n", wd);
} // ���󸻾� ���� // ���๮�� ���� // �ϱ� ���� // load�� ���� �ҷ��;� ��.
