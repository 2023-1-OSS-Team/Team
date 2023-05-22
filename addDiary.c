#include "BibleDiary.h"

int addDiary(Diary *today)
{   
    today->contents = (char*)malloc(sizeof(char));
    pr("\n일기 작성을 시작합니다.\n");
    pr("오늘 날짜를 입력해주세요(ex.2023 01 05): ");
    sc("%d %d %d", &today->year, &today->mon, &today->day);
    pr("일기 작성을 시작해주세요\n"); // 자동으로 텍스트 커서가 작성하는 곳으로 넘어가도록 수정할 것.
    while(getchar()!='\n');
    sc("%[^\n]s", today->contents);
    while(getchar()!='\n');
    //today->contents[strlen(today->contents)-1] = '\0';
    pr("\n=> 일기 입력이 완료되었습니다.\n");
    return 1;
}
