#include "BibleDiary.h"

int updateDiary(Diary *today)
{
    pr("\n�����Ͻ� ��¥�� �Է����ּ���(ex.2023 01 05): ");
    sc("%d %d %d", &today->year, &today->mon, &today->day);;
    pr("�ϱ� �ۼ��� �������ּ���\n"); // �ڵ����� �ؽ�Ʈ Ŀ���� �ۼ��ϴ� ������ �Ѿ���� ������ ��.
    
    fgets(today->contents, 2000, stdin);
    today->contents[strlen(today->contents)-1] = '\0';
    pr("\n=> �ϱ� �Է��� �Ϸ�Ǿ����ϴ�.\n");

    int index = strlen(today->contents);
    return 1;
}