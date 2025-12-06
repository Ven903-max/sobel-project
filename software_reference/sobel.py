import cv2
import sys

img = cv2.imread(sys.argv[1], 0)

sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)

sobel = cv2.convertScaleAbs(sobelx) + cv2.convertScaleAbs(sobely)

cv2.imwrite(sys.argv[2], sobel)
print("Saved:", sys.argv[2])
