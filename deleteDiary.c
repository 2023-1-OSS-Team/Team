#include "BibleDiary.h"

int deleteDiary(Diary *today)
{
    today->year = -1;
    today->mon = -1;
    today->year = -1;
    free(today->contents);
    return 1;
}
