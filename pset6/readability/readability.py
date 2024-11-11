from cs50 import get_string

text = get_string("Text: ")
N = len(text)
word_counter = 1
letter_counter = 0
sentences = 0
for i in range (N):
    if text[i].isspace():
        word_counter  +=  1
    elif text[i].isalpha:
        letter_counter += 1
    elif text[i] == "." or text[i]  == "!" or text[i] == "?":
        sentences += 1
print(word_counter)
print(letter_counter)
print(sentences)
L = (letter_counter/word_counter) * 100
S = (sentences/word_counter) * 100
index = int(0.0588 * L - 0.296 * S - 15.8)
print("Grade: " + str(index))
