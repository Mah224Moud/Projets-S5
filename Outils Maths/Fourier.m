pkg load image;
clear all;

#I = [1 2 1 -1 5 7 1 1];
########################################################
# Test Transformée de Fourier 1D Brutale et rapide
#A = fft(I);
#B = TF1D(I);
#C = TF1DR(I);

# Test Transformée de Fourier 1D Inverse Brutale et rapide
#AI = ifft(A)
#BI = TF1DI(A)
#CI = TF1DIR(A)
########################################################

#I = [1 2 0 1; 1 -5 -2 1; 2 2 0 -1; 1 2 1 1];
I = imread('calimero.jpg');
I = rgb2gray(I);
I = double(I)/255;
imshow(I);
########################################################
# Test Transformée de Fourier 2D Brutale et rapide
A = fft2(I);
figure, imshow(A);
#B = TF2D(I);
#figure, imshow(B);
C = TF2DR(I);
figure, imshow(C);

# Test Transformée de Fourier 2D Inverse Brutale et rapide
#AI = ifft2(A);
#BI = TF2DI(A);
#CI = TF2DIR(A);

