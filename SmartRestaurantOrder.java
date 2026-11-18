import java.util.Scanner;

public class SmartRestaurantOrder {

    public static void main(String[] args) {

        // ----- Constants -----
        final double DRINK_PRICE = 15.50;
        final double STUDENT_DISCOUNT = 0.10;
        final double SENIOR_DISCOUNT = 0.05;
        final double TIP_RATE = 0.10;
        final int SENIOR_AGE = 60;

        Scanner input = new Scanner(System.in);

        // ----- Input -----
        System.out.print("Customer's name: ");
        String name = input.nextLine();

        System.out.print("Customer's age: ");
        int age = input.nextInt();

        System.out.print("Price of the meal: $");
        double mealPrice = input.nextDouble();

        System.out.print("Number of drinks ordered: ");
        int drinks = input.nextInt();

        System.out.print("Is the customer a student? (true/false): ");
        boolean isStudent = input.nextBoolean();

        System.out.print("Service rating (1-5): ");
        int rating = input.nextInt();

        // ----- Validate rating -----
        if (rating < 1 || rating > 5) {
            System.out.println("Error: service rating must be between 1 and 5.");
            input.close();
            return;
        }

        // ----- Calculations -----
        double drinksCost = drinks * DRINK_PRICE;
        double subtotal = mealPrice + drinksCost;

        // Only one discount: pick the larger one if both apply
        double discountRate = 0.0;
        if (isStudent && age >= SENIOR_AGE) {
            discountRate = Math.max(STUDENT_DISCOUNT, SENIOR_DISCOUNT);
        } else if (isStudent) {
            discountRate = STUDENT_DISCOUNT;
        } else if (age >= SENIOR_AGE) {
            discountRate = SENIOR_DISCOUNT;
        }
        double discount = subtotal * discountRate;

        double afterDiscount = subtotal - discount;

        // 10% tip for ratings 4 or 5
        double tip = 0.0;
        if (rating >= 4) {
            tip = afterDiscount * TIP_RATE;
        }

        double finalBill = afterDiscount + tip;
        int wholeBill = (int) finalBill; // cast: drops the cents

        // ----- Receipt -----
        System.out.println();
        System.out.println("SMART RESTAURANT");
        System.out.println("Customer: " + name);
        System.out.printf("Meal: $%.2f%n", mealPrice);
        System.out.printf("Drinks: $%.2f%n", drinksCost);
        System.out.printf("Discount: $%.2f%n", discount);
        System.out.printf("Tip: $%.2f%n", tip);
        System.out.printf("Final bill: $%.2f%n", finalBill);
        System.out.println("Whole amount: $" + wholeBill);

        input.close();
    }
}
