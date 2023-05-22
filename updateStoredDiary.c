#include "BibleDiary.h"

int updateStoredDiary(Diary stored, Bible last_word)
{
    int result = loadStoredDiary(&stored, &last_word);

    if (result != 1) {
        printf("\n=> 저장된 일기를 불러오는 데 실패했습니다.\n");
        return -1;
    }

    printf("\n저장된 일기 내용을 수정합니다.\n");
    printf("이전 내용: %s\n", stored.contents);

    result = updateDiary(&stored);

    if (result != 1) {
        printf("\n=> 일기 내용 수정에 실패했습니다.\n");
        return -1;
    }

    printf("\n수정된 일기 내용: %s\n", stored.contents);

    // Save the modified diary back to storage
    char path[15]; // Replace with appropriate path
    snprintf(path, sizeof(path), "%d/%d/%d.txt", stored.year, stored.mon, stored.day);
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf("\n=> 수정된 일기를 저장하는 데 실패했습니다.\n");
        return -1;
    }
    fprintf(fp, "%s", stored.contents);
    fclose(fp);

    printf("\n수정된 일기를 저장했습니다.\n");

    return 1;
}
