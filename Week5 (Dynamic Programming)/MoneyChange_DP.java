import java.lang.reflect.Array;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * Problem Money Change Dynamic Programming (Algorithmic Toolbox).
 *
 * */

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter amount of money: ");
        int money = scanner.nextInt();
        System.out.println("Enter number of coins: ");
        int coinsNum = scanner.nextInt();
        System.out.println("Enter coins: ");
        int[] coins= new int[coinsNum];
        for(int i=0; i<coinsNum; i++){
            coins[i]=scanner.nextInt();
        }
        System.out.println("Minimum coins change is: "+DPChange(money,coins));
    }

    public static int DPChange(int money, int[] coins){
        int[] dp = new int[money+1];
        dp[0]=0;

        for(int i=1; i<=money; i++){
            dp[i]=Integer.MAX_VALUE;
        }

        for(int i=1; i<=money; i++){
            for(int j=0; j<coins.length; j++){
                if(coins[j]<= i){
                    int res = dp[i-coins[j]];
                    if(res != Integer.MAX_VALUE && res+1 <dp[i]){
                        dp[i] = res+1;
                    }
                }
            }
        }
        if(dp[money]==Integer.MAX_VALUE){
            return -1;
        }

        return dp[money];
    }
}