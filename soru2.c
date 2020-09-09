#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "fields.h"



int main(int argc, char **argv)
{
  IS is;
  int i;


  if (argc != 3) {fprintf(stderr, "usage: printwords filename\n"); exit(1); }
 

  is = new_inputstruct(argv[2]);
  if (is == NULL) {
    perror(argv[2]);
    exit(1);
  }
    //regex ve normal degiskenleri olusturuyoruz.
    regex_t regexSTRCPY; 
    regex_t regexSTRCAT;
    regex_t regexSPRINTF;
    regex_t regexFGETS;
    regex_t regexGETS;
    regex_t regexGETPW;
    char *kontrol = "-s";
    char *kontrol2 = "-r";
    int strcpy;
    int strcat;
    int sprintf;
    int fgets;
    int gets;
    int getpw;
	//regex de kontrol yapacagimiz ifadeleri yaziyoruz.
      strcpy = regcomp(&regexSTRCPY,"strcpy(", 0);
      strcat = regcomp(&regexSTRCAT,"strcat(", 0);
      sprintf = regcomp(&regexSPRINTF,"sprintf(",0);
      fgets = regcomp(&regexFGETS,"fgets(",0);
      gets = regcomp(&regexGETS,"gets(",0);
      getpw = regcomp(&regexGETPW,"getpw(",0);

  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) { 
	//her bir kelimeyi regex ifadeleriyle tek tek kontrol ediyoruz.
      strcpy = regexec(&regexSTRCPY,is->fields[i],0,NULL,0);
      strcat = regexec(&regexSTRCAT,is->fields[i],0,NULL,0);
      sprintf = regexec(&regexSPRINTF,is->fields[i],0,NULL,0);
      fgets = regexec(&regexFGETS,is->fields[i],0,NULL,0);
      gets = regexec(&regexGETS,is->fields[i],0,NULL,0);
      getpw = regexec(&regexGETPW,is->fields[i],0,NULL,0);
	//eger aradigimiz ifadelerden birisi varsa if'in icine giriyoruz.
        if(strcpy == 0)
        {
	//girilen argv[1]'e (-r,-s) gore ne yazdiracagimiza karar verip yazdiriyoruz.
          if(strcmp(argv[1],kontrol) == 0)
          {
            printf("Satir %d: strcpy() kullanilmis.\n", is->line);
          }
          else if(strcmp(argv[1],kontrol2) == 0)
          {
            printf("Satir %d: strcpy() kullanilmis, yerine strlcpy() (BSD library) or strncpy() kullanmalisiniz.\n", is->line);
          }
        }

        if(strcat == 0)
        {
          if(strcmp(argv[1],kontrol) == 0)
          {
            printf("Satir %d: strcat() kullanilmis.\n", is->line);
          }
          else if(strcmp(argv[1],kontrol2) == 0)
          {
            printf("Satir %d: strcat() kullanilmis, yerine strlcat() (BSD library) or strncat() kullanmalisiniz.\n", is->line);
          }
        }

        if(sprintf == 0)
        {
          if(strcmp(argv[1],kontrol) == 0)
          {
            printf("Satir %d: sprintf() kullanilmis.\n", is->line);
          }
          else if(strcmp(argv[1],kontrol2) == 0)
          {
            printf("Satir %d: sprintf() kullanilmis, yerine snprintf() kullanmalisiniz.\n", is->line);
          }
        }

        if(fgets == 0)
        {

        }
        else if(gets == 0)
        {
          if(strcmp(argv[1],kontrol) == 0)
          {
            printf("Satir %d: gets() kullanilmis.\n", is->line);
          }
          else if(strcmp(argv[1],kontrol2) == 0)
          {
            printf("Satir %d: gets() kullanilmis, yerine fgets() kullanmalisiniz.\n", is->line);
          }
        }

        if(getpw == 0)
        {
          if(strcmp(argv[1],kontrol) == 0)
          {
            printf("Satir %d: getpw() kullanilmis.\n", is->line);
          }
          else if(strcmp(argv[1],kontrol2) == 0)
          {
            printf("Satir %d: getpw() kullanilmis, yerine getpwuid() kullanmalisiniz.\n", is->line);
          }
        }
      
    }
  }

  jettison_inputstruct(is);
  exit(0);
}
