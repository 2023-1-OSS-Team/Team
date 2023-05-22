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
            pr("���α׷��� �����մϴ�. �ȳ��� ������.\n\n");
            break;    
        } 
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5)
            if(start == 0)
            {
                pr("\n�ϱ⸦ ���� �ۼ��� �ּ���.\n");
                continue; //add�� �� �� ������ read, update, delete, save, search�Ұ���
            }
        if (menu == 1) 
        {
            if(start != 0)
            {
                pr("\n�̹� �ۼ��� �ϱⰡ �����մϴ�.\n");
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
            pr("������ �����Ͻðڽ��ϱ�?(����: 1, ���: 0): ");
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
            pr("Ȯ���ϰ� ���� ����, ���� �� �Է����ּ���(ex.2014 01): ");
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
            pr("�����ϰ� ���� ����, ��, ���� �� �Է����ּ���(ex.2014 01 05): ");
            sc("%d %d %d", &yy, &mm, &dd);
            pr("������ �����Ͻðڽ��ϱ�?(����: 1, ���: 0)");
            sc("%d", &check);
            getchar();
            if (check == 1)
                excute_check = deleteStoredDiary(yy, mm, dd);
            else if(check == 0)
                continue;
        else
            pr("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
        }  
    }
    free(recommend.book);
    free(today.contents);
    free(last_word.book);
    free(stored.contents);
    return 0;
}
