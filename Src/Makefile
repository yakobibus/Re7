# Makefile du projet Re7
# ----------------------
#

CC = g++
ARGS = -std=c++17

PRG_HOME = /cygdrive/c/Users/Jacques/GitHubRepository/Re7

EXE_DIR = .

# --

CMN_DIR = $(PRG_HOME)/Src/Common
CMN_SRC = $(CMN_DIR)/C
CMN_HDR = $(CMN_DIR)/H

PRG_DIR = $(PRG_HOME)/Src
SRC_DIR = $(PRG_DIR)/C
HDR_DIR = $(PRG_DIR)/H

HDR_LST = $(HDR_DIR)/Re7.h $(CMN_HDR)/MainBase.h $(HDR_DIR)/Partie.h $(CMN_HDR)/UI_distribution_randomizer.h
SRC_LST = $(SRC_DIR)/Re7.c $(CMN_SRC)/MainBase.c $(SRC_DIR)/Partie.c $(CMN_SRC)/UI_distribution_randomizer.c

$(EXE_DIR)/Re7.exe : $(HDR_LST) $(SRC_LST)
	$(CC) $(ARGS) -o $(EXE_DIR)/Re7.exe $(SRC_LST) -I $(HDR_DIR) -I $(CMN_HDR)

clean :
	rm -f $(EXE_DIR)/Re7.exe
