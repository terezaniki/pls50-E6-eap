//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 2                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************

#include <stdio.h> /* needed for printf and scanf */
#include <math.h> /* needed for sqrt */

#define PI 3.14159265   /* the Pi mathematical constant */

/*function prototypes */
float tetragwno(float);
float parallilogrammo(float,float);
float trigwno(float,float);
float kuklos(float);

int main(void) {

    float num1, num2; /* used for dimensions of shapes */
    char choice; /* the user choice */
    do {
        printf ("\n0. Ejodos\n1. Tetragwno\n2. Parallilogrammo\n"); /* prompt for user choice */
        printf ("3. Orthogonio Trigwno\n4. Kuklos\ndwse epilogi\n");
        scanf(" %c", &choice);   /* read user choice */
        printf("Ekanes tin epilogi: %c\n", choice);

        if (choice == '1') {
            printf("Dwse mikos pleuras\n");
            scanf("%f", &num1);
            printf("H PERIMETROS TOY TETRAGWNOU EINAI: %f\n",tetragwno(num1));
        }
        else
            if (choice == '2') {
                printf("Dwse platos\n");
                scanf("%f", &num1);
                printf("Dwse mikos\n");
                scanf("%f", &num2);
                printf("H PERIMETROS TOY PARALLHLOGRAMOU EINAI: %f\n",parallilogrammo(num1,num2));
             }
             else
                if (choice == '3') {
                    printf("Dwse mikos kathetis pleuras\n");
                    scanf("%f", &num1);
                    printf("Dwse mikos orizontias pleuras\n");
                    scanf("%f", &num2);
                    printf("H PERIMETROS TOY ORTHOGONIOU TRIGONOU EINAI: %f\n",trigwno(num1,num2));
                }
                else
                    if (choice == '4') {
                       printf("Dwse mikos aktinas\n");
                       scanf("%f", &num1);
                       printf("H PERIMETROS TOY KYKLOU EINAI: %f\n",kuklos(num1));
                    }
                    else
                       if (choice != '0')
                       /* if none of the above was chosen, the choice was wrong */
                           printf("Lathos epilogi!! Janadokimase\n");
    } while (choice != '0');  /* repeat until exit choice (0) is given */
    return 0;
}


float tetragwno(float pleura) {
    /* the calculation for perimeter is performed within return */
    return(4 * pleura);
}


float parallilogrammo(float pleura1, float pleura2) {
    /* the calculation for perimeter is performed within return */
    return( 2 * pleura1 + 2 * pleura2);
}

float trigwno(float pleura1, float pleura2) {
    float ypoteinousa; /* local variable */

    /* calculate the third edge, according to Pythagora's theorem */
    ypoteinousa = sqrt( pleura1 * pleura1 + pleura2 * pleura2);
    /* the calculation for perimeter is performed within return */
    return ( pleura1 + pleura2 + ypoteinousa);
}

float kuklos(float aktina) {
    /* the calculation for perimeter is performed within return */
    return(2* PI * aktina);
}
