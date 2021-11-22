pkg load image;
clear all;

#I = [1 2 1 -1 5 7 1 1];
#I = ones(1,1024);

########################################################
# Test Transformée de Fourier 1D Brutale et rapide
#A = fft(I);
#tic
#B = TF1D(I);
#toc
#tic
#C = TF1DR(I);
#toc

# Test Transformée de Fourier 1D Inverse Brutale et rapide
#AI = ifft(A)
#BI = TF1DI(A)
#CI = TF1DIR(A)
########################################################

I = [1 2 0 1; 1 -5 -2 1; 2 2 0 -1; 1 2 1 1];
#I = imread('calimero.jpg');
#I = rgb2gray(I);
#I = double(I)/255;
#imshow(I);
########################################################
# Test Transformée de Fourier 2D Brutale et rapide
A = fft2(I);
#figure, imshow(A);

#tic
#B = TF2D(I)
#toc
#figure, imshow(B);

#tic
#C = TF2DR(I)
#toc
#figure, imshow(C);

# Test Transformée de Fourier 2D Inverse Brutale et rapide
AI = ifft2(A)
#figure, imshow(AI);

#tic
BI = TF2DI(A)
#toc
#figure, imshow(BI);

#tic
CI = TF2DIR(A)
#toc
#figure, imshow(CI);
