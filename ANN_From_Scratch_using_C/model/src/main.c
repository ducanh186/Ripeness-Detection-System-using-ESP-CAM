#include <stdio.h>
#include "../include/math_functions.h"

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
