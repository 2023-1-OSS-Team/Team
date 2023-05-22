#include "BibleDiary.h"

int selectServices()
{
    int menu;
    printf("\n*** 성경 묵상 일기 작성 ***\n");
    printf("1. 오늘 일기 쓰기\n");
    printf("2. 오늘 일기 보기\n");
    printf("3. 오늘 일기 수정\n");
    printf("4. 오늘 일기 삭제\n");
    printf("5. 오늘 일기 저장\n");
    printf("6. 지난 일기 목록\n");
    printf("7. 지난 일기 보기\n");
    printf("8. 지난 일기 수정\n");
    printf("9. 지난 일기 삭제\n"); // 월간정산 불러올 지, 일간정산 불러올 지 입력 받고 하기.
    printf("0. 일기 종료하기\n\n");
    printf(" >> 원하시는 기능을 선택하세요: ");
    scanf("%d", &menu);
    printf("\n");
    return menu;
} // UI는 임시로 이렇게 사용하되 개발 마무리 과정에서 수정할 것.
