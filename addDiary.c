#include "BibleDiary.h"

int addDiary(Diary *today)
{   
    today->contents = (char*)malloc(sizeof(char));
    pr("\n�ϱ� �ۼ��� �����մϴ�.\n");
    pr("���� ��¥�� �Է����ּ���(ex.2023 01 05): ");
    sc("%d %d %d", &today->year, &today->mon, &today->day);
    pr("�ϱ� �ۼ��� �������ּ���\n"); // �ڵ����� �ؽ�Ʈ Ŀ���� �ۼ��ϴ� ������ �Ѿ���� ������ ��.
    while(getchar()!='\n');
    sc("%[^\n]s", today->contents);
    while(getchar()!='\n');
    //today->contents[strlen(today->contents)-1] = '\0';
    pr("\n=> �ϱ� �Է��� �Ϸ�Ǿ����ϴ�.\n");
    return 1;
}
