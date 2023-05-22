#include "BibleDiary.h"

void printForm()
{
    int i, j = 0;

    for(i = 0; i < 80; i++)
    {
        pr("¢Ã");
        if(i == 0 || i == 79)
        {
            for(j = 0; j > -79; j--)
                pr("\n¢Ã");
        }
    }
}