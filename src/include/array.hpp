#if !defined(ARRAY_CLASS)
	#define ARRAY_CLASS
	#include "globals.hpp"
	#include "tools.hpp"
//
//	Checking any previous misuse of macro OMP_STATIC_LOOP_POLICY:
//
	#if defined(OMP_STATIC_LOOP_POLICY)
		#undef OMP_STATIC_LOOP_POLICY
	#endif
//
//	Checking any previous misuse of macro OMP_DYNAMIC_LOOP_POLICY:
//
	#if defined(OMP_DYNAMIC_LOOP_POLICY)
		#undef OMP_DYNAMIC_LOOP_POLICY
	#endif
//
//	Checking any previous misuse of macro INIT_ITER:
//
	#if defined(INIT_ITER)
		#undef INIT_ITER
	#endif
//
//	Checking any previous misuse of macro CURRENT_RANK:
//
	#if defined(CURRENT_RANK)
		#undef CURRENT_RANK
	#endif
//
//	Redefining the macros OMP_STATIC_LOOP_POLICY and OMP_DYNAMIC_LOOP_POLICY:
//
	#if defined(USE_PARALLEL_ARRAY_CLASS)
		#define OMP_STATIC_LOOP "omp for schedule(static) nowait"
		#define OMP_DYNAMIC_LOOP "omp for schedule(dynamic, chunk()) nowait"
		#define OMP_STATIC_LOOP_POLICY _Pragma(OMP_STATIC_LOOP)
		#define OMP_DYNAMIC_LOOP_POLICY _Pragma(OMP_DYNAMIC_LOOP)
	#else
		#define OMP_STATIC_LOOP "omp master"
		#define OMP_DYNAMIC_LOOP "omp master"
		#define OMP_STATIC_LOOP_POLICY _Pragma(OMP_STATIC_LOOP)
		#define OMP_DYNAMIC_LOOP_POLICY _Pragma(OMP_DYNAMIC_LOOP)
	#endif
//
//	Defining the initialization of iterators (based on OMP limitations):
//
	#if defined(USE_PARALLEL_ARRAY_CLASS)
//		For OMP loops:
		#define INIT_ITER(iter, value) unsigned int iter = value
	#else
//		For non-OMP loops and for performance reasons:
		#define INIT_ITER(iter, value) unsigned int iter(value)
	#endif
//
//	Defining the class prototype:
//
	template<typename data_type, unsigned int rank>
	class array
	{
	};
//
//	Defining the rank one specialization:
//
	#define CURRENT_RANK 1
	template<typename data_type>
	class array<data_type, CURRENT_RANK>
	{
		public:
		typedef array<data_type, CURRENT_RANK> array_type;
		#include "array/id.cpp"
		#include "array/set.cpp"
		#include "array/get.cpp"
		#include "array/min.cpp"
		#include "array/max.cpp"
		#include "array/sum.cpp"
		#include "array/rank.cpp"
		#include "array/norm.cpp"
		#include "array/sort.cpp"
		#include "array/clear.cpp"
		#include "array/create.cpp"
		#include "array/resize.cpp"
		#include "array/has_nan.cpp"
		#include "array/is_null.cpp"
		#include "array/addition.cpp"
		#include "array/is_ready.cpp"
		#include "array/set_zero.cpp"
		#include "array/assignment.cpp"
		#include "array/destructor.cpp"
		#include "array/first_rank.cpp"
		#include "array/third_rank.cpp"
		#include "array/left_shift.cpp"
		#include "array/is_positive.cpp"
		#include "array/is_negative.cpp"
		#include "array/subtraction.cpp"
		#include "array/fourth_rank.cpp"
		#include "array/second_rank.cpp"
		#include "array/constructor.cpp"
		#include "array/debug_check.cpp"
		#include "array/function_call.cpp"
		#include "array/data_typename.cpp"
		#include "array/build_randomly.cpp"
		#include "array/multiplication.cpp"
		private:
		#include "array/offset.cpp"
		#include "array/init_as.cpp"
		#include "array/data_end.cpp"
		#include "array/init_data.cpp"
		#include "array/copy_ranks.cpp"
		#include "array/data_length.cpp"
		#include "array/delete_data.cpp"
		#include "array/clear_internals.cpp"
		#include "array/copy_data_members.cpp"
		#include "array/reset_data_members.cpp"
//
///		The pointer pointing the beginning of the array data.
		data_type *data;
//
///		The length of the first rank.
		unsigned int rank1;
	};
	#undef CURRENT_RANK
//
//	Defining the rank two specialization:
//
	#define CURRENT_RANK 2
	template<typename data_type>
	class array<data_type, CURRENT_RANK>
	{
		public:
		typedef array<data_type, CURRENT_RANK> array_type;
		#include "array/id.cpp"
		#include "array/set.cpp"
		#include "array/get.cpp"
		#include "array/min.cpp"
		#include "array/max.cpp"
		#include "array/sum.cpp"
		#include "array/rank.cpp"
		#include "array/sort.cpp"
		#include "array/write.cpp"
		#include "array/clear.cpp"
		#include "array/trace.cpp"
		#include "array/create.cpp"
		#include "array/resize.cpp"
		#include "array/has_nan.cpp"
		#include "array/is_null.cpp"
		#include "array/set_zero.cpp"
		#include "array/addition.cpp"
		#include "array/is_ready.cpp"
		#include "array/transpose.cpp"
		#include "array/is_square.cpp"
		#include "array/assignment.cpp"
		#include "array/destructor.cpp"
		#include "array/first_rank.cpp"
		#include "array/third_rank.cpp"
		#include "array/left_shift.cpp"
		#include "array/is_positive.cpp"
		#include "array/is_negative.cpp"
		#include "array/subtraction.cpp"
		#include "array/fourth_rank.cpp"
		#include "array/second_rank.cpp"
		#include "array/constructor.cpp"
		#include "array/debug_check.cpp"
		#include "array/set_diagonal.cpp"
		#include "array/function_call.cpp"
		#include "array/data_typename.cpp"
		#include "array/build_randomly.cpp"
		#include "array/multiplication.cpp"
		#include "array/set_anti_diagonal.cpp"
		#include "array/build_identity_form.cpp"
		private:
		#include "array/offset.cpp"
		#include "array/init_as.cpp"
		#include "array/data_end.cpp"
		#include "array/init_data.cpp"
		#include "array/copy_ranks.cpp"
		#include "array/data_length.cpp"
		#include "array/delete_data.cpp"
		#include "array/clear_internals.cpp"
		#include "array/copy_data_members.cpp"
		#include "array/reset_data_members.cpp"
//
///		The pointer pointing the beginning of the array data.
		data_type *data;
//
///		The length of the first rank.
		unsigned int rank1;
//
///		The length of the second rank.
		unsigned int rank2;
	};
	#undef CURRENT_RANK
//
//	Defining the rank three specialization:
//
	#define CURRENT_RANK 3
	template<typename data_type>
	class array<data_type, CURRENT_RANK>
	{
		public:
		typedef array<data_type, CURRENT_RANK> array_type;
		#include "array/id.cpp"
		#include "array/set.cpp"
		#include "array/get.cpp"
		#include "array/min.cpp"
		#include "array/max.cpp"
		#include "array/sum.cpp"
		#include "array/rank.cpp"
		#include "array/sort.cpp"
		#include "array/clear.cpp"
		#include "array/create.cpp"
		#include "array/resize.cpp"
		#include "array/has_nan.cpp"
		#include "array/is_null.cpp"
		#include "array/set_zero.cpp"
		#include "array/addition.cpp"
		#include "array/is_ready.cpp"
		#include "array/assignment.cpp"
		#include "array/destructor.cpp"
		#include "array/first_rank.cpp"
		#include "array/third_rank.cpp"
		#include "array/left_shift.cpp"
		#include "array/is_positive.cpp"
		#include "array/is_negative.cpp"
		#include "array/subtraction.cpp"
		#include "array/fourth_rank.cpp"
		#include "array/second_rank.cpp"
		#include "array/constructor.cpp"
		#include "array/debug_check.cpp"
		#include "array/function_call.cpp"
		#include "array/data_typename.cpp"
		#include "array/build_randomly.cpp"
		#include "array/multiplication.cpp"
		private:
		#include "array/offset.cpp"
		#include "array/init_as.cpp"
		#include "array/data_end.cpp"
		#include "array/init_data.cpp"
		#include "array/copy_ranks.cpp"
		#include "array/data_length.cpp"
		#include "array/delete_data.cpp"
		#include "array/clear_internals.cpp"
		#include "array/copy_data_members.cpp"
		#include "array/reset_data_members.cpp"
//
///		The pointer pointing the beginning of the array data.
		data_type *data;
//
///		The length of the first rank.
		unsigned int rank1;
//
///		The length of the second rank.
		unsigned int rank2;
//
///		The length of the third rank.
		unsigned int rank3;
	};
	#undef CURRENT_RANK
//
//	Defining the rank four specialization:
//
	#define CURRENT_RANK 4
	template<typename data_type>
	class array<data_type, CURRENT_RANK>
	{
		public:
		typedef array<data_type, CURRENT_RANK> array_type;
		#include "array/id.cpp"
		#include "array/set.cpp"
		#include "array/get.cpp"
		#include "array/min.cpp"
		#include "array/max.cpp"
		#include "array/sum.cpp"
		#include "array/rank.cpp"
		#include "array/sort.cpp"
		#include "array/clear.cpp"
		#include "array/create.cpp"
		#include "array/resize.cpp"
		#include "array/has_nan.cpp"
		#include "array/is_null.cpp"
		#include "array/set_zero.cpp"
		#include "array/addition.cpp"
		#include "array/is_ready.cpp"
		#include "array/assignment.cpp"
		#include "array/destructor.cpp"
		#include "array/first_rank.cpp"
		#include "array/third_rank.cpp"
		#include "array/left_shift.cpp"
		#include "array/is_positive.cpp"
		#include "array/is_negative.cpp"
		#include "array/subtraction.cpp"
		#include "array/fourth_rank.cpp"
		#include "array/second_rank.cpp"
		#include "array/constructor.cpp"
		#include "array/debug_check.cpp"
		#include "array/function_call.cpp"
		#include "array/data_typename.cpp"
		#include "array/build_randomly.cpp"
		#include "array/multiplication.cpp"
		private:
		#include "array/offset.cpp"
		#include "array/init_as.cpp"
		#include "array/data_end.cpp"
		#include "array/init_data.cpp"
		#include "array/copy_ranks.cpp"
		#include "array/data_length.cpp"
		#include "array/delete_data.cpp"
		#include "array/clear_internals.cpp"
		#include "array/copy_data_members.cpp"
		#include "array/reset_data_members.cpp"
//
///		The pointer pointing the beginning of the array data.
		data_type *data;
//
///		The length of the first rank.
		unsigned int rank1;
//
///		The length of the second rank.
		unsigned int rank2;
//
///		The length of the third rank.
		unsigned int rank3;
//
///		The length of the fourth rank.
		unsigned int rank4;
	};
	#undef CURRENT_RANK
#endif
