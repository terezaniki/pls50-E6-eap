//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************

#include <stdio.h>
const int div_val =2;  /* declaration of the constant value used with the % and / operator */

int main(void)
{

    int number;                  /* The user input */

    printf("Dwste enan thetiko akeraio arithmo:\n");
    scanf("%d",&number);         /* read input */
    while (number <= 0) {         /* while the user input is invalid, read input */
        printf ("Mi epitrepti timi, janadokimase\n");
        scanf("%d", &number);
    }
    printf("Duadiki anaparastasi apo to ligotero pros to perissotero simantiko bit:\n");
    do {
        number % div_val? putchar('1'):putchar('0'); /* print the remainder of the division by 2 */
        number /= div_val;                           /* shift number to the left by dividing by 2 */
    } while (number > 0);

}


