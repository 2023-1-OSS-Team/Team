#include "BibleDiary.h"

int main(void) {
    int menu;
    int count = 0;
    Diary today, stored;
    Bible recommend, last_word;
    int yy, mm, dd;
    todayWord(&recommend);
    while (1) 
    {
        int check = 0;
        menu = selectServices();
        if (menu == 0) 
        {
            printf("프로그램을 종료합니다. 안녕히 가세요.\n\n");
            break;    
        } 
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5)
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
            pr("정말로 삭제하시겠습니까?(삭제: 1, 취소: 0): ");
            sc("%d", &check);
            if (check == 1)
                deleteDiary(&today);
        } 
        else if (menu == 5) 
        {
            saveDiary(today, recommend);
        } 
        else if (menu == 6) 
        {   
            pr("확인하고 싶은 연도, 월을 띄어서 입력해주세요(ex.2014 01): ");
            sc("%d %d", &yy, &mm);
            listStoredDiary(yy, mm);
        } 
        else if (menu == 7) 
        {
            readStoredDiary(stored, last_word);
        } 
        else if (menu == 8) 
        {
            updateStoredDiary(stored, last_word);
        } 
        else if (menu == 9) 
        {   
            pr("삭제하고 싶은 연도, 월을 띄어서 입력해주세요(ex.2014 01): ");
            sc("%d %d", &yy, &mm);
            pr("정말로 삭제하시겠습니까?(삭제: 1, 취소: 0)");
            sc("%d", &check);
            if (check == 1)
                deleteStoredDiary(yy, mm, dd);
            else if(check == 0)
                continue;
            else
                pr("잘못된 입력입니다. 다시 입력해 주세요.\n");
        }  
    }
    for(int i = 0; i < 4; i++)
        free(recommend.book[i]);
    free(recommend.word);
    return 0;
}
