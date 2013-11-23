//
//
//
inline unsigned int count_orbitals(array &atomic_type)
{
    unsigned int i = 0, sum = 0;
    #pragma omp parallel for private(i) reduction(+:sum) ordered schedule(dynamic)
    for(i = 1; i <= atomic_type.array::size_of_row(); ++i)
    {
        periodic_table get(atomic_type(i));
        #pragma omp atomic
        sum += get.periodic_table::orbitals_number();
    }
    return sum;
};
