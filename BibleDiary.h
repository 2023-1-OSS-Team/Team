#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>
#include <errno.h>
#include <Windows.h>
#include <time.h>
#include <dirent.h>

#define PATH "./"
#define pr printf
#define sc scanf
#define press 0x8000
#define LF VK_LEFT
#define RT VK_RIGHT
#define UP VK_UP
#define DW VK_DOWN

typedef struct
{
    int year, mon, day;
    char *contents;
} Diary;

// Diary today, stored;

typedef struct
{
    char *book;
    int verse, chp;
    char word[200];
} Bible;

// Bible search, recommend;

// �ð��� ���� ��� DB �����ؼ� id, password üũ�ϴ� ����� �־��.

void printForm();
void gotoxy(int x, int y);
// ������ ������ ���콺 Ŀ�� �̵�.
int checkUser();
// ����� id, password ���ؼ� �´��� Ȯ���ϰ� return 1, -1
int selectServices();
// ��� ����.
int addDiary(Diary *today);
// ���ο� �ϱ⸦ �ۼ�. today�� �ִ� ��¥ ���� ���. return strlen(today.contents) ������ �� �� �������� �ʱ� ����. time�� ���� ������� �ʴ� ������ ������ �ۼ� �� �� �ϱ⵵ �ۼ��� �� �ְ� �ϱ� ����.
void readDiary(Diary check, Bible word);
// �ۼ��� �ϱ⸦ Ȯ��.
int updateDiary(Diary *today);
// �ۼ��� �ϱ⸦ ����. return strlen(today.contents)
int deleteDiary(Diary *today);
// �ۼ��� �ϱ� ����. return�� ����� �ƴ��� Ȯ��. 1, -1. loadStoredDiary Ȱ��.
int updateStoredDiary(Diary stored, Bible last_word);
// ����� �ϱ� ����. return�� ����� �ƴ��� Ȯ��. 1, -1. loadStoredDiary Ȱ��.
int readStoredDiary(Diary stored, Bible last_word);
// ����� �ϱ⸦ �ҷ��ͼ� Ȯ��.
int loadStoredDiary(Diary *stored, Bible *last_word);
// ����� �ϱ� �ҷ���.
int deleteStoredDiary(int yy, int mm, int dd);
// ����� �ϱ� ����. �ϱ� ���� �� ���� ���� ���� Ȯ���ϰ� ������ ������ ���� ����. �������� ���� ���� Ȯ���ϰ� �ƹ��͵� ������ �����ϱ�. return�� ����� �ƴ��� Ȯ��. 1, 0
void listStoredDiary(int yy, int mm);
/*��, ���� �Է� �ޱ� -> ���ǿ� ���缭 ����Ʈ �����ֱ�
listStoredDiary
�߰��� ������ ��� ���� �Է¹ޱ� o,x -> o�� ��� ����, ����, ���� �ɼ� ����
-> ���� �Է� �޾����� ����, ���� �Է� �޾����� �� �Է¹޾� ��� �����ϱ�
readDiary, deleteStoredDiary, updateStoredDiary*/
void makeFolder(Diary today);
// �ۼ��� �ϱ� ������ ���� ����. 1, -1.
void saveDiary(Diary today, Bible word);
// �ۼ��� �ϱ� ����.
void todayWord(Bible *recommend);
/*�⺻������ time���� ������ DB���� �������� ���� �ϳ� �ҷ���.
��� ���� ��� ���� ���� ��� �ϰ�, �� �������� �Ͻðڽ��ϱ� Ȯ�� �ް� ����. ����� ���� ����.*/