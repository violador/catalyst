//
//
//
inline unsigned int number_of(const unsigned int option)
{
    switch(option)
    {
        case option::tasks: return total_tasks; break;
                   default: return 0; break;
    }
};
