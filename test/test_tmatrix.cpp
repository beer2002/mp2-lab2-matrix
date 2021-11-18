#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix,can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> matr1(3);
	TMatrix<int> matr2(matr1);

	ASSERT_EQ(matr1, matr2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> matr1(3);
	TMatrix<int> matr2(matr1);

	ASSERT_NE(&matr1[0], &matr2[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> matr(3);
	ASSERT_EQ(matr.GetSize(), 3);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> matr(3);
	matr[0][0] = 1;

	ASSERT_EQ(matr[0][0], 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> matr(3);
	ASSERT_ANY_THROW(matr[-1][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> matr(3);
	ASSERT_ANY_THROW(matr[5][0] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	int size = 3;
	TMatrix<int> matr(size);
	
	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			matr[i][j] = 5;
		}
	}

	bool isOk = true;

	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if(matr[i][j] != 5){
				isOk = false;
			}
			
		}
	}

	ASSERT_EQ(isOk, true);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(5);

	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			matr1[i][j] = 7;
		}
	}

	matr2 = matr1;
	bool isOk = true;

	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			if(matr2[i][j] != 7){
				isOk = false;
			}
		}
	}

	ASSERT_EQ(isOk, true);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(4);

	matr2 = matr1;

	ASSERT_EQ(matr2.GetSize(), 5);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(4);

	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			matr1[i][j] = 7;
		}
	}

	matr2 = matr1;
	bool isOk = true;

	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			if(matr2[i][j] != 7){
				isOk = false;
			}
		}
	}

	ASSERT_EQ(isOk,true);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{

	TMatrix<int> matr1(5);
	TMatrix<int> matr2(5);

	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			matr1[i][j] = 7;
		}
	}

	matr2 = matr1;
	ASSERT_EQ(matr1, matr2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> matr1(5);

	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			matr1[i][j] = 7;
		}
	}

	ASSERT_EQ(matr1,matr1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(4);

	ASSERT_NE(matr1, matr2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(5);
	TMatrix<int> res1(5);
	TMatrix<int> res2(5);


	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			matr1[i][j] = 2;
			matr2[i][j] = 3;
			res2[i][j] = 5;
		}
	}

	res1 = matr1 + matr2;

	ASSERT_EQ(res1, res2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(4);
	ASSERT_ANY_THROW(matr1 + matr2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(5);
	TMatrix<int> res1(5);
	TMatrix<int> res2(5);


	for(int i = 0; i < 5; i++){
		for(int j = i; j < 5; j++){
			matr1[i][j] = 5;
			matr2[i][j] = 3;
			res2[i][j] = 2;
		}
	}

	res1 = matr1 - matr2;

	ASSERT_EQ(res1, res2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> matr1(5);
	TMatrix<int> matr2(4);
	ASSERT_ANY_THROW(matr1 - matr2);
}

