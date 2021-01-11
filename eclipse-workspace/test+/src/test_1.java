/*
 * Homework2_4
 * Developed by SeongJune Park
 * April-24 2020
 */
import java.util.InputMismatchException;
import java.util.Scanner;

public class test_1 {

   public static void main(String[] args) {
      int [][]arr = new int [4][4];
      Scanner scan = new Scanner(System.in);
      for(int i = 0; i < 3;i++) {
         for(int j = 0;j<3;j++) {
            try {
               System.out.print("Input arr[" + i +"][" + j +"]");
               arr[i][j] = scan.nextInt();
            }
            catch(InputMismatchException e){
               arr[i][j]=0;
               j--;
            }
         }
         System.out.println("");
      }
      for(int i = 0;i<3;i++) {
         for(int j = 0;j < 3;j++) {
            arr[i][3] += arr[i][j];
         }

         
         for(int k = 0;k < 3;k++) {
            arr[3][k] += arr[i][k];
         }
         
         
         
      }
      
      for(int i = 0;i<3;i++) {
         arr[3][3] += arr[3][i];
      }

      for(int i = 0;i<4;i++) {
         for(int j = 0;j<4;j++) {
            System.out.print(arr[i][j] + "\t");
         }
         System.out.println("");
      }
      
   }

}