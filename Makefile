CC = gcc
CFLAGS =  -W -Wall
TARGET = diary
OBJECTS = BibleDiaryMain.c printForm.o gotoxy.o checkuser.o selectServices.o\
addDiary.o readDiary.o updateDiary.o deleteDiary.o updateStoredDiary.o readStoredDiary.o\
loadStoredDiary.o deleteStoredDiary.o listStoredDiary.o\
makeFolder.o saveDiary.o todayWord.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^
clean : 
	rm *.o diary