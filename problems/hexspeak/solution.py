class Solution:
	def toHexspeak(self, num: str) -> str:
		res = ""
		num = str(hex(int(num))[2:])
		for i in num:
			if i == "1":
				res += "I"
			elif i == "0":
				res += "O"
			elif i == "a":
				res += "A"
			elif i == "b":
				res += "B"
			elif i == "c":
				res += "C"
			elif i == "d":
				res += "D"
			elif i == "e":
				res += "E"
			elif i == "f":
				res += "F"
			else:
				return "ERROR"
		return res