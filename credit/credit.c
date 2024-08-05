#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for input
    long number = get_long("Number: ");

    // First we need to determine the length of the number
    long tempNumber = number;
    int length = 0;

    while (tempNumber != 0)
    {
        tempNumber /= 10;
        length++;
    }

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // If the number length is valid, we then apply Luhn's algorithm to validate it
    int sum = 0;
    tempNumber = number;

    for (int i = 0; i < length; i++)
    {
        int digit = tempNumber % 10;
        if (i % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int multiple = 2 * digit;
            sum += (multiple / 10) + (multiple % 10); // Add the sum of the digits of the multiple
        }
        tempNumber /= 10;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Now we know that the card number is valid, let's find out what type of card it is
    while (number > 100)
    {
        number /= 10;
    }

    if ((number / 10 == 5) && (0 < number % 10 && number % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (number / 10 == 3 && (number % 10 == 4 || number % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (number / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
