# Open the .txt file
with open("ASCII.txt", "r") as file:
    # Read the contents of the file
    contents = file.read()
    # Split the contents by a delimiter, such as a space or a newline
elements = contents.split()
    # Convert each element to an integer
int_array = [int(element) for element in elements]


# Convert each integer in the array to its corresponding character
words = [chr(value) for value in int_array]

# Join the characters together to form a string
sentence = "".join(words)

# Split the string into a list of words
words = sentence.split()

# Initialize a dictionary to keep track of the frequency of each word
word_count = {}

# Loop through each word in the list of words
for word in words:
    # If the word is not in the dictionary, add it with a frequency of 1
    if word not in word_count:
        word_count[word] = 1
    # If the word is already in the dictionary, increment its frequency by 1
    else:
        word_count[word] += 1

# Sort the dictionary by frequency in ascending order
sorted_word_count = sorted(word_count.items(), key=lambda x: x[1])

# Print the bottom 10 least used words
for word, frequency in sorted_word_count[:10]:
    print("{}: {}".format(word, frequency))

print(sentence)

