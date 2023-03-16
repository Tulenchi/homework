using System;

namespace lab4
{
    class Utils
    {
        public static int Greater(int a, int b)
        {
            if (a > b)
                return a;
            else
                return b;
        }

        public static void Swap (ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        public static bool Factorial (int n, out int answer)
        {
            int i, f = 1;
            bool end = true;
            if (n > 0)
            {
                try
                {
                    for (i = 1; i <= n; i++)
                    {
                        f = f * i;
                    }
                }

                catch (Exception)
                {
                    end = false;
                }
            }
            
            else
                end = false;

            answer = f;

            return end;
        }
        public static int RecursiveFactorial(int n)
        {
            int answer;
            if (n == 1)
                return 1;
            answer = RecursiveFactorial(n - 1) * n;
            return answer;
        }
    }

    public class Test
    { 
        static void Main()
        {
            int x, y, z, greater, f;
            bool end;
            try
            {
                //first
            Console.WriteLine("Please enter number x: ");
            string num = Console.ReadLine();
            x = int.Parse(num);

            Console.WriteLine("Please enter number y: ");
            num = Console.ReadLine();
            y = int.Parse(num);

            greater = Utils.Greater(x, y);

            Console.WriteLine("Largest number: {0}", greater);

                //second
                Console.WriteLine("x: {0}, y: {1}", x, y);
            Utils.Swap(ref x, ref y);
            Console.WriteLine("After swap: x: {0}, y: {1}", x, y);

                //third
            Console.WriteLine("Number for factorial: ");
            num = Console.ReadLine();
            z = int.Parse(num);
            end = Utils.Factorial(z, out f);

            if (end)
                Console.WriteLine("Factorial {0} = {1}", z, f);
            else
                Console.WriteLine("Error");

                //fourth
            Console.WriteLine("Factorial(rec) {0} = {1}", z, Utils.RecursiveFactorial(z));
            }
            catch (FormatException)
            {
                Console.WriteLine("Error");
            }
        }
    }
}