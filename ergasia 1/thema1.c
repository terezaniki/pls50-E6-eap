//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 1                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h> /* needed for printf and scanf */

int main (void) {

    float num1, num2; /* the two numbers entered by the user */
    char op;          /* the operation to be performed */

    printf ("Dwse arithmo praji arithmo\n");  /* prompt for input */
    scanf("%f %c %f", &num1, &op, &num2);     /* read imput */
    switch (op) {                             /* switch according to the operation entered */
        case '+': 	printf("apotelesma = %.2f\n",num1 + num2); /* Addition */
                    break;
        case '-': 	printf("apotelesma = %.2f\n",num1 - num2); /* Ssubstraction */
                    break;
        case '*': 	printf("apotelesma = %.2f\n",num1 * num2); /* Multiplication */
                    break;
        case '/': 	if (num2 == 0)                             /* Division. Check for division by 0 */
                        printf("prospatheia gia diairesi me to miden\n");
                    else
                        printf("apotelesma = %.2f\n",num1 / num2);
                    break;
        default:	printf("lahtos praji %c, janadokimase\n", op);   /* wrong choice */
    }
    return 0;
}


