#include "BibleDiary.h"

int updateDiary(Diary *today)
{
    pr("�ϱ� �ۼ��� �������ּ���\n"); // �ڵ����� �ؽ�Ʈ Ŀ���� �ۼ��ϴ� ������ �Ѿ���� ������ ��.
    while(getchar()!='\n');
    sc("%[^\n]s", today->contents);
    while(getchar()!='\n');
    pr("\n=> �ϱ� �Է��� �Ϸ�Ǿ����ϴ�.\n");
    return 1;
}