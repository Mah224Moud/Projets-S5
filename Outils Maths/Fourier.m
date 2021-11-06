pkg load image;
clear all;

#I = [1 2 1 -1];


# Test Transformée de Fourier 1D Brutale
#A = TF1D(I);
#B = TF1DR(I);
#C = fft(I);


# Test Transformée de Fourier 1D Inverse Brutale
#AI = TF1DI(A)
#BI = TF1DIR(A)
#CI = ifft(A)

########################################################
#I = [100 102 220; 11 221 21; 80 130 222; 112 192 91; 85 24 210; 55 16 110];
#I = I/255
#I = imread("img.jpg");

#I = [0 0 0 0 0 0; 1 1 1 1 1 1; 0 0 0 0 0 0];

I = [0 0 2 1 1 1 5 2 2];

#figure;imshow(I);

A = fft(I)
B = TF1DR(I)

#figure;imshow(A);
#figure;imshow(B);

#C = ifft2(A);
#D = TF2DI(A);
#figure;imshow(C);
#figure;imshow(D);