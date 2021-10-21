pkg load image;
clear all;

I = [0 1 1 0 1 1 0 1 1 0 1 1 0];

# Test Transformée de Fourier 1D Brutale
A = TF1D(I);
B = fft(I)

# Test Transformée de Fourier 1D Inverse Brutale
C = TF1DI(A);
D = ifft(A);
