INC=libfdr
LIB=libfdr

SRC=soru1.c
SRC2=soru2.c

hepsi:soru1 soru2

soru1:soru1.c
	gcc $(SRC) -o soru1 -I$(INC) -L$(LIB) -lfdr -lm

soru2:soru2.c
	gcc $(SRC2) -o soru2 -I$(INC) -L$(LIB) -lfdr -lm
