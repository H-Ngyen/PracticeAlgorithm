// See https://aka.ms/new-console-template for more information
using System;
namespace DSA;

class Program
{
    static void Main(string[] args)
    {
        int[] arr = [1, 2, 3, 4,5];
        var sol = new Solution();
        var result = sol.getAlternates(arr);
        foreach (var r in result)
        {
            Console.WriteLine(r);
            
        }
    }
    class Solution
    {
        public List<int> getAlternates(int[] arr)
        {
            List<int> result = new List<int>();
            for(int i = 0; i < arr.Length; i+=2)
            {
                result.Add(arr[i]);
            } 
            return result;
        }
    }
}