## Copyright (C) 2021 Saikou Oumar
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{ITF} =} TF1D (I)
##
## @seealso{}
## @end deftypefn

## Author: BAH Saikou Oumar
## Author: DIALLO Mamoudou
## Created: 2021-10-21

# Transformée de Fourier 1D Brutale

function ITF = TF1D (I)
  N = length(I);
  for u = 1:N
    somme  = 0;
    for x = 1 :N
      somme += (I(x) * exp((-2 * i * pi * (u-1) * (x-1)) / N));
    endfor
    ITF(u) = somme;
  endfor
endfunction
