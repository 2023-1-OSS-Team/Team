#include "BibleDiary.h"

int updateStoredDiary(Diary stored, Bible last_word)
{
    char path[20], file_name[10];
    int check;
    path[0] = '\0';
    file_name[0] = '\0';
    char *wd = getcwd(NULL, 0);
    int result = loadStoredDiary(&stored, &last_word);
    pr("\n���� �ϱ� ������ �����մϴ�.\n");
    pr("���� �ϱ� ����: %s\n", stored.contents);
    
    pr("�ϱ� ������ ���� �Է����ּ���.\n"); // �ڵ����� �ؽ�Ʈ Ŀ���� �ۼ��ϴ� ������ �Ѿ���� ������ ��.
    sc("%[^\n]s", stored.contents);
    while(getchar()!='\n');
    /*if (result != 1) {
        printf("\n=> �ϱ� ���� ������ �����߽��ϴ�.\n");
        return -1;
    }*/
    pr("\n������ �ϱ� ����: %s\n", stored.contents);
    sprintf(path, "%d/%d", stored.year, stored.mon);
    sprintf(file_name, "%d.txt", stored.day);
    chdir(path);
    pr("\n������ �����Ͻðڽ��ϱ�?(����: 1, ���: 0): ");
    sc("%d", &check);
    getchar();

    if(check == 1){
        FILE *fp = fopen(file_name, "w");
        if (fp == NULL) {
            pr("\n=> ������ �ϱ⸦ �����ϴ� �� �����߽��ϴ�.\n");
            return -1;
        }
        else
        {
        fprintf(fp, "%s %d %d %s", last_word.book, last_word.verse, last_word.chp, last_word.word);
        fprintf(fp, "%s", stored.contents);
        fclose(fp);
        pr("=> ������ ���� ������ �Ϸ�Ǿ����ϴ�.\n");
        }
    }
    return 1;
}
