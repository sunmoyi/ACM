/**
 * Created by sunqilong on 2017/1/25.
 */

import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        BigInteger a[] = new BigInteger[500];
        while(cin.hasNext())
        {
            for(int i = 0; i < 3; i++)
                a[i] = cin.nextBigInteger();
            for(int i = 3; i < 100; i++)
                a[i] = a[i - 1].add(a[i - 2].add(a[i - 3]));
            System.out.println(a[99]);
        }
    }
}
