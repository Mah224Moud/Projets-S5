pkg load image;
clear all;

I = [1 2 1 -1];

# Test Transformée de Fourier 1D Brutale
A = TF1D(I);
B = TF1DR(I);
C = fft(I);


# Test Transformée de Fourier 1D Inverse Brutale
AI = TF1DI(A)
BI = TF1DIR(A)
CI = ifft(A)
