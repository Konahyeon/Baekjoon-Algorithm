num = (int)(input())

#입력받은 단어 리스트로 형성
word = []
for i in range(num):
    word.append(input())
    
#중복 제거
remove_overlap = list(set(word))

#(단어 길이, 단어)
check_len = []
for i in remove_overlap:
    check_len.append((len(i), i))
check_len.sort()
for l, w in check_len:
    print(w)