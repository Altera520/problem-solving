from queue import PriorityQueue

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        if len(barcodes) == 1:
            return barcodes

        pq = PriorityQueue()
        ans = []
        d = {}
        tmp = None 

        for barcode in barcodes:
            if barcode not in d:
                d[barcode] = 0
            d[barcode] += 1
        
        for k, v in d.items():
            pq.put((v * -1, k))

        while not pq.empty():
            cnt, k = pq.get()
            cnt += 1

            if tmp:
                pq.put(tmp)
                tmp = None
            if cnt != 0:
                tmp = (cnt, k)

            ans.append(k)

        return ans
