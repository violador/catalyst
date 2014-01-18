// ../src/tools/tools__factorial.cpp -------------------------------------------------------- //
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
/// @return @f$ a! @f$ for @f$ 0.0 < a \leq 170 @f$. If @f$ a @f$ 
///         is out of range, the function returns one.
//
/// @cite
//
inline double factorial(const int &a)
{
    switch(a <= 0 or a > GSL_SF_FACT_NMAX)
    {
        case false: return gsl_sf_fact(a); break;
        case  true: return 1.0; break;
    }
};
