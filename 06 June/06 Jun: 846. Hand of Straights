from collections import Counter

class Solution:
    def isNStraightHand(self, hand, groupSize):
        if len(hand) % groupSize != 0:
            return False

        card_count = Counter(hand)
        sorted_cards = sorted(card_count.keys())

        for card in sorted_cards:
            if card_count[card] > 0:
                num_groups = card_count[card]
                for i in range(groupSize):
                    if card_count[card + i] < num_groups:
                        return False
                    card_count[card + i] -= num_groups

        return True

# Test cases
s = Solution()
print(s.isNStraightHand([1,2,3,6,2,3,4,7,8], 3))  # Output: True
print(s.isNStraightHand([1,2,3,4,5], 4))  # Output: False
