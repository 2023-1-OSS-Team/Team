#include "BibleDiary.h"

int updateStoredDiary(Diary stored, Bible last_word)
{
    char path[20], file_name[10];
    int check;
    path[0] = '\0';
    file_name[0] = '\0';
    char *wd = getcwd(NULL, 0);
    int result = loadStoredDiary(&stored, &last_word);
    pr("\n지난 일기 수정을 시작합니다.\n");
    pr("지난 일기 내용: %s\n", stored.contents);
    
    pr("일기 내용을 새로 입력해주세요.\n"); // 자동으로 텍스트 커서가 작성하는 곳으로 넘어가도록 수정할 것.
    sc("%[^\n]s", stored.contents);
    while(getchar()!='\n');
    /*if (result != 1) {
        printf("\n=> 일기 내용 수정에 실패했습니다.\n");
        return -1;
    }*/
    pr("\n수정한 일기 내용: %s\n", stored.contents);
    sprintf(path, "%d/%d", stored.year, stored.mon);
    sprintf(file_name, "%d.txt", stored.day);
    chdir(path);
    pr("\n정말로 수정하시겠습니까?(수정: 1, 취소: 0): ");
    sc("%d", &check);
    getchar();

    if(check == 1){
        FILE *fp = fopen(file_name, "w");
        if (fp == NULL) {
            pr("\n=> 수정된 일기를 저장하는 데 실패했습니다.\n");
            return -1;
        }
        else
        {
        fprintf(fp, "%s %d %d %s", last_word.book, last_word.verse, last_word.chp, last_word.word);
        fprintf(fp, "%s", stored.contents);
        fclose(fp);
        pr("=> 수정된 내용 저장이 완료되었습니다.\n");
        }
    }
    return 1;
}
