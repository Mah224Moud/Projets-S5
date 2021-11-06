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
## @deftypefn {} {@var{retval} =} TF2DR (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Saikou Oumar <bah@debian>
## Created: 2021-10-21

# Transformée de fourier 2D Rapide

function ITF = TF2DR (I)
  [M,N] = size(I);
  for u = 1:M
    for v = 1:N
      ITF(u,v) = FourierRapide2D(u,v,I);
    endfor
  endfor
endfunction

function val = FourierRapide2D(u, v, I)
  [M,N] = size(I);
  val = 0;
  #[u,v]
  for x = 1:M
    val += exp(-2*i*pi*(u-1)*(x-1)/M) * FourierRapide1D(v,I(x,:));
    #val = FourierRapide1D(v,I(x,:))
  endfor
endfunction

function val = FourierRapide1D(v,I)
  N = length(I);
  #N
  if N == 1
    val = I(1);
  else
    val = FourierRapide1D(v, I(1:2:end)) + exp((-2*i*pi*(v-1)/N)) * FourierRapide1D(v, I(2:2:end));
  #else
    
  endif
endfunction
