#include "BibleDiary.h"

int selectServices()
{
    int menu;
    printf("\n*** ���� ���� �ϱ� �ۼ� ***\n");
    printf("1. ���� �ϱ� ����\n");
    printf("2. ���� �ϱ� ����\n");
    printf("3. ���� �ϱ� ����\n");
    printf("4. ���� �ϱ� ����\n");
    printf("5. ���� �ϱ� ����\n");
    printf("6. ���� �ϱ� ����\n");
    printf("7. ���� �ϱ� ����\n");
    printf("8. ���� �ϱ� ����\n"); // �������� �ҷ��� ��, �ϰ����� �ҷ��� �� �Է� �ް� �ϱ�.
    printf("0. �ϱ� �����ϱ�\n\n");
    printf(" >> ���Ͻô� �޴��� �����ϼ���: ");
    scanf("%d", &menu);
    printf("\n");
    return menu;
} // UI�� �ӽ÷� �̷��� ����ϵ� ���� ������ �������� ������ ��.
