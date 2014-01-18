// ../src/tools/tools__incomplete_gamma_function.cpp ---------------------------------------- //
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
/// @date 10/2013
//
/// @return The incomplete gamma function value, 
///         @f[ \int_{b}^{\infty} t^{a - 1} \exp(-t)dt @f]
///         for @f$ b \geq 0.0 @f$. If @f$ b @f$ is out 
///         of range, the function returns zero.
//
/// @cite
//
inline double incomplete_gamma_function(const double &a, 
                                        const double &b)
{
    switch(b >= 0.0)
    {
        case false: return 0.0; break;
        case  true: return gsl_sf_gamma_inc(a, b); break;
    }
};
