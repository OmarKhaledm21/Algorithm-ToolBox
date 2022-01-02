import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * Problem Majority Element Divide & Conquer (Algorithmic Toolbox).
 *
 * */

public class Main {
    public static void hasMajority(int[] arr,int size){
        int count=1;
        int current_count=1;

        for(int i=1; i<size; i++){
            if(arr[i]==arr[i-1]){
                count++;
            }else{
                if(count>current_count){
                    current_count=count;
                    count=1;
                }
            }
        }
        if(current_count>1){
            System.out.println("1");
        }else{
            System.out.println("0");
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int size=in.nextInt();
        int[] sample=new int[size];
        quickSort(sample,size);
        hasMajority(sample,size);



        in.close();
    }

    static int partitionMiddle(int[] arr,int l,int r,int pivot) {
        while (l <= r) {
            while (arr[l] < pivot) {
                l++;
            }

            while (arr[r] > pivot) {
                r--;
            }


            if (l <= r) {
                int temp = arr[l];
                arr[l]=arr[r];
                arr[r]=temp;
                l++;
                r--;
            }
        }
        return l;
    }

    static void quickSortMiddlePivot(int[] arr,int l,int r) {
        if (l < r) {
            int pivot = arr[ (l+r) / 2 ];

            int pivotInRightPlaceIndex = partitionMiddle(arr,l,r,pivot);

            quickSortMiddlePivot(arr, l, pivotInRightPlaceIndex - 1);
            quickSortMiddlePivot(arr, pivotInRightPlaceIndex, r);
        }
    }

    static void quickSort(int[] arr,int size) {
        quickSortMiddlePivot(arr, 0, size - 1);
    }


}