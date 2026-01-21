#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct
{
    int accNo;
    char name[100];
    char address[150];
    int pin;
    double balance;
} Account;
typedef struct
{
    int accNo;
    char type[50];
    double amount;
    int receiverAcc;
} Transaction;

void createAcc();
void depositMoney();
void WithdrawMoney();
void checkBalance();
void changeDetails();
void listallAcc();
void ViewTrans();
const char *AccountFile = "accounts.dat";
int main()
{
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~>                                                      <~><~><~><~><~>\n");
    printf("<~><~><~><~><~>                Bank Management System                <~><~><~><~><~>\n");
    printf("<~><~><~><~><~>                                                      <~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");

    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~>                                    WELCOME                                   <~>\n");
    printf("<~>                                      TO                                      <~>\n");
    printf("<~>                                     ASST                                     <~>\n");
    printf("<~>                                 Bank Limited                                 <~>\n");
    printf("<~>                              Aftab Nagar Dhaka                               <~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("\nPress any key to continue...\n");
    getch();
    system("cls");
    while (1)
    {
        int choice;

        printf("\n");
        printf("=====================================================\n");
        printf("                  ASST BANK LIMITED                  \n");
        printf("=====================================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Change Account Details\n");
        printf("6. List All Accounts\n");
        printf("7. View Transaction\n");
        printf("8. Exit Program\n");
        printf("-----------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAcc();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            WithdrawMoney();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            changeDetails();
            break;
        case 6:
            listallAcc();
            break;
        case 7:
            ViewTrans();
            break;
        case 8:

            printf("********************************************************************************\n");
            printf("*                                                                              *\n");
            printf("*                       *** THANK YOU FOR VISITING ***                         *\n");
            printf("*                                                                              *\n");
            printf("*                          *** AST BANK LIMITED ***                            *\n");
            printf("*                                                                              *\n");
            printf("********************************************************************************\n");
            printf("*                                                                              *\n");
            printf("*                    We hope to see you again soon!                            *\n");
            printf("*                                                                              *\n");
            printf("********************************************************************************\n");
            return 0;
        default:
            printf("********************************************************************************\n");
            printf("*                                                                              *\n");
            printf("*                          *** INVALID CHOICE ***                              *\n");
            printf("*                                                                              *\n");
            printf("********************************************************************************\n");
            printf("*                                                                              *\n");
            printf("*                   Please select a valid option from the menu.                *\n");
            printf("*                                                                              *\n");
            printf("********************************************************************************\n");
            break;
        }
        printf("--------------------------------------------\n");
    }
    return 0;
}

void createAcc()
{

    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** Create New Account ***                          *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Please fill in the details below:                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");

    Account acc;//object create
    FILE *file = fopen(AccountFile, "ab+");
    if (!file)//!file >file==NULL
    {
        printf("Unable to open file!!!\n");
        return;
    }
    printf("Enter Account No: ");
    scanf("%d", &acc.accNo);
    getchar();

    printf("Enter your name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';

    printf("Enter your address: ");
    fgets(acc.address, sizeof(acc.address), stdin);
    acc.address[strcspn(acc.address, "\n")] = '\0';

    printf("Set 4-digit PIN: ");
    scanf("%d", &acc.pin);

    printf("Initial deposit: ");
    scanf("%lf", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, file);
    fclose(file);

    printf("Account created successfully!\n");
}

void depositMoney()
{
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** Deposit Money ***                               *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Please fill in the details below:                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    FILE *file = fopen(AccountFile, "rb+");
    if (!file)
    {
        printf("Unable to open file!!!\n");
        return;
    }

    int accnum, pin;
    double amount;
    Account acc;
    int found = 0;

    printf("Enter Account No: ");
    scanf("%d", &accnum);
    printf("Enter 4-digit Pin: ");
    scanf("%d", &pin);
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    while (fread(&acc, sizeof(acc), 1, file))
    {
        if (acc.accNo == accnum)
        {
            found = 1;
            if (acc.pin != pin)
            {
                printf("Wrong Pin!! Access denied.\n");
                fclose(file);
                return;
            }

            acc.balance += amount;
            fseek(file, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, file);
            fclose(file);

            Transaction t;//object
            t.accNo = acc.accNo;
            strcpy(t.type, "Deposit");
            t.amount = amount;
            t.receiverAcc = 0;

            FILE *tFile = fopen("transaction.dat", "ab");
            if (tFile)// tfile!=null
            {
                fwrite(&t, sizeof(t), 1, tFile);
                fclose(tFile);
            }

            printf("\nDeposit Successful!!!\n");
            printf("Account No: ");
            printf("%d\n", acc.accNo);
            printf("Deposited Amount: ");
            printf("%.2lf\n", amount);
            printf("New Balance: ");
            printf("%.2lf\n", acc.balance);
            return;
        }
    }

    fclose(file);
    if (!found)
        printf("Account %d not found.\n", accnum);
}

void WithdrawMoney()

{
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** Withdraw Money ***                              *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Please fill in the details below:                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    FILE *file = fopen(AccountFile, "rb+");
    if (!file)
    {
        printf("Unable to open file!!!\n");
        return;
    }

    int accnum, pin;
    double amount;
    Account acc;
    int found = 0;

    printf("Enter Account No: ");
    scanf("%d", &accnum);
    printf("Enter 4-digit Pin: ");
    scanf("%d", &pin);
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    while (fread(&acc, sizeof(acc), 1, file))
    {
        if (acc.accNo == accnum)
        {
            found = 1;
            if (acc.pin != pin)
            {
                printf("Wrong Pin!! Access denied.\n");
                fclose(file);
                return;
            }

            if (amount > acc.balance)
            {
                printf("Insufficient balance!!\n");
                fclose(file);
                return;
            }

            acc.balance -= amount;
            fseek(file, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, file);
            fclose(file);

            Transaction t;
            t.accNo = acc.accNo;
            strcpy(t.type, "Withdraw");
            t.amount = amount;
            t.receiverAcc = 0;

            FILE *tFile = fopen("transaction.dat", "ab");
            if (tFile)
            {
                fwrite(&t, sizeof(t), 1, tFile);
                fclose(tFile);
            }

            printf("\nWithdrawal Successful!!!\n");
            printf("Account No: ");
            printf("%d\n", acc.accNo);
            printf("Withdrawn Amount: ");
            printf("%.2lf\n", amount);
            printf("New Balance: ");
            printf("%.2lf\n", acc.balance);
            return;
        }
    }

    fclose(file);
    if (!found)
        printf("Account %d not found.\n", accnum);
}

void checkBalance()
{
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** Check Balance ***                               *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Please enter your account details:                     *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    FILE *file = fopen(AccountFile, "rb");
    if (!file)
    {
        printf("Unable to open file!!!\n");
        return;
    }

    int accnum, pin;
    Account acc;
    int found = 0;

    printf("Enter Account No: ");
    scanf("%d", &accnum);
    printf("Enter 4-digit Pin: ");
    scanf("%d", &pin);

    while (fread(&acc, sizeof(acc), 1, file))
    {
        if (acc.accNo == accnum)
        {
            found = 1;
            if (acc.pin != pin)
            {
                printf("Wrong Pin!! Access denied.\n");
                fclose(file);
                return;
            }

            printf("\n--- Account Details ---\n");
            printf("Account No: ");
            printf("%d\n", acc.accNo);
            printf("Name      : ");
            printf("%s\n", acc.name);
            printf("Address   : ");
            printf("%s\n", acc.address);
            printf("Balance   : ");
            printf("%.2lf\n", acc.balance);
            fclose(file);
            return;
        }
    }

    fclose(file);
    if (!found)
        printf("Account %d not found.\n", accnum);
}

void changeDetails()
{
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** Change Account Details ***                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Please enter your new account details:                 *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    FILE *file = fopen(AccountFile, "rb+");
    if (!file)
    {
        printf("Unable to open file!!!\n");
        return;
    }

    int accnum, pin;
    Account acc;
    int found = 0;

    printf("Enter Account No: ");
    scanf("%d", &accnum);
    printf("Enter 4-digit Pin: ");
    scanf("%d", &pin);
    getchar();

    while (fread(&acc, sizeof(acc), 1, file))
    {
        if (acc.accNo == accnum)
        {
            found = 1;
            if (acc.pin != pin)
            {
                printf("Wrong Pin!! Access denied.\n");
                fclose(file);
                return;
            }

            printf("\n--- What do you want to change? ---\n");
            printf("1. Name\n");
            printf("2. Address\n");
            printf("3. PIN\n");
            printf("Enter choice: ");
            int choice;
            scanf("%d", &choice);
            getchar();

            switch (choice)
            {
            case 1:
                printf("Enter new name: ");
                fgets(acc.name, sizeof(acc.name), stdin);
                acc.name[strcspn(acc.name, "\n")] = '\0';
                break;
            case 2:
                printf("Enter new address: ");
                fgets(acc.address, sizeof(acc.address), stdin);
                acc.address[strcspn(acc.address, "\n")] = '\0';
                break;
            case 3:
                printf("Enter new 4-digit PIN: ");
                scanf("%d", &acc.pin);
                break;
            default:
                printf("Invalid option!!\n");
                fclose(file);
                return;
            }

            fseek(file, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, file);

            printf("\nDetails updated successfully!!!\n");
            printf("Account No: ");
            printf("%d\n", acc.accNo);
            printf("Name      : ");
            printf("%s\n", acc.name);
            printf("Address   : ");
            printf("%s\n", acc.address);
            printf("Pin       : ");
            printf("%d\n", acc.pin);

            fclose(file);
            return;
        }
    }

    fclose(file);
    if (!found)
        printf("Account %d not found.\n", accnum);
}

void listallAcc()
{
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** All Accounts ***                                *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       List of all accounts in the system:                    *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    FILE *file = fopen(AccountFile, "rb");
    if (file==NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    Account acc;
    int count = 0;
    printf("\n--- List of Accounts ---\n");

    while (fread(&acc, sizeof(acc), 1, file))
    {
        printf("Account No: ");
        printf("%d\n", acc.accNo);
        printf("Name      : ");
        printf("%s\n", acc.name);
        printf("Balance   : ");
        printf("%.2lf\n", acc.balance);
        printf("------------------------\n");
        count++;
    }

    if (count == 0)
        printf("No accounts available.\n");

    fclose(file);
}

void ViewTrans()
{
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                          *** View Transactions ***                           *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Please enter your account details:                     *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    int accnum, pin;
    printf("Enter Account No: ");
    scanf("%d", &accnum);
    printf("Enter 4-digit Pin: ");
    scanf("%d", &pin);

    FILE *file = fopen(AccountFile, "rb");
    if (!file)
    {
        printf("Unable to open account file!\n");
        return;
    }

    Account acc;
    int accFound = 0;
    while (fread(&acc, sizeof(acc), 1, file))
    {
        if (acc.accNo == accnum)
        {
            if (acc.pin != pin)
            {
                printf("Wrong Pin!! Access denied.\n");
                fclose(file);
                return;
            }
            accFound = 1;
            break;
        }
    }
    fclose(file);

    if (!accFound)
    {
        printf("Account %d not found.\n", accnum);
        return;
    }

    FILE *transfile = fopen("transaction.dat", "rb");
    if (!transfile)
    {
        printf("No transactions found!!!\n");
        return;
    }

    Transaction t;
    int transFound = 0;
    printf("\n--- Transactions ---\n");

    while (fread(&t, sizeof(t), 1, transfile))
    {
        if (t.accNo == accnum)
        {
            printf("Transaction Type: ");
            printf("%s\n", t.type);
            printf("Amount          : ");
            printf("%.2lf\n", t.amount);
            printf("------------------------\n");
            transFound = 1;
        }
    }

    if (!transFound)
        printf("No transactions found!!!\n");

    fclose(transfile);
}
