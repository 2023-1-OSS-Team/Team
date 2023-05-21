#include "BibleDiary.h"

int main(void) {
  int menu;
  Diary today;
  Bible recommend;

  while (1) {
    menu = selectServices();
    switch (menu) {
      case 1:
        addDiary(&today);
        break;
      case 2:
        readDiary(today);
        break;
      case 3:
        updateDiary(&today);
        break;
      case 4:
        deleteDiary(today);
        break;
      case 5:
        saveDiary(today);
        break;
      case 6:
        listStoredDiary(today.year, today.mon);
        break;
      case 7:
        readStoredDiary(&today);
        break;
      case 8:
        updateStoredDiary(&today);
        break;
      case 9:
        deleteStoredDiary(today.year, today.mon, today.day);
        break;
      case 0:
        return 0;
        break;
      default:
        printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
        break;
    }
  }

  return 0;
}
