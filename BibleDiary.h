#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>
#include <windwos.j>
#define PATH "./"
#define pr printf
#define sc scanf

typedef struct
{
    int year, mon, day;
    char* contents;
}Diary;

//Diary today, stored;

typedef struct
{
    char book[6];
    int verse, chp;
    char* word;
}Bible;

// Bible search, recommend;

//시간이 남을 경우 DB 연동해서 id, password 체크하는 기능을 넣어보자.

int checkUser();
//저장된 id, password 비교해서 맞는지 확인하고 return 1, 0
int selectServices();
//기능 선택.
int addDiary(Diary *today);
//새로운 일기를 작성. today에 있는 날짜 변수 사용. return strlen(today.contents) 수정할 때 다 수정하지 않기 위해;
void readDiary(Diary check);
//작성한 일기를 확인.
int updateDiary(Diary *today);
//작성한 일기를 수정. return strlen(today.contents)
int deleteDiary(Diary today);
//작성한 일기 삭제. return은 제대로 됐는지 확인. 1, 0
int updateStoredDiary(Diary *stored);
//저장된 일기 수정. return은 제대로 됐는지 확인. 1, 0
int readStoredDiary(Diary *stored);
//저장된 일기를 불러와서 확인.
int loadStoredDiary(Diary *sotred);
//저장된 일기 불러옴.
int deleteStoredDiary(int yy, int mm, int dd);
//저장된 일기 삭제. 일기 삭제 후 파일 존재 유무 확인하고 파일이 없으면 폴더 삭제. 마지막은 연도 폴더 확인하고 아무것도 없으면 삭제하기. return은 제대로 됐는지 확인. 1, 0
void listStoredDiary(int yy, int mm);
void StoredDiary(Diary *stored);
/*연, 연월 입력 받기 -> 조건에 맞춰서 리스트 보여주기
listStoredDiary
추가로 수행할 기능 여부 입력받기 o,x -> o일 경우 보기, 수정, 삭제 옵션 제시
-> 연도 입력 받았으면 월일, 연월 입력 받았으면 일 입력받아 기능 수행하기
readDiary, deleteStoredDiary, updateStoredDiary*/
void makeFolder(Diary today);
//작성한 일기 저장할 폴더 만듦.
void saveDiary(Diary today);
//작성한 일기 저장.
void todayWord(Bible *recommend);
/*기본적으로 time난수 돌려서 DB에서 랜덤으로 말씀 하나 불러옴.
계속 돌릴 경우 랜덤 난수 사용 하고, 이 말씀으로 하시겠습니까 확인 받고 종료. 종료시 난수 저장.*/
int searchWord();
//함수 안에서 Bible serach 만들고 입력 받아서 보여줌. book, contetns 마지막 개행문자 제거하기.

