using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int n = Convert.ToInt32(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int f = a[0];
        int index = 1;
        int num = 1;
        int ok = 1;
        while (index < n && a[index] == f)
        {
        	num++;
        	index++;
        }
        int now = num;
        for (var i = index; i < n; ++i)
        {
        	if (f == a[i])
        	{
        		now++;
        	}
        	else
        	{
        		if (now != num)
        		{
        			ok = 0;
        			break;
        		}
        		f = 1 - f;
        		now = 1;
        	}
        }
        if (ok == 1 && now == num)
        {
        	Console.WriteLine("YES");
        }
        else
        {
        	Console.WriteLine("NO");
        }  
    }
}
