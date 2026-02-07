// See https://aka.ms/new-console-template for more information
using System;
using System.ComponentModel;
namespace DSA;

class Program
{
    static void Main(string[] args)
    {
        int x = 1, y = 8;
        var sol = new Solution();
        var result = sol.isPowerOfAnother(x, y);
        Console.WriteLine(result);
    }
    class Solution
    {
        public bool isPowerOfAnother(int X, int Y)
        {
            if(X == 1) return X == Y;
            int powerX = 1;
            while (powerX < Y)
            {
                powerX *= X;
            }
            return powerX == Y;
        }
    }
}