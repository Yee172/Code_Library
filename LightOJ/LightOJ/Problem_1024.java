import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	static public void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for(int _ = 1; _ <= T; _++)
		{
			int n = cin.nextInt();
			BigInteger ans = BigInteger.ONE;
			for(int i = 0; i < n; i++)
			{
				BigInteger x = cin.nextBigInteger();
				ans = ans.divide(x.gcd(ans)).multiply(x);
			}
			System.out.println("Case " + _ + ": " + ans);
			System.gc();
		}
		cin.close();
	}
}