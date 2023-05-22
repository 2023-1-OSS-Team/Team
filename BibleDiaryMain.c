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
            printf("���α׷��� �����մϴ�. �ȳ��� ������.\n\n");
            break;    
        } 
        if (menu == 2 || menu == 3 || menu == 4 || menu == 5)
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
            pr("������ �����Ͻðڽ��ϱ�?(����: 1, ���: 0): ");
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
            pr("Ȯ���ϰ� ���� ����, ���� �� �Է����ּ���(ex.2014 01): ");
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
            pr("�����ϰ� ���� ����, ���� �� �Է����ּ���(ex.2014 01): ");
            sc("%d %d", &yy, &mm);
            pr("������ �����Ͻðڽ��ϱ�?(����: 1, ���: 0)");
            sc("%d", &check);
            if (check == 1)
                deleteStoredDiary(yy, mm, dd);
            else if(check == 0)
                continue;
            else
                pr("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
        }  
    }
    for(int i = 0; i < 4; i++)
        free(recommend.book[i]);
    free(recommend.word);
    return 0;
}
