# Makefile du projet Re7
# ----------------------
#

CC = g++
ARGS = -std=c++17

PRG_HOME = /cygdrive/c/Users/Jacques/GitHubRepository/Re7

EXE_DIR = .
OBJ_DIR = ./Obj

# --

CMN_DIR = $(PRG_HOME)/Src/Common
CMN_SRC = $(CMN_DIR)/C
CMN_HDR = $(CMN_DIR)/H

PRG_DIR = $(PRG_HOME)/Src
SRC_DIR = $(PRG_DIR)/C
HDR_DIR = $(PRG_DIR)/H

HDR_LST = $(HDR_DIR)/Re7.h $(CMN_HDR)/MainBase.h $(HDR_DIR)/Partie.h $(CMN_HDR)/UI_distribution_randomizer.h $(HDR_DIR)/LeDe.h
SRC_LST = $(SRC_DIR)/Re7.c $(CMN_SRC)/MainBase.c $(SRC_DIR)/Partie.c $(CMN_SRC)/UI_distribution_randomizer.c $(SRC_DIR)/LeDe.c
OBJ_LST = $(OBJ_DIR)/Re7.o $(OBJ_DIR)/MainBase.o $(OBJ_DIR)/Partie.o $(OBJ_DIR)/UI_distribution_randomizer.o $(OBJ_DIR)/LeDe.o


$(EXE_DIR)/Re7.exe : $(OBJ_LST)
	$(CC)  -o $(EXE_DIR)/Re7.exe $(OBJ_LST)

$(OBJ_DIR)/Re7.o : $(SRC_DIR)/Re7.c $(HDR_DIR)/Re7.h
	$(CC) $(ARGS) -c -o $(OBJ_DIR)/Re7.o $(SRC_DIR)/Re7.c -I $(HDR_DIR) -I $(CMN_HDR)

$(OBJ_DIR)/Partie.o : $(SRC_DIR)/Partie.c $(HDR_DIR)/Partie.h
	$(CC) $(ARGS) -c -o $(OBJ_DIR)/Partie.o $(SRC_DIR)/Partie.c -I $(HDR_DIR) -I $(CMN_HDR)

$(OBJ_DIR)/LeDe.o : $(SRC_DIR)/LeDe.c $(HDR_DIR)/LeDe.h
	$(CC) $(ARGS) -c -o $(OBJ_DIR)/LeDe.o $(SRC_DIR)/LeDe.c -I $(HDR_DIR) -I $(CMN_HDR)

$(OBJ_DIR)/UI_distribution_randomizer.o : $(CMN_SRC)/UI_distribution_randomizer.c $(CMN_HDR)/UI_distribution_randomizer.h
	$(CC) $(ARGS) -c -o $(OBJ_DIR)/UI_distribution_randomizer.o $(CMN_SRC)/UI_distribution_randomizer.c -I $(HDR_DIR) -I $(CMN_HDR)

$(OBJ_DIR)/MainBase.o : $(CMN_SRC)/MainBase.c $(CMN_HDR)/MainBase.h
	$(CC) $(ARGS) -c -o $(OBJ_DIR)/MainBase.o $(CMN_SRC)/MainBase.c -I $(HDR_DIR) -I $(CMN_HDR)

clean :
	rm -f $(EXE_DIR)/Re7.exe $(OBJ_DIR)/*.o
