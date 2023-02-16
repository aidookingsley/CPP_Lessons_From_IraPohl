// Change in dimes and pennies
import java.io.Console;
import tio.*;

class MakeChange {
    public static void main (String[] args) {
        int price, change, dimes, pennies;

        System.out.println("type price (0:100):");
        price = System.in.readInt();
        change = 100 - price;
        dimes = change / 10;
        pennies = change % 10;
        System.out.print("The change is :");
        System.out.print(dimes);
        System.out.print(" dimes ");
        System.out.print(pennies);
        System.out.print(" pennies.\n ");
        
    }
}