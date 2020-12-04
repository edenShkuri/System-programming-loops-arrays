  #include <stdio.h>
  #include "myBank.h"
  int main()
  { 
    char T;
    do{
        printf("\nPlease choose a transaction type:");
        printf("\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        scanf(" %c", &T);
        printf("the T: %c\n", T);
          switch (T)
          {  
            case 'O':
            openAccount();
            break;
            
            case 'B':      
            checkBalance();
            break;
            
            case 'D':
            deposit();
            break;
            
            case 'W':
            withdraw();
            break;
            
            case 'C':
            closeAccount();
            break;
            
            case 'I':
            addInterest();
            break;
            
            case 'P':
            printAccount();
            break;
           
            case 'E':
            closeAccounts();
            break;

            default:
            printf("Invalid transaction type\n");
          }
      }
    while(T!='E');
  return 0;
  }