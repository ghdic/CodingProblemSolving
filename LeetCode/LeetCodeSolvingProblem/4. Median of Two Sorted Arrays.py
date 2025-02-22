# 두개의 정렬된 배열이 주어질때
# O(log(n + m)) 시간 복잡도로 중앙값을 찾는 문제
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # nums1이 항상 더 짧은 배열이 되도록 보장
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        x, y = len(nums1), len(nums2)
        left, right = 0, x

        while left <= right:
            partitionX = (left + right) // 2
            partitionY = (x + y + 1) // 2 - partitionX

            # maxLeftX, minRightX 정의
            maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX - 1]
            minRightX = float('inf') if partitionX == x else nums1[partitionX]

            # maxLeftY, minRightY 정의
            maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY - 1]
            minRightY = float('inf') if partitionY == y else nums2[partitionY]

            # 정답 조건 만족
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                # 전체 길이가 홀수인 경우
                if (x + y) % 2 == 1:
                    return max(maxLeftX, maxLeftY)
                # 전체 길이가 짝수인 경우
                else:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2

            # 왼쪽으로 이동
            elif maxLeftX > minRightY:
                right = partitionX - 1
            # 오른쪽으로 이동
            else:
                left = partitionX + 1

