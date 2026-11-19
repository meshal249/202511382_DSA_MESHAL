import java.util.ArrayList;
import java.util.Scanner;

public class atm {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        final int PIN = 1234;
        final int MAX_ATTEMPTS = 3;
        double balance = 0;
        ArrayList<String> transactions = new ArrayList<>();

       
        int attempts = 0;
        boolean loggedIn = false;

        while (attempts < MAX_ATTEMPTS) {
            System.out.print("Enter PIN: ");
            int enteredPin = input.nextInt();

            if (enteredPin == PIN) {
                loggedIn = true;
                break;
            } else {
                attempts++;
                System.out.println("Wrong PIN. Attempts left: " + (MAX_ATTEMPTS - attempts));
            }
        }

        if (!loggedIn) {
            System.out.println("Too many failed attempts. Card blocked.");
            return;
        }

        
        int choice;
        do {
            System.out.println("\n1. Check Balance");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Transaction History");
            System.out.println("5. Exit");
            System.out.print("Choose: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Balance: " + balance);
                    break;

                
                case 2:
                    System.out.print("Amount to deposit: ");
                    double dep = input.nextDouble();
                    if (dep > 0) {
                        balance += dep;
                        transactions.add("Deposit: " + dep);
                        System.out.println("Deposited successfully.");
                    } else {
                        System.out.println("Invalid amount.");
                    }
                    break;

               
                case 3:
                    System.out.print("Amount to withdraw: ");
                    double wd = input.nextDouble();
                    if (wd > 0 && wd <= balance) {
                        balance -= wd;
                        transactions.add("Withdraw: " + wd);
                        System.out.println("Withdrawal successful.");
                    } else {
                        System.out.println("Error: insufficient balance or invalid amount.");
                    }
                    break;

               
                case 4:
                    if (transactions.isEmpty()) {
                        System.out.println("No transactions yet.");
                    } else {
                        for (String t : transactions) {
                            System.out.println(t);
                        }
                    }
                    break;

                case 5:
                    System.out.println("Goodbye!");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 5);

        input.close();
    }
}