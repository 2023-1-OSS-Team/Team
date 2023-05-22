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
            printf("���α׷��� �����մϴ�. �ȳ��� ������.\n\n");
            break;    
        } 
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 8 || menu == 9)
            if (count == 0)
                continue; //add�� �� �� ������ read, update, delete, save, search�Ұ���
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
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", &check);
            if (check == 1)
            {
                if (deleteDiary(&today) == 1)
                {
                    count--;
                }
            }
            printf("\n=> �����Ǿ����ϴ�.\n");
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
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", &check);
            if (check == 1)
            {
                if (deleteStoredDiary(today.year, today.mon, today.day) == 1)
                {
                    count--;
                }
            }
            printf("\n=> �����Ǿ����ϴ�.\n");
        }  
        else 
        {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
        }
    }
    for(int i = 0; i < 4; i++)
        free(recommend.book[i]);
    free(recommend.word);
    return 0;
}
