from googletrans import Translator
flag = True
text = str(input('Enter the text to be translated: '))
while flag:
    try:
        desti = str(input('Input Language Code(ko,ja,es,etc): '))
        translator = Translator()
        translated = translator.translate(text, dest=desti)
        print(f'{text} -> {translated.text}')
        flag = False
    except ValueError:
        print('Please enter correct language code')
