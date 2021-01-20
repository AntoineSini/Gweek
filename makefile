C		:= -g++
CFLAGS	:= -pedantic-errors -Wall -Wextra
LDFLAGS	:= -L./lib/
INCLUDE	:= -isysteminclude/ -Iinclude/

# SOURCE FOLDERS
SRC_DIR := src
SRC		:= 							\
	$(wildcard src/*/*.cpp) 		\
	$(wildcard src/*/*.c)			\
	$(wildcard src/*.c)				\
	$(wildcard src/*.cpp)			

# BUILD FOLDERS
BUILD	:= build
OBJ_DIR	:= $(BUILD)/obj
APP_DIR	:= $(BUILD)/bin
# YOU CAN CHANGE THE NAME OF THE APP
TARGET	:= Gweek-game.exe

# DO NOT EDIT PAST THIS POINT
OBJECTS	+= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@win-mkdir.bat $(@D)
	$(C) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@win-mkdir.bat $(@D)
	$(C) $(CFLAGS) $(INCLUDE) $(OBJECTS) -o $(APP_DIR)/$(TARGET) $(LDFLAGS) 

build:
	./win-mkdir.bat $(APP_DIR)
	./win-mkdir.bat $(OBJ_DIR)

release: C       += -mwindows
release: all

clean:
	-./win-rmdir.bat $(OBJ_DIR)/*
	-rm $(APP_DIR)/$(TARGET)