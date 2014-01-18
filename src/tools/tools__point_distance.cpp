// ../src/tools/tools__point_distance.cpp --------------------------------------------------- //
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
/// @date 06/2013
//
/// @return The distance between two points onto only one axis.
//
/// @cite
//
template<typename data_type>
inline data_type point_distance(const data_type &a, // x-axis value of the first point.
                                const data_type &b) // x-axis value of the second point.
{
    return module(a, b);
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 06/2013
//
/// @return The distance between two points by means of their set of coordinates, 
///         onto two axis.
//
/// @cite
//
template<typename data_type>
inline data_type point_distance(const data_type &a, // x-axis value of the first point.
                                const data_type &b, // y-axis value of the first point.
                                const data_type &c, // x-axis value of the second point.
                                const data_type &d) // y-axis value of the second point.
{
    return std::sqrt(gsl_pow_2(c - a) + gsl_pow_2(d - b));
};
//
//
//
/// @author Humberto Jr. 
//
/// @date 06/2013
//
/// @return The distance between two points by means of their set of coordinates,
///         onto three axis.
//
/// @cite
//
template<typename data_type>
inline data_type point_distance(const data_type &a, // x-axis value of the first point.
                                const data_type &b, // y-axis value of the first point.
                                const data_type &c, // z-axis value of the first point.
                                const data_type &d, // x-axis value of the second point.
                                const data_type &e, // y-axis value of the second point.
                                const data_type &f) // z-axis value of the second point.
{
    return std::sqrt(gsl_pow_2(d - a) + gsl_pow_2(e - b) + gsl_pow_2(f - c));
};
