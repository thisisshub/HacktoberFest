#we need the alphabet because we convert letters into numerical values to be able to use
#mathematical operations (note we encrypt the spaces as well)
ALPHABET = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'

#the Vigenere algorithm
def vigenere_encrypt(plain_text, key):

	#this is the text we want to encrypt
	plain_text = plain_text.upper()
	# we make the algorithm case insensitive
	key = key.upper()
	
	cipher_text = ''
	#it represents the index as far as the key is concerned
	key_index = 0
	
	#we have to consider all the characters in the plain_text
	for character in plain_text:
		#number of shifts = index of the character in the alphabet + index of the character in the key
		index = (ALPHABET.find(character)+(ALPHABET.find(key[key_index])))%len(ALPHABET)
		#keep appending the encrypted character to the cipher_text
		cipher_text = cipher_text + ALPHABET[index]
		
		#increment the key index because we consider the next letter
		key_index = key_index + 1

		#if we've considered the last letter of the key we start again
		if key_index == len(key):
			key_index = 0
			
	return cipher_text
	
#decryption is the same except now we use the following formula:
#number of shifts = index of the character in the alphabet - index of the character in the key
def vigenere_decrypt(cipher_text, key):

	cipher_text = cipher_text.upper()
	key = key.upper()
	
	plain_text = ''
	key_index = 0
	
	for character in cipher_text:
		index = (ALPHABET.find(character)-(ALPHABET.find(key[key_index])))%len(ALPHABET)
		plain_text = plain_text + ALPHABET[index]
		
		key_index = key_index + 1
		
		if key_index == len(key):
			key_index = 0
			
	return plain_text
	
if __name__ == "__main__":
	
	plain_text = "Shannon defined the quantity of information produced by a source for example, the quantity in a message--by a formula similar to the equation that defines thermodynamic entropy in physics. In its most basic terms, Shannon's informational entropy is the number of binary digits required to encode a message. Today that sounds like a simple, even obvious way to define how much information is in a message. In 1948, at the very dawn of the information age, this digitizing of information of any sort was a revolutionary step. His paper may have been the first to use the word bit, short for binary digit. As well as defining information, Shannon analyzed the ability to send information through a communications channel. He found that a channel had a certain maximum transmission rate that could not be exceeded. Today we call that the bandwidth of the channel. Shannon demonstrated mathematically that even in a noisy channel with a low bandwidth, essentially perfect, error-free communication could be achieved by keeping the transmission rate within the channel's bandwidth and by using error-correcting schemes: the transmission of additional bits that would enable the data to be extracted from the noise-ridden signal. Today everything from modems to music CDs rely on error-correction to function. A major accomplishment of quantum-information scientists has been the development of techniques to correct errors introduced in quantum information and to determine just how much can be done with a noisy quantum communications channel or with entangled quantum bits (qubits) whose entanglement has been partially degraded by noise."
	plain_text = 'CRYPTOGRAPHY IS QUITE IMPORTANT IN CRYPTOCURRENCIES'
	encrypted = vigenere_encrypt(plain_text,'table')
	print('Encrypted message: %s' % encrypted)
	decrypted = vigenere_decrypt(encrypted,'table')
	print('Decrypted mesage: %s' % decrypted)