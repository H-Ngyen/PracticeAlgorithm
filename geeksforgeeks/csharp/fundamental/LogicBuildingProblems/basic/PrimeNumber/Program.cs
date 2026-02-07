// See https://aka.ms/new-console-template for more information
using System;
namespace DSA;

class Program
{
    static void Main(string[] args)
    {
        int n = 25;
        var sol = new Solution();
        var result = sol.isPrime(n);
        Console.WriteLine(result);
    }
    class Solution
    {
        public bool isPrime(int n)
        {
            if(n <= 1) return false;
            for(long i = 2; i * i <= n; i++)
            {
                if(n % i == 0) return false;
            }
            return true;
        }
    }

}