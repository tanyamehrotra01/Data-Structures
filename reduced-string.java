//https://www.hackerrank.com/challenges/reduced-string

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static void super_reduced_string(String s){
        
        for(int i = 1 ; i < s.length() ; i++)
        {
            if(s.charAt(i) == s.charAt(i-1))
            {
                s = s.substring(0,i-1)+s.substring(i+1);
                i = 0;
            }
        }
        if(s.length() == 0)
            System.out.println("Empty String");
        else
            System.out.println(s);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        super_reduced_string(s);
    }
}
