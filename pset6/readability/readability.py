from cs50 import get_string
# getting text from the user
text = get_string("Text: ")
# declairing variables
N = len(text)
word_counter = 1  # start as one to count last word
letter_counter = 0
sentences = 0
# loop to iterate through the string
for i in range(N):
    if text[i].isspace():  # space indicate end of the word
        word_counter += 1
    elif text[i].isalpha():
        letter_counter += 1
    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
# calculating L and S
L = (letter_counter/word_counter) * 100
S = (sentences/word_counter) * 100
#  calculating index by the Coleman-Liau formula
index = round(0.0588 * L - 0.296 * S - 15.8)
# printing the results
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(index))
