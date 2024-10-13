#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INPUT_NODES 2   // Số nơ-ron đầu vào
#define HIDDEN_NODES 2  // Số nơ-ron lớp ẩn
#define OUTPUT_NODES 1  // Số nơ-ron đầu ra
// Hàm kích hoạt Sigmoid
double sigmoid(double x);
// Hàm kích hoạt ReLU
double relu(double x);
// Tính đầu ra của lớp ẩn
double feed_forward(double input[INPUT_NODES], double W_hidden[HIDDEN_NODES][INPUT_NODES], 
                    double b_hidden[HIDDEN_NODES], double W_output[OUTPUT_NODES][HIDDEN_NODES], 
                    double b_output[OUTPUT_NODES]);

#endif