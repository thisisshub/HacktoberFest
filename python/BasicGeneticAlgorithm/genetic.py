import numpy as np
import random

from problems import *

class GenAlgProblem:

    def __init__(self, population_size=12, n_crossover=3, mutation_prob=0.05):
        # Initialize the population - create population of 'size' individuals,
        # each individual is a bit string of length 'word_len'.
        self.population_size = population_size
        self.n_crossover = 3
        self.mutation_prob = 0.05
        self.population = [self.generate_individual() for _ in range(self.population_size)]

    def generate_individual(self):
        # Generate random individual.
        # To be implemented in subclasses
        raise NotImplementedError

    def show_individual(self, x):
        # Show the given individual x, either to console or graphically.
        # To be implemented in subclasses
        raise NotImplementedError

    def show_population(self, title='Population:', limit=None, **kwargs):
        # Show whole population.
        # To be implemented in subclasses
        raise NotImplementedError


    def fitness(self, x):
        # Returns fitness of a given individual.
        # To be implemented in subclasses
        raise NotImplementedError

    def crossover(self, x, y, k):
        # Take two parents (x and y) and make two children by applying k-point
        # crossover. Positions for crossover are chosen randomly.
        places = set()
        x_new = []
        y_new = []
        x, y = list(x), list(y)
        while len(places) < k:
            places.add(random.randint(0,min(len(x), len(y))))
        places = sorted(places)
        
        for i in range(0, len(places)):
            while len(x_new) < places[i]:
                x1 = x.pop(0)
                y1 = y.pop(0)
                if i % 2 == 0:
                    x_new.append(x1)
                    y_new.append(y1)
                else:
                    x_new.append(y1)
                    y_new.append(x1)
        while len(x) > 0 and k % 2 == 0:
            x_new.append(x.pop(0))
        while len(y) > 0 and k % 2 == 1:
            x_new.append(y.pop(0))
        while len(y) > 0 and k % 2 == 0:
            y_new.append(y.pop(0))
        while len(x) > 0 and k % 2 == 1:
            y_new.append(x.pop(0))
                
        return (x_new, y_new)

    def boolean_mutation(self, x, prob):
        # Elements of x are 0 or 1. Mutate (i.e. change) each element of x with given probabipity.
        num = 1 / prob
        for i in range(len(x)):
            ri = random.randint(1, num)
            if ri * 1 == 1:
                x[i] = 0 if x[i] == 1 else 1
        return x

    def number_mutation(self, x, prob):
        # Elements of x are real numbers [0.0 .. 1.0]. Mutate (i.e. add/substract random number)
        # each number in x with given probabipity.
        num = 1 / prob
        sigma = 0.5
        for i in range(len(x)):
            ri = random.randint(1, num)
            if ri * 1 == 1:
                x[i] += -1 ** random.randint(0, 1) * random.gauss(0, sigma)
        return x

    def mutation(self, x, prob):
        # To be specified in subclasses, uses boolean_mutation or number_mutation functions
        raise NotImplementedError

    def roulette(self):
        parents = []  # create empty array
        s = 0  # sum of all fitness functions
        for individual in self.population:
            s += self.fitness(individual)

        while len(parents) < 2:
            stop = random.uniform(0, s)  # choose random number from the range from 0 to the sum
            p = 0
            for individual in self.population:
                if individual in parents:  # dont count the same individual twice
                    continue
                p += self.fitness(individual)  # partial summary
                if p >= stop:  # if the summary is bigger than the random number we found our winner
                    parents.append(individual)
                    s -= self.fitness(individual)  # decrease the total sum
                    break
        return parents[0], parents[1]  # return two lucky winners

    def tournament(self):
        parents = []
        while len(parents) < 2:
            population = [x for x in self.population if x not in parents]  # actual population from which we can select
            k = random.randint(2, len(population) - 1)
            # random number of individuals chosen to tournament
            fighters = []
            while len(fighters) < k:
                rn = random.randint(0, len(population) - 1)  # random index
                fighters.append(population[rn])  # add individual to the next round
                population.remove(fighters[-1])
            parents.append(max(fighters, key=lambda x: self.fitness(x)))  # choose best individual
        return parents[0], parents[1]

    def solve(self, max_generations, goal_fitness=1):
        # Implementation of genetic algorithm. Produce generations until some
        # individual`s fitness reaches goal_fitness, or you exceed total number
        # of max_generations generations. Return best found individual.
        while max_generations > 0:
            new_population = []
            for i in range(1, len(self.population), 2):
                parent1, parent2 = self.tournament()
                child1, child2 = self.crossover(parent1, parent2, self.n_crossover)
                child1 = self.mutation(child1, self.mutation_prob)
                child2 = self.mutation(child2, self.mutation_prob)
                new_population += [parent1, parent2, child1, child2]
            new_population = sorted(new_population, key=lambda x: self.fitness(x), reverse=True)  # sort new population
            self.population = new_population[: self.population_size]  # take best individuals from new population
            if goal_fitness in [self.fitness(x) for x in self.population]:
                break  # if the population contains best possible individual break
            max_generations -= 1
            
        return max(self.population, key=lambda x: self.fitness(x))  # return best individual


if __name__ == "__main__":
    ## Choose problem
    # ga = OnesString()
    ga = Smiley()
    # ga = Painting('painting.jpg', population_size=32, mutation_prob=0.25)
    ga.show_population('Initial population', limit=None)

    ## You can play with parameters
    # ga.n_crossover = 5
    # ga.mutation_prob = 0.1

    ## Solve to find optimal individual
    best = ga.solve(100) # you can also play with max. generations
    ga.show_population('Final population', limit=None)
    ga.show_individual(best, 'Best individual')


    ## Test your crossover function
    # ga = OnesString()
    # children = ga.crossover([0]*32, [1]*32, k=3)
    # print('{}\n{}'.format(*children))
