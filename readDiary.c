#include "BibleDiary.h"

void readDiary(Diary check, Bible word)
{
    pr("\n���� ��¥: %d-%d-%d\n", check.year, check.mon, check.day);
    pr("\n������ ���� ����: %s %d %d\n %s\n", word.book[1], word.verse, word.chp, word.word);
    pr("\n�ϱ� ����: %s", check.contents);
}
