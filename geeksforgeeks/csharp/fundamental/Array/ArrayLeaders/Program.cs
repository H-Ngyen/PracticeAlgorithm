// See https://aka.ms/new-console-template for more information
using System;
namespace DSA;

class Program
{
    static void Main(string[] args)
    {
        int[] arr = [10, 4, 2, 4, 1];
        var sol = new Solution();
        var result = sol.leaders(arr);
        foreach (var r in result)
        {
            Console.WriteLine(r);

        }
    }
    class Solution
    {
        public List<int> leaders(int[] arr)
        {
            var result = new List<int>();
            var maxRight = arr[^1];
            for(int i = arr.Length - 1; i >= 0; i--)
            {
                if(arr[i] >= maxRight)
                {
                    maxRight = arr[i];
                    result.Add(maxRight);
                }
            } 
            result.Reverse();
            return result;
        }
    }
}