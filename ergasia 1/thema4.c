//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 4                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h>  /* logw printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h> /* logw exit() */

int main()
{
   FILE* f_in, *f_out;        /* metablites-deiktes se arxeio */
   int bus[53];               /* lewforeio me to polu 53 theseis */
   char license[8];           /* pinakida kykloforias, 7 grammata-arithmoi kai to '\0' */
   int seats;                 /* plithos thesewn */
   int i, choice, count;      /* boithitikes metablites */

   f_in = fopen("bus.txt", "r"); /* Anoigei to arxeio eisodou*/
   if(f_in == NULL) /* se periptwsi problimatos kata to anoigma */
   {
      printf("To arxeio bus.txt de mporese na anagnwstei\n");
      exit(1);      /* ejodos apo to programma */
   }
   fscanf(f_in,"%s %d", license, &seats);
   fclose(f_in);    /* kleisimo arxeiou eisodou */
   printf("%s %d\n", license, seats); /* ektypwsi pinakidas kai plithous thesewn */
   if (seats > 53) {
     printf("megisto plitos thesewn 53\n");
     exit(1);
   }
   /* elegxos elaxistou kai megistou plithous thesewn */
   if (seats < 5 || (seats-5)%4 != 0 ) {
     printf("mi egkyro plithos thesewn\n");
     exit(1);
   }
   for (i=0;i<seats;i++)
     bus[i]=0; /* arxikopoiisi thesewn lewforeiou */

   choice = 1; /* arxiki timi gia eisodo sto loop */
   while (choice != 0) { /* mexri na epilegei termatismos */
      printf("1. emfanish synolikoy plhthous kenwn thesewn kai twn arithmwn  tous\n");
      printf("2. krathsh theshs me sygkekrimeno arithmo\n");
      printf("3. eyresh kai krathsh theshs pou vrisketai se parathyro\n");
      printf("4. akyrwsh krathshs theshs me sygkekrimeno arithmo\n");
      printf("5. anazhthsh gia to an einai krathmenh thesh me sygkekrimeno arithmo\n");
      printf("6. emfanish listas krathmenwn thesewn taksinomhmenhs kata arithmo theshs\n");
      printf("7. emfanish ths pinakidas kykloforias kai tou diagrammatos tou lewforeiou\n");
      printf("8. apothhkefsh ths pinakidas kykloforias kai tou diagrammatos tou lewforeiou se arxeio\n");
      printf("0. termatismos\n");
      scanf("%d", &choice); printf("Epilogi: %d\n",choice);
      switch(choice) {
        case 1:
           count = 0;   /* arxikopoiisi metriti */
           for (i=0;i<seats;i++)
              if (bus[i] == 0) count++; /* an thesi eleutheri, aujise to metriti */
           /* tha mporousame anti na metrame kathe fora tis kenes theseis,
           na kratame se metabliti to plithos twn kenwn thesewn kai na tin
           enimerwnoume gia kathe kratisi / apodesmeusi */
           printf("Plithos kenwn thesewn = %d apo %d\nArithmoi thesewn:\n",count,seats);
           for (i=0;i<seats;i++)
              if (bus[i] == 0)   /* an thesi eleutheri */
                printf("%d ",i+1); /* typwse ton arithmot tis */
           printf("\n");
           break;
        case 2:
           printf("dwse arithmo thesis\n");
           scanf("%d", &i);
           if (i<1 || i>seats) /* elegxos oti arithmos thesis entos oriwn */
              printf("arithmos thesis ektos oriwn\n");
           else if (bus[i-1] == 0) {/* an einai eleutheri */
                  bus[i-1] =1;     /* kratise tin */
                  printf("thesi kratithike\n");
                }
                else
                  printf("thesi idi kateilhmmeni\n");
           break;
        case 3:
           /* stin teleutaia seira den yparxei keno diadromou */

           for (i=0;i<seats-2;i++) /* gia oles ektos apo tin 2 teleutaies theseis*/
              /* an thesi eleutheri kai sto parathuro aristera, i dejia */
              if (bus[i] == 0 && (i %4 == 0 || i % 4 == 3)) {
                 bus[i] = 1; /* kratise tin */
                 break;      /* stamata to loop */
              }
           if (i<seats-2)  /* an brika thesi */
              printf("kratithike i thesi %d\n",i+1);
           else
              /* an de brika thesi kai einai eleutheri i teleutaia */
              if (i == seats -2 && bus[seats-1] == 0) {
                 bus[seats-1] = 1;  /* kratise tin teleutaia */
                 printf("kratithike i thesi %d\n",seats);
              }
              else
                 printf("de brethike eleutheri thesi se parathuro\n");
           break;
        case 4:
           printf("dwse arithmo thesis\n");
           scanf("%d", &i);
           if (i<1 || i>seats)   /* elegxos oti arithmos thesis entos oriwn */
              printf("arithmos thesis ektos oriwn\n");
           else if (bus[i-1] != 0) { /* an thesi kratimeni */
                  bus[i-1] = 0;    /* apodesmeuse tin */
                  printf("thesi apodesmeutike\n");
                }
                else
                  printf("thesi idi eleutheri\n");
           break;
        case 5:
           printf("dwse arithmo thesis\n");
           scanf("%d", &i);
           if (i<1 || i>seats)   /* elegxos oti arithmos thesis entos oriwn */
              printf("arithmos thesis ektos oriwn\n");
           else if (bus[i-1] != 0) /* an thesi kratimeni */
                  printf("thesi kateilimmeni\n");
                else
                  printf("thesi eleutheri\n");
           break;
        case 6:
           printf("kratimenes theseis\n");
           for (i=0;i<seats;i++)
              if (bus[i] != 0) /* an thesi kratimeni */
                 printf("%d ",i+1); /* tupwse tin */
           printf("\n");
           break;
        case 7:
           printf("%s\n",license); /* tupwse tin pinakida */
           for (i=0;i<seats;i++) {
              if (bus[i] == 0) /* an thesi eleutheri */
                 printf("_");  /* tupwse _ */
              else
                 printf("*");  /* alliws * */
              if ( i %4 == 1 && i < seats-4) /* an i thesi exei dejia tis to diadromo */
                 printf(" ");  /* tupwse keno */
              if ( i %4 == 3 && i < seats-4) /* an teleiwse i seira */
                 printf("\n");  /* allaje grammi */
           }
           printf("\n");
           break;
        case 8:
           f_out = fopen("layout.txt", "w"); /* Anoigei to arxeio ejodou*/
           if(f_out == NULL) /* se periptwsi problimatos kata to anoigma */
           {
              printf("To arxeio layout.txt den mporese na anoixtei\n");
              exit(1);
           }
           /* kai sto 7, alla i ektupwseis ginontai sto arxeio */
           fprintf(f_out,"%s\n",license);
           for (i=0;i<seats;i++) {
              if (bus[i] == 0)
                 fprintf(f_out,"_");
              else
                 fprintf(f_out,"*");
              if ( i %4 == 1 && i < seats-4)
                 fprintf(f_out," ");
              if ( i %4 == 3 && i < seats-4)
                 fprintf(f_out,"\n");
           }
           fprintf(f_out,"\n");
           fclose(f_out); /* kleise to arxeio ejodou */
        case 0:  /* min kaneis tipote */
           break;
        default:
           printf("akatallili epilogi\n");
      }
    }
}



