using System;

namespace lab1._2
{
    class Program
    {
        public static void Main()
        {
            int i = 0, j = 0;
            string temp;

            try
            {
                Console.WriteLine("Please, enter first number:");
                temp = Console.ReadLine();
                i = int.Parse(temp);

                Console.WriteLine("Please, enter second number:");
                temp = Console.ReadLine();
                j = int.Parse(temp);

                int k = i / j;
                Console.WriteLine("The result of division {0} by {1} is {2}", i, j, k);
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("You can't divide by {0}", j);
            }
            catch (FormatException)
            {
                Console.WriteLine("You entered not a number");
            }
            catch (OverflowException)
            {
                Console.WriteLine("You entered not an Int32 value");
            }

            Console.ReadKey();

        }
    }
}