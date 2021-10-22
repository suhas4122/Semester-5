import numpy as np
import matplotlib.pyplot as plt

def iterative_ls(A, b, num_iter=100):
    iter_array = []
    error_array = []
    (m, n) = A.shape
    x = np.zeros(shape=(n,))

    x_hat = np.linalg.lstsq(A, b, rcond=None)[0]

    for i in range(num_iter):
        x = x - (1 / np.linalg.norm(A, 2) ** 2) * np.dot(np.transpose(A), (np.dot(A, x) - b))
        iter_array.append(i + 1)
        error_array.append(np.linalg.norm(x - x_hat))

    print(f'\nNo. of iterations: {num_iter}')
    print('\nLeast squares solution computed using iterative method:\n', x)
    print('\nActual least squares solution:\n', x_hat)

    plt.plot(iter_array, error_array)
    plt.xlabel('No. of iterations')
    plt.ylabel('Error (Norm of (x_k - x_hat))')
    plt.show()

def main():
    m = 30
    n = 10
    A = np.random.rand(m, n)
    b = np.random.rand(m,)
    np.set_printoptions(linewidth=np.inf)
    print('\nMatrix A:\n', A)
    np.set_printoptions(linewidth=120)
    print('\nVector b:\n', b)
    np.set_printoptions(linewidth=np.inf)
    print(f'\nRank of A = {np.linalg.matrix_rank(A)}')

    iterative_ls(A, b)

if __name__ == '__main__':
    main()