import os
import cv2
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
from numpy import linalg

# 이미지 크기를 변환하고 해당하는 벡터를 반환하는 함수
def process_image(img, n):
    img_array = np.array(Image.fromarray(img).resize((n, n)))
    img_vector = img_array.reshape((n * n, 1)).astype(float)
    return img_vector

# Dataset 폴더 내의 모든 파일 목록 가져오기
folder_path = 'FacePix'
image_paths = [os.path.join(folder_path, file) for file in os.listdir(folder_path) if file.lower().endswith(('.png', '.jpg', '.jpeg'))]

# 이미지를 통해 구한 벡터를 배열로 저장 (n*n 이 픽셀의 개수)
n = 80
vectors = []
for image_path in image_paths:
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    img_vector = process_image(img, n)
    vectors.append(img_vector)

# 벡터를 쌓아서 행렬 생성
image_matrix = np.hstack(vectors)

# 모든 벡터의 평균값 계산 후 행렬의 각 요소에서 평균값 빼기.
mean_value = np.mean(image_matrix)
centered_matrix = image_matrix - mean_value

# 데이터 행렬 A 생성 (행 벡터)
A = np.transpose(centered_matrix)

# 특이값 분해 (SVD)
U, s, Vt = linalg.svd(A)
V = Vt.transpose()

# 유지할 Eigenvector의 개수를 추출 (큰 순서대로)
num_components = 2000
eigenfaces = V[:, :num_components]

# eigenfaces 을 표시
fig, axes = plt.subplots(1, num_components, figsize=(100, 5))
for i in range(num_components):
    eigenface = eigenfaces[:, i].reshape((n, n))
    axes[i].imshow(eigenface, cmap='gray')
    axes[i].axis('off')
    axes[i].set_title(f'{i + 1}')
plt.show()

# Reconstruct 할 대상 이미지들 가져오기
target_folder_path = 'targetImages'
target_images = []
target_coefficients = []  # 비교를 위해 계수 저장

for target_file in os.listdir(target_folder_path):
    if target_file.lower().endswith(('.png', '.jpg', '.jpeg')):
        target_path = os.path.join(target_folder_path, target_file)
        target_image = cv2.imread(target_path, cv2.IMREAD_GRAYSCALE)
        target_image = np.array(Image.fromarray(target_image).resize((n, n)))
        target_vector = target_image.reshape((n * n, 1)).astype(float)
        target_vector = target_vector - mean_value

        # 대상 이미지의 계수 계산
        coefficients = np.zeros((num_components, 1))
        for i in range(num_components):
            coefficients[i] = np.dot(target_vector[:, 0], eigenfaces[:, i])

        # 계수와 대상 이미지 저장
        target_images.append(target_image)
        target_coefficients.append(coefficients)

# 비교할 새로운 이미지의 벡터에서 평균값을 뺀 벡터 계산
new_image_path = 'NewImage_.jpg'
new_image = cv2.imread(new_image_path, cv2.IMREAD_GRAYSCALE)
new_image = np.array(Image.fromarray(new_image).resize((n, n)))
new_vector = new_image.reshape((n * n, 1)).astype(float) 
new_vector = new_vector - mean_value

# 새 이미지의 계수 계산
new_coefficients = np.zeros((num_components, 1))
for i in range(num_components):
    new_coefficients[i] = np.dot(new_vector[:, 0], eigenfaces[:, i])

# 새로운 계수와 저장된 계수 비교
# 여기서는 유클리드 거리를 사용하여 유사성을 측정
distances = [np.linalg.norm(new_coefficients - coeff) for coeff in target_coefficients]

# 가장 유사한 얼굴의 인덱스 찾기
most_similar_index = np.argmin(distances)

# 가장 유사한 얼굴에 대한 새로운, 원본, 재구성된 이미지 표시
fig, axes = plt.subplots(1, 3, figsize=(12, 4))

# 새 이미지
axes[0].imshow(new_image, cmap='gray')
axes[0].axis('off')
axes[0].set_title('새 이미지')

# 원본 이미지
axes[1].imshow(target_images[most_similar_index], cmap='gray')
axes[1].axis('off')
axes[1].set_title('원본 이미지')

# 재구성된 이미지
reconstruction_image = np.dot(target_coefficients[most_similar_index].T, eigenfaces.T) + mean_value
reconstruction_image = reconstruction_image.reshape((n, n))
axes[2].imshow(reconstruction_image, cmap='gray')
axes[2].axis('off')
axes[2].set_title('재구성된 이미지')

plt.show()