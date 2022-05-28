
class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        leng = len(senders)
        freq = {}
        for i in range(leng):
            sender = senders[i]
            msg = messages[i]
            msg_len = len(msg.split())
            if sender in freq:
                freq[sender] += msg_len
            else:
                freq[sender] = msg_len
            
            
        max_sender_len = float('-inf')
        max_sender_name = ''
        
        for sender in freq:
            if freq[sender] > max_sender_len:
                max_sender_len = freq[sender]
                max_sender_name = sender
            elif freq[sender] == max_sender_len:
                max_sender_name = max(max_sender_name , sender)
                
        return max_sender_name