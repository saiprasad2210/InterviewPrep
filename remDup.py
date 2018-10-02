class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        num_map = dict()
        for i in nums:
            num_map[i] = 0
        
        for i in nums:
            if num_map[i] >= 1:
                return True
            num_map[i] += 1
