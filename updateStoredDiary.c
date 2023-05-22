#include "BibleDiary.h"

int updateStoredDiary(Diary stored, Bible last_word)
{
    int result = loadStoredDiary(&stored, &last_word);

    if (result != 1) {
        printf("\n=> ����� �ϱ⸦ �ҷ����� �� �����߽��ϴ�.\n");
        return -1;
    }

    printf("\n����� �ϱ� ������ �����մϴ�.\n");
    printf("���� ����: %s\n", stored.contents);

    result = updateDiary(&stored);

    if (result != 1) {
        printf("\n=> �ϱ� ���� ������ �����߽��ϴ�.\n");
        return -1;
    }

    printf("\n������ �ϱ� ����: %s\n", stored.contents);

    // Save the modified diary back to storage
    char path[15]; // Replace with appropriate path
    snprintf(path, sizeof(path), "%d/%d/%d.txt", stored.year, stored.mon, stored.day);
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf("\n=> ������ �ϱ⸦ �����ϴ� �� �����߽��ϴ�.\n");
        return -1;
    }
    fprintf(fp, "%s", stored.contents);
    fclose(fp);

    printf("\n������ �ϱ⸦ �����߽��ϴ�.\n");

    return 1;
}
