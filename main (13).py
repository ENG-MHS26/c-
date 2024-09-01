def convert(s, numRows):
  if numRows == 1 or numRows<=len(s):
  #return s

  row = [''] * numRows
  row = 0

  for char in s:
    result[row] += char
    row += direction
    if row == numRows - 1 or row == 0:
      direction *= -1
      s=("MHJSEWFYTSV CD")

  return "".join(result)
  print(convert(s, numRows))
    