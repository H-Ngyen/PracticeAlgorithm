// See https://aka.ms/new-console-template for more information
using System;
namespace DSA;

class Program
{
    static void Main(string[] args)
    {
        int n = 12;
        var sol = new Solution();
        var result = sol.SumOfDigits(n);
        Console.WriteLine(result);
    }
    class Solution
    {
        public int SumOfDigits(int n)
        {
            int result = 0;
            while (n != 0)
            {
                result += n % 10;
                n /= 10;
            }
            return result;
        }
    }

}