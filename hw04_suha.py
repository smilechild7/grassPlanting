import random
#Gram Schmidt에 사용될 함수들
def dot_product(vec1, vec2):
    return sum(x * y for x, y in zip(vec1, vec2))

def vector_subtraction(vec1, vec2):
    return [x - y for x, y in zip(vec1, vec2)]

def vector_scalar_multiply(vec, scalar):
    return [x * scalar for x in vec]

def vector_magnitude(vec):
    return sum(x**2 for x in vec)**0.5

def gram_schmidt(vectors):
    basis = []
    for vector in vectors:
        for b in basis:
            projection = vector_scalar_multiply(b, dot_product(vector, b) / vector_magnitude(b)**2)
            vector = vector_subtraction(vector, projection)
        basis.append(vector_scalar_multiply(vector, 1 / vector_magnitude(vector)))
    return basis

def print_matrix_with_basis(matrix, basis_names):
    print("\nOrthonormal Basis Matrix [{}]: ".format(" ".join(basis_names)))
    for row in matrix:
        print(row)

def generate_random_vector(dim):
    return [random.uniform(-10, 10) for _ in range(dim)]
    
def main():
    try:
        # 백터 차원 입력 (# Dimensions)
        n = int(input("백터 차원 입력 (3~10): "))
        if not (3 <= n <= 10):
            raise ValueError("백터 차원은 3~10 만 입력 가능합니다.")
        
       # Random Generator(-10,10)로 백터 생성 
        vectors = []
        print("\nRandomly Generated Vectors (a):")
        for i in range(n):
            vector = generate_random_vector(n)
            vectors.append(vector)
            print(f"a{i + 1} =", vector)
        # Gram-Schmidt 적용
        basis_vectors = gram_schmidt(vectors)

        # Orthonormal Basis Vectors 출력
        print("\nOrthonormal Basis Vectors (q):")
        vector_list = []  # List to hold the vectors
        for i, vector in enumerate(basis_vectors):
            print(f"q{i + 1} =", vector)
            vector_list.append(vector)  # Append the vector to the list

        # Orthonormal Basis Vectors List으로 묶이게 출력
        print("\nList of Vectors:")
        print(vector_list)

    #예외 처리 (Exception Handling)
    except ValueError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
