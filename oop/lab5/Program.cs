using System;                // Console
using System.IO;             // FileStream, FileReader

class FileDetails
{
    static void Summarize(char[] array)
    {
        int vowel = 0, consonant = 0, line =0;
        foreach(char arr in array)
        {
            if (char.IsLetter(arr))
            {
                if ("AEIOUaeiou".IndexOf(arr) != -1)
                {
                    vowel++;
                    // myCharacter is a vowel
                }
                else
                {
                    consonant++;
                    // myCharacter is not a vowel
                }
            }

            else if (arr == '\n')
                line++;
        }

        Console.WriteLine("Character: {0}", array.Length);
        Console.WriteLine("Vowes: {0}", vowel);
        Console.WriteLine("Consonant: {0}", consonant);
        Console.WriteLine("line: {0}", line);
    }
    static void Main(string [] args)
    {
        Console.WriteLine(args.Length);
        foreach (string arg in args)
        {
            //Console.WriteLine(arg);
            for (int i = 0; i < args.Length; i++)
            {
                Console.WriteLine($"Array[{arg + 1}] =");
                string num = Console.ReadLine();
                args[i] = num;
            }
        }
               
        string fileName = args[0];

		FileStream stream = new FileStream(fileName, FileMode.Open);
        StreamReader reader = new StreamReader(stream); 

        int len = (int)stream.Length;
        Console.WriteLine("Length: {0}", len);

        char[] contents = new char[len];

        for (int i = 0; i < len; i++)
        {
            contents[i] = (char)reader.Read();
        }

        foreach(char arr in contents)
        {
            Console.WriteLine(arr);
        }

        Summarize(contents);
    }
}
