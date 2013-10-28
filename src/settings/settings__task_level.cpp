//
//
//
inline unsigned int &task_level(unsigned int &task_number)
{
    switch((task_number >= 1) and (task_number <= total_tasks))
    {
        case false: task_number  = 0; break;
        case  true: task_number -= 1; break;
    }
    return theory_level[task_number];
};
