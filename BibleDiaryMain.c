#include "BibleDiary.h"

int main(void) {
    int menu;
    int count = 0;
    Diary today;
    Bible recommend;
//    todayWord(Bible recommend);
    while (1) 
    {
        int check = 0;
        menu = selectServices();
        if (menu == 0) 
        {
            printf("프로그램을 종료합니다. 안녕히 가세요.\n\n");
            break;    
        } 
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 8 || menu == 9)
            if (count == 0)
                continue; //add가 안 돼 있으면 read, update, delete, save, search불가능
        if (menu == 1) 
        {
            addDiary(&today);
            count += addDiary(&today);
        }          
        else if (menu == 2) 
        {
            readDiary(today, recommend);
        } 
        else if (menu == 3) 
        {
            updateDiary(&today);
        } 
        else if (menu == 4) 
        {
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &check);
            if (check == 1)
            {
                if (deleteDiary(&today) == 1)
                {
                    count--;
                }
            }
            printf("\n=> 삭제되었습니다.\n");
        } 
        else if (menu == 5) 
        {
            saveDiary(today, recommend);
        } 
        else if (menu == 6) 
        {
            listStoredDiary(today.year, today.mon);
        } 
        else if (menu == 7) 
        {
            readStoredDiary(today, recommend);
        } 
        else if (menu == 8) 
        {
            updateStoredDiary(today, recommend);
        } 
        else if (menu == 9) 
        {        
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &check);
            if (check == 1)
            {
                if (deleteStoredDiary(today.year, today.mon, today.day) == 1)
                {
                    count--;
                }
            }
            printf("\n=> 삭제되었습니다.\n");
        }  
        else 
        {
            printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
        }
    }

    return 0;
}
