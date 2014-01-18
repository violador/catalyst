//
//
//
inline unsigned int count_orbitals(array &atomic_type)
{
    periodic_table data;
    unsigned int i = 0;
    unsigned int sum = 0;
    #pragma omp parallel for private(i) reduction(+:sum) ordered schedule(dynamic)
    for(i = 1; i <= atomic_type.array::size_of_row(); ++i)
    {
        data.periodic_table::init(atomic_type(i));
        #pragma omp atomic
        sum += data.periodic_table::sub_shells();
    }
    return sum;
};
