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
## @deftypefn {} {@var{retval} =} TF2D (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Saikou Oumar <bah@debian>
## Created: 2021-10-21

# Transformée de fourier 2D Brutale

function ITF = TF2D (I)
  [nbl, nbc] = size(I);
  
  for u = 1:nbl
    for v = 1:nbc
      
      som = 0;
      
      for x = 1:nbl
        for y = 1:nbc
          som += double(I(x,y)) * exp((-2*i*pi)*(((u-1)*(x-1)/nbl)+((v-1)*(y-1)/nbc)));
        endfor
      endfor
      
      ITF(u,v) = som;
    endfor
  endfor
  
endfunction
