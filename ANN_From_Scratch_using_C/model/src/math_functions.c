#include "../include/math_functions.h" 
// Hàm kích hoạt Sigmoid
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Hàm kích hoạt ReLU
double relu(double x) {
    return (x > 0) ? x : 0;
}

// Hàm tính toán mạng nơ-ron
double feed_forward(double input[INPUT_NODES], double W_hidden[HIDDEN_NODES][INPUT_NODES], 
                    double b_hidden[HIDDEN_NODES], double W_output[OUTPUT_NODES][HIDDEN_NODES], 
                    double b_output[OUTPUT_NODES]) {
    double hidden_output[HIDDEN_NODES];

    // Tính đầu ra của lớp ẩn
    for (int i = 0; i < HIDDEN_NODES; i++) {
        hidden_output[i] = 0;
        for (int j = 0; j < INPUT_NODES; j++) {
            hidden_output[i] += W_hidden[i][j] * input[j];
        }
        hidden_output[i] += b_hidden[i];  // Cộng bias
        hidden_output[i] = relu(hidden_output[i]); // Áp dụng hàm kích hoạt ReLU
    }

    // Tính đầu ra của lớp đầu ra
    double output = 0;
    for (int i = 0; i < OUTPUT_NODES; i++) {
        for (int j = 0; j < HIDDEN_NODES; j++) {
            output += W_output[i][j] * hidden_output[j];
        }
        output += b_output[i];  // Cộng bias
        output = sigmoid(output); // Áp dụng hàm kích hoạt Sigmoid
    }

    return output;
}


