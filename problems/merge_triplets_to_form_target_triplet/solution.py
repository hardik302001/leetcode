class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        
        def rindex(lst, value):
            for i, v in enumerate(reversed(lst)):
                if v == value:
                    return len(lst) - i - 1  # return the index in the original list
            return -1

        triplets.sort()
    # print(" printing sorted 1 ")
    # print(triplets)
        ans1 = []
        t1 = []
        for i in triplets:
            t1.append(i[0])
    # f1 = first(t1,target[0],len(t1))
    # l1 = last(t1,target[0],len(t1))
        l1 = rindex(t1, target[0])
        if l1 == -1:
            return False
        else:
            triplets2 = [triplets[i] for i in range(l1 + 1)]
    # print(triplets2)

        triplets2.sort(key=lambda x: x[1])
    # print("printing sorted 2")
    # print(triplets2)
        ans2 = []
        t2 = []
        for i in triplets2:
            t2.append(i[1])
    # f2 = first(t2,target[1],len(t2))
    # l2 = last(t2,target[1],len(t2))

        l2 = rindex(t2, target[1])
        if l2 == -1:
            return False
        else:
            triplets3 = [triplets2[i] for i in range(l2 + 1)]
    # print(triplets3)

        triplets3.sort(key=lambda x: x[2])
    # print("printing sorted 3")
    # print(triplets3)
        ans3 = []
        t3 = []
        for i in triplets3:
            t3.append(i[2])
    # f3 = first(t3,target[2],len(t3))
    # l3 = last(t3,target[2],len(t3))
        l3 = rindex(t3, target[2])
        if l3 == -1:
            return False
        else:
            triplets4 = [triplets3[i] for i in range(l3 + 1)]
    # print(triplets4)

        m1 = 0
        m2 = 0
        m3 = 0
        for i in triplets4:
            m1 = max(i[0],m1)
            m2 = max(i[1],m2)
            m3 = max(i[2],m3)
        final = [m1,m2,m3]
        if final==target:
            return True
        return False

