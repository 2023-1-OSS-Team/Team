#include "BibleDiary.h"

int readStoredDiary(Diary stored, Bible last_word)
{   
    int result = loadStoredDiary(&stored, &last_word);
    if(result != 1)
        return -1;
    else
    {
        pr("\n���� ��¥: %d-%d-%d\n", stored.year, stored.mon, stored.day);
        pr("\n������ ���� ����: %s %d %d\n %s\n", last_word.book[1], last_word.verse, last_word.chp, last_word.word);
        pr("\n�ϱ� ����: %s", stored.contents);
    }
    return 1;
}