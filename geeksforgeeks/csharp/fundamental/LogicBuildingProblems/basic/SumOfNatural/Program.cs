// See https://aka.ms/new-console-template for more information
using System;
namespace SumOfNatural;

class Program
{
    static void Main(string[] args)
    {
        int n = 5;
        var sol = new Solution();
        var result = sol.findSum2(n);
        Console.WriteLine(result);
    }
    class Solution
    {
        public int findSum(int n)
        {
            int result = 0;
            for(int i = 1; i <= n; i++) result += i;
            return result;
        }

        public int findSum2(int n)
        {
            return n * (n + 1) / 2;
        }
    }

}