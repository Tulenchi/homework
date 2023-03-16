using System;

enum AccountType { Checking, Deposit }

class Program
{
    public static void Main()
    {
        AccountType goldAccount = AccountType.Checking;
        AccountType platinumAccount = AccountType.Deposit;

        Console.WriteLine($"goldAccount: {goldAccount}");
        Console.WriteLine($"platinumAccount: {platinumAccount}");
    }
}
