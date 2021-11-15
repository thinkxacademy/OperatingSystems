import re

crib = str(input("Crib:"))
cipher = []
cipherText1 = ''
cipherText2 = ''
print("Enter Cipher Text(Enter empty line to quit):")
temp_map = {}
while True:
    cipherText = str(input())
    cipherText1 = cipherText1 + str(cipherText) + ' ' + '\n'
    temp_ciphertext = cipherText1
    cipherText2 = cipherText2 + str(cipherText.strip()) + ' '
    if cipherText:
        cipher.append(cipherText)
    else:
        break


def remove_and_reset(crib, cipherText1, cipherText2):
    global mapp
    mapp = {}
    crib_input = ''
    count2 = 0
    for i in crib.split():
        crib_input = crib_input + str(len(i)) + ' '
    cipher_split = cipherText1.split()
    temp_cipher = cipherText1
    temp = ''
    count = 0
    for i in temp_cipher.split('\n'):
        for j in i.split():
            temp = temp + str(len(j)) + ' '
        if temp.find(crib_input) == -1:
            count += 1
            count2 += 1

    pos = temp.find(crib_input) - count + count2
    pos2 = pos // 2
    words_select = crib.split()
    words_cipher = cipherText2.split()
    substitute_cipher = ''
    for i in range(pos2, pos2 + len(words_select)):
        substitute_cipher = substitute_cipher + str(words_cipher[i]) + ' '
    substitute_words = substitute_cipher.split()

    for i in range(len(words_select)):
        for j in range(len(words_select[i])):
            if words_select[i][j] in mapp:
                if substitute_words[i][j] != mapp[words_select[i][j]]:
                    mapp = {}
                    del words_cipher[0:pos2 + len(substitute_words)]
                    del cipher_split[0:pos2 + len(substitute_words)]
                    new_cipher2 = words_cipher
                    new_cipher2 = " ".join(new_cipher2)
                    new_cipher = " ".join(cipher_split)
                    remove_and_reset(crib, new_cipher, new_cipher2)
            else:
                mapp[words_select[i][j]] = substitute_words[i][j]
    # Replace and display
    if len(set(crib.replace(" ", ""))) == len(mapp.keys()):
        for i in temp_ciphertext.lower():
            if i in mapp.values():
                print(list(mapp.keys())[list(mapp.values()).index(i)].upper(),end='')
            else:
                print(i,end='')


cipherText1 = re.sub('\W+', ' ', cipherText1)
cipherText2 = re.sub('\W+', ' ', cipherText2)
remove_and_reset(crib, cipherText1, cipherText2)
