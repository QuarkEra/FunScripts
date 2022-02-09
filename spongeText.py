from random import randrange
def main():
    str = spongeThis(input('> '))
    print(str)
def spongeThis(text):
    str = ''
    flipCase = False
    for char in text:
        if char is char.isalpha():
            str += ''
            continue
        if flipCase:
            str += char.upper()
        else:
            str += char.lower()
        if randrange(1,10) <= 8:
            flipCase = not flipCase
    return str
if __name__ == '__main__': main()
