#include "BibleDiary.h"

int updateDiary(Diary *today)
{
    pr("일기 작성을 시작해주세요\n"); // 자동으로 텍스트 커서가 작성하는 곳으로 넘어가도록 수정할 것.
    while(getchar()!='\n');
    sc("%[^\n]s", today->contents);
    while(getchar()!='\n');
    pr("\n=> 일기 입력이 완료되었습니다.\n");
    return 1;
}