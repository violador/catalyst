//
//
//
inline unsigned int &task_level(unsigned int &task_number)
{
    (task_number >= 1) and (task_number <= total_tasks)? task_number -= 1 : task_number = 0;
    return theory_level[task_number];
};
