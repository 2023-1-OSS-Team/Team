#include "BibleDiary.h"

void readDiary(Diary check, Bible today)
{
    pr("\n오늘 날짜: %d-%d-%d\n", check.year, check.mon, check.day);
    pr("\n오늘의 묵상 말씀: %s %d %d\n %s\n", today.book[1], today.verse, today.chp, today.word);
    pr("\n일기 내용: %s", check.contents);
}
