import random
#Gram Schmidt에 사용될 함수들
def dot_product(vec1, vec2):
    return sum(x * y for x, y in zip(vec1, vec2))

def vector_addition(vec1, vec2):
    return [x + y for x, y in zip(vec1, vec2)]

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

def is_almost_zero(value, tolerance=1e-6):
    return abs(value) < tolerance

def is_almost_one(value, epsilon=1e-10):
    return abs(value - 1) < epsilon

def generate_linear_combination(basis_vectors, coefficients):
    if len(basis_vectors) != len(coefficients):
        raise ValueError("basis벡터와 coefficients의 갯수는 동일해야 합니다.")

    result_vector = [0] * len(basis_vectors[0])

    # result_vector = a1 * v1 + a2 * v2 + ... + an * vn
    for basis, coeff in zip(basis_vectors, coefficients):
        scaled_basis = vector_scalar_multiply(basis, coeff)
        result_vector = vector_addition(result_vector, scaled_basis)

    return result_vector

def generate_coefficients(basis_vectors, target_vector):
    coefficients = []

    # using projection
    for basis_vector in basis_vectors:
        dot_prod = dot_product(target_vector, basis_vector)
        magnitude_squared = vector_magnitude(basis_vector)**2
        
        if magnitude_squared != 0:
            coefficients.append(dot_prod / magnitude_squared)
            
         # 크기가 0인 경우 (분모가 0)
        else:
            coefficients.append(0)

    return coefficients
    
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
            vector_list.append(vector)  # append to list

        # Orthonormal Basis Vectors List으로 묶이게 출력
        print("\nList of Vectors:")
        print(vector_list)
        
        flag = 0
        for i in range(n):
            for j in range(n):
                if i != j:
                    x = dot_product(vector_list[i], vector_list[j])
                    if not is_almost_zero(x):
                        flag = 1
                        break
                    else:
                        flag = 0
                else:
                    x = dot_product(vector_list[i], vector_list[j])
                    if not is_almost_one(x):
                        flag = 1
        
        # Check orthogonal    
        if(flag == 0):
            print("\nThis matrix is an orthonomal matrix.")
        else:
            print("\nThis matrix is not an orthonomal matrix.")
        
        
        # randomly generate target_vector
        target_vector = generate_random_vector(n)
        print("\nGenerated Target Vector:", target_vector)
        
        # generate coefficients using projection
        coefficients = generate_coefficients(basis_vectors, target_vector)
        print("\nGenerated Coefficients : ", coefficients)
        
        # generate combination with linear combination
        # for checking these vectors are orthogonal
        linear_combination = generate_linear_combination(basis_vectors, coefficients)
        print("\nResulting Linear Combination:", linear_combination)



    #예외 처리 (Exception Handling)
    except ValueError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
