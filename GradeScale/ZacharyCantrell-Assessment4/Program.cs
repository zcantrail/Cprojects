using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ZacharyCantrell_Assessment4
{
    class Program
    {
        static void Main()
        {
            double uInput;
            int counter = 0;
            double sum = 0;
            double average = 0;

            //instructions.
            Console.WriteLine("This program will ask you to begin entering grades.");
            Console.WriteLine("You may enter as many as you like.");
            Console.WriteLine("please enter -3 when you are finished entering grades.");
            Console.WriteLine("Please enter grade score 1 : ( -3 to exit)");
            uInput = Convert.ToInt32(Console.ReadLine());
            sum = sum + uInput;
            ++counter;
            while (uInput != -3 && uInput > 0 && uInput < 100)
            {
                Console.WriteLine("Please enter next grade score: ( -3 to exit)");
                uInput = Convert.ToInt32(Console.ReadLine());
                if (uInput != -3)
                    if (uInput > 0 && uInput < 100)
                    {
                        sum = sum + uInput;
                        ++counter;
                    }
                    else
                        Console.WriteLine(" ");
                else
                    if (uInput == -3)
                    Console.WriteLine(" ");
                else
                    Console.WriteLine("Invalid input!!");
                       
                    
            }
            average = sum / counter;
            Console.WriteLine("the average of the {0} grades is: {1:f2}", counter, average);
            Console.ReadKey();
        }
    }
}

