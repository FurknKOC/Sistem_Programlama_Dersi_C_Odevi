#include <stdio.h>
  #include <malloc.h>
  #include <unistd.h>
  #include <alloca.h>

  extern void afunc(void);

  int bss_var;            
  int data_var = 42;      

  int
  main(int argc, char **argv)
  {
      char *p, *b, *nb;



      printf("Data bolumu: baslangic= %p\n", & data_var);

      p = (char *) alloca(32);
      if (p != NULL) {
          printf("Yigin bolumu: baslangic= %p,", p);
          printf("\tBoyut= %ld Byte\n",((p+31)-p)*1024);
      }

      b = sbrk((ptrdiff_t) 32);  
      nb = sbrk((ptrdiff_t) 0);
      printf("Yigit bolumu: baslangic= %p ,", b);
	printf("\tBoyut= %ld Byte\n",(nb-b)*1024);
      
		return 0;
      while (1) {}
  }

  void
  afunc(void)
  {
      static int level = 0;       
      auto int stack_var;        

      if (++level == 3)           
          return;

      afunc();                    
  }
