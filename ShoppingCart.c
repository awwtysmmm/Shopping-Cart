#include <stdio.h>
#include <string.h> // Include the string.h header for string manipulation functions
int main()
{
int quantity;
float price;
float total;
char currency;
char item[20];
printf("What is the name of the item? ");

fgets(item,sizeof(item),stdin); /* Read the item name from the user input.
It does not require a loop to read the input(a single call to fgets function can grab an entire line of text at once,rather than needing to read character or words one by one).
And it can handle spaces in the item name.*/

item[strlen(item) - 1] = '\0'; // Remove the newline character from the item name
printf("How many would you like to purchase? ");
scanf("%d", &quantity);
printf("What is the price of each item? ");
scanf("%f", &price);
int c;
while ((c=getchar()) != '\n' && c != EOF); // Clear the input buffer to avoid issues with reading the currency symbol

/*The terminal doesn’t need to be told which line to look at because everything you type goes into a single,shared waiting room called the Input Buffer (stdin).
Your code doesn't look at lines of text,it looks at a continuous stream of characters waiting in that room.
Here is exactly how the while loop finds and processes that leftover \n without you explicitly pointing to it:
1.The Waiting Room Concept (stdin)
When the terminal prompts you for the price (Line 18) and you type 5.50 and press Enter,you send five characters into the buffer:
['5', '.', '5', '0', '\n']

Line 19 (scanf) steps into the waiting room.It looks for a float (%f).It takes '5', '.', '5', and '0', converts them to 5.50,and stores it in price.
Crucially,scanf leaves the \n behind.The waiting room is not empty,['\n'] is still sitting right there at the front of the line.

2.How c Gets Its Value Inside the Loop
You are completely right that when you write int c,it holds no specific data yet.However,look closely inside the while condition:

while ((c = getchar()) != '\n' && c != EOF);

The magic happens right here: c = getchar()

   1. getchar() is called first.This function automatically goes to the front of the stdin waiting room and picks up whatever character is next.
      It doesn't need to be told where to look—it always looks at the stdin buffer.
   2. The assignment happens.The character fetched by getchar() (which is the leftover \n) is immediately assigned to your variable c.
   3. The check happens.Now that c holds '\n',the loop checks the condition: is c != '\n'? Since c is equal to '\n',the condition becomes false.
   4. The loop ends.The loop stops immediately,but because getchar() already pulled the \n out of the waiting room to check it,that newline character is now gone.

To Summarize
You don't have to specify which value goes into the loop because getchar() automatically grabs whatever is currently stuck at the very front of the input stream.Since scanf left the \n at the front of the stream,getchar() naturally sucks it in first.*/

printf("What is the symbol of currency you would like to pay with? ");
scanf("%c", &currency);
total = quantity * price;
printf("Item name is: %s\n", item);
printf("Quantity of the selected item: %d\n", quantity);
printf("Price of each item: %.2f\n", price);
printf("You have bought %d %s/s\n", quantity, item);
printf("Your total is: %c%.2f\n", currency, total);
printf("Thanks,for shopping with us!");
return 0;
}
