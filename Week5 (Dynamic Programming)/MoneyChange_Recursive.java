import java.lang.reflect.Array;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * Problem Money Change Recursive (Algorithmic Toolbox).
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
        System.out.println("Minimum coins change is: "+recursiveChange(money,coins));
    }

    public static int recursiveChange(int money, int[] coins) {
        if (money == 0) {
            return 0;
        }

        int minCoinsChange = Integer.MAX_VALUE;

        for(int i=0; i<coins.length; i++){
            if(coins[i] <= money) {
                int numCoins = recursiveChange(money - coins[i], coins);
                if (numCoins!=Integer.MAX_VALUE && numCoins + 1 < minCoinsChange) {
                    minCoinsChange = numCoins + 1;
                }
            }
        }
        return minCoinsChange;
    }
}