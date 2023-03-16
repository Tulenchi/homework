using System;

enum AccountType { Checking, Deposit }
class Program
{
    public struct BankAccount
    {
        public long accNo;
        public decimal accBal;
        public AccountType accType;
    } 
    public static void Main()
    {
        BankAccount goldAccount;
        goldAccount.accNo = 1;
        goldAccount.accBal = 2;
        goldAccount.accType = AccountType.Checking;

        Console.WriteLine($"goldAccount.accNo: {goldAccount.accNo}");
        Console.WriteLine($"goldAccount.accBal: {goldAccount.accBal}");
        Console.WriteLine($"goldAccount.accType: {goldAccount.accType}");
    }
}

