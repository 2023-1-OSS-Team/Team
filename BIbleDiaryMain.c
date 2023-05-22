#include "BibleDiary.h"

int main(void) {
    int menu, excute_check, start;
    Diary today, stored;
    Bible recommend, last_word;
    int yy, mm, dd;
    todayWord(&recommend);
    int check = 0;

    while (1) 
    {
        menu = selectServices();
        if (menu == 0) 
        {
            pr("프로그램을 종료합니다. 안녕히 가세요.\n\n");
            break;    
        } 
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5)
            if(start == 0)
            {
                pr("\n일기를 먼저 작성해 주세요.\n");
                continue; //add가 안 돼 있으면 read, update, delete, save, search불가능
            }
        if (menu == 1) 
        {
            if(start != 0)
            {
                pr("\n이미 작성된 일기가 존재합니다.\n");
                continue;
            }
            excute_check = addDiary(&today);
            start++;
        }          
        else if (menu == 2) 
        {
            readDiary(today, recommend);
        } 
        else if (menu == 3) 
        {   
            excute_check = updateDiary(&today);
        } 
        else if (menu == 4) 
        {   
            pr("정말로 삭제하시겠습니까?(삭제: 1, 취소: 0): ");
            sc("%d", &check);
            getchar();
            if (check == 1)
            {
                excute_check = deleteDiary(&today);
                start--;
            }
        } 
        else if (menu == 5) 
        {
            saveDiary(today, recommend);
        } 
        else if (menu == 6) 
        {   
            pr("확인하고 싶은 연도, 월을 띄어서 입력해주세요(ex.2014 01): ");
            sc("%d %d", &yy, &mm);
            getchar();
            listStoredDiary(yy, mm);
        } 
        else if (menu == 7) 
        {
            excute_check = readStoredDiary(stored, last_word);
        } 
        else if (menu == 8) 
        {
            excute_check = updateStoredDiary(stored, last_word);
        } 
        else if (menu == 9) 
        {   
            pr("삭제하고 싶은 연도, 월, 일을 띄어서 입력해주세요(ex.2014 01 05): ");
            sc("%d %d %d", &yy, &mm, &dd);
            pr("정말로 삭제하시겠습니까?(삭제: 1, 취소: 0)");
            sc("%d", &check);
            getchar();
            if (check == 1)
                excute_check = deleteStoredDiary(yy, mm, dd);
            else if(check == 0)
                continue;
        else
            pr("잘못된 입력입니다. 다시 입력해 주세요.\n");
        }  
    }
    free(recommend.book);
    free(today.contents);
    free(last_word.book);
    free(stored.contents);
    return 0;
}
