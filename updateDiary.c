#include "BibleDiary.h"

int updateDiary(Diary *today)
{
    pr("\n수정하실 날짜를 입력해주세요(ex.2023 01 05): ");
    sc("%d %d %d", &today->year, &today->mon, &today->day);;
    pr("일기 작성을 시작해주세요\n"); // 자동으로 텍스트 커서가 작성하는 곳으로 넘어가도록 수정할 것.
    
    fgets(today->contents, 2000, stdin);
    today->contents[strlen(today->contents)-1] = '\0';
    pr("\n=> 일기 입력이 완료되었습니다.\n");

    int index = strlen(today->contents);
    return 1;
}