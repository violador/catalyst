//
//
//
inline unsigned int number_of(unsigned int option)
{
    switch(option)
    {
        case 1: return total_tasks;          break;
        case 2: return check_current_cpus(); break;
       default: return 0;
    }
};