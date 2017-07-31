https://www.hackerrank.com/challenges/time-conversion

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String p[] =s.split(":");
        int x=Integer.parseInt(p[0]);
        if (x<12 && s.endsWith("PM"))
           
        {
            s=s.substring(0,8);
            
            
            x=x+12;
            System.out.println(x+":"+p[1]+":"+p[2].substring(0,2));
            
        }
        else if(x==12 && s.endsWith("PM"))
            {
            System.out.println(s.substring(0,8));
        }
            else if(x==12 && s.endsWith("AM"))
                {
                p[0]="00";
                System.out.println(p[0]+":"+p[1]+":"+p[2].substring(0,2));
            }
        else
            {
            if(x<10)
       
            System.out.println("0"+x+":"+p[1]+":"+p[2].substring(0,2));
            else
                System.out.println(x+":"+p[1]+":"+p[2].substring(0,2));
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}
