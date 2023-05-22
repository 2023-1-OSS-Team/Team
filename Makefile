CC = gcc
TARGET = diary
OBJECTS = BibleDiaryMain.c selectServices.o\
addDiary.o readDiary.o updateDiary.o deleteDiary.o updateStoredDiary.o readStoredDiary.o\
loadStoredDiary.o deleteStoredDiary.o listStoredDiary.o\
makeFolder.o saveDiary.o todayWord.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^
.PHONY: clean
clean : 
	del *.o diary.exe