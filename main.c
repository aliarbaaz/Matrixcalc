#include<stdio.h>
//additon of matrices
void sumof_mat (int a[10][10], int b[10][10], int result[10][10], int m, int n)
{
  int i, j;
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  result[i][j] = a[i][j] + b[i][j];
	}
    }
  printf ("The addition of the two matrices A & B is:\n");
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  printf ("%d\t", result[i][j]);
	}
      printf ("\n");
    }

}

//Subtraction of two matrices
void subof_mat (int a[10][10], int b[10][10], int result[10][10], int m, int n)
{
  int i, j;
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  result[i][j] = a[i][j] - b[i][j];
	}
    }
  printf ("The Subtraction of the two matrices A & B is:\n");
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  printf ("%d\t", result[i][j]);
	}
      printf ("\n");
    }

}

//Multiplication of two matrices
void pro_mat (int m1, int n1, int m2, int n2, int a[10][10], int b[10][10],
	 int result[10][10])
{
  int i, j, k;
  for (i = 0; i < m1; i++)
    {
      for (j = 0; j < n1; j++)
	{
	  result[i][j] = 0;
	  for (k = 0; k < n1; k++)
	    {
	      result[i][j] = result[i][j] + a[i][k] * b[k][j];
	    }

	}
    }
  printf ("The product of the two matrices A & B is:\n");
  for (i = 0; i < m1; i++)
    {
      for (j = 0; j < n1; j++)
	{
	  printf ("%d\t", result[i][j]);

	}
      printf ("\n");
    }
}

//Transpose of a matix
void Transpose (int m, int n, int a[10][10], int result[10][10])
{
  int i, j;
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  result[j][i] = a[i][j];
	}
    }
  printf ("The Transpose of the given matrix is:\n");
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	{
	  printf ("%d\t", result[i][j]);
	}
      printf ("\n");
    }
}

//matrix_A input
int read_matrix_B (int a[10][10], int m, int n)
{
  int i, j;
  printf ("Enter the elements of Matrix B:\n");
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  scanf ("%d", &a[i][j]);
	}
    }
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  return a[i][j];
	}
    }
}
//matrix_B input

int read_matrix_A (int a[10][10], int m, int n)
{
  int i, j;
  printf ("Enter the elements of Matrix A:\n");
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  scanf ("%d", &a[i][j]);
	}
    }
  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  return a[i][j];
	}
    }
}

int main ()
{
  int m1, n1, m2, n2, i, j;
  int a[10][10], b[10][10], c[10][10];
  int op;
  printf("-------------- Matrix Calculator --------------\n\n");
  printf("1.Matrix Addition\t2.Matrix Subtraction\n3.Matrix Multiplication\t4.Transpose of Matrix\n5.Exit\n");
  scanf ("%d", &op);
  if(op==5){
      printf("\a");
      goto exit;
  }
  printf ("\a");
  switch (op)
    {
    case 1:
      printf ("Enter number of rows and columns for Matrix A & Matrix B:\n");
      scanf ("%d %d", &m1, &n1);
      read_matrix_A (a, m1, n1);
      read_matrix_B (b, m1, n1);
      sumof_mat (a, b, c, m1, n1);
      break;
    case 2:
      printf ("Enter number of rows and columns for Matrix A & Matrix B:\n");
      scanf ("%d %d", &m1, &n1);
      read_matrix_A (a, m1, n1);
      read_matrix_B (b, m1, n1);
      subof_mat (a, b, c, m1, n1);
      break;
    case 3:
      printf ("Enter number of rows and columns for Matrix A:\n");
      scanf ("%d %d", &m1, &n1);
      printf ("Enter number of rows and columns for Matrix B:\n");
      scanf ("%d %d", &m2, &n2);
      if (n1 != m2)
	{
	  printf ("Matrix multiplication is not possible!\n");
	}
      else
	{
	  read_matrix_A (a, m1, n1);
	  read_matrix_B (b, m2, n2);
	  pro_mat (m1, n1, m2, n2, a, b, c);
	}
      break;
    case 4:
      printf ("Enter number of rows and columns for Matrix A:\n");
      scanf ("%d %d", &m1, &n1);
      read_matrix_A (a, m1, n1);
      Transpose (m1, n1, a, c);
      break;


    default:
      printf ("Invalid input!");
      break;
    }

    exit:
  return 0;
}



