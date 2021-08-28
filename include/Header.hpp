#pragma once

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void binary_acquisition(int vet[], int dim);
void display(int vet[], int dim);
void copy(int vet1[], int vet2[], int dim);
void Not(int vet[], int dim);
void conversion_unsigned(int vet[], int &decimal, int dim);

void two_complement(int vet[], int &decimal, int dim);
void one_complement(int vet[], int &decimal, int dim);