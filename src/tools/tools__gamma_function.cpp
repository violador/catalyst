// ../src/tools/tools__gamma_function.cpp --------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
//
//
//
/// @author Humberto Jr. 
//
/// @date 09/2013
//
/// @return The gamma function value, @f$ \Gamma(a) \equiv (a - 1)! @f$, 
///         for @f$ 0.0 < a \leq 171.0 @f$. If @f$ a @f$ is out of range, 
///         the function returns zero.
//
/// @cite
//
inline double gamma_function(const double &a)
{
    switch(a <= 0.0 or a > GSL_SF_GAMMA_XMAX)
    {
        case false: return gsl_sf_gamma(a); break;
        case  true: return 0.0; break;
    }
};
