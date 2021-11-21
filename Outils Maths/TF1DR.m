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
## @deftypefn {} {@var{retval} =} TF1DR (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Saikou Oumar <bah@debian>
## Created: 2021-10-21

# Transformée de fourier 1D Rapide

function ITFR = TF1DR (I)
  N = length(I);
  for u = 1:N
    ITFR(u) = FourierRapide(u, I);
  endfor
endfunction

function val = FourierRapide(u,I)
  N = length(I);
  if N == 1
    val = I(1);
  else
    val = FourierRapide(u, I(1:2:end)) + exp((-2*i*pi*(u-1)/N)) * FourierRapide(u, I(2:2:end));
  endif
endfunction