#include "BibleDiary.h"

int readStoredDiary(Diary stored, Bible last_word)
{
    pr("\n오늘 날짜: %d-%d-%d\n", stored.year, stored.mon, stored.day);
    pr("\n오늘의 묵상 말씀: %s %d %d\n %s\n", last_word.book[1], last_word.verse, last_word.chp, last_word.word);
    pr("\n일기 내용: %s", stored.contents);

    return 1;
}