using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution {

   static void Main(String[] args) {
      //C
      string line = Console.ReadLine().Trim();
      int C       = int.Parse(line);

      for(int n=0; n<C; ++n)
      {
         //L, N    
         int[] arr = GetArrFromLine(Console.ReadLine().Trim());
         int N = arr[0];
         int L = arr[1];
         //l_costs
         int[] arr_costs = GetArrFromLine(Console.ReadLine().Trim());

         for(int i=0; i<N-L+1; ++i)
            for(int j=i+L; j<N+1; ++j)
            {
               
            }


         

      }
   }

   static int[] GetArrFromLine(string line)
   {
      List<int> l = new List<int>();

      string[] words = line.Split(' ');
      foreach(string w in words)
      {
         l.Add(int.Parse(w));   
      }

      return l.ToArray();
   }



}
