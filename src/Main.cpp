#include "../include/Header.hpp"

// *? ctrl + k + u will uncomment the code | ctrl + k + c comment the code

// *! What is the ones' complement =>
// * The ones' complement of a binary number is the value obtained by inverting al the bits (swapping 0s and 1s).
// * The ones' complement arithmetic is a system in which negative numbers are represented by the inverse of the binary
// * representations of their corresponding positive numbers (look at the image 1° in the README file).
// * For further details: https://en.wikipedia.org/wiki/Ones%27_complement

// *! What is the two' complement =>
// * In two's-complement, negating a number is done by inverting (swapping 0s and 1s) all the bits and then adding
// * one to that result (look at the image 2° in the README file).
// * For further details: https://en.wikipedia.org/wiki/Two%27s_complement

int main()
{
    int choise = 0;
    do
    {
        system("cls");

        int dim;
        do
        {
            cout << "\nEnter the size of binary number to convert => ";
            cin >> dim;
            if (dim <= 0)
            {
                system("cls");
            }

        } while (dim <= 0);

        int binary[dim], ones[dim], two[dim], decimal = 0;
        system("cls");

        binary_acquisition(binary, dim);

        cout << "\nYou inserted => ";
        display(binary, dim);

        conversion_unsigned(binary, decimal, dim);
        cout << "\nThe unsigned converted number is => " << decimal << endl;

        do
        {
            cout << "\nMAKE YOUR CHOISE =>\n"
                 << endl;
            cout << "(1) Ones' Complement" << endl;
            cout << "(2) Two' Complement" << endl;
            cout << "(3) Insert another number" << endl;
            cout << "(4) Exit" << endl;

            cin >> choise;
            system("cls");

            cout << "\nYou inserted => ";
            display(binary, dim);

            conversion_unsigned(binary, decimal, dim);
            cout << "\nThe unsigned converted number is => " << decimal << endl;

            switch (choise)
            {
                
            case 1:
                copy(ones, binary, dim);

                cout << "\nONES' COMPLEMENT";
                one_complement(ones, decimal, dim);
                cout << "\nThe signed converted number is => " << decimal << endl;
                break;

            case 2:
                copy(two, binary, dim);

                cout << "\nTWO' COMPLEMENT";
                two_complement(two, decimal, dim);
                cout << "\nThe signed converted number is => " << decimal << endl;

            case 3:
                break;

            case 4:
                break;

            default:
                cout << "\n! WRONG CHOISE !" << endl;
                break;
            }

        } while (choise != 4 && choise != 3);

    } while (choise == 3);

    return 0;
}
