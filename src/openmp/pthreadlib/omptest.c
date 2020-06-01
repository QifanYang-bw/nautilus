#include <nautilus/nautilus.h>
#include <nautilus/shell.h>
#include <nautilus/libccompat.h>
#ifndef NAUT_CONFIG_DEBUG_GPUDEV
#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, args...) 
#endif

#define ERROR(fmt, args...) ERROR_PRINT("omptest: " fmt, ##args)
#define DEBUG(fmt, args...) DEBUG_PRINT("omptest: " fmt, ##args)
#define INFO(fmt, args...) INFO_PRINT("omptest: " fmt, ##args)





#define MAXN 100  /* Max value of N */
int N;  /* Matrix size */
int procs;  /* Number of processors to use */

/* Matrices and vectors */
volatile float A[MAXN][MAXN], B[MAXN], X[MAXN];
/* A * X = B, solve for X */


/* Prototype */
void gauss();  /* The function you will provide.
		* It is this routine that is timed.
		* It is called only on the parent.
		*/

/* Initialize A and B (and X to 0.0s) */
void initialize_inputs() {
  int row, col;

  printf("\nInitializing...\n");
  for (col = 0; col < N; col++) {
    for (row = 0; row < N; row++) {
      A[row][col] = (float) (col+row);
    }
    B[col] = (float)(col);
    X[col] = 0.0;
  }

}

/* Print input matrices */
void print_inputs() {
  int row, col;

  if (N < 100) {
    printf("\nA =\n\t");
    for (row = 0; row < N; row++) {
      for (col = 0; col < N; col++) {
	printf("%5.2f%s", A[row][col], (col < N-1) ? ", " : ";\n\t");
      }
    }
    printf("\nB = [");
    for (col = 0; col < N; col++) {
      printf("%5.2f%s", B[col], (col < N-1) ? "; " : "]\n");
    }
  }
}


void gauss() {
  int norm, row, col;  /* Normalization row, and zeroing
			* element row and col */
  float multiplier;
  //doneflag[0] = 1;
  
  printf("Computing using omp.\n");

  /* Gaussian elimination */
  
  #pragma omp parallel private(col, row, multiplier) num_threads(procs)
  for (norm = 0; norm < N - 1; norm++) {
    
    int num = N - norm;
    
  {
    #pragma omp for schedule(dynamic)
      for (row = norm + 1; row < N; row++) {

        multiplier = A[row][norm] / A[norm][norm];

        for (col = norm; col < N; col++) {
            A[row][col] -= A[norm][col] * multiplier;
        }
        B[row] -= B[norm] * multiplier;
      }
  }
  }
  /* (Diagonal elements are not normalized to 1.  This is treated in back
   * substitution.)
   */
  /* Back substitution */
  for (row = N - 1; row >= 0; row--) {
    X[row] = B[row];
    for (col = N-1; col > row; col--) {
      X[row] -= A[row][col] * X[col];
    }
    X[row] /= A[row][row];
  }
}



static int handle_omptest (char * buf, void * priv)
{
    N = 3;
    procs = 3;
    A[0][0] = 4;    A[0][1] = -3;    A[0][2] = 1;
    A[1][0] = -2;    A[1][1] = 1;    A[1][2] = -3;
    A[2][0] = 1;    A[2][1] = -1;    A[2][2] = 2;
    B[0] = -8;    B[1] = -4;    B[2] = 2; 
    print_inputs();
    gauss();
    print_inputs();
    return 0;

}


static struct shell_cmd_impl omptest_impl = {
    .cmd      = "omptest",
    .help_str = "openmp test",
    .handler  = handle_omptest,
};
nk_register_shell_cmd(omptest_impl);

