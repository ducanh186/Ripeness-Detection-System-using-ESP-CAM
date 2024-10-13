#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_NODES 2   // Số nơ-ron đầu vào
#define HIDDEN_NODES 2  // Số nơ-ron lớp ẩn
#define OUTPUT_NODES 1  // Số nơ-ron đầu ra

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

int main() {
    // Dữ liệu đầu vào
    double input[INPUT_NODES] = {1.0, 0.5};

    // Khởi tạo trọng số ngẫu nhiên cho lớp ẩn
    double W_hidden[HIDDEN_NODES][INPUT_NODES] = {
        {0.15, 0.20},
        {0.25, 0.30}
    };

    // Khởi tạo bias ngẫu nhiên cho lớp ẩn
    double b_hidden[HIDDEN_NODES] = {0.35, 0.35};

    // Khởi tạo trọng số ngẫu nhiên cho lớp đầu ra
    double W_output[OUTPUT_NODES][HIDDEN_NODES] = {
        {0.40, 0.45}
    };

    // Khởi tạo bias ngẫu nhiên cho lớp đầu ra
    double b_output[OUTPUT_NODES] = {0.60};

    // Tính toán đầu ra của mạng nơ-ron
    double output = feed_forward(input, W_hidden, b_hidden, W_output, b_output);

    // In ra kết quả đầu ra
    printf("Output of ANN: %.5f\n", output);
    
    return 0;
}
