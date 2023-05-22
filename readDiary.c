#include "BibleDiary.h"

void readDiary(Diary check, Bible word)
{
    pr("\n¿À´Ã ³¯Â¥: %d-%d-%d\n", check.year, check.mon, check.day);
    pr("\n¿À´ÃÀÇ ¹¬»ó ¸»¾¸: %s %d %d\n %s\n", word.book[1], word.verse, word.chp, word.word);
    pr("\nÀÏ±â ³»¿ë: %s", check.contents);
}
