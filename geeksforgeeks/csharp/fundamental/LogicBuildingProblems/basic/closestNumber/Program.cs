// See https://aka.ms/new-console-template for more information
using System;
namespace DSA;

class Program
{
    static void Main(string[] args)
    {
        int n = -15, m = 6;
        var sol = new Solution();
        var result = sol.closestNumber(n, m);
        Console.WriteLine(result);
    }
    class Solution
    {
        public int closestNumber(int n, int m)
        {
            int result = 0, min = (int)1e5, start = n - Math.Abs(m), end = n + Math.Abs(m);
            for(int i = start; i <= end; i++)
            {
                if(i % m == 0)
                {
                    int current = Math.Abs(n - i);

                    if(min > current || current == min && Math.Abs(i) > Math.Abs(result))
                    {
                        min = current;
                        result = i;
                    } 
                }
            }
            return result;
        }
    }

}