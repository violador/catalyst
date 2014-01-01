//
//
//
inline bool check_filename(const std::string &given_filename)
{
    switch(given_filename == "")
    {
        case false: return false; break;
        case  true: return  true; break;
    }
};
