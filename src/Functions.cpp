#include "../include/Header.hpp"

void binary_acquisition(int vet[], int dim)
{
    string number;
    bool temp;
    do
    {
        system("cls");
        temp = true;
        cout << "\nInsert the binary digits from right to left => ";
        cin >> number;

        if (dim < number.length())
        {
            temp = false;
        }

        for (int i = 0; i < number.length() || i < dim; i++)
        {
            if (number[i] == '0' || number[i] == '1')
            {
                vet[i] = (int)number[i] - 48;
            }
            else
            {
                temp = false;
                break;
            }
        }
    } while (temp == false);
}

void display(int vet[], int dim)
{
    for (int i = dim - 1; i >= 0; i--)
    {
        cout << vet[i];
    }
}

void copy(int vet1[], int vet2[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        vet1[i] = vet2[i];
    }
}

void Not(int vet[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if (vet[i] == 0)
        {
            vet[i] = 1;
        }
        else
        {
            vet[i] = 0;
        }
    }
}

void conversion_unsigned(int vet[], int &decimal, int dim)
{
    decimal = 0;

    for (int i = 0; i < dim; i++)
    {
        decimal += vet[i] * pow(2, i);
    }
}

void one_complement(int vet[], int &decimal, int dim)
{
    decimal = 0;

    for (int i = 0; i < dim; i++)
    {
        if (vet[dim - 1] == 1)
        {
            if (vet[i] == 0)
            {
                decimal -= pow(2, i);
            }
        }
        else if (vet[dim - 1] == 0)
        {
            decimal += vet[i] * pow(2, i);
        }
    }
}

void two_complement(int vet[], int &decimal, int dim)
{
    int r = 1;
    decimal = 0;

    if (vet[dim - 1] == 1)
    {
        Not(vet, dim);

        for (int i = 0; i < dim; i++)
        {
            if (vet[i] == 0 && r == 0)
            {
                vet[i] = 0;
                r = 0;
            }
            else if (vet[i] == 0 && r == 1 || vet[i] == 1 && r == 0)
            {
                vet[i] = 1;
                r = 0;
            }
            else if (vet[i] == 1 && r == 1)
            {
                vet[i] = 0;
            }

            if (vet[i] == 1)
            {
                decimal -= pow(2, i);
            }
        }
    }
    else
    {
        conversion_unsigned(vet, decimal, dim);
    }
}
