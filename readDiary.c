#include "BibleDiary.h"

void readDiary(Diary check, Bible word)
{
    if(check.year == -1 || check.mon == -1 || check.day == -1 )
        return;
    pr("\n���� ��¥: %d-%d-%d\n", check.year, check.mon, check.day);
    pr("\n������ ���� ����: %s %d %d\n %s\n", word.book, word.verse, word.chp, word.word);
    pr("\n�ϱ� ����: ");
    puts(check.contents);    
}
