#include "BibleDiary.h"

int selectFunction()
{
    int menu;
    printf("\n*** 성경 묵상 일기 작성 ***\n");
    printf("1. 새로운 일기 작성하기\n");
    printf("2. 작성한 일기 확인하기\n");
    printf("3. 작성한 일기 수정하기\n");
    printf("4. 작성한 일기 삭제하기\n");
    printf("5. 저장된 일기 확인하기\n");
    printf("6. 저장된 일기 편집하기\n");
    printf("7. 성경 말슴 검색하기\n");
    printf("8. 오늘의 추천 말씀\n"); // 월간정산 불러올 지, 일간정산 불러올 지 입력 받고 하기.
    printf("0. 일기 종료하기\n\n");
    printf(" >> 원하시는 메뉴를 선택하세요: ");
    scanf("%d", &menu);
    printf("\n");
    return menu;
} // UI는 임시로 이렇게 사용하되 개발 마무리 과정에서 수정할 것.
