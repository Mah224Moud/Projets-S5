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
## @deftypefn {} {@var{retval} =} TF2DIR (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Saikou Oumar <bah@debian>
## Created: 2021-10-21

# Transformée de fourier 2D Inverse Rapide

function I = TF2DIR (ITF)
  [M,N] = size(ITF);
  
  for u = 1:M
    ILine(u,:) = TF1DIR(ITF(u,:));
  endfor
  
  for v = 1:N
    I(:,v) = TF1DIR(ILine(:,v));
  endfor  
endfunction
