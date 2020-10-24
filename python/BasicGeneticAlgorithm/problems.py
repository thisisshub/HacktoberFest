import os
import atexit
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

from genetic import GenAlgProblem


def keypress(e):
    if e.key in {'q', 'escape'}: os._exit(0) # unclean exit, but exit() or sys.exit() won't work
    if e.key in {' ', 'enter'}: plt.close() # skip blocking figures


def finish():
    plt.show(block=True) # Woraround to prevent plots from closing

atexit.register(finish)


class OnesString(GenAlgProblem):
    def __init__(self, str_len = 32, **kwargs):
        self.str_len = str_len
        super().__init__(**kwargs)

    def generate_individual(self):
        return list(np.random.randint(2, size=(self.str_len,)))

    def show_individual(self, x, title=None, **kwargs):
        # Convert individual x and its fitness into string and print
        if title: print('\n' + title)
        print('{} -> fit = {}'.format(''.join([str(bit) for bit in x]),
                                      self.fitness(x)
                                      ))

    def show_population(self, title='Population:', limit=None, **kwargs):
        # Print whole population, along with maximal and average fitness.
        num = min(limit or np.inf, len(self.population))
        print('\n' + title + ('' if limit is None else ' (best ' + str(limit) + ')') )
        srt_pop = sorted(self.population, key=lambda x:self.fitness(x), reverse=True)[:num]
        for x in srt_pop:
            self.show_individual(x)
        fits = np.array([self.fitness(x) for x in self.population])
        print('Fitness: max = {:.3f}, avg = {:.3f}\n'.format(np.max(fits), np.mean(fits)))

    def fitness(self, x):
        return np.mean(x)

    def mutation(self, x, prob):
        return self.boolean_mutation(x, prob)



class Smiley(GenAlgProblem):
    def __init__(self, **kwargs):
        img = np.zeros((7,7), dtype='int32')
        img[1:3,[2,4]] = 1
        img[4, [0,6]] = 1
        img[5, [1,5]] = 1
        img[6, 2:5] = 1
        self.target_image = img.flatten()
        self.img_shape = img.shape
        self.img_flat_size = len(self.target_image)
        super().__init__(**kwargs)

    def generate_individual(self):
        # return list(np.zeros((self.img_flat_size,)))
        return list(np.random.randint(2, size=(self.img_flat_size,)))

    def show_individual(self, x, title=None, block=False):
        plt.figure(num=title).canvas.mpl_connect('key_press_event', keypress)
        plt.imshow(np.array(x).reshape(self.img_shape), interpolation='none', cmap='binary')
        plt.title('Fitness = {:.3f}'.format(self.fitness(x)))
        plt.xticks([]); plt.yticks([])
        plt.show(block=block)
        plt.waitforbuttonpress(timeout=0.001)

    def show_population(self, title='Population', limit=None, block=False):
        num = min(limit or np.inf, len(self.population))
        n_cols = int(np.ceil(np.sqrt(num)))
        n_rows = int(np.ceil(num / n_cols))
        title = title + ('' if limit is None else ' (best ' + str(limit) + ')')
        fig, axs = plt.subplots(n_rows, n_cols, num=title)
        fig.canvas.mpl_connect('key_press_event', keypress)
        axs = np.array([axs]).flatten()
        srt_pop = sorted(self.population, key=lambda x:self.fitness(x), reverse=True)[:num]
        for x, ax in zip(srt_pop, axs):
            ax.imshow(np.array(x).reshape(self.img_shape), interpolation='none', cmap='binary')
            ax.set_title('f={:.3f}'.format(self.fitness(x)))
            ax.set_xticks([]); ax.set_yticks([])
        for ax in axs[num:]:
            ax.axis('off')
        plt.tight_layout()
        plt.show(block=block)
        plt.waitforbuttonpress(timeout=0.001)

    def fitness(self, x):
        return np.mean(np.array(x) == self.target_image)

    def mutation(self, x, prob):
        return self.boolean_mutation(x, prob)




class Painting(GenAlgProblem):
    def __init__(self, pic_path, num_squares=7, **kwargs):
        self.target_image = np.array(Image.open(pic_path))
        self.img_shape = self.target_image.shape
        self.num_squares = num_squares
        super().__init__(**kwargs)

    def generate_individual(self):
        return list(np.random.rand(self.num_squares * 7))

    def render_individual(self, x):
        canvas = np.ones(self.img_shape, dtype='float64')
        x_size, y_size, _ = self.img_shape
        for i in range(self.num_squares):
            square = x[i*7 : (i+1)*7]
            x1, x2 = sorted([int(np.floor(num * x_size)) for num in square[:2]])
            y1, y2 = sorted([int(np.floor(num * y_size)) for num in square[2:4]])
            c, m, y = square[4:] # CMY - subtractive color model
            canvas[x1:x2, y1:y2, 0] -= c
            canvas[x1:x2, y1:y2, 1] -= m
            canvas[x1:x2, y1:y2, 2] -= y
        canvas = np.clip(canvas, a_min=0, a_max=1)
        return canvas

    def show_individual(self, x, title=None, block=False):
        plt.figure(num=title).canvas.mpl_connect('key_press_event', keypress)
        plt.imshow(self.render_individual(x))
        plt.title('Fitness = {:.3f}'.format(self.fitness(x)))
        plt.xticks([]); plt.yticks([])
        plt.show(block=block)
        plt.waitforbuttonpress(timeout=0.001)

    def show_population(self, title='Population', limit=None, block=False):
        num = min(limit or np.inf, len(self.population))
        n_cols = int(np.ceil(np.sqrt(num)))
        n_rows = int(np.ceil(num / n_cols))
        title = title + ('' if limit is None else ' (best ' + str(limit) + ')')
        fig, axs = plt.subplots(n_rows, n_cols, num=title)
        fig.canvas.mpl_connect('key_press_event', keypress)
        axs = np.array([axs]).flatten()
        srt_pop = sorted(self.population, key=lambda x:self.fitness(x), reverse=True)[:num]
        for x, ax in zip(srt_pop, axs):
            ax.imshow(self.render_individual(x))
            ax.set_title('f={:.3f}'.format(self.fitness(x)))
            ax.set_xticks([]); ax.set_yticks([])
        for ax in axs[num:]:
            ax.axis('off')
        plt.tight_layout()
        plt.show(block=block)
        plt.waitforbuttonpress(timeout=0.001)

    def fitness(self, x):
        return 1 - np.mean( np.abs(self.target_image/256 - self.render_individual(x)) )

    def mutation(self, x, prob):
        return list(np.clip(self.number_mutation(x, prob), a_min=0, a_max=1))

