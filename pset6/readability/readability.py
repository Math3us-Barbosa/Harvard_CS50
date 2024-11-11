from cs50 import get_string

text = get_string("Text: ")
N = len(text)
word_counter = 1
letter_counter = 0
sentences = 0
for i in range (N):
    if text[i] == ' ':
        word_counter  +=  1
    elif isalpha(text[i]):
        letter_counter += 1
    elif text[i] == '.' or text[i]  == '!' or text[i] == "?":
        sentences += 1
L = (letter_counter/word_counter) * 100
S = (sentences/word_counter) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)
print("Grade: " + index)
