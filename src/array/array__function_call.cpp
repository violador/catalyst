//
//
//
inline double &operator ()(const unsigned int &i) 
{
    return user_1d_array[i - 1];
};
//
//
//
inline void operator ()(const unsigned int &i, const double &value) 
{
    switch(is_const_array)
    {
        case false: user_1d_array[i - 1] = value; break;
        case  true: break;
    }
};
//
//
//
inline double &operator ()(const unsigned int &i, const unsigned int &j) 
{
    return user_2d_array[(i - 1)*sizeof_row + (j - 1)];
};
//
//
//
inline void operator ()(const unsigned int &i, const unsigned int &j, const double &value) 
{
    switch(is_const_array)
    {
        case false: user_2d_array[(i - 1)*sizeof_row + (j - 1)] = value; break;
        case  true: break;
    }
};
//
//
//
inline double &operator ()(const unsigned int &i, const unsigned int &j, const unsigned int &m) 
{
    return user_3d_array[i - 1][j - 1][m - 1];
};
//
//
//
inline void operator ()(const unsigned int &i, 
                        const unsigned int &j, 
                        const unsigned int &m, 
                        const double &value) 
{
    switch(is_const_array)
    {
        case false: user_3d_array[i - 1][j - 1][m - 1] = value; break;
        case  true: break;
    }
};
//
//
//
inline double &operator ()(const unsigned int &i, 
                           const unsigned int &j, 
                           const unsigned int &m, 
                           const unsigned int &n) 
{
    return user_4d_array[i - 1][j - 1][m - 1][n - 1];
};
//
//
//
inline void operator ()(const unsigned int &i, 
                        const unsigned int &j, 
                        const unsigned int &m, 
                        const unsigned int &n, 
                        const double &value) 
{
    switch(is_const_array)
    {
        case false: user_4d_array[i - 1][j - 1][m - 1][n - 1] = value; break;
        case  true: break;
    }
};
