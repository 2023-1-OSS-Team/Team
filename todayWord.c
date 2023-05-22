#include "BibleDiary.h"

void todayWord(Bible *recommend)
{   
    int today_random, line_count = 0;
    char buffer[200];
    FILE *fp;

    for(int i = 0;  i < 4; i++)
        recommend->book[i] = (char*)malloc(sizeof(char));
    recommend->word = (char*)malloc(sizeof(char));

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int base_time = (tm.tm_year + 1900)*1000 + (tm.tm_mon + 1)*100 + tm.tm_mday;
    srand(base_time);
    today_random = rand() % 7715 + 1;

    if((fp = fopen("Bible2.txt", "r")) != NULL)
        {
            while(1)
            {   
                if(line_count = today_random)
                {
                    fscanf(fp, "%s", &recommend->book[0]);
                    if(feof(fp)) return;
                    fscanf(fp, "%s", &recommend->book[1]);
                    fscanf(fp, "%s", &recommend->book[2]);
                    fscanf(fp, "%s", &recommend->book[3]);
                    fscanf(fp, "%d", &recommend->verse);
                    fscanf(fp, "%d", &recommend->chp);
                    fgets(recommend->word, 200, fp);
                    break;
                }
                line_count++;
                fgets(buffer, 200, fp);
            }
            pr("오늘의 성경 말씀: %s %d장 %d절\n\n%s\n", recommend->book[1], recommend->verse, recommend->chp, recommend->word);
        }
    else
        printf("\n성경 파일 읽어오기에 실패하였습니다.\n");
    

    fclose(fp);
}