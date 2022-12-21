#BMHS
def bmhs( text,  textLength,  pattern,  patternLength):
  maxChar = 256
  displacement = []
  # Assign default value to all letters
  for i in range(maxChar):
    displacement.append(patternLength + 1)

  # Pattern letters shift value
  # Since the index starts at 0, it is not necessary to add 1
  for letterIndex in range(patternLength):
      displacement[ord(pattern[letterIndex])] = patternLength - letterIndex
    
  # Adjust index to avoid out of bound error  
  i = patternLength - 1

  while (i < textLength):
      textLetterIndex = i
      patternLetterIndex = patternLength - 1

      # Compare from right to left
      while ((patternLetterIndex >= 0) and (text[textLetterIndex] == pattern[patternLetterIndex])):
        patternLetterIndex -= 1
        textLetterIndex -= 1
      
      
      # Match found in all pattern letters 
      if (patternLetterIndex < 0) :
        print (f'Match from position {textLetterIndex + 1} to position {textLetterIndex + patternLength}')
      

      # Shift the text pattern 
      i = i + displacement[ord(text[textLetterIndex + 1])]
  

text = "hbadecaedcade";
txt = "JAVAJAVAJAVJAVAJAVACJAVA";
patternk = "JAVA";
pattern = "cade";
bmhs(txt, len(txt), patternk, len(patternk));
