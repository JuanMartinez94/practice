import collections

def readTXT(read):
    ascii= []
    with open(read) as the_txt:
        for line in the_txt:
            ascii.extend(int(value) for value in line.strip().split())
    return ascii

read = "ASCII.txt"
ascii = readTXT(read)
string = "".join(chr(ascii) for ascii in ascii)

def least(string, n=10):
    words = string.split()
    word_counts = collections.Counter(words)
    top_10 = word_counts.most_common()[:-n-1:-1]
    return top_10
    
top_10 = least(string)
print("The 10 least common words are:", top_10)
