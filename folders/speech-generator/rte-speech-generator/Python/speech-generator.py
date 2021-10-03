from keras.preprocessing import sequence
import keras
import tensorflow as tf
import os
import numpy as np

##dosyaya ulaşıyor
dosya_yolu = tf.keras.utils.get_file('prepared-data.txt', 'https://raw.githubusercontent.com/ardauzunoglu/rte-speech-generator/master/rte-speech-generator/Text%20Files/prepared-data.txt')
yazi = open(dosya_yolu, 'rb').read().decode(encoding='utf-8')

##yazının içerisindeki kelimeleri sıralıyor
kelimeler = sorted(set(yazi))

##harfleri index numaralarına dönüştürüp numpy listesi oluşturuyor
char2idx = {u:i for i, u in enumerate(kelimeler)}
idx2char = np.array(kelimeler)

##yazıyı sayıya çeviriyor
def yazidan_sayiya(yazi):
  return np.array([char2idx[c] for c in yazi])

##yazının sayı halini oluşturuyor
sayiyla_yazi = yazidan_sayiya(yazi)

##sayıları geri yazıya çevirme
def sayidan_yaziya(sayilar):
  try:
    sayilar = sayilar.numpy()
  except:
    pass
  return ''.join(idx2char[sayilar])

##girdi uzunluğu ve train başına epoch hesaplaması
seq_length = 100  
examples_per_epoch = len(yazi)//(seq_length+1)

char_dataset = tf.data.Dataset.from_tensor_slices(sayiyla_yazi)

sequences = char_dataset.batch(seq_length+1, drop_remainder=True)


def split_input_target(chunk):
    input_text = chunk[:-1]  
    target_text = chunk[1:] 
    return input_text, target_text

dataset = sequences.map(split_input_target)

##train için gerekli bilgiler
BATCH_SIZE = 64
VOCAB_SIZE = len(kelimeler) 
EMBEDDING_DIM = 256
RNN_UNITS = 1024

BUFFER_SIZE = 10000

data = dataset.shuffle(BUFFER_SIZE).batch(BATCH_SIZE, drop_remainder=True)

##model oluşturma fonksiyonu
def build_model(vocab_size, embedding_dim, rnn_units, batch_size):
  model = tf.keras.Sequential([
    tf.keras.layers.Embedding(vocab_size, embedding_dim,
                              batch_input_shape=[batch_size, None]),
    tf.keras.layers.LSTM(rnn_units,
                        return_sequences=True,
                        stateful=True,
                        recurrent_initializer='glorot_uniform'),
    tf.keras.layers.Dense(vocab_size)
  ])
  return model

##model oluşturuyor
model = build_model(VOCAB_SIZE,EMBEDDING_DIM, RNN_UNITS, BATCH_SIZE)


for input_example_batch, target_example_batch in data.take(1):
  example_batch_predictions = model(input_example_batch)  

##tahminde bulunma
pred = example_batch_predictions[0]
time_pred = pred[0]

sampled_indices = tf.random.categorical(pred, num_samples=1)

sampled_indices = np.reshape(sampled_indices, (1, -1))[0]
predicted_chars = sayidan_yaziya(sampled_indices)

##kayıp hesaplama fonksiyonu
def loss(labels, logits):
  return tf.keras.losses.sparse_categorical_crossentropy(labels, logits, from_logits=True)

model.compile(optimizer='adam', loss=loss)

##checkpoint oluşturma
checkpoint_dir = './training_checkpoints'

checkpoint_prefix = os.path.join(checkpoint_dir, "ckpt_{epoch}")

checkpoint_callback=tf.keras.callbacks.ModelCheckpoint(
    filepath=checkpoint_prefix,
    save_weights_only=True)

##train ediyoruz, epoch sayısı arttıkça overfitting(aşırı öğrenme) olmadıkça kayıp azalır
history = model.fit(data, epochs=1, callbacks=[checkpoint_callback])

model = build_model(VOCAB_SIZE, EMBEDDING_DIM, RNN_UNITS, batch_size=1)

model.load_weights(tf.train.latest_checkpoint(checkpoint_dir))
model.build(tf.TensorShape([1, None]))

model.build(tf.TensorShape([1, None]))

##girdi ile yazinin devamini oluşturuyoruz
def generate_text(model, start_string):
  
  ##yazıda oluşturulacak karakter sayısı
  num_generate = 800

  input_eval = [char2idx[s] for s in start_string]
  input_eval = tf.expand_dims(input_eval, 0)

  text_generated = []

  ##az temperature daha tahmin edilebilir bir yazı oluşturur
  ##yüksek temperature daha şaşırtıcı bir yazı oluşturur
  temperature = 1.0

  model.reset_states()
  for i in range(num_generate):
      predictions = model(input_eval)
    
      predictions = tf.squeeze(predictions, 0)

      predictions = predictions / temperature
      predicted_id = tf.random.categorical(predictions, num_samples=1)[-1,0].numpy()

      input_eval = tf.expand_dims([predicted_id], 0)

      text_generated.append(idx2char[predicted_id])

  return (start_string + ''.join(text_generated))

inp = input("Konuşmanın başlangıcını giriniz: ")
print(generate_text(model, inp))